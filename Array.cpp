//عمر سامح 

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Person.cpp"
using namespace std;

class Array {
private:
    Person *arr;
    int capacity;
    int size;

public:
    Array(int cap = 10);
    ~Array();
    void append();
    void display() const;
    void reverse();
    int getSize() const;
    Person get(int index) const;
    int searchLastName(const string &LastName) const;
    void Delete(int index);
    void printAt(int index);
    int searchClassification(const string &classification) const;
    void printByFav();
    void modify(int index);
    void save();
    void load();
};
int Person::id=0;
Array::Array(int cap=10) : capacity(cap), size(0) {
    arr = new Person[capacity];
}
void Array::modify(int index) {
    if (index <= size) {
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
    } else
        throw out_of_range("error");
}
void Array::printByFav() {
    for (int i = 0; i < size; i++) {
        if (arr[i].getFav() == true)
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

void Array::printAt(int index) {
    if (index > -1 && index <= size)
        cout << arr[index]<<endl;
    else
        throw out_of_range("error index");
}

void Array::display() const {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
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
void Array::save()
{
    if (size<=0)
        throw out_of_range("error in range");
        else{
        ofstream out;
        out.open("data.xls");
        out<<"ID\t"<<"Fname\t"<<"Lname\t"<<"Classification\t"<<"Fav\t"<<"Address\t"<<"Phone_num\t"<<"Mails\n";
        for(int i=0;i<size;i++)
        {
            
            out<<arr[i].getId()<<"\t"<<arr[i].getFname()<<"\t"<<arr[i].getLname()<<"\t"<<arr[i].getclass()<<"\t"<<((arr[i].getFav())?"Yes":"No")<<"\t"<<arr[i].getstreetnum()<<" "<<arr[i].getstreetname()<<","<<arr[i].gettwon()<<","<<arr[i].getstate()<<"\t"<<arr[i].getNumbers()<<"\t"<<arr[i].getMails()<<"\n";
        }
        out.close();
        }
        
        }
        void Array::load()//open file 
{
    ifstream in("data.xls");
    if (!in)
    {
        cout << "Unable to open file.\n";
        return;
    }

    string header;
    getline(in, header);

    while (in)
    {
        Person p;
        string fav;

        in >> p.person_id >> p.first_name >> p.last_name >> p.Class >> fav;
        p.fav = (fav == "Yes");

        in >> p.streetnum;
        in.ignore();
        getline(in, p.streetname, ',');
        getline(in, p.town, ',');
        in >> p.state;
        int numPhones;
        in >> numPhones;
        p.numbers = new string[numPhones];
        p.numSize = numPhones;
        for (int i = 0; i < numPhones; ++i)
        {
            in >> p.numbers[i];
        }

        int numMails;
        in >> numMails;
        p.mails = new string[numMails];
        p.mailSize = numMails;
        for (int i = 0; i < numMails; ++i)
        {
            in >> p.mails[i];
        }
    }
    in.close();
    cout << "Contacts loaded successfully.\n";
}

Array::~Array() {
    delete[] arr;
}
