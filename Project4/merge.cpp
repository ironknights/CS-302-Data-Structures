//
// Created by Deeptanshu Das on 10/25/18.
//


#include <iostream>
#include"time.h"

using namespace std;

const int MAX_SIZE = 1000000; // maximum number of items in array

void merge(int theArray[], int first, int mid, int last,double &comp, double &swaps)
{
    int tempArray[MAX_SIZE]; // Temporary array
// Initialize the local indices to indicate the subarrays
    int first1 = first; // Beginning of first subarray
    int last1 = mid; // End of first subarray
    int first2 = mid+1; // Beginning of second subarray
    int last2 = last; // End of second subarray
// While both subarrays are not empty, copy the smaller item into the
// temporary array
    int index = first1; // next available location in tempArray
    //cout << "First1: " << first1 << endl;
   // cout << "last1: " << last1 << endl;
    //cout << "first2: " << first2 << endl;
    //cout << "last2: " << last2 << endl;

    while ((first1<=last1) && (first2 <=last2))
    {
// At this point, tempArray[first..index-1] is in order
        comp++;

        if (theArray[first1] <= theArray[first2])
        {
            tempArray[index] = theArray[first1];
            first1++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            first2++;
        } // end if
        index++;
    } // end while
    while ((first1<=last1))
    {
// at this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first1];
        first1++;
        index++;
        swaps++;
    } // end while
// Finish off the second subarray, if necessary
    while (first2<=last2)
    {
// at this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2];
        first2++;
        index++;
        swaps++;
    } // end for
// Copy the result back into the original array
    for (index=first; index<=last; index++)
        theArray[index] = tempArray[index];
        comp++;
        swaps++;


} // end merge

void mergeSort(int theArray[], int first, int last,double &comp, double &swaps)
{

    comp++;
    if (first < last)
    {
        int mid = first + (last-first)/2;

        mergeSort(theArray,first,mid,comp,swaps);
        mergeSort(theArray,mid+1,last,comp,swaps);
        merge(theArray, first, mid, last,comp,swaps);
    } // end if
}

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

    double comp=0;

    double swaps=0;

    int num = 0,ch=0,n=0;

    double arrprint=0;

    int arr[1000];
    clock_t tstart = clock();

    srand(time(NULL));

    int i,j = 0;




    do {
        cout << "From this menu, do the following selection:" << endl;
        cout << "1. Generating random numbers between 1 and 1000 for mergesort " << endl;
        cout << "2. Generating random numbers between 1 and 10000 for merge sort " << endl;
        cout << "3. Generating random numbers between 1 and 100000 for merge sort " << endl;
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

                n = sizeof(arr)/sizeof(arr[0]);

                //insertionSort(arr,n);
                quicksort(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1, comp, swaps);

                print(arr,n);
                 */

                for( i =0; i < 10 ;i++) {
                    //insertionSort(arr,n,);
                    int  arr[1000];
                    //double arrprint;
                    for ( j = 0; j < 1000; j++) {
                        num = rand() % 1000000 + 1;
                        arr[j] = num;
                        //cout << num << " " << i << endl;


                    }

                    n = sizeof(arr) / sizeof(arr[0]);

                    //insertionSort(arr,n);
                    //quicksort(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1, comp, swaps);
                    mergeSort(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1, comp, swaps);
                    // print(arr, n);
                    cout << "Time taken for each mergeSort:" << (double) (clock() - tstart) / CLOCKS_PER_SEC
                         << endl;
                    arrprint = (double) (clock() - tstart) / CLOCKS_PER_SEC;
                    //cout << num << " " << i << endl;
                    cout << "No.of swaps :" << swaps << endl;
                    cout << "No.of comps:" << comp << endl;


                }

                cout<<"The average time taken :"<<arrprint/i<<endl;
                cout<<"The average comparisons :"<<(comp)/i<<endl;
                cout<<"The average swaps:"<<swaps/i<<endl;
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

                //insertionSort(arrr,n);
                quicksort(arrr, 0, (sizeof(arrr)/sizeof(arrr[0]))-1, comp, swaps);

                print(arrr,n);
                 */
                for( i =0; i < 10 ;i++) {

                    int  arrr[10000];
                    //double arrprint;
                    for ( j = 0; j < 10000; j++) {
                        num = rand() % 1000000 + 1;
                        arrr[j] = num;
                        //cout << num << " " << i << endl;
                    }
                    n = sizeof(arrr)/sizeof(arrr[0]);

                    mergeSort(arrr, 0, (sizeof(arrr) / sizeof(arrr[0])) - 1, comp, swaps);

                    cout << "Time taken for each mergesort :" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
                    arrprint = (double) (clock() - tstart) / CLOCKS_PER_SEC;
                    cout<<"No.of swaps :"<<swaps<<endl;
                    cout<<"No.of comps:"<<comp<<endl;
                }

                cout<<"The average time taken:"<<arrprint/i<<endl;
                cout<<"The average comparisons :"<<(comp)/i<<endl;
                cout<<"The average swaps:"<<swaps/i<<endl;
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

                //insertionSort(array,n);
                quicksort(array, 0, (sizeof(array)/sizeof(array[0]))-1, comp, swaps);

                print(array,n);
                 */

                for( i =0; i < 10 ;i++) {
                    int  array[100000];
                    for (int i = 0; i < 100000; i++) {
                        num = rand() % 1000000 + 1;
                        array[i] = num;
                        //cout << num << " " << i << endl;


                    }

                    n = sizeof(array)/sizeof(array[0]);
                    //insertionSort(array,n);
                    mergeSort(array, 0, (sizeof(array)/sizeof(array[0]))-1, comp, swaps);
                    cout << "Time taken for each mergeSort :" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
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
    //int arr[] = { 23,14,18,19,2,24,12, 23, 1, 4, 3, 3};

    for(int i=0;i<1000;i++)
    {
        num = rand() % 1000000 + 1;
        arr[i] = num;
    }




    int n = sizeof(arr)/sizeof(arr[0]);

    //cout<<n<<endl;

   mergeSort(arr, 0, n - 1,comp,swaps);

    cout<<"comp"<<comp<<endl;

    cout<<"swaps"<<swaps<<endl;

    //print(arr,n);

    cout<<"total time taken :"<<(double)(clock()-tstart)/CLOCKS_PER_SEC<<endl;
    */

    return 0;

}

