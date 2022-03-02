#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int remove_element(vector<int>& nums, int val)
{
    int left = 0, right = 0, len = nums.size();
    for ( ; right < len; ++right) {
        if (nums[right] != val) {
            nums[left++] = nums[right];
        }
    }

    return left;
}

int main()
{

    ostream_iterator<int> out_iter(cout, " ");

    vector<int> case1 { 3, 2, 2, 3 };
    int res1 = remove_element(case1, 3);
    copy(case1.begin(), case1.begin() + res1, out_iter); 
    cout << endl;

    vector<int> case2 { 0, 1, 2, 2, 3, 0, 4, 2 }; 
    int res2 = remove_element(case2, 2); 
    copy(case2.begin(), case2.begin() + res2, out_iter); 
    cout << endl;

    vector<int> case3 { }; 
    int res3 = remove_element(case3, 1); 
    copy(case3.begin(), case3.begin() + res3, out_iter); 
    cout << endl;

    return 0;
}
