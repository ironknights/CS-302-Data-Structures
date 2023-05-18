//
// Created by Deeptanshu Das on 10/24/18.
//

#include <iostream>

using namespace std;

const int MIN_SIZE =4;

//Insertion Sort
void insertionSort (int theArray[], int first, int last,int &comp)
{
    // unsorted = first index of the unsorted region
    // loc = index of insertion in the sorted region
    // nextItem = next item in the unsorted region
    // Initially, sorted region is theArray[0],
    //unsorted region is theArray[1..n-1]
    // In general, sorted region is theArray[0..unsorted-1],
    // unsorted region theArray[unsorted..n-1]
    for (int unsorted=first + 1; unsorted <= last; unsorted++)
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
    } // end ofr
} // end insertionSort


//Adjusting the partition algorithm

//Arranges the first, middle and last entries into ascending order

void sortFirstMiddleLast(int theArray[],int first,int mid,int last, int &comp, int &swaps)
{
    if(theArray[first]>theArray[mid])
    {
        std::swap(theArray[first],theArray[mid]);
        swaps++;
    }
    comp++;

    if(theArray[mid]>theArray[last])
    {
        std::swap(theArray[mid],theArray[last]);
        swaps++;

    }
    comp++;

    if(theArray[first]>theArray[mid])
    {
        std::swap(theArray[first],theArray[mid]);
        swaps++;
    }
    comp++;
}

//Partitioning function

int partition(int theArray[], int first, int last,int &comp, int &swaps)
{
    int mid;

    //Choose pivot and reposition it

    mid = (first + (last-first))/2;

    sortFirstMiddleLast(theArray, first, mid,last,comp,swaps);

    std::swap(theArray[mid],theArray[last-1]);

    int pivotIndex = last -1;

    int pivot = theArray[pivotIndex];

    //Determining the region S1 and S2

    int indexFromLeft = first +1;
    int indexFromRight = last -2;

    bool done = false;

    while(!done)
    {
        //Locate first entry on left that is >= pivot

        while(theArray[indexFromLeft]<pivot)
        {
            indexFromLeft = indexFromLeft+1;
            comp++;
        }

        //Locate first entry on right that is <=pivot

        while(theArray[indexFromRight] > pivot)
        {
            indexFromRight = indexFromRight -1;
            comp++;
        }

        if(indexFromLeft < indexFromRight)
        {
            std::swap(theArray[indexFromLeft],theArray[indexFromRight]);
            swaps++;
            //cout << "hi" << endl;
            indexFromLeft = indexFromLeft +1;
            indexFromRight = indexFromRight - 1;
        }

        else
        {
            done = true;
        }
    }

    //Place pivot in proper position between S1 and S2 and mark its new location

    std::swap(theArray[pivotIndex],theArray[indexFromLeft]);
    swaps++;
    pivotIndex = indexFromLeft;

    return pivotIndex;
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


//** Sorts an array into ascending order. Uses the quick sort with
//        median-of-three pivot selection for arrays of at least MIN_SIZE
//        entries, and uses the insertion sort for other arrays.
//@pre theArray[first..last] is an array.
//@post theArray[first..last] is sorted
//@param theArray – the given array
//@param first – the index of 1st element to consider in theArray
//@param last – the index of last element to cnsdr in theArray

void quicksort(int theArray[], int first, int last, int &comp, int &swaps)
{

    if (last-first+1<MIN_SIZE)
    {
        insertionSort(theArray, first ,last,comp);

    }

    else{
// Create the partition: S1 | Pivot | S2
        int pivotIndex = partition(theArray, first, last,comp,swaps);
        //cout << "hi" << endl;
        comp++;
        swaps++;
// Sort subarrays S1 and S2
        quicksort(theArray, first, pivotIndex-1, comp, swaps);
        quicksort(theArray, pivotIndex+1, last, comp, swaps);
    } // end if
} // end quickSort

int main()
{

    int num = 0;
    int swaps = 0;
    int comp = 0;
    //int arr[100000];

    clock_t tstart = clock();

    srand(time(NULL));

    int ch = 0;

    int i =0;
    int j=0;

    int n = 0;

    double arrprint = 0;

    do {
        cout << "From this menu, do the following selection:" << endl;
        cout << "1. Generating random numbers between 1 and 1000 for quicksort " << endl;
        cout << "2. Generating random numbers between 1 and 10000 for quicksort " << endl;
        cout << "3. Generating random numbers between 1 and 100000 for quicksort " << endl;
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
                        quicksort(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1, comp, swaps);
                       // print(arr, n);
                        cout << "Time taken for each quickSort:" << (double) (clock() - tstart) / CLOCKS_PER_SEC
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

                    quicksort(arrr, 0, (sizeof(arrr) / sizeof(arrr[0])) - 1, comp, swaps);

                        cout << "Time taken for each quickSort :" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
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
                    quicksort(array, 0, (sizeof(array)/sizeof(array[0]))-1, comp, swaps);
                    cout << "Time taken for each quickSort :" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
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

    //quicksort(arr,0,n-1);


    quicksort(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1);

    print(arr,n);

    cout<<"total time taken :"<<(double)(clock()-tstart)/CLOCKS_PER_SEC<<endl;

*/



    return 0;
}