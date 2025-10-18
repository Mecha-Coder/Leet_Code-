#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        size_t zeroCounter = 0;
        size_t  numSize = nums.size() - 1;

        for (int i = 0; i <= numSize; i++)
        {
            if (nums[i] == 0)
                zeroCounter++;
            else
                nums[i - zeroCounter] = nums[i];
        }
        for (int i = 0; i < zeroCounter; i++)
        {
            nums[numSize - i] = 0;
        }
    }
};


void showarray(vector<int>& nums)
{
    for (int num : nums)
        cout << num << ", ";
    cout << endl;
}

void testcase(vector<int> nums)
{
    cout << "--------------------------------\n"
         << "Before : ";
    showarray(nums);
    cout << "After  : ";
    Solution test;
    test.moveZeroes(nums);
    showarray(nums);
}

int main()
{
    testcase(vector<int>{0,1,0,3,12});
    testcase(vector<int>{0});
    testcase(vector<int>{0,1});
    testcase(vector<int>{1,1});
    testcase(vector<int>{1,0});
    testcase(vector<int>{0,2,1,6,0});
    testcase(vector<int>{11123,432424,0,66666,34, 4324, 2});
    testcase(vector<int>{0,0,0,0,0});
    testcase(vector<int>{0,0,0,5,0});
    testcase(vector<int>{0,0,0,0,10});
    testcase(vector<int>{1,1,1,1,0});
    testcase(vector<int>{5,0,0,0,0});
}
