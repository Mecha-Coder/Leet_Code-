#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int j = 0;

        if (!s.size())
            return true;
        for (int i = 0; i < t.size() ; i++)
        {
            if (s[j] == t[i] && s[++j] == 0)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution test;
    cout<< "---------------------------\n" 
        << test.isSubsequence(
            string(""),
            string("")
        ) << endl;

    cout<< "---------------------------\n" 
        << test.isSubsequence(
            string(""),
            string("c")
        ) << endl;

    cout<< "---------------------------\n"
        << test.isSubsequence(
            string("abc"),
            string("")
        ) << endl;
    
    cout<< "---------------------------\n"
        << test.isSubsequence(
            string(""),
            string("abc")
        ) << endl;
    
    cout<< "---------------------------\n"
        << test.isSubsequence(
            string("c"),
            string("abc")
        ) << endl;
    
    cout<< "---------------------------\n"
        << test.isSubsequence(
            string("abc"),
            string("ahbgdc")
        ) << endl;
    
    cout<< "---------------------------\n"
    << test.isSubsequence(
        string("axc"),
        string("ahbgdc")
    ) << endl;
}