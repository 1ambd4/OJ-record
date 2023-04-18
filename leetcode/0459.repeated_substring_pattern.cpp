#include <iostream>
#include <string>
#include <vector>


// TLE了，难崩
class KMP {
public:
    KMP(std::string pat) :
        pat(pat), dp(std::vector(pat.size(), std::vector<int>(256)))
    {
        int n = pat.size();

        dp[0][pat[0]] = 1;
        for (int j = 1, x = 0; j < n; ++j) {
            for (int c = 0; c < 256; ++c) {
                dp[j][c] = dp[x][c];
            }
            dp[j][pat[j]] = j + 1;
            x = dp[x][pat[j]];
        }
    }

    int search(std::string txt)
    {
        int n = txt.size(), m = pat.size();

        for (int i = 0, j = 0; i < n; ++i) {
            j = dp[j][txt[i]];
            if (j == m) return i - m + 1;
        }

        // return std::string::npos;
        return -1;
    }

private:
    std::string pat;
    std::vector<std::vector<int>> dp;
};

bool repeated_substring_pattern(std::string s)
{
    std::string ss = s + s;
    ss = ss.substr(1, ss.size()-2);
    KMP kmp(s);
    return kmp.search(ss) != -1;
}


// 移位匹配，注意倍增之后，需要删掉头尾元素，以去除自身匹配的情况
bool _repeated_substring_pattern(std::string s)
{
    std::string ss = s + s;
    ss = ss.substr(1, ss.size()-2);
    return ss.find(s) != std::string::npos;
}


int main()
{
    std::cout << repeated_substring_pattern("abab") << std::endl;
    std::cout << repeated_substring_pattern("aba") << std::endl;
    return 0;
}
