#include <string>
#include <iostream>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        
        int skip = 0;
        for (int i = 0; i < s.size() ; ++i)
        {
            if (isalnum(s[i]))
            {
                if (isalpha(s[i]) && isupper(s[i]))
                    s[i - skip] = tolower(s[i]);
                else
                    s[i - skip] = s[i];
            }
            else
                skip++;
        }
        s.erase(s.size() - skip);
        
        cout << "[" << s << "] Size = " << s.size() << endl;

        if (s.size() == 0)
            return true;

        int lastIndex = s.size() - 1;
        for (int i = 0; i < s.size() ; ++i)
        {
            if (s[i] != s[lastIndex - i])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution test;
    cout << "----------------------\n"
         << test.isPalindrome("Hello5 world ") << endl;
    
    cout << "----------------------\n"
         << test.isPalindrome("") << endl;

    cout << "----------------------\n"
         << test.isPalindrome("321c e3_c55ec") << endl;

    cout << "----------------------\n"
         << test.isPalindrome("A man, a plan, a canal: Panama") << endl;
    
    cout << "----------------------\n"
         << test.isPalindrome("race a car") << endl;

    cout << "----------------------\n"
         << test.isPalindrome("99") << endl;
    
    cout << "----------------------\n"
         << test.isPalindrome("    ") << endl;
    
    cout << "----------------------\n"
         << test.isPalindrome("0P") << endl;
}
