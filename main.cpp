#include <iostream>
#include "contactbook.cpp"

using namespace std;

int main() {
    int num, t;
    string temp;
    Contact c1;

    do {
        cout << "Enter\n";
        cout << tab << "1: Add a contact" << endl;
        cout << tab << "2: Search by last name" << endl;
        cout << tab << "3: Search by classification" << endl;
        cout << tab << "4: Print all contacts" << endl;
        cout << tab << "5: Print favorite contacts" << endl;
        cout << tab << "6: Save to file" << endl;
        cout << tab << "7: Load from file" << endl;
        cout << tab << "8: Delete contact" << endl;
        cout << tab << "9: Update contact information" << endl;
        cout << tab << "10: Share contacts with others" << endl;
        cout << tab << "11: Reverse contacts book" << endl;
        cout << tab << "12: Exit" << endl;
        cin >> num;

        switch (num) {
            case 1:
                c1.add();
                break;
            case 2:
                cin >> temp;
                c1.searchByLastName(temp);
                break;
            case 3:
                cin >> temp;
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
                cin >> t;
                c1.deleteContact(t);
                break;
            case 9:
                cin >> t;
                c1.update(t);
                break;
            case 10:
               
                break;
            case 11:
                c1.reverseContact();
                break;
            default:
                break;
        }
    } while (num < 12 && num > 0);

    return 0;
}
