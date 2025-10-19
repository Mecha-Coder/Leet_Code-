#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int allProduct = 1;
        int zeroCounter = 0;
        int zeroIndex;
        int i;

        vector<int> answer(nums.size());
        
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (zeroCounter > 0)
                    return answer;
                zeroCounter++;
                zeroIndex = i;
            }
            else
                allProduct *= nums[i];
        }

        if (zeroCounter > 0)
        {
            answer[zeroIndex] = allProduct;
            return answer;
        }

        for (i = 0; i < nums.size(); i++)
            answer[i] = allProduct / nums[i];
        return answer;
    }
};


void testcase(vector<int> nums)
{   
    cout << "--------------------------------\n";

    for (int num : nums)
        cout << num << ", ";
    cout << "\n" <<endl;

    Solution test;
    vector<int> answers = test.productExceptSelf(nums);

    for (int answer : answers)
        cout << answer << ", ";
    cout << endl;
}

int main()
{
    testcase(vector<int>{1, 3, 3, 4});
    testcase(vector<int>{-3, -5, -1, -2});
    testcase(vector<int>{-1, 2, -3, 4});
    testcase(vector<int>{0, -5, 2, 3, -4, 0});
    testcase(vector<int>{-1, 1, 0, -3, 3});
}


