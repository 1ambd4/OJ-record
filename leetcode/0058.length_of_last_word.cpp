#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int LengthOfLastWord(string s)
{
    stringstream ss(s);
    while (ss >> s) ;
    return s.length();
}

int main(void)
{
    string first_test_case {"Hello World"};
    cout << LengthOfLastWord(first_test_case) << endl;

    string second_test_case {"   fly me   to   the moon  "};
    cout << LengthOfLastWord(second_test_case) << endl;

    string third_test_case {"luffy is still joyboy"};
    cout << LengthOfLastWord(third_test_case) << endl;

    return 0;
}
