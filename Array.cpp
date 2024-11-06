#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;
template <class T>
class Array
{
private:
    T *arr;
    int capacity;
    int size;

public:
    Array(int cap = 1);
    ~Array();
    void append();
    void display() const;
    void reverse();
    int getSize() const;
    void Delete(int index);
    T operator[](int index);

Array::Array(int cap) : capacity(cap), size(0)
{
    arr = new T [capacity];
}

void Array::append()
{
    if (size >= capacity)
    {
        capacity *= 2;
        T *newArr = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    size++;
}
void Array::reverse()
{
    if (size > 0)
    {
        for (int i = 0, j = size - 1; i < j; i++, j--)
        {
            Person temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
int Array::getSize() const
{
    return size;
}



void Array::Delete(int index)
{
    if (index >= size || index < 0)
        throw out_of_range("Index out of range");

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}
Array::~Array()
{
    delete[] arr;
}
T Array::operator[](int index)
{
    return arr[i];
}
};
#endif
