// You may need to build the project (run Qt uic code generator) to get "ui_AddCustomer.h" resolved

#include "addcustomer.hpp"
#include "ui_AddCustomer.h"

namespace OpenScheduler {
    AddCustomer::AddCustomer(QWidget *parent) :
            QDialog(parent), ui(new Ui::AddCustomer) {
        ui->setupUi(this);
    }

    AddCustomer::~AddCustomer() {
        delete ui;
    }
} // OpenScheduler
