#include <iostream>
#include "contactbook.cpp"

using namespace std;


int main()
{
    int num,t;

    string temp;
    Contact c1;

    do
    {
        cout<<"enter\n";
        cout<<tab<<"1: add a contact"<<endl;
        cout<<tab<<"2: search by last name"<<endl;
        cout<<tab<<"3: search by classification"<<endl;
        cout<<tab<<"4: print all contacts"<<endl;
        cout<<tab<<"5: print fav"<<endl;
        cout<<tab<<"6: save to file"<<endl;
        cout<<tab<<"7: load from file"<<endl;
        cout<<tab<<"8: delete contact"<<endl;
        cout<<tab<<"9: update contact informstion"<<endl;
        cout<<tab<<"10: share contacts with other"<<endl;
        cout<<tab<<"11: reverse contacts book"<<endl;
        cout<<tab<<"12: exit"<<endl;
        cin>>num;
        switch (num)
        {
        case 1:
            c1.add();
            break;
        case 2:
        cin>>temp;
        c1.searchByLastName(temp);
        break;
        case 3:
        cin>>temp;
        c1.searchByClassification(temp);
        break;
        case 4:
        c1.printAllContact();
        break;
        case 5:
        c1.printFavContact();
        break;
        case 6:
        break;
        case 7:
        break;
        case 8:
        cin>>t;
        c1.deleteContact(t);
        break;
        case 9:
        cin>>t;
        c1.update(t);
        case 10:
        break;
        case 11:
        c1.reverseContact();
        break;
        default:
            break;
        }
        
    }
    while (num<12&&num>0);
    

    return 0;
}