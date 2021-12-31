#include <cassert>
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() { }

    void push(int x)
    {
        m_data.push(x);

        if (m_min.empty() || x < m_min.top()) {
            m_min.push(x);
        } else {
            m_min.push(m_min.top());
        }
    }

    void pop()
    {
        assert(!m_data.empty() && !m_min.empty());
        m_data.pop();
        m_min.pop();
    }

    int top()
    {
        assert(!m_data.empty());
        return m_data.top();
    }

    int min()
    {
        assert(!m_min.empty());
        return m_min.top();
    }

private:
    stack<int> m_data, m_min;
};

int main()
{
    return 0;
}
