#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int ThirdMaximumNumber(vector<int> &nums) {
    // 计数？或许可行，但是空间浪费太严重
    // 扔set里去重排序？那没意思了
    // 唔，一次遍历就解决了啊，类似快慢指针的思想

    // 测试样例就离谱：[1,2,-2147483648]
    // int first = INT32_MIN, second = INT32_MIN, third = INT32_MIN;
    int64_t first = INT64_MIN, second = INT64_MIN, third = INT64_MIN;

    for (auto const &num : nums) {
        if (num > first) {
            third = second;
            second = first;
            first = num;
        } else if (num > second && num < first) {
            third = second;
            second = num;
        } else if (num > third && num < second) {
            third = num;
        }
    }

    if (third == INT64_MIN) {
        return first;
    } else {
        return third;
    }
}

int main(void)
{
    vector<int> first_test_case {3, 2, 1};
    cout << ThirdMaximumNumber(first_test_case) << endl;

    vector<int> second_test_case {1, 2};
    cout << ThirdMaximumNumber(second_test_case) << endl;

    vector<int> third_test_case {2, 2, 3, 1};
    cout << ThirdMaximumNumber(third_test_case) << endl;

    vector<int> fourth_test_case {1, 2, -2147483648 };
    cout << ThirdMaximumNumber(fourth_test_case) << endl;
    return 0;
}
