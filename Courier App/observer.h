//
// Created by Teodora Schiau on 28.06.2024.
//

#ifndef DELIVERY_OBSERVER_H
#define DELIVERY_OBSERVER_H
#include <vector>
#include <algorithm>

using namespace std;

class Observer{
public:
    virtual void update()=0;
    virtual ~Observer() = default;
};

class Observable{
private:
    vector<Observer*> observer;
public:
    virtual ~Observable() = default;
    void addObserver(Observer* obs){
        observer.push_back(obs);
    }
    void removeObserver(Observer* obs){
        auto it = find(observer.begin(), observer.end(), obs);
        if(it != observer.end())
            observer.erase(it);
    }
    void notify(){
        for(auto obs: observer)
            obs->update();
    }
};
#endif //DELIVERY_OBSERVER_H
