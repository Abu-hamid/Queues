

#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class solution
{

public:
    int tour(petrolPump p[], int n)//this  error due to constructor element;
    {

        int deficit = 0;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < n; i++)
        {

            balance = p[i].pertol - p[i].distance;

            if (balance > 0)
            {

                deficit += balance;
                start = i + 1;
                balance = 0;
            }
        }

        if (deficit + balance >= 0)
        {

            return start;
        }

        else
            return -1;
    }
};
int main()
{

    return 0;
}