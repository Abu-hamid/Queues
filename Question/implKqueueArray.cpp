#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class KQueue
{

public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int *next;

    KQueue(int n, int k)
    {
        this->n = n;
        this->k = k;

        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < n; i++)
        {

            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        arr = new int[n];
        freespot = 0;
    }

    void enque(int data, int qn)
    {

        // overflow;

        if (freespot == -1)
        {
            cout << "overflow occured" << endl;

            return;
        }

        // find first free index;

        int index = freespot;

        // update freespot;

        freespot = next[index];

        // check whether first element;

        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }

        else
        {

            // link the new element to the previous element;

            next[rear[qn - 1]] = index;
        }

        // update next;
        next[index] = -1;

        // update rear;

        rear[qn - 1] = index;

        // push element;

        arr[index] = data;
    }

    int deque(int qn)
    {

        // under flow condition;

        if (front[qn - 1] == -1)
        {

            cout << "queue under flow";
            return -1;
        }

        // find indx;
        int index = front[qn - 1];

        // front ko age badhao;

        front[qn - 1] = next[index];

        // manage freespot;

        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};
int main()
{

    return 0;
}