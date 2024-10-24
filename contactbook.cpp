#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H
#include<iostream>
#include "Array.cpp"
using namespace std;
class Contact
{
    private:
    Array a;
    public:
    void add()
    {
        a.append();
    }
    void searchByLastName(string lastName)
    {
        int index=a.searchLastName(lastName);
        if (index>-1)
        a.printAt(index);
        else
        cout<<"Not exist\n";
    }
    void searchByClassification(string classifiction)
    {
        int index=a.searchClassification(classifiction);
        if (index>-1)
        a.printAt(index);
        else
        cout<<"Not exist\n";
    }
    void printAllContact()
    {
        a.display();
    }
    void printFavContact()
    {
        a.printByFav();
    }
    void deleteContact(int index)
    {
        a.Delete(index);
    }
    void update(int index)
    {
        
        a.modify(index);
        a.printAt(index);
    
    }
    void reverseContact()
    {
        a.reverse();
        a.display();
    }

};






#endif