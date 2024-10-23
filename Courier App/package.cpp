//
// Created by Teodora Schiau on 28.06.2024.
//

#include "package.h"
Package::Package(std::string recipient, std::string address, int number, int lat,int longi, bool stat): recipient{recipient}, address{address}, number{number}, latitude{lat}, longitude{longi}, status{stat} {}

vector<string> Package::tokenize(std::string str, char deli) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while(getline(ss, token, deli))
        result.push_back(token);
    return result;
}

istream &operator>>( istream &input, Package &c){
    string line;
    getline(input,line);
    vector<string>tokens = Package::tokenize(line, ';');
    if(tokens.size()!= 6)
        return input;
    c.recipient = tokens[0];
    c.address = tokens[1];
    c.number= stoi(tokens[2]);
    c.longitude = stoi(tokens[3]);
    c.latitude = stoi(tokens[4]);
    if(tokens[5]=="true")
        c.status = true;
    else
        c.status = false;
    return input;
}
ostream &operator<<(ostream &output, const Package &p) {
    output<<p.recipient<<";"<<p.address<<";"<<p.number<<";"<<p.longitude<<";"<<p.latitude<<";"<<p.status;
    return output;
}