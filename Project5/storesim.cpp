//--------------------------------------------------------------------
//
//  Laboratory 7, Programming Exercise 1                   storesim.cs
//
//  Program implementation shell.
//
//--------------------------------------------------------------------

// Simulates the flow of customers through a line in a store.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

// Use which ever implementation is currently configured.
//#if LAB7_TEST1
//#   include "QueueLinked.cpp"
//#else
#include "QueueArray.h"
//#endif

using namespace std;

int main ()
{
#if LAB7_TEST1
    QueueLinked<int> custQ;      // Line (queue) of customers containing the
#else
    QueueArray<int> custQ;       // Line (queue) of customers containing the
#endif 				 //   time that each customer arrived and
    //   joined the line
    int simLength ,              // Length of simulation (minutes)
            minute,                  // Current minute
            timeArrived,             // Time dequeued customer arrived
            waitTime,                // How long dequeued customer waited
            totalServed = 0,         // Total customers served
            totalWait   = 0,         // Total waiting time
            maxWait     =0,         // Longest wait
            numArrivals = 0;         // Number of new arrivals

    // Seed the random number generator. Equally instructive to run the
    // simulation with the generator seeded and not seeded.
    srand(1);

    cout << endl << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    srand(time(NULL));



    // Put your code here to run this simulation. Use "rand()" to get
    // a pseudorandom number that you can use to calculate probabilities.

    for(minute = 0; minute <simLength ; minute++)
    {
        int k;
        int temp = 0;

        if(!custQ.isEmpty())
        {

            //cout<<minute<<"min"<<endl;
            //removing the customer at the front of the queue
            timeArrived=custQ.dequeue();

            waitTime = minute - timeArrived;

            totalWait +=waitTime;

            totalServed++;


            if(waitTime > maxWait )
            {
                maxWait = waitTime;
            }

            timeArrived = temp;

        }

        k = rand()%4;

        //If k is 1, then add one customer to the line
        if(k==1)
        {
            numArrivals++;
        }

        //If k is 2, then add two customers to the line
        else if(k==2)
        {
            numArrivals+=2;
        }

        //Otherwise (if k is 0 or 3), do not add any customers to the line
        else if((k==0)||(k==3))
        {
            numArrivals = 0;
        }



        for(int x=0;x< numArrivals; x++)
        {
            custQ.enqueue(minute);
        }

        numArrivals = 0;



    }

    // Print out simulation results
    cout << endl;
    cout << "Customers served : " << totalServed << endl;
    cout << "Average wait     : " << setprecision(2)<< double(totalWait)/totalServed << endl;
    cout << "Longest wait     : " << maxWait<< endl;

    return 0;
}
