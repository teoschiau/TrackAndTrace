//
// Created by Teodora Schiau on 28.06.2024.
//

#include "service.h"

Service::Service(CourierRepo &crepo, PackageRepo &prepo):couriers{crepo},packages{prepo} {
}

const vector<Package>& Service::getAll() {
    return this->packages.getAll();
}
vector<Package> Service::getUndelivered(Courier c) {
    vector<Package> result;
    for(int i=0;i<packages.getAll().size();i++)
        for(auto & s: c.getStreets())
        {
            if(!(packages.getAll()[i].getStatus()) && s == packages.getAll()[i].getAddress())
                result.push_back(packages.getAll()[i]);
        }

    return result;
}
void Service::addPackage(std::string recipient, std::string address, int num,int longi, int lat) {
    if(address.empty() && recipient.empty())
        throw exception();
    Package p(recipient,address,num,lat,longi,false);
    packages.addPackage(p);
    this->notify();
}
void Service::DeliverPackage(string recipient, string address, int num, int longi, int lat, bool status) {
    if(address == "" && recipient.empty())
        throw exception();
    Package p(recipient,address,num,lat,longi,status);
    packages.deliverPackage(p);
    this->notify();
}
vector<Package> Service::getStreet(std::string street) {
    vector<Package> rez;
    for(auto &p: packages.getAll())
        if(p.getAddress()==street)
            rez.push_back(p);
    return rez;
}
vector<Package> Service::getU() {
    vector<Package> result;
    for(auto &p: packages.getAll())
        if(!p.getStatus())
            result.push_back(p);
    return result;
}