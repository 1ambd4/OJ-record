#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int ThirdMaximumNumber(vector<int> &nums) {
    int64_t first = INT64_MIN, second = INT64_MIN, third = INT64_MIN;

    // 优化一下，减少if判断次数
    // 对于找k大数，那么先和第k大的数比较，如果比第k大还小，那么也就不用和其他的比了，结果定然是小的
    // 而如果先和最大的比较，那么比较完了还要依次比较下去，性能上会差一些
    for (auto const &num : nums) {
        if (num > third) {
            if (num < second) {
                third = num;
            } else if (num > second) {
                if (num < first) {
                    third = second;
                    second = num;
                } else if (num > first) {
                    third = second;
                    second = first;
                    first = num;
                }
            }
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
