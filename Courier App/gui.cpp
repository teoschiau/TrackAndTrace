//
// Created by Teodora Schiau on 28.06.2024.
//

#include "gui.h"
gui::gui(Service &service, Courier& c, QWidget *parent): service{service},c{c}, QWidget(parent){
    this->service.addObserver(this);
    this->initGui();
    this->initGuiCompany();
    this->show();
    populateListCourier();
    populateListCompany();
}
void gui::update() {
    populateListCompany();
    populateListCourier();
}
void gui::initGuiCompany() {
    packagesList = new QListWidget{};

    addButton = new QPushButton{"Add package"};
    displayproducts = new QPushButton{"Display package"};
    displayproducts = new QPushButton{"Display package"};
    viewbutton = new QPushButton{"View Undelivered"};

    recipient = new QLineEdit{};
    address = new QLineEdit{};
    number= new QLineEdit{};
    longitude = new QLineEdit{};
    latitiude = new QLineEdit{};

    QLabel* r = new QLabel("Recipient");
    QLabel* a = new QLabel("Address");
    QLabel* n = new QLabel("Number");
    QLabel* lo = new QLabel("Longitude");
    QLabel* la = new QLabel("Latitude");
    QLabel* packages = new QLabel("The list of packages:");

    QVBoxLayout* companyLayout = new QVBoxLayout();
    companyLayout->addWidget(packages);
    companyLayout->addWidget(this->packagesList);

    QFormLayout* details= new QFormLayout();
    details->addRow(r, recipient);
    details->addRow(a, address);
    details->addRow(n, number);
    details->addRow(lo, longitude);
    details->addRow(la, latitiude);

    companyLayout->addLayout(details);
    companyLayout->addWidget(addButton);
    companyLayout->addWidget(displayproducts);
    companyLayout->addWidget(viewbutton);

    this->streetsbox = new QComboBox{};
    this->streetsbox->addItem("All");
    this->streetsbox->addItem("Tudor Vladimirecu");
    this->streetsbox->addItem("LALA");
    this->streetsbox->addItem("Teodor Mihali");
    this->streetsbox->addItem("Trandafirilor");
    this->streetsbox->addItem("Lalelelor");

    companyLayout->addWidget(streetsbox);


    QWidget *mainDisplay = new QWidget();
    mainDisplay->setWindowTitle("Fan Courier");
    mainDisplay->setLayout(companyLayout);
    mainDisplay->show();
    QObject::connect(this->addButton, &QPushButton::clicked, this, &gui::addPackage);
    QObject::connect(this->displayproducts, &QPushButton::clicked, this, &gui::afterstreet);
    QObject::connect(this->viewbutton,&QPushButton::clicked,this,&gui::view);

}
void gui::initGui() {
    QLabel* zone = new QLabel(QString::number((c.getRadius()^2)*3.14));
    string str;
    for(auto& s:c.getStreets())
        str = str+s +" ";
    QLabel* street = new QLabel(QString::fromStdString(str));

    undeliveredpackagesList = new QListWidget{};
    deliverButton = new QPushButton{"Deliver Package"};
    displayButton = new QPushButton{"Display"};

    QVBoxLayout* courier = new QVBoxLayout();
    courier->addWidget(zone);
    courier->addWidget(street);
    courier->addWidget(undeliveredpackagesList);
    courier->addWidget(deliverButton);
    courier->addWidget(displayButton);


    this->streetsbox2 = new QComboBox{};
    this->streetsbox2->addItem("All");
    for(int i=0;i<c.getStreets().size();i++)
        streetsbox2->addItem(QString::fromStdString(c.getStreets()[i]));
    courier->addWidget(streetsbox2);

    this->setLayout(courier);
    this->setWindowTitle(QString::fromStdString(this->c.getName()));
    this->resize(600,300);

    QObject::connect(this->displayButton, &QPushButton::clicked, this, &gui::afterstreet2);
    QObject::connect(this->deliverButton, &QPushButton::clicked, this, &gui::deliverPackage);
    QObject::connect(this->undeliveredpackagesList, &QListWidget::itemSelectionChanged, [this](){
        int index = this->getSelectedIndex();

        if(index<0)
            return;

        Package p = this->service.getUndelivered(c)[index];
        this->recipient->setText(QString::fromStdString(p.getRecipient()));
        this->address->setText(QString::fromStdString(p.getAddress()));
        this->number->setText(QString::fromStdString(to_string(p.getNumber())));
        this->longitude->setText(QString::fromStdString(to_string(p.getLong())));
        this->latitiude->setText(QString::fromStdString(to_string(p.getLat())));

    });
}

