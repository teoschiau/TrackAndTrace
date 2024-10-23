//
// Created by Teodora Schiau on 28.06.2024.
//

#ifndef DELIVERY_REPO_COURIERS_H
#define DELIVERY_REPO_COURIERS_H
#include "courier.h"
class CourierRepo{
private:
    vector<Courier> people;
    void LoadData();

public:
    CourierRepo();
    ~CourierRepo()=default;
    vector<Courier>& getAll();
};
#endif //DELIVERY_REPO_COURIERS_H
