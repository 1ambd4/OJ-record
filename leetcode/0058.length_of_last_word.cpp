#include <cctype>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int LengthOfLastWord(string s)
{
    // 双指针，从后往前遍历
    // j指向第一个非空字符，i从此位置开始继续向前遍历，直到遇到第一个空字符

    s = " " + s;    // 过"a"这种前面没空空格的
    for (int j = s.length() - 1; j >= 0; j--) if (isalpha(s[j])) {
        for (int i = j; i >= 0; i--) if (!isalpha(s[i])) {
            return j - i;
        }
    }
}

int main(void)
{
    string first_test_case {"Hello World"};
    cout << LengthOfLastWord(first_test_case) << endl;

    string second_test_case {"   fly me   to   the moon  "};
    cout << LengthOfLastWord(second_test_case) << endl;

    string third_test_case {"luffy is still joyboy"};
    cout << LengthOfLastWord(third_test_case) << endl;

    string fourth_test_case {"a"};
    cout << LengthOfLastWord(fourth_test_case) << endl;

    return 0;
}
