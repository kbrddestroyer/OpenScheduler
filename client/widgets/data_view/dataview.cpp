
// You may need to build the project (run Qt uic code generator) to get "ui_dataview.h" resolved

#include "dataview.hpp"
#include "ui_dataview.h"

namespace OpenScheduler {
dataview::dataview(QWidget *parent) :
    QWidget(parent), ui(new Ui::dataview) {
    ui->setupUi(this);

    table_ = ui->tableView;
    table_->setModel( & model_ );
    table_->resizeColumnsToContents();
    table_->show();
}

dataview::~dataview() {
    delete ui;
}
} // OpenScheduler
