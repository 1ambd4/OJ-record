#include <iostream>
#include <string>
#include <vector>


// 状态机写法
// https://mp.weixin.qq.com/s/r9pbkMyFyMAvmkf4QnL-1g
class KMP {
public:
    KMP(std::string pat);
    int search(std::string txt);
private:
    std::vector<std::vector<int>> dp;
    std::string pat;
};

KMP::KMP(std::string pat) : pat(pat)
{
    int n = pat.size();
    // dp[j]]c]：状态j读入字符c转到的状态
    dp = std::vector<std::vector<int>>(n, std::vector<int>(256));

    // base case，从状态0读入串的第一个字符转入状态1
    dp[0][pat[0]] = 1;

    int x = 0; // 影子状态初始为0
    for (int j = 1; j < n; ++j) {
        for (int c = 0; c < 256; ++c) {
            dp[j][c] = dp[x][c];
        }
        // 在状态j上遇到字符pat[j]则转移到状态j+1
        // 为啥是j+1呢？其实无所谓的，这里就是方便嘛
        // 顺序的读取pat里的字符，按序构造状态机
        dp[j][pat[j]] = j + 1;
        // 同时更新所谓的影子状态，一样是读入字符c后转移到新的状态
        x = dp[x][pat[j]];
    }
}

int KMP::search(std::string txt)
{
    int n = txt.size(), m = pat.size();

    for (int i = 0, j = 0; i < n; ++i) {
        // 计算下一个状态
        j = dp[j][txt[i]];
        // 到达终止状态，返回结果
        if (j == m) return i - m + 1;
    }

    return -1;
}


int main()
{
    KMP kmp1("sad");
    std::cout << kmp1.search("sadbutsad") << std::endl;

    KMP kmp2("leeto");
    std::cout << kmp2.search("leetcode") << std::endl;
    return 0;
}
