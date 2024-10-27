#ifndef PERSON_H
#define PERSON_H

#include "address.cpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#define  tab setw(20)

using namespace std;
class Person:public address{
    public:
    string first_name,last_name,Class,*numbers,*mails;
    int numSize,mailSize;
    bool fav;
    
    int person_id;
    
    static int id;
    Person()
    {
        id++;
        person_id=id;
    }
    void setFname()
    {
        cout<<"Fn: ";
        cin>>first_name;
    }
    void setLname()
    {
        cout<<"Ln: ";
        cin>>last_name;
    }
    void setclass()
    {
        string c;
        cout<<"Class (friend,work,family,other): ";
        cin>>c;
        if (c=="friend"||c=="work"||c=="family")
        Class=c;
        else
        Class="other";
        
    }
    void setNumbers()
    {
        cout<<"How many numbers : ";
        cin>>numSize;
        if(numSize>0)
        {
        numbers=new string[numSize];
        for(int i=0;i<numSize;i++)
        {
        cout<<"Phone #"<<i+1<<" : ";
        cin>>numbers[i];
        }
        }
        else
            throw out_of_range("error in index");
    }
    void setMails()
    {
        cout<<"How many mails : ";
        cin>>mailSize;
        if(mailSize>0)
        {
        mails=new string[mailSize];
        for(int i=0;i<mailSize;i++)
        {
        cout <<"Mail #"<<i+1<<" : ";
        
        cin>>mails[i];
        }

        }
        else
            throw out_of_range("error in index");
    }
    void setFav()
    {
        cout<<"set as fav: (press 1 (fav) or 0 (not))";
        cin>>fav;
    }
    //get
    string getFname()
    const
    {
        return first_name;
    }
    string getLname()
    const
    {
        return last_name;
    }
    string getclass()
    const
    {
        return Class;
        
    }
    string getNumbers()
    const
    {
        string res="";
        
        if(numSize>0)
        {
        for(int i=0;i<numSize;i++)
        {
        res+=numbers[i]+" ";
        }
        return res;
        }
        else
            throw out_of_range("error in index");
    }
    string getMails()
    const
    {
        string res="";
        if(mailSize>0)
        {
        for(int i=0;i<mailSize;i++)
        {
        res+=mails[i]+" ";
        }
        return res;
        }
        else
            throw out_of_range("error in index");
    }

    bool getFav()
    const
    {
        return fav;
    }
    friend ostream& operator<<(ostream &output, Person &p) {
    output << left << setw(5) << "ID" << setw(15) << "Fname" << setw(15) << "Lname"
           << setw(15) << "Classification" << setw(5) << "Fav" << setw(30) << "Address"
           << setw(20) << "Phone num" << setw(20) << "Mails" << endl;

    output << left << setw(5) << p.person_id << setw(15) << p.getFname() << setw(15) << p.getLname()
           << setw(15) << p.getclass() << setw(5) << (p.getFav() ? "Yes" : "No") << setw(30)
           << to_string(p.getstreetnum()) + " " + p.getstreetname() + "," + p.gettwon() + "," + p.getstate();

    
    output << setw(20)<<p.getNumbers();

    
    output << setw(20)<<p.getMails();

    output << endl;
    return output;
}
 int getId()
 {
    return person_id;
 }

    ~Person()
    {
        delete []mails;
        delete []numbers;
    }
};
#endif