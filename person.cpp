#ifndef PERSON_H
#define PERSON_H
#include "address.cpp"
#include <iostream>
#include <stdexcept>
using namespace std;
class person:public address{
    private:
    string first_name,last_name,Class,*numbers,*mails;
    int numSize,mailSize;
    bool fav;
    public:
    void setFname()
    {
        cout<<"Fn: ";
        cin>>first_name;
    }
    void setLname(string ln)
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
        cout<<numbers[i]<<"\t";
        }
        cout<<endl;
        }
        else
            throw out_of_range("error in index");
    }
    void setMails()
    const
    {
        if(mailSize>0)
        {
        for(int i=0;i<mailSize;i++)
        {
        cout<<mails[i]<<"\t";
        }
        cout<<endl;
        }
        else
            throw out_of_range("error in index");
    }

    bool getFav()
    const
    {
        return fav;
    }
    ~person()
    {
        delete []mails;
        delete []numbers;
    }
};
#endif