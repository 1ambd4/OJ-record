#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public: 
    MyQueue() = default;

    void push(int x)
    {
        s2.emplace(x);
    }

    int pop()
    {
        if (s1.empty()) {
            help();
        }
        int tmp = s1.top();
        s1.pop();
        return tmp;
    }

    int peek()
    {
        if (s1.empty()) {
            help();
        }
        return s1.top();
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
private:
    void help()
    {
        while(!s2.empty()) {
            int tmp = s2.top();
            s1.emplace(tmp);
            s2.pop();
        }
    }
    // s1队头，s2队尾
    stack<int> s1{}, s2{};
};

int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(2);
    obj->push(3);
    int param1 = obj->pop();
    int param2 = obj->peek();
    int param3 = obj->empty();
    cout << param1 << " " << param2 << " " << param3 << endl;
    return 0;
}
