#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> ReverseK(queue<int> q, int k)
{

    stack<int> s;

    for (int i = 0; i < k; i++)
    {

        int val = q.front();
        q.pop();
        s.push(val);
    }

    // pop from the stack and put into the queue;

    while (!s.empty())
    {

        int val = s.top();
        s.pop();
        q.push(val);
    }

    // pop n-k value of the element and push into the back of the queue;

    int t = q.size() - k;
    while (t--)
    {

        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}

int main()
{

    return 0;
}