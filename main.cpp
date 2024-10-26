#include <iostream>
#include "contactbook.cpp"

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
    Contact c1;

    do {
        displayMenu();
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
                c1.saveFile();
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
