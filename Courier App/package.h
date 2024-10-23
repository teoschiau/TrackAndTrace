//
// Created by Teodora Schiau on 28.06.2024.
//

#ifndef DELIVERY_PACKAGE_H
#define DELIVERY_PACKAGE_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Package{
private:
    string recipient;
    string address;
    int number;
    int longitude, latitude;
    bool status;

public:
    Package() = default;
    Package(string recipient, string address, int number, int lat, int longi, bool stat);
    ~Package() = default;
    string getRecipient() const {return recipient;}
    string getAddress() const {return address;}
    int getNumber() const {return number;}
    int getLong() const {return longitude;}
    int getLat() const {return latitude;}
    bool getStatus() const {return status;}
    void setStatus(){status = true;}

    friend istream& operator>>(istream&, Package&);
    friend ostream& operator<<(ostream&, const Package&);
    static vector<string> tokenize(string str, char deli);
};
#endif //DELIVERY_PACKAGE_H
