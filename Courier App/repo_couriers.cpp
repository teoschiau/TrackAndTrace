//
// Created by Teodora Schiau on 28.06.2024.
//

#include "repo_couriers.h"
CourierRepo::CourierRepo(){
    LoadData();
}
vector<Courier>&CourierRepo::getAll() {
    return people;
}
void CourierRepo::LoadData() {
    ifstream  f("../couriers.txt");
    Courier current;
    this->people.clear();
    while( f>> current)
        this->people.push_back(current);
    f.close();
}
