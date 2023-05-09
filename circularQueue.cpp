#include <iostream>
#include <queue>
using namespace std;

class CircularQueue
{

    int *arr;
    int front;
    int rear;
    int size;

public:
    // initialization of the data memeber;
    CircularQueue(int n)
    {

        size = 10001;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue(int value)
    {

        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {

            cout << "Queue is full" << endl;

            return false;
        }

        else if (front == -1)
        { // first element for push in queue;

            front = rear = 0;

            arr[rear] = value;
        }

        else if (rear == size - 1 && front != 0)
        {

            rear = 0;
            arr[rear] = value;
        }

        else
        {

            rear++;
            arr[rear] = value;
        }

        return true;
    }

    int dequeue()
    {

        if (front == -1)
        {

            cout << "queue is empty" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        { // single element is present in the queue;

            front = rear = -1;
        }

        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        return ans;
    }
};
int main()
{

    return 0;
}