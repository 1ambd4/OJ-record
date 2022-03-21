#include <iostream>                      
#include <queue>

using namespace std;


class MyStack {
public:
    MyStack() = default;

    void push(int x)
    {
        stk.push(x);
    }

    int pop()
    {
        int len = stk.size(), tmp = 0;
        while (len-- > 1) {
            tmp = stk.front();
            stk.pop();
            stk.push(tmp);
        }
        tmp = stk.front();
        stk.pop();
        return tmp;
    }

    int top()
    {
        return stk.back();
    }

    bool empty()
    {
        return stk.empty();
    }
private:
    queue<int> stk;
};

int main()
{
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    int param1 = obj->top();
    int param2 = obj->pop();
    int param3 = obj->pop();
    bool param4 = obj->empty();
    cout << param1 << " " << param2 << " " << param3 << " " << param4 << endl;
    return 0;
}
