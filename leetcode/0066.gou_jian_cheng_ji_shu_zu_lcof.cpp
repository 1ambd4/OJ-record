#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// bf会t的叭
// 还不给用除法
// 分块？

struct Block {
    int32_t start, end, value;
};

vector<int> ConstructArray(vector<int> &a)
{
    if (a.size() == 0) {
        return vector<int>();
    }
    // 1、分块，每个块sqrt(n)
    int size_of_block = sqrt(a.size());
    // 维护每个块的起止元素下标，左开右闭
    vector<Block> blocks(ceil(a.size() / float(size_of_block)));
    for (int i = 0; i < blocks.size(); ++i) {
        blocks[i].start = i * size_of_block;
        blocks[i].end = (i+1) * size_of_block;
        blocks[i].value = 1;
    }
    blocks[blocks.size()-1].end = a.size();    // 修正不完整块
    
    // 2、预处理
    for (auto &block : blocks) {
       for (int i = block.start; i < block.end; ++i) {
           block.value *= a[i];
       }
    }

    // 3、构建数组b
    vector<int> b(a.size(), 1);
    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < blocks.size(); ++j) {
            if (i/size_of_block == j) {
                // 对i所在的块重新计算
                for (int k = blocks[j].start; k < blocks[j].end; ++k) {
                    if (i == k) {
                        continue;
                    }
                    b[i] *= a[k];
                }
            } else {
                // 其他的直接查表
                b[i] *= blocks[j].value;
            }
       }
    }

    return b;
}

int main(void)
{
    vector<int> v1 = {};
    vector<int> r1 = ConstructArray(v1);
    for (auto const &e : r1) {
        cout << e << " ";
    }
    cout << endl;

    vector<int> v2 = {1, 2, 3, 4, 5};
    vector<int> r2 = ConstructArray(v2);
    for (auto const &e : r2) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
