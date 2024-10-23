//
// Created by Teodora Schiau on 28.06.2024.
//

#ifndef DELIVERY_REPO_PACKAGE_H
#define DELIVERY_REPO_PACKAGE_H
#include "package.h"
class PackageRepo{
private:
    vector<Package> packages;
    void LoadData();
    void WriteData(vector<Package> filerepo);
public:
    PackageRepo();
    ~PackageRepo()= default;
    const vector<Package>& getAll();
    void addPackage(Package p);
    void deliverPackage(Package p);
};
#endif //DELIVERY_REPO_PACKAGE_H
