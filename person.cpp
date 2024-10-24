#ifndef PERSON_H
#define PERSON_H

#include "address.cpp"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#define  tab setw(25)

using namespace std;
class Person:public address{
    private:
    string first_name,last_name,Class,*numbers,*mails;
    int numSize,mailSize;
    bool fav;
    int person_id;
    public:
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
    void getNumbers()
    const
    {
        
        
        if(numSize>0)
        {
        for(int i=0;i<numSize;i++)
        {
        cout<<numbers[i]<<"  ";
        }
        }
        else
            throw out_of_range("error in index");
    }
    void getMails()
    const
    {
        if(mailSize>0)
        {
        for(int i=0;i<mailSize;i++)
        {
        cout<<mails[i]<<"  ";
        }
        }
        else
            throw out_of_range("error in index");
    }

    bool getFav()
    const
    {
        return fav;
    }
    friend ostream&operator<<(ostream &output,Person &p)
    {
        output<<"ID"<<tab<<"Fname"<<tab<<"Lname"<<tab<<"Classifiction"<<tab<<"Fav"<<tab<<tab<<tab<<tab<<"Address"<<tab<<"Phone num"<<tab<<"mails\n";
        output<<id<<tab<<p.getFname()<<tab<<p.getLname()<<tab<<p.getclass()<<tab<<p.getFav()<<tab<<p.getstreetnum()<<p.getstreetname()<<p.gettwon()<<p.getstate()<<tab;
        p.getNumbers();
        output<<tab;
        p.getMails();
        output<<endl;
    }
    ~Person()
    {
        delete []mails;
        delete []numbers;
    }
};
#endif