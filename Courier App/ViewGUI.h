//
// Created by Teodora Schiau on 28.06.2024.
//

#ifndef DELIVERY_VIEWGUI_H
#define DELIVERY_VIEWGUI_H
#include "Service.h"
#include <qwidget.h>
class ViewGui : public QWidget
{
private:
    Service& service;
public:
    ViewGui(Service& service);
    ~ViewGui() {};
    void initGUI();
    void paintEvent(QPaintEvent* ev);

};
#endif //DELIVERY_VIEWGUI_H
