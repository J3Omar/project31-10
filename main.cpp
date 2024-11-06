#include <iostream>
#include "contactbook.cpp"
#include "array.cpp"

using namespace std;


void displayMenu()
{
    cout << "\n================ Contacts Book Menu: ================\n";
    cout << "1: Add a new Contact\n";
    cout << "2: Search by Last Name\n";
    cout << "3: Search by Classification\n";
    cout << "4: Print All Contacts\n";
    cout << "5: Print Favorite Contacts\n";
    cout << "6: Save to File\n";
    cout << "7: Load from File\n";
    cout << "8: Delete Contact\n";
    cout << "9: Update Contact Information\n";
    cout << "10: Share contact with other\n";
    cout << "11: Reverse contacts book\n";
    cout << "12: Exit\n";
    cout << "=====================================================\n";
}




int main() {
    int num, t;
    string temp;
    Array<Contact> a(1);

    do {
        displayMenu();
        cin >> num;

        switch (num) {
            case 1:
                a.append();
                a[a.getSize()].add();
                break;
            case 2:
                cin >> temp;
                for (int i=0;i<a.getSize();i++)
                {
                    if(a[i].searchBYLastName(temp)==true)
                    cout<<a[i]<<endl;
                }
                break;
            case 3:
                cin >> temp;
                for (int i=0;i<a.getSize();i++)
                {
                    if(a[i].searchByClassification(temp)==true)
                    cout<<a[i];
                }
                break;
            case 4:
                for(int i=0;i<a.getSize();i++)
                {
                    cout<<a[i];
                }
                break;
            case 5:
                for (int i=0;i<a.getSize();i++)
                {
                    if(a[i].isFav()==true)
                    cout<<a[i];
                }
                break;
            case 6:
                    ofstream out;
                    out.open("data.xls");
                    out << "ID\t" << "Fname\t" << "Lname\t" << "Classification\t" << "Fav\t" << "Address\t" << "Phone_num\t" << "Mails\n";
                    for (int i=0;i<a.getSize();i++)
                    {
                        out<<a[i];
                    }
                    out.close();
                break;
            case 7:
                ifstream in("data.xls");
                if (!in) {
                cout << "Error opening file for reading.\n";
                return;
                }
                else
                {
                for (int i=0;i<a.getSize();i++)
                {
                    in>>a[i];
                }
                }
                in.close();
                break;
            case 8:
                cin >> t;
                a.Delete(t);
                break;
            case 9:
                cin >> t;
                if (t>-1)
                a[t].add();
                else 
                throw out_of_range("error");
                break;
            case 10:
            cin>>t;
            if (t>-1)
                cout<<a[t];
                else 
                throw out_of_range("error");
                break;
            case 11:
                a.reverse();
                break;
            default:
                break;
        }
    } while (num < 12 && num > 0);

    return 0;
}
