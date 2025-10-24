#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Compilation command:  gcc med_Add_Two_valbers.c -lm

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode *createList(int *array, int arrSize)
{
    struct ListNode *newList = NULL;
    struct ListNode *currentNode = NULL;

    for (int i = 0; i < arrSize; i++)
    {
        if (i == 0)
        {
            newList = createNode(array[i]);
            currentNode = newList;
        }
        else
        {
            currentNode->next = createNode(array[i]);
            currentNode = currentNode->next;
        }
    }
    return newList;
}

void checkArray(struct ListNode *array)
{
    while (1)
    {
        printf("%d, ", array->val);
        if (array->next == NULL)
        {
            printf("\n");
            break;
        }
        array = array->next;
    }
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int total = 0; 
    int carry = 0; 
    int num1 = l1->val; 
    int num2 = l2->val;
    struct ListNode *start = NULL;
    struct ListNode *current = NULL;


    for (int i = 0; ;i++)
    {
        total = num1 + num2 + carry;
        if (i == 0)
        {
            current = createNode(total % 10);
            start = current;
        }
        else
        {
            current->next = createNode(total % 10);
            current = current->next;
        }
        
        carry = total / 10;
        if (!l1->next && !l2->next)
        {
            if (carry > 0)
                current->next = createNode(carry);
            break;
        }

        num1 = num2 = 0;
        if (l1->next) {
            l1 = l1->next;
            num1 = l1->val;
        }
        if (l2->next) {
            l2 = l2->next;
            num2 = l2->val;
        }
    }
    return start;
}

int main()
{
    struct ListNode *l1 = createList((int[]){9,9,9,9,9,9,9}, 7);
    struct ListNode *l2 = createList((int[]){9,9,9,9}, 4);

    checkArray(l1);
    checkArray(l2);

    struct ListNode *finalList = addTwoNumbers(l1, l2);
    checkArray(finalList);
}
