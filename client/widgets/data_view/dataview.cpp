
// You may need to build the project (run Qt uic code generator) to get "ui_dataview.h" resolved

#include "dataview.hpp"
#include "ui_dataview.h"

namespace OpenScheduler {
dataview::dataview(QWidget *parent) :
    QWidget(parent), ui(new Ui::dataview) {
    ui->setupUi(this);

    table_ = ui->tableView;

    ui->dateEdit->setDate(model_.getDate());

    table_->setModel( & model_ );
    table_->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
    table_->resizeColumnsToContents();

    model_.resync();

    table_->show();
}

dataview::~dataview() {
    delete ui;
}

void dataview::onDateChanged(const QDate & date) {
    model_.setDate(date);
    model_.resync();
    table_->viewport()->update();
}
} // OpenScheduler
