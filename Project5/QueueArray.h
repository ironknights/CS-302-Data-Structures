//
// Created by Deeptanshu Das on 11/11/18.
//

#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H
static const int DEFAULT_CAPACITY = 10000;

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Queue.h"

template <typename DataType>
class QueueArray : public Queue<DataType> {
public:
    QueueArray(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE);
    QueueArray(const QueueArray& other);
   QueueArray& operator=(const QueueArray& other);
    ~QueueArray();

    void enqueue(const DataType& newDataItem) throw (logic_error);
    DataType dequeue() throw (logic_error);

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void putFront(const DataType& newDataItem) throw (logic_error);
    DataType getRear() throw (logic_error);
    int getLength() const;

    void showStructure() const;

private:
    int maxSize;
    int front;
    int back;
    int count;
    DataType* dataItems;
};

template<typename DataType>
QueueArray<DataType>::QueueArray(int maxNumber)
{
    dataItems = new DataType[maxNumber];
    maxSize = maxNumber;
    front = 0;
    back = -1;
}

template<typename DataType>
QueueArray<DataType>::QueueArray(const QueueArray& other)
{
    maxSize = other.maxSize;
    dataItems = new DataType[maxSize];
    for(int i = 0;i<=other.back;i++){
        dataItems[i] = other.dataItems[i];
    }
    front = other.front;
    back = other.back;
}

template <typename DataType>
QueueArray<DataType>& QueueArray<DataType>::operator=(const QueueArray& other)
{
    maxSize = other.maxSize;
    dataItems = new DataType[maxSize];
    for(int i = 0;i<=other.back;i++){
        dataItems[i] = other.dataItems[i];
    }
    front = other.front;
    back = other.back;

    return *this;
}

template <typename DataType>
QueueArray<DataType>::~QueueArray()
{
    maxSize = 0;
    front = 0;
    back = -1;
    delete[] dataItems;
}

template<class DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{

    if (count < DEFAULT_CAPACITY)
    {
        dataItems[++back] = newDataItem;
        count++;

    } // end if

} // end enqueue

template<class DataType>
DataType QueueArray<DataType>::dequeue() throw (logic_error)
{
    ++front;
    return dataItems[front-1];
} // end dequeue

template<class DataType>
bool QueueArray<DataType>::isEmpty() const
{
   return front > back;
} // end isEmpty


template<class DataType>
bool QueueArray<DataType>::isFull() const
{
    if(back == front-1){
        return true;
    }
    if((front == 0) &&( back == (maxSize-1))){
        return true;
    }
    return false;
}

template<class DataType>
int QueueArray<DataType>::getLength() const
{
    if(isFull()){
        return maxSize;
    }else{
        if(back < front){
            return maxSize - front + back;
        }else if(back > front){
            return back - front;
        }
    }
    return -1;
}

template <typename DataType>
void QueueArray<DataType>::showStructure() const
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if ( front == -1 )
        cout << "Empty queue" << endl;
    else
    {
        cout << "Front = " << front << "  Back = " << back << endl;
        for ( j = 0 ; j < maxSize ; j++ )
            cout << j << "\t";
        cout << endl;
        if ( back >= front )
            for ( j = 0 ; j < maxSize ; j++ )
                if ( ( j >= front ) && ( j <= back ) )
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
        else
            for ( j = 0 ; j < maxSize ; j++ )
                if ( ( j >= front ) || ( j <= back ) )
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
        cout << endl;
    }
}

template < class DataType>
void QueueArray<DataType>::putFront(const DataType& newDataItem) throw (logic_error)
{

    if(isEmpty()){
        throw logic_error("Queue is empty ");
    }
    dataItems[front] = newDataItem;

}

template <typename DataType>
DataType QueueArray<DataType>::getRear() throw (logic_error)
{
    DataType temp;
    temp = dataItems[back];
    return temp;
}


template<class DataType>
void QueueArray<DataType>::clear()
{
    count = 0;
} // end clear



#endif //QUEUEARRAY_H
