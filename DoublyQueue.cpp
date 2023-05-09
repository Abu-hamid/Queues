#include <iostream>
#include <queue>
using namespace std;

class Dequeue
{

    int *arr;
    int rear;
    int front;
    int size;

public:
    // initialize the data structure;

    Dequeue(int n)
    {
        size = n;
        arr = new int[size];
    }

    bool push_front(int x)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return false;
        }

        else if (front == -1)
        { // first elemnt push in the queue;

            front = rear = 0;
        }

        else if (front == 0 && rear != size - 1)
        { // circular part maintain;
            front = size - 1;
        }

        else
        {

            front--; // normal push in the efront of the queue;
        }
        arr[front] = x;

        return true;
    }

    bool push_rear(int x)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            return false;
        }
        else if (front == -1)
        { // first elemnt push in the queue;
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        { // circular part maintain;
            rear = 0;
        }
        else
        {
            rear++; // normal push in the efront of the queue;
        }
        arr[rear] = x;
        return true;
    }

    int popfront()
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

    int poprear()
    {

        if (front == -1)
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if (front == rear)
        { // single element is present in the queue;
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return ans;
    }

    int getfront()
    {

        if (isEmpty())
        {

            return -1;
        }

        return arr[front];
    }

    int getrear()
    {

        if (isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty()
    {

        if (front == -1)

            return true;

        else
            return false;
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            return true;
        }

        else
            return false;
    }
};

int main()
{

    return 0;
}