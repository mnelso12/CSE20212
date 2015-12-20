// NDVector.cpp, also contains NDVector.h class
// Madelyn Nelson, CSE20212 Lab9
#ifndef NDVECTOR_H
#define NDVECTOR_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename T>
class NDVector {
    public:
        NDVector( int = 10 ); // default constructor
        NDVector( const NDVector<T> & ); // copy  constructor
        ~NDVector(); // deconstructor
        int getSize() const; // returns size

        const NDVector &operator=( const NDVector<T> & ); // assignment operator
        int operator==( const NDVector<T> & )
            const; // equality operator

        T& operator[](int offset){ return ptr[offset];}
        const T& operator[](int offset) const{
            return ptr[offset];}

        int operator!=( const NDVector<T> &right ) const {
            return ! ( *this == right ); // invokes NDVector::operator==
        } // end of function operator !=

        void push_front( T );
        void printVec();
        void push_back( T );
        void pop_back();
        void pop_front();
        T accessFront(); // returns front element
        T accessLast(); // returns last element
        void clear(); // clears vector
        T getLast(); 
        void random_shuffle(); // supports other shuffle method

    private:
        int size; // pointer-based array size
        int capacity;
        T *ptr; // pointer to first element of pointer-based array

};

#endif

template <typename T>
void NDVector<T>::random_shuffle(){
    int tempVal;
    int num1, num2;
    int count = 0;
    while ( count < 300 ) {
        num1 = rand()%size;
        num2 = rand()%size;
        tempVal = ptr[num1];
        ptr[num1] = ptr[num2];
        ptr[num2] = tempVal;
        tempVal = 0;
        count++;
    }
}

template <typename T>
void NDVector<T>::clear(){
    for ( int i = 0; i < capacity; i++ ){ // sets all elements equal to NULL
        ptr[i] = NULL;
    }
    capacity = 0; // capacity and size start over
    size = 0;
}

template <typename T>
T NDVector<T>::accessFront(){
    return (ptr[0]); // returns the first element
}

template <typename T>
T NDVector<T>::getLast(){
    return (ptr[capacity-1]); 
}

template <typename T>
T NDVector<T>::accessLast(){
    return (ptr[size-1]); // returns the last element
}

template <typename T>
void NDVector<T>::pop_front(){
    size--;
    ptr[0] = NULL; // gets rid of the first element
}

template <typename T>
void NDVector<T>::pop_back(){
    size--;
    ptr[size] = NULL; // gets rid of the last one
}

template <typename T>
void NDVector<T>::push_back( T element ){
    size++; // we are guna have one more element
    if (size >= capacity) // adds new allocated memory if necessary
    {
        T * tempptr;
        tempptr = new T[ capacity*2 ];
        for (int j = 0; j < size; j++) { 
            tempptr[j] = ptr[j];
        }
        delete [] ptr;
        ptr = new T [ capacity*2 ];
        ptr = tempptr;

        capacity*=2; // double the capacity
    }
    ptr[size-1] = element; // sets last value equal to inputted element
}

template <typename T>
void NDVector<T>::push_front( T element ){
    size++;
    if (size >= capacity) // adds new allocated memory if necessary
    {
        T * tempptr;
        tempptr = new T[ capacity*2 ];
        for (int j = 0; j < size; j++) { 
            tempptr[j] = ptr[j];
        }
        delete [] ptr;
        ptr = new T [ capacity*2 ];
        ptr = tempptr;

        capacity*=2; // double the capacity
    }

    for (int i = size; i > 0; i--){
        ptr[i] = ptr[i-1]; // each element is moved backwards one spot
    }
    ptr[0] = element; // new element is put in front
}

template <typename T>
void NDVector<T>::printVec() {
    int length = getSize();
    for (int i = (length-1); i>0; --i){
        cout  << ptr[i] << ", ";
    }
    cout << ptr[0] << ";";
    cout << endl;
}

template <typename T>
NDVector<T>::NDVector( int arraySize ){ // defualt
    size = 0;
    capacity = ( arraySize > 0 ? arraySize : 10 ); // validate arraySize
    ptr = new T[ capacity ]; // create space for pointer-based array
}

template <typename T>
NDVector<T>::NDVector( const NDVector<T> &arrayToCopy ) : size( arrayToCopy.size) { // copy-constructor
    ptr = new T[ size ]; // create space for pointer-based array
    for ( int i = 0; i < size; i++ ) {
        ptr[ i ] = arrayToCopy.ptr[ i ]; // copy into object
    }
}

template <typename T>
NDVector<T>::~NDVector(){ // deconstructor
    delete [] ptr; // release pointer-based array space
}

template <typename T>
int NDVector<T>::getSize() const {
    return (size); // number of elements in Array
}

template <typename T>
const NDVector<T> &NDVector<T>::operator=( const NDVector<T> &right ) {
    if ( &right != this ) {
        if ( size != right.size ) {
            delete [] ptr; // release space
            size = right.size; // resize this object
            ptr = new T[ size ]; // create space for array copy
        }
        for ( int i = 0; i < size; i++ ){
            ptr[ i ] = right.ptr[ i ]; // copy array into object
        }
    }
    return (*this); // enables x = y = z function
} // end function operator=
