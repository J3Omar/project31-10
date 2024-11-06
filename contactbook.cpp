#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H
#include <iostream>
#include "person.cpp"
#include "address.cpp"
#include "array.cpp"
#include <fstream>
using namespace std;

class Contact
{
private:
    Person p;
    address a;

public:
    friend ostream &operator<<(ostream &output, Contact c)
    {
        output << left << setw(5) << "ID" << setw(15) << "Fname" << setw(15) << "Lname"
               << setw(15) << "Classification" << setw(5) << "Fav"
               << setw(20) << "Phone num" << setw(20) << "Mails" << setw(30) << "Address" << endl;
        output << c.p << c.a;
        return output;
    }
    void add()
    {
        string *words;
        int num;
        cout << "Fn: ";
        cin >> *words;
        p.setFname(*words);
        cout << "Ln: ";
        cin >> *words;
        p.setLname(*words);
        cout << "classification: ";
        cin >> *words;
        p.setClass(*words);
        cout << "press 1 to add in fav or 0 to not: ";
        cin >> num;
        p.setFav(num);
        cout << "How many numbers: ";
        cin >> num;
        if (num > 0)
        {
            words = new string[num];
            for (int i = 0; i < num; i++)
            {
                cin >> words[i];
            }
        }
        else
            throw out_of_range("error in index");
        p.setNumbers(num, words);
        cout << "How many mails: ";
        cin >> num;
        if (num > 0)
        {
            words = new string[num];
            for (int i = 0; i < num; i++)
            {
                cin >> words[i];
            }
        }
        else
            throw out_of_range("error in index");
        p.setMails(num, words);
        cout << "street num: ";
        cin >> num;
        a.setstreetnum(num);
        cout << "street name: ";
        words = new string;
        cin >> *words;
        a.setstreetname(*words);
        cout << "town: ";
        cin >> *words;
        a.settwon(*words);
        cout << "state: ";
        cin >> *words;
        a.setstate(*words);

        delete words;
    }

    bool searchBYLastName(const string &lastName) const
    {

        if (p.getLname() == lastName)
        {
            return 1;
        }

        return 0;
    }
    bool searchByClassification(const string &classification) const
    {

        if (p.getLname() == classification)
        {
            return 1;
        }

        return 0;
    }
    bool isFav()
    {
        if (p.getFav() == true)
            return true;
        return false;
    }
    friend ofstream &operator<<(ofstream &out, Contact &c)
    {
        out << c.p.getId() << "\t" << c.p.getFname() << "\t" << c.p.getLname() << "\t" << c.p.getClass() << "\t" << ((c.p.getFav()) ? "Yes" : "No") << "\t" << c.p.getNumbers() << "\t" << c.p.getMails() << "\t" << c.a.getstreetnum() << " " << c.a.getstreetname() << "," << c.a.gettwon() << "," << c.a.getstate() << "\n";
        return out;
    }
    friend ifstream &operator>>(ifstream &in, Contact &c)
    {
        string firstName, lastName, classification;
        int streetnum;
        string streetname, town, state, phone, email;
        cout << "enter by order Fn,Ln,Phone,email,Streetnum,Streetname,Town,Classification\n";
        in >> firstName >> lastName >> phone >> email >> streetnum >> streetname >> town >> state >> classification;
        return in;
    }
};

#endif
