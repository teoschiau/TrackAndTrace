//
// Created by Teodora Schiau on 28.06.2024.
//

#include "repo_package.h"
PackageRepo::PackageRepo(){
    LoadData();
}
const vector<Package>& PackageRepo::getAll() {
    return packages;
}
void PackageRepo::LoadData() {
    ifstream  f("../packages.txt");
    Package current;
    this->packages.clear();
    while( f>> current)
        this->packages.push_back(current);
    f.close();
}
void PackageRepo::addPackage(Package p) {
    packages.push_back(p);
    WriteData(packages);
}
void PackageRepo::deliverPackage(Package p) {
    for(auto & m:packages)
        if(m.getRecipient() == p.getRecipient() && m.getAddress() == p.getAddress() && m.getLong() == p.getLong())
            m.setStatus();
    WriteData(packages);
}
void PackageRepo::WriteData(vector<Package> filerepo) {
    ofstream g("../packages.txt");
    for(auto CurrentElement: filerepo)
        g << CurrentElement<<"\n";

}
