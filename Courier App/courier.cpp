//
// Created by Teodora Schiau on 28.06.2024.
//

#include "courier.h"

Courier::Courier(string name, int center, int radius, vector<string> streets):name{name}, zone_center{center},zone_radius{radius}, streets{streets}{
}

vector<string> Courier::tokenize(std::string str, char deli) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while(getline(ss, token, deli))
        result.push_back(token);
    return result;
}

istream &operator>>( istream &input, Courier &c){
    string line;
    getline(input,line);
    vector<string>tokens = Courier::tokenize(line, ';');
    if(tokens.size()!= 4)
        return input;
    c.name = tokens[0];
    c.zone_center = stoi(tokens[1]);
    c.zone_radius = stoi(tokens[2]);
    string loc = tokens[3];
    vector<string> street = Courier::tokenize(loc,',');
    c.streets = street;
    return input;
}
