#include <QApplication>
#include <QPushButton>
#include "repo_couriers.h"
#include "repo_package.h"
#include "service.h"
#include "gui.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CourierRepo couriers;
    PackageRepo package;
    Service service(couriers,package);
    vector<gui*> windows;
    for( int i=0;i<couriers.getAll().size();i++)
    {
        windows.push_back(new gui(service, couriers.getAll()[i]));
    }
    return a.exec();
}
