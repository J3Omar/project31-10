/*
عمر احمد ابراهيم
عمر احمد عبدالعال
*/
#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H
#include <iostream>
#include "Array.cpp"
#include <fstream>
using namespace std;

class Contact {
private:
    Array a;

public:
    void add() {
        a.append();
    }

    void searchByLastName(string lastName) {
        int index = a.searchLastName(lastName);
        if (index > -1)
            a.printAt(index);
        else
            cout << "Not exist\n";
    }

    void searchByClassification(string classifiction) {
        int index = a.searchClassification(classifiction);
        if (index > -1)
            a.printAt(index);
        else
            cout << "Not exist\n";
    }

    void printAllContact() {
        a.display();
    }

    void printFavContact() {
        a.printByFav();
    }

    void deleteContact(int index) {
        a.Delete(index);
    }

    void update(int index) {
        a.modify(index);
        a.printAt(index);
    }

    void reverseContact() {
        a.reverse();
        a.display();
    }
    void saveFile ()
    {
        a.save();
    }
    void loadfile()
    {
        a.load();
    }
    void shareContact(int index) {
    if (index >= 0 && index < a.getSize()) {
        cout << "Contact to Share:\n";
        a.printAt(index);
    } else {
        cout << "Error: Invalid contact index.\n";
    }
}

};

#endif
