//
// Created by Teodora Schiau on 28.06.2024.
//

#ifndef DELIVERY_SERVICE_H
#define DELIVERY_SERVICE_H
#include "repo_couriers.h"
#include "repo_package.h"
#include "courier.h"
#include "observer.h"
class Service: public Observable{
private:
    CourierRepo& couriers;
    PackageRepo& packages;

public:
    Service(CourierRepo& crepo, PackageRepo& prepo);
    ~Service()=default;
    const vector<Package>& getAll();
    vector<Package> getUndelivered(Courier c);
    void addPackage(string recipient, string address, int num, int longi, int lat);
    void DeliverPackage(string recipient, string address, int num, int longi, int lat, bool status);
    vector<Package> getStreet(string street);
    vector<Package> getU();
};
#endif //DELIVERY_SERVICE_H
