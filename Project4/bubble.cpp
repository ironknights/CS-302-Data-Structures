//
// Created by Deeptanshu Das on 10/23/18.
//

//Bubble sort

#include <iostream>
#include "time.h"

using namespace std;


void bubbleSort (int theArray[], int n,long &inc, long &comp){

    bool sorted = false; // False when swaps occur
    int pass = 1;
   // int inc = 0;
    while (!sorted && (pass < n))
    {
        // At this point, theArray[n+1-pass..n-1] is sorted
        // and all of its entries are > the entries in
        // theArray[0..n-pass]
        sorted = true; // Assume sorted
        for (int index = 0; index < n-pass; index++)
        {
                // At this point, all entries in theArray[0..index-1]
                // are <= theArray[index]
                int nextIndex = index + 1;

                comp++;
                if (theArray[index] > theArray[nextIndex])
                {
                    // Exchange entries
                    std::swap(theArray[index], theArray[nextIndex]);
                    sorted = false; // Signal exchange
                   inc ++;
                } // end ifx

        } // end for
        // Assertion: theArray[0..n-pass-1] < theArray[n-pass]
        pass++;
        //cout<<"The number of swaps"<<inc<<endl;
    }


    // end while
} // end bubbleSortre

void print(int arr[],int size)
{
    int i;

    for(i=0;i<size;i++)
    {
        cout<<" "<<arr[i];
    }

    cout<<endl;
}

int main()
{

    //test for bubble sort

    int num;
    long inc,comp;

    int ch = 0;

    int n =0;

    int i =0;

    int j = 0;

    double arrprint=0;

    clock_t tstart = clock();

    srand(time(NULL));


    //num = rand() % 100 + 1;




    do {
        cout << "From this menu, do the following selection:" << endl;
        cout << "1. Generating random numbers between 1 and 1000 to bubble sort" << endl;
        cout << "2. Generating random numbers between 1 and 10000 to bubble sort" << endl;
        cout << "3. Generating random numbers between 1 and 100000 to bubble sort" << endl;
        cout << "4.Enter 4 to exit  " << endl;
        cin >> ch;


        switch (ch) {

            case 1 :


                /*
               int  arr[1000];
               //double arrprint;
                for ( i = 0; i < 1000; i++) {
                    num = rand() % 1000000 + 1;
                    arr[i] = num;
                    //cout << num << " " << i << endl;


                }
                 */

                // n = sizeof(arr)/sizeof(arr[0]);

                //bubbleSort(arr,n,inc,comp);

               //print(arr,n);

                for( i =0; i < 10 ;i++) {
                    int  arr[1000];
                    //double arrprint;
                    for ( j = 0; j < 1000; j++) {
                        num = rand() % 1000000 + 1;
                        arr[j] = num;
                    }
                    n = sizeof(arr)/sizeof(arr[0]);

                    bubbleSort(arr,n,inc,comp);

                    cout << "Time taken for each Bubble Sort:" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
                    arrprint = (double) (clock() - tstart) / CLOCKS_PER_SEC;
                    cout<<"No.of swaps :"<<inc<<endl;
                    cout<<"No.of comps:"<<comp<<endl;
                   //cout<<"average:"<<arrprint/i;
                }
                cout<<"The average time taken :"<<arrprint/i<<endl;
                cout<<"The average comparisons :"<<(comp)/i<<endl;
                cout<<"The average swaps:"<<inc/i<<endl;
                break;


            case 2 :


                /*
                int  arrr[10000];
                for (int i = 0; i < 10000; i++) {
                    num = rand() % 1000000 + 1;
                    arrr[i] = num;
                    cout << num << " " << i << endl;


                }
                n = sizeof(arrr)/sizeof(arrr[0]);

                bubbleSort(arrr,n,inc,comp);

                print(arrr,n);

                 */
                for( i =0; i < 10 ;i++) {

                    int  arrr[10000];
                    //double arrprint;
                    for ( j = 0; j < 10000; j++) {
                        num = rand() % 1000000 + 1;
                        arrr[j] = num;
                    }
                    n = sizeof(arrr)/sizeof(arrr[0]);

                    bubbleSort(arrr,n,inc,comp);
                    bubbleSort(arrr,n,inc,comp);
                    cout << "Time taken for each Bubble Sort :" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
                    arrprint = (double) (clock() - tstart) / CLOCKS_PER_SEC;
                    cout<<"No.of swaps :"<<inc<<endl;
                    cout<<"No.of comps:"<<comp<<endl;
                }

                cout<<"The average time taken:"<<arrprint/i<<endl;
                cout<<"The average comparisons :"<<(comp)/i<<endl;
                cout<<"The average swaps:"<<inc/i<<endl;
                break;

            case 3:
                /*
                int  array[100000];
                for (int i = 0; i < 100000; i++) {
                    num = rand() % 1000000 + 1;
                    array[i] = num;
                    cout << num << " " << i << endl;


                }
                 n = sizeof(array)/sizeof(array[0]);

                bubbleSort(array,n,inc,comp);

                print(array,n);
                 */
                for( i =0; i < 2 ;i++) {

                    int  array[100000];
                    //double arrprint;
                    for ( j = 0; j < 100000; j++) {
                        num = rand() % 1000000 + 1;
                        array[j] = num;
                    }
                    n = sizeof(array)/sizeof(array[0]);

                    bubbleSort(array,n,inc,comp);
                    bubbleSort(array,n,inc,comp);
                    cout << "Time taken for each Bubble Sort :" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
                    arrprint = (double) (clock() - tstart) / CLOCKS_PER_SEC;
                    cout<<"No.of swaps :"<<inc<<endl;
                    cout<<"No.of comps:"<<comp<<endl;
                }
                cout<<"The average time taken:"<<arrprint/i<<endl;
                cout<<"The average comparisons :"<<(comp)/i<<endl;
                cout<<"The average swaps:"<<inc/i<<endl;

                break;

            default :
                cout << "Invalid selection (ignore entry 4)" << endl;

        }

    }while(ch !=4);


    //generating random numbers and inserting them into the array

    /*
    for(int i=0;i<10000;i++)
    {
        num = rand() % 1000000 + 1;
        arr[i] = num;
    }

   // int arr[] = { 23,14,18,19,2,11,9,10};



    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,n);

    print(arr,n);

    cout<<"total time taken :"<<(double)(clock()-tstart)/CLOCKS_PER_SEC<<endl;

*/


    return 0;
}