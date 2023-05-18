//
// Created by Deeptanshu Das on 10/25/18.
//

#include <iostream>

using namespace std;

int findIndexOfLargest(const int theArray[], int size,double &comp, double &swaps)
{
    int indexSoFar = 0; // Index of largest entry found so far
    for (int currentIndex = 1; currentIndex < size; currentIndex++)
    {
// At this point, theArray[indexSoFar] >= all entries in
// theArray[0..currentIndex – 1]

        comp++;
        if (theArray[currentIndex] > theArray[indexSoFar])
            indexSoFar = currentIndex;

    } // end for
    return indexSoFar; // Index of largest entry
} // end findIndexOfLargest

void print(int arr[],int size)
{
    int i;

    for(i=0;i<size;i++)
    {
        cout<<" "<<arr[i];
    }

    cout<<endl;
}


void selectionSort( int theArray[], int n,double &comp, double &swaps)
{
// last = index of the last item in the subarray of items yet
// to be sorted;
// largest = index of the largest item found
for (int last=n-1; last>=1; last--)
{
// At this point, theArray[last+1,..n-1] is sorted, and
// its entries are greater than those
// theArray[0..last].
// Select the largest entry in theArray[0..last]
int largest = findIndexOfLargest(theArray, last+1,comp,swaps);
// Swap the largest entry, theArray[largest], with
// theArray[last]
std::swap(theArray[largest], theArray[last]);
swaps++;
} // end for
} // end selectionSort

int main()
{
    int num;

    int ch = 0;

    int n = 0,i=0,j=0;

    int arr[100000];
    double arrprint=0;

    double comp =0,swaps=0;

    clock_t tstart = clock();

    srand(time(NULL));


    do {
        cout << "From this menu, do the following selection:" << endl;
        cout << "1. Generating random numbers between 1 and 1000 to selection sort" << endl;
        cout << "2. Generating random numbers between 1 and 10000 to selection sort" << endl;
        cout << "3. Generating random numbers between 1 and 100000 to selection sort" << endl;
        cout << "4.Enter 4 to exit  " << endl;
        cin >> ch;


        switch (ch) {

            case 1 :

                //print(arr,n);

                for( i =0; i < 10 ;i++) {

                    int  arr[1000];
                    //double arrprint;
                    for ( j = 0; j < 1000; j++) {
                        num = rand() % 1000000 + 1;
                        arr[j] = num;
                        //cout << num << " " << i << endl;


                    }
                    n = sizeof(arr)/sizeof(arr[0]);
                    selectionSort( arr, n,comp,swaps);
                    cout << "Time taken for each Selection Sort:" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
                    arrprint = (double) (clock() - tstart) / CLOCKS_PER_SEC;
                    cout<<"No.of swaps :"<<swaps<<endl;
                    cout<<"No.of comps:"<<comp<<endl;
                    //cout<<"average:"<<arrprint/i;
                }
                cout<<"The average time taken :"<<arrprint/i<<endl;
                cout<<"The average comparisons :"<<(comp)/i<<endl;
                cout<<"The average swaps:"<<swaps/i<<endl;
                break;


            case 2 :

                for( i =0; i < 10 ;i++) {
                    int  arrr[10000];
                    for (int i = 0; i < 10000; i++) {
                        num = rand() % 1000000 + 1;
                        arrr[i] = num;
                       // cout << num << " " << i << endl;
                    }

                    n = sizeof(arrr)/sizeof(arrr[0]);

                    selectionSort( arrr, n,comp,swaps);

                    cout << "Time taken for each Selection Sort :" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
                    arrprint = (double) (clock() - tstart) / CLOCKS_PER_SEC;
                    cout<<"No.of swaps :"<<swaps<<endl;
                    cout<<"No.of comps:"<<comp<<endl;
                }

                cout<<"The average time taken:"<<arrprint/i<<endl;
              //  cout<<"The average comparisons :"<<(comp)/i<<endl;
              //  cout<<"The average swaps:"<<inc/i<<endl;
                break;

            case 3:


                for( i =0; i < 10 ;i++) {
                    int  array[100000];
                    for (int i = 0; i < 100000; i++) {
                        num = rand() % 1000000 + 1;
                        array[i] = num;
                        //cout << num << " " << i << endl;

                    }
                    n = sizeof(array)/sizeof(array[0]);

                    selectionSort( array, n,comp,swaps);
                    cout << "Time taken for each selection Sort :" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
                    arrprint = (double) (clock() - tstart) / CLOCKS_PER_SEC;
                    cout<<"No.of swaps :"<<swaps<<endl;
                    cout<<"No.of comps:"<<comp<<endl;
                }
               cout<<"The average time taken:"<<arrprint/i<<endl;
             //   cout<<"The average comparisons :"<<(comp)/i<<endl;
             //   cout<<"The average swaps:"<<inc/i<<endl;

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

    selectionSort(arr,n);

    print(arr,n);

    cout<<"total time taken :"<<(double)(clock()-tstart)/CLOCKS_PER_SEC<<endl;

     */

    return 0;
}