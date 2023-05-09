#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<long long> firstNegative(long long int A[], long long int N, long long int K)
{

    deque<long long int> dq;
    vector<long long> ans;

    // process the first window;
    for (int i = 0; i < K; i++)
    {

        if (A[i] < 0)
        {

            dq.push_back(i);
        }
    }

    // store the ans of the first window;

    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }

    else
    {
        ans.push_back(0);
    }

    // proseccc the rest of the window;

    for (int i = K; i < N; i++)
    {

        // removal;

        if (!dq.empty() && i - dq.front() >= K)
        {

            dq.pop_front();
        }

        // Addition;

        if (A[i] < 0)
        {

            dq.push_back(i);
        }

        // store the ans;
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}
int main()
{

    return 0;
}