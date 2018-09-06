// /Liudmila Zyrianova
//CSCI 235
//05/17/2018
//Programming Assignment 2
//Problem 2

#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

template <class T>      //Allows MyQueue to keep any type of elements.
class MyQueue{
private:
    stack <T> realQ;        //Stores elements in the order of the queue (the top element of stack is the front element of MyQueue) and is used for class functions dequeue(), peek(), isEmpty(), and size().
    stack <T> reverseQ;     //Stores elements in the reverse order and is used for class functions enqueue(value x).
public:
    MyQueue(){          //Creates empty realQ and reverseQ.
        realQ;
        reverseQ;
    }

    T dequeue() {       //Deletes the first element of MyQueue and returns it.
        if (realQ.size() > 0) { //If size of realQ (hence MyQueue) is more than 0:
            T x = realQ.top();
            realQ.pop();        //Pop the top element of realQ
            return x;           //and return it
        } else {                //In other case, return -1.
            return (-1);
        }
    };

    T peek() {      //Returns the first element of MyQueue.
        if (realQ.size() > 0){      //If size of realQ (hence MyQueue) is more than 0:
            T x = realQ.top();      //Take the top element of realQ and
            return x;               //return it.
        } else {                    //In other case, return -1.
            return (-1);
        }
    };

    void enqueue (T x){     //Pushes x to the end of MyQueue
        //Reverse realQ to reverseQ
        while (!realQ.empty()){             //Each time
            reverseQ.push(realQ.top());     //popping top element from realQ, and pushing it to reverseQ.
            realQ.pop();
        }
        reverseQ.push(x);       //Push x to the reverseQ.
        //Reversing everything back to realQ.
        while (!reverseQ.empty()){          //Each time
            realQ.push(reverseQ.top());     //popping top element from reverseQ, and pushing it to realQ.
            reverseQ.pop();
        }
    };

    bool isEmpty() {        //Returns true, if MyQueue is empty, and return false otherwise.
        return realQ.empty();       //Returns true, if realQ (hence MyQueue) is empty, and false otherwise.
    };

    int size() {            //Returns the size of MyQueue.
        return realQ.size();        //Returns the size of realQ (hence, the size of MyQueue).
    };
};


int main() {
    MyQueue <int> mq;   //MyQueue of integer numbers
    mq.enqueue(1);
    mq.dequeue();
    cout <<"Peek:"<< mq.peek()<< ", "<<"size:"<<mq.size()<<", "<< "isEmpty:"<<mq.isEmpty() << endl;
    return 0;

}