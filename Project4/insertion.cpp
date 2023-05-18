//
// Created by Deeptanshu Das on 10/24/18.
//
#include <iostream>
#include "time.h"

using namespace std;

// Sorts the items in an array into ascending order

void insertionSort (int theArray[], int n,double &comp, double &swaps)
{
        // unsorted = first index of the unsorted region
        // loc = index of insertion in the sorted region
        // nextItem = next item in the unsorted region
        // Initially, sorted region is theArray[0],
        //unsorted region is theArray[1..n-1]
        // In general, sorted region is theArray[0..unsorted-1],
        // unsorted region theArray[unsorted..n-1]
        for (int unsorted=1; unsorted < n; unsorted++)
        {
                // At this point, theArray[0..unsorted-1] is sorted
                // Find the right position (loc) in theArray[0..unsorted]
                // for theArray[unsorted], which is the first entry in the
                // unsorted region; shift, if necessary to make room
                int nextItem = theArray[unsorted];
                int loc = unsorted;
                while ((loc>0) && (theArray[loc-1] > nextItem))
                {
                        // Shift theArray[loc-1] to the right
                        theArray[loc] = theArray[loc-1];
                        loc--;
                        comp++;
                } // end while
                // At this point, theArray[loc] is where nextItem belongs
                theArray[loc] = nextItem; // Insert maxItem into sorted region
                swaps++;
        } // end ofr
} // end insertionSort

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
    int num;
    double comp=0,swaps=0;

    //int arr[100000];

    srand(time(NULL));

    clock_t tstart = clock();

    int ch=0;

    int i=0,j=0;

    int n=0;

    double arrprint = 0;

    do {
        cout << "From this menu, do the following selection:" << endl;
        cout << "1. Generating random numbers between 1 and 1000 to insertion sort" << endl;
        cout << "2. Generating random numbers between 1 and 10000 to insertion sort" << endl;
        cout << "3. Generating random numbers between 1 and 100000 to insertion sort" << endl;
        cout << "4.Enter 4 to exit  " << endl;
        cin >> ch;


        switch (ch) {

            case 1 :





                //print(arr,n);

                for( i =0; i < 10 ;i++) {

                    int  arr[1000];
                    // double arrprint;
                    for ( j = 0; j < 1000; j++) {
                        num = rand() % 1000000 + 1;
                        arr[j] = num;
                        //cout << num << " " << i << endl;


                    }

                    n = sizeof(arr)/sizeof(arr[0]);

                    insertionSort(arr,n,comp,swaps);
                    cout << "Time taken for each Insertion Sort:" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
                    arrprint = (double) (clock() - tstart) / CLOCKS_PER_SEC;
                    //cout << num << " " << i << endl;
                    cout<<"No.of swaps :"<<swaps<<endl;
                    cout<<"No.of comps:"<<comp<<endl;

                }
                cout<<"The average time taken :"<<arrprint/i<<endl;
                cout<<"The average comparisons :"<<(comp)/i<<endl;
                cout<<"The average swaps:"<<swaps/i<<endl;
                break;


            case 2 :




                //insertionSort(arrr,n,comp,swaps);

                //print(arrr,n);
                for( i =0; i < 10 ;i++) {

                    int  arrr[10000];
                    for (int j = 0; j < 10000; j++) {
                        num = rand() % 1000000 + 1;
                        arrr[j] = num;
                        //cout << num << " " << i << endl;


                    }

                    n = sizeof(arrr)/sizeof(arrr[0]);

                    insertionSort(arrr,n,comp,swaps);
                    cout << "Time taken for each Insertion Sort :" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
                    arrprint = (double) (clock() - tstart) / CLOCKS_PER_SEC;
                    cout<<"No.of swaps :"<<swaps<<endl;
                    cout<<"No.of comps:"<<comp<<endl;
                }

                cout<<"The average time taken:"<<arrprint/i<<endl;
                cout<<"The average comparisons :"<<(comp)/i<<endl;
                cout<<"The average swaps:"<<swaps/i<<endl;
                break;

            case 3:



               // insertionSort(array,n,comp,swaps);

              //  print(array,n);

                for( i =0; i < 3 ;i++) {

                    int  array[100000];
                    for (int i = 0; i < 100000; i++) {
                        num = rand() % 1000000 + 1;
                        array[i] = num;
                       // cout << num << " " << i << endl;

                    }
                    n = sizeof(array)/sizeof(array[0]);

                    insertionSort(array,n,comp,swaps);

                    cout << "Time taken for each insertion Sort :" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
                    arrprint = (double) (clock() - tstart) / CLOCKS_PER_SEC;
                    cout<<"No.of swaps :"<<swaps<<endl;
                    cout<<"No.of comps:"<<comp<<endl;
                }
                cout<<"The average time taken:"<<arrprint/i<<endl;
                cout<<"The average comparisons :"<<(comp)/i<<endl;
                cout<<"The average swaps:"<<swaps/i<<endl;

                break;

            default :
                cout << "Invalid selection (ignore entry 4)" << endl;

        }

    }while(ch !=4);





    /*
    for(int i=0;i<100000;i++)
    {
        num = rand() % 1000000 + 1;
        arr[i] = num;
    }

    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr,n);

   print(arr,n);

    cout<<"total time taken :"<<(float)(clock()-tstart)/CLOCKS_PER_SEC<<endl;

     */

    return 0;
}

