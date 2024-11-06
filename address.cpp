#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
class address
{
    private:
    int streetnum;
    string streetname,town,state;
    public:
    address()
    {}
    //set
    void setstreetnum(int n)
    {
        
        streetnum=n;
    }
    void setstreetname(string s)
    {
        streetname=s;
    }
    void settwon(string t)
    {
        town=t;
    }
    void setstate(string s)
    {
        state=s;
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
    friend ostream& operator<<(ostream &output,address &a) 
    {
        output<<setw(30)<< to_string(a.getstreetnum()) + " " + a.getstreetname() + "," + a.gettwon() + "," + a.getstate()<<endl;
        return output;
    }
  ~address()
  {
    
  }
};

#endif