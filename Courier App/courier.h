//
// Created by Teodora Schiau on 28.06.2024.
//

#ifndef DELIVERY_COURIER_H
#define DELIVERY_COURIER_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Courier{
private:
    string name;
    vector<string> streets;
    int zone_center, zone_radius;

public:
    Courier()= default;
    Courier(string name,int center, int radius,vector<string> streets);
    ~Courier() = default;
    int getCenter() const {return zone_center;}
    int getRadius() const {return zone_radius;}
    vector<string> getStreets() const {return streets;}
    string getName() const {return name;}

    friend istream& operator>>(istream&, Courier&);
    static vector<string> tokenize(string str, char deli);
};
#endif //DELIVERY_COURIER_H
