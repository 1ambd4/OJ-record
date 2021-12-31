#include <iostream>
#include <stack>

using namespace std;

class CQueue {
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        stk1.push(value);
    }

    int deleteHead()
    {
        // 删除操作的时候，如果stk2空，则stk1全部出栈并压入stk2
        // 如果此时stk2不空，则栈顶出栈，否则表明“队列”为空
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }

        if (stk2.empty()) {
            return -1;
        } else {
            int tmp = stk2.top();
            stk2.pop();
            return tmp;
        }
    }

private:
    stack<int> stk1, stk2;
};

int main()
{
    CQueue* q = new CQueue();
    q->appendTail(2);
    q->appendTail(3);
    q->appendTail(4);
    cout << q->deleteHead() << endl;
    cout << q->deleteHead() << endl;
    cout << q->deleteHead() << endl;
    cout << q->deleteHead() << endl;
    cout << q->deleteHead() << endl;

    return 0;
}
