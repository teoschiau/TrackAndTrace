//
// Created by Teodora Schiau on 28.06.2024.
//

#ifndef DELIVERY_GUI_H
#define DELIVERY_GUI_H
#pragma "Observer.h"
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include <QTableView>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QSortFilterProxyModel>
#include "service.h"
#include "courier.h"
#include  <QMessageBox>
#include <QListWidgetItem>
#include <QComboBox>
#include <QDebug>
#include "ViewGUI.h"


class gui: public Observer, public QWidget{
private:
    Service& service;
    Courier& c;
    QListWidget* packagesList;
    QListWidget* undeliveredpackagesList;
    QPushButton* addButton, *deliverButton,*displayproducts,*viewbutton,*displayButton;
    QLineEdit* recipient,*address,*number,*longitude,*latitiude;
    QComboBox* streetsbox, *streetsbox2;

public:
    gui(Service& service, Courier& c, QWidget* parent = Q_NULLPTR);
    ~gui() = default;
    void update() override;
    void initGui();
    void initGuiCompany();
    void addPackage();
    void deliverPackage();
    int getSelectedIndex();
    void populateListCompany();
    void populateListCourier();
    void afterstreet();
    void afterstreet2();
    void view();

};
#endif //DELIVERY_GUI_H