void gui::addPackage() {
    string recipient = this->recipient->text().toStdString();
    string address = this->address->text().toStdString();
    int number = stoi(this->number->text().toStdString());
    int lo = stoi(this->longitude->text().toStdString());
    int lat = stoi(this->latitiude->text().toStdString());

    try{
        this->service.addPackage(recipient,address,number,lo,lat);
        this->recipient->clear();
        this->address->clear();
        this->number->clear();
        this->latitiude->clear();
        this->longitude->clear();
    }catch(...){
        QMessageBox::critical(this,"Error", "Invalid input!");
    }
}

int gui::getSelectedIndex() {
    QModelIndexList selected = this->undeliveredpackagesList->selectionModel()->selectedIndexes();
    if(selected.isEmpty())
        return -1;
    int selectedIndex = selected.at(0).row();
    return selectedIndex;
}

void gui::deliverPackage() {
    string recipient = this->recipient->text().toStdString();
    string address = this->address->text().toStdString();
    int number = stoi(this->number->text().toStdString());
    int lo = stoi(this->longitude->text().toStdString());
    int lat = stoi(this->latitiude->text().toStdString());
    try{
        this->service.DeliverPackage(recipient,address,number,lo,lat, false);
        this->recipient->clear();
        this->address->clear();
        this->number->clear();
        this->latitiude->clear();
        this->longitude->clear();
    }catch(...){
        QMessageBox::critical(this,"Error", "Invalid input!");
    }
}
void gui::afterstreet() {
    string address = this->streetsbox->currentText().toStdString();
    vector<Package> res;
    if(address=="All")
        res = service.getAll();
    else
        res = service.getStreet(address);
    packagesList->clear();
    for (auto &package : res) {
        QListWidgetItem* item = new QListWidgetItem{QString::fromStdString(package.getRecipient()+" "+package.getAddress()+" "+ to_string(package.getNumber())+
                                                                                                                                to_string(package.getLong())+" "+
                                                                                                                                                             to_string(package.getLat()))};
        this->packagesList->addItem(item);
    }
}
void gui::populateListCompany() {
    this->packagesList->clear();
    vector<Package> packages = this->service.getAll();

    for (auto &package : packages) {
        QListWidgetItem* item = new QListWidgetItem{QString::fromStdString("Recipient: "+package.getRecipient()+" "+"Address: "+package.getAddress()+" "+
                                                                                                                           to_string(package.getNumber())+" Location: "+
                                                                                                                                                          to_string(package.getLong())+" "+
                                                                                                                                                                                       to_string(package.getLat()))};
        if(package.getStatus())
            item->setBackground(Qt::green);
        this->packagesList->addItem(item);
    }
}
void gui::populateListCourier() {
    this->undeliveredpackagesList->clear();
    vector<Package> pac = this->service.getUndelivered(c);
    string address = this->streetsbox->currentText().toStdString();
    vector<Package> res = service.getStreet(address);
    for (auto &package : pac) {
        QListWidgetItem* item = new QListWidgetItem{QString::fromStdString(package.getRecipient()+" "+package.getAddress()+" "+
                                                                                                                           to_string(package.getNumber()))};
        this->undeliveredpackagesList->addItem(item);
    }

}
void gui::view() {
    ViewGui* view = new ViewGui{ this->service };
    view->show();
}
void gui::afterstreet2() {
    string address = this->streetsbox2->currentText().toStdString();
    vector<Package> res;
    if(address=="All")
        res = service.getUndelivered(c);
    else
        res = service.getStreet(address);
    undeliveredpackagesList->clear();
    for (auto &package : res) {
        QListWidgetItem* item = new QListWidgetItem{QString::fromStdString(package.getRecipient()+" "+package.getAddress()+" "+ to_string(package.getNumber())+
                                                                           to_string(package.getLong())+" "+
                                                                           to_string(package.getLat()))};
        this->undeliveredpackagesList->addItem(item);
    }
}