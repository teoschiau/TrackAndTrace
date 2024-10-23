//
// Created by Teodora Schiau on 28.06.2024.
//

#include <QPainter>
#include "ViewGUI.h"
ViewGui::ViewGui(Service& service) :service{ service }
{
    initGUI();
}

void ViewGui::initGUI()
{
    QPainter painter{ this };
    painter.setPen(Qt::black);
    int x = 0;
    for (auto b: service.getAll())
    {
        if(b.getStatus()== false)
        {
            if(b.getRecipient()=="bag"){
                //painter.drawEllipse(100 + 25,100+x+3, 20, 20);
                painter.drawEllipse(b.getLong(),b.getLat(), 50, 50);
                painter.drawText(b.getLong() + 20, b.getLat() + 20, QString::fromStdString(b.getRecipient()+" "+b.getAddress()+" "+
                                                                                                                               to_string(b.getNumber())));

            }
            else
            {
                //painter.drawRect( 100 +25,100+x+3, 20, 20);
                painter.drawRect( b.getLong(),b.getLat(), 50, 50);
                painter.drawText(b.getLong() + 20, b.getLat() + 20, QString::fromStdString(b.getRecipient()+" "+b.getAddress()+" "+
                                                                                                                               to_string(b.getNumber())));

            }
            x += 50;
        }
    }

}

void ViewGui::paintEvent(QPaintEvent* ev)
{
    initGUI();
}
