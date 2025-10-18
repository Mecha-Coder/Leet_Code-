#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        map<int, int> trackNum;
        int maxKey = 0;
        int maxValue = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            trackNum[nums[i]]++;
            if (trackNum[nums[i]] > maxValue)
            {
                maxKey = nums[i];
                maxValue = trackNum[nums[i]];
            }
        }
        return maxKey;
    }
};


void testcase(vector<int> nums)
{
    for (int num : nums)
        cout << num << ", ";
    cout << endl;

    Solution test;
    cout << "Answer = " << test.majorityElement(nums) 
         << "\n--------------------------------" << endl;
}

int main()
{
    testcase(vector<int>{3,2,3});
    testcase(vector<int>{47,47,72,47,72,47,79,47,12,92,13,47,47,83,33,15,18,47,47,47,47,64,47,65,47,47,47,47,70,47,47,55,47,15,60,47,47,47,47,47,46,30,58,59,47,47,47,47,47,90,64,37,20,47,100,84,47,47,47,47,47,89,47,36,47,60,47,18,47,34,47,47,47,47,47,22,47,54,30,11,47,47,86,47,55,40,49,34,19,67,16,47,36,47,41,19,80,47,47,27});
}