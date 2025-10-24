#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void reverseWords(string s) 
    {
        string reverse;
        bool isWord = false;
        bool space = false;
        size_t wordEnd;

        for (int i = s.size() - 1; i >=0 ; i--)
        {
            if (s[i] != ' ' && isWord == false)
            {
                isWord = true;
                wordEnd = i;
            }
            
            if (s[i] == ' ' && isWord == true)
            {
                isWord = false;
                if (space)
                    reverse.append(" ");
                space = true;
                reverse.append(s, i + 1, wordEnd - i);
                cout << "1: [" << reverse << "] start= " << i + 1 << " end= " << wordEnd << endl;
            }

            if (i == 0 && isWord ==true)
            {
                if (space)
                    reverse.append(" ");
                reverse.append(s, i, wordEnd - i + 1);
                cout << "2: [" << reverse << "] start= " << i << " end= " << wordEnd << endl;
            }

                
            
            //cout << "s[" << i << "] = " << s[i] << " | " << (isWord? "True" : "False") << endl;  
        }

        /*
        string reverse;
        size_t wordEnd;
        bool isWord = false;
        bool space = false;

        for (int i = s.size() - 1; i >=0 ; i--)
        {
            if (isWord == false && s[i] != ' ')
            {
                if (i == 0)
                {
                    reverse.append(" ");
                    reverse.append(s, s[0], 1);
                }
                    
                isWord = true;
                wordEnd = i;
            }
            else if (isWord == true && (i == 0 || s[i] == ' ' && s[i + 1] != 0))
            {
                isWord = false;
                if (space)
                    reverse.append(" ");
                space = true;
                if (i == 0)
                    reverse.append(s, i, wordEnd - i + 1);
                else
                    reverse.append(s, i + 1, wordEnd - i);
                cout << "test: [" << reverse << "] start= " << i << " end= " << wordEnd << endl;
            }
        }
        return reverse;
        */
    }
};


void testcase(string s)
{   
    cout << "--------------------------------\n";

    Solution test;
    cout << "[" << s << "]" << endl;
    test.reverseWords(s);
}

int main()
{
    testcase(string("GOOD"));
    testcase(string("   CIA    "));
    testcase(string("FBI    "));
    testcase(string("      BOOM"));
    testcase(string("   the    sky     is    blue   "));
    testcase(string(" If# the stringr data@ type is3 mutable in your language, 54 "));
    testcase(string("a good   example b"));
    testcase(string("a b c d e f"));
    testcase(string("  a   b    c    d   e   f  "));
    testcase(string("a b c yoo e f"));
    testcase(string("a"));
}
