#include<iostream>

#include "stdlib.h"

#include "time.h"

//#include "bubble.cpp"
using namespace std;

int main()
{
    int num;

    int ch = 0;

    clock_t tstart = clock();

    //to initialize random seed :

    srand(time(NULL));




    do {
        cout << "From this menu, do the following selection:" << endl;
        cout << "1. Generating random numbers between 1 and 1000" << endl;
        cout << "2. Generating random numbers between 1 and 10000" << endl;
        cout << "3. Generating random numbers between 1 and 100000" << endl;
        cout << "4.Enter 4 to exit  " << endl;
        cin >> ch;


        switch (ch) {

            case 1 :
                for (int i = 0; i < 1000; i++) {
                    num = rand() % 1000000 + 1;
                    cout << num << " " << i << endl;

                }
                cout << "Time taken:" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
                break;


            case 2 :
                for (int i = 0; i < 10000; i++) {
                    num = rand() % 1000000 + 1;
                    cout << num << " " << i << endl;


                }
                cout << "total time taken :" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
                break;

            case 3:
                for (int i = 0; i < 100000; i++) {
                    num = rand() % 1000000 + 1;
                    cout << num << " " << i << endl;


                }
                cout << "total time taken :" << (double) (clock() - tstart) / CLOCKS_PER_SEC << endl;
                break;

            default :
                cout << "Invalid selection (ignore entry 4)" << endl;

        }

    }while(ch !=4);


    //generating random numbers between 1 and 100 :
/*
    for(int i=0;i<10000;i++) {
        num = rand() % 1000000 + 1;
        cout << num <<" "<<i<<" "<<"time taken:"<<(double)(clock()-tstart)/CLOCKS_PER_SEC<<endl;
    }

    cout<<"total time taken :"<<(double)(clock()-tstart)/CLOCKS_PER_SEC<<endl;
*/
return 0;
}


