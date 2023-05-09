#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interLeaveQueue(queue<int> &q)
{

    if (q.size() % 2 != 0)

        cout << "enter the even value of the  queue";
    stack<int> s;
    int halfSize = q.size() / 2;

    for (int i = 0; i < halfSize; i++)
    {

        int val = q.front();
        q.pop();
        s.push(val);
    }

    // insert the element of the stack in the back side of the queue;

    while (!s.empty())
    {

        int val = s.top();
        s.pop();
        q.push(val);
    }

    // push the queue element back from the front elemnt ;
    for (int i = 0; i < halfSize; i++)
    {

        int val = q.front();
        q.pop();
        q.push(val);
    }

    // push the elemnt of the queu into the stack again;
    for (int i = 0; i < halfSize; i++)
    {

        int val = q.front();
        q.pop();
        s.push(val);
    }

    // inter leave the queue;
    while (!s.empty())
    {

        q.push(s.top());
        s.pop();

        q.push(q.front());
        q.pop();
    }
}
int main()
{

    queue<int> q;

    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    interLeaveQueue(q);
    for (int i = 0; i < q.size(); i++)
    {

        cout << q.front() << "  ";
        q.pop();
    }
    return 0;
}