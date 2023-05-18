//
// Created by Deeptanshu Das on 10/3/18.
//

#ifndef POLISH_STACH_H
#define POLISH_STACH_H

#include <iostream>
#include <ctype.h>
#include <math.h>
#endif //POLISH_STACH_H


using namespace std;

template <class T>
struct Element{
    Element *previous = NULL;
    Element *next = NULL;
    T value;
};

template <class T>
class Stack{
private:
    Element<T> *head, *tail;
    int length = 0;

public:
    void push(T value){
        if (length == 0){
            head = new Element<T>();
            head->previous = NULL;
            head->next = NULL;
            head->value = value;

            tail = head;
        }
        else {
            tail->next = new Element<T>();
            tail->next->previous = tail;
            tail->next->value = value;
            tail = tail->next;
        }

        ++length;
    }

    T pop(){
        T c = head->value;
        Element<T> *temp = head->next;
        delete head;
        head = temp;
        --length;
        return c;
    }

    T pop_back(){
        T c = tail->value;
        Element<T> *temp = tail->previous;
        delete tail;
        tail = temp;
        --length;
        return c;
    }

    int getLength(){
        return length;
    }

    void print(){
        Element<T> *p = head;
        while(p != NULL){
            cout<<p->value;
            p = p->next;
        }
        cout<<endl;
    }

    ~Stack(){
        while (length > 0) pop();
    }
};
