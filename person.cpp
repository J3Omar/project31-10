#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "array.cpp"
using namespace std;

class Person {
    private:
    string first_name, last_name, Class, *numbers, *mails;
    int numSize, mailSize;
    bool fav;
    int person_id;
    
    public:
    static int id;
    
    Person() {
        id++;
        person_id = id;
    }

    // set methods with parameters
    void setFname(const string& fname) {
        first_name = fname;
    }

    void setLname(const string& lname) {
        last_name = lname;
    }

    void setClass(const string& c) {
        if (c == "friend" || c == "work" || c == "family") {
            Class = c;
        } else {
            Class = "other";
        }
    }

    void setNumbers(int size, const string* nums) {
        if (size > 0) {
            numSize = size;
            numbers = new string[numSize];
            for (int i = 0; i < numSize; i++) {
                numbers[i] = nums[i];
            }
        } else {
            throw out_of_range("error in index");
        }
    }

    void setMails(int size, const string* mailsArr) {
        if (size > 0) {
            mailSize = size;
            mails = new string[mailSize];
            for (int i = 0; i < mailSize; i++) {
                mails[i] = mailsArr[i];
            }
        } else {
            throw out_of_range("error in index");
        }
    }

    void setFav(bool favorite) {
        fav = favorite;
    }

    // get methods
    string getFname() const {
        return first_name;
    }

    string getLname() const {
        return last_name;
    }

    string getClass() const {
        return Class;
    }

    string getNumbers() const {
        string res = "";
        if (numSize > 0) {
            for (int i = 0; i < numSize; i++) {
                res += numbers[i] + " ";
            }
            return res;
        } else {
            throw out_of_range("error in index");
        }
    }

    string getMails() const {
        string res = "";
        if (mailSize > 0) {
            for (int i = 0; i < mailSize; i++) {
                res += mails[i] + " ";
            }
            return res;
        } else {
            throw out_of_range("error in index");
        }
    }

    bool getFav() const {
        return fav;
    }

    int getId() const {
        return person_id;
    }

    friend ostream& operator<<(ostream &output, Person &p) {
        output << left << setw(5) << p.getId() << setw(15) << p.getFname() << setw(15) << p.getLname()
               << setw(15) << p.getClass() << setw(5) << (p.getFav() ? "Yes" : "No"); 
        output << setw(20) << p.getNumbers();
        output << setw(20) << p.getMails();
        return output;
    }

    ~Person() {
        delete[] mails;
        delete[] numbers;
    }
    
    int Person::id = 0;
};

#endif
