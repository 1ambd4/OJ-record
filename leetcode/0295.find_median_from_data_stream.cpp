#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class median_finder {
public:
    median_finder() = default;

    // 这里比较巧妙，需要维护根堆的两个方面性质
    // 1.两个根堆元素个数之差不能大于1
    // 2.大根堆里的元素都要大于小根堆里的元素
    void add_num(int n)
    {
        // 不能这样直接插入，会无法满足性质2
        // if (large.size() > small.size()) {
        //     small.push(n);
        // } else {
        //     large.push(n);
        // }

        // 要往小根堆里插入数据，需要先将其插入到大根堆里
        // 然后拿大根堆堆顶的元素插入小根堆，这样才能保证满足性质1
        // 往大根堆里插入数据同理
        if (large.size() > small.size()) {
            large.push(n);
            small.push(large.top());
            large.pop();
        } else {
            small.push(n);
            large.push(small.top());
            small.pop();
        }
    }

    double find_median()
    {
        if (large.size() > small.size()) {
            return large.top();
        } else if (large.size() < small.size()) {
            return small.top();
        } else {
            return (large.top() + small.top()) / 2.0;
        }
    }

private:
    // 两个优先队列模拟大小根堆
    // 即可以认为是把所有的元素分成了两部分，一部分较大，一部分较小
    // 较大部分用小根堆，较小部分用大根堆
    // 那么中位数就容易计算了
    // 当大小根堆元素相同的时候，取两个根堆顶部元素的平均值
    // 否则，哪边元素个数多取哪个根堆对定元素即可
    priority_queue<int, vector<int>, greater<int>> large;
    priority_queue<int, vector<int>, less<int>> small;
};

int main()
{
    median_finder mf;
    mf.add_num(1);
    mf.add_num(2);
    cout << mf.find_median() << endl;
    mf.add_num(3);
    cout << mf.find_median() << endl;

    return 0;
}

