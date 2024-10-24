#include <iostream>
#include <stdexcept>
#include "Person.cpp"
using namespace std;

class Array {
private:
    Person *arr;          
    int capacity;     
    int size;     

public:
    Array(int cap=10); 
    ~Array();               
    void append();   
    void insert(int index, const Person &element);  
    void display() const;  
    void reverse();         
    void sort();          
    int getSize() const;      
    Person get(int index) const;    
    void remove();          
    int searchLastName(const string &LastName) const;  
    void Delete(int index);  
    void operator[](int i);
    void printAt(int index);
    int searchClassification(const string &classification) const;
    void printByFav();
    void modify(int index);

};

Array::Array(int cap=10) : capacity(cap), size(0) {
    arr = new Person[capacity];    
}
void Array::modify(int index)
{
    if(index<=size)
    {
    arr[index].setFname();
    arr[index].setLname();
    arr[index].setclass();
    arr[index].setFav();
    arr[index].setNumbers();
    arr[index].setMails();
    arr[index].setstreetnum();
    arr[index].setstreetname();
    arr[index].settwon();
    arr[index].setstate();
    }
    else 
    throw out_of_range("error");
}
void Array::printByFav()
{
    for(int i=0;i<size;i++)
    {
        if(arr[i].getFav()==true)
        printAt(i);
    }
}

void Array::append() {
    if (size >= capacity) {        
        capacity *= 2;       
        Person *newArr = new Person[capacity];      

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];       
        }

        delete[] arr;   
        arr = newArr;    
    }

    arr[size].setFname();
    arr[size].setLname();
    arr[size].setclass();
    arr[size].setFav();
    arr[size].setNumbers();
    arr[size].setMails();
    arr[size].setstreetnum();
    arr[size].setstreetname();
    arr[size].settwon();
    arr[size].setstate();
    size++;
}
void Array:: operator[](int i)
    {
        capacity=i;
        arr=new Person[capacity];
    }

void Array:: printAt(int index)
{
        if(index>-1&&index<=size)
        cout<<arr[index];
        else
        throw out_of_range("error index");
}
void Array::insert(int index, const Person &element) {
    if (index > size || index < 0)  
        throw out_of_range("Index out of range");

    if (size >= capacity) { 
        capacity *= 2;
        Person *newArr = new Person[capacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];  
    }
    arr[index] = element; 
    size++;
}

void Array::display() const {
    for (int i = 0; i < size; i++) {
        cout << arr[i]<<endl;
    }
}

void Array::reverse() {
    if (size > 1) {
        for (int i = 0, j = size - 1; i < j; i++, j--) {
            Person temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

int Array::getSize() const {
    return size;
}

Person Array::get(int index) const {
    if (index >= size || index < 0)
        throw out_of_range("Index out of range");
    return arr[index];
}

void Array::remove() {
    if (size > 0)
        size--;
    else
        throw out_of_range("Array is empty, cannot remove");
}

int Array::searchLastName(const string &lastName) const {
    if (size == 0) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i].getLname() == lastName) {
            return i;
        }
    }
    return -1;
}

int Array::searchClassification(const string &classification) const {
    if (size == 0) {
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i].getclass() == classification) {
            return i;
        }
    }
    return -1;
}

void Array::Delete(int index) {
    if (index >= size || index < 0)  
        throw out_of_range("Index out of range");
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];  
    }
    size--;
}

Array::~Array() {
    delete[] arr; 
}

void Array::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].getFname() > arr[j + 1].getFname()) {
                Person temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
