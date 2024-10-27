#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <iostream>
using namespace std;
class address
{
    public:
    int streetnum;
    string streetname,town,state;
    
    address()
    {}
    //set
    void setstreetnum()
    {
        cout <<"streetnum: ";
        cin>>streetnum;
    }
    void setstreetname()
    {
        cout<<"streetname: ";
        cin>>streetname;
    }
    void settwon()
    {
        cout<<"town: ";
        cin>>town;
    }
    void setstate()
    {
        cout<<"state: ";
        cin>>state;
    }

    //get
    int getstreetnum()
    const
    {
        
        return streetnum;    
    }
    string getstreetname()
    const
    {
        return streetname;
    }
    string gettwon()
    const
    {
       return town;
    }
    string getstate()
    const
    {
        return state;
    }
  ~address()
  {
    
  }
};

#endif
