
// You may need to build the project (run Qt uic code generator) to get "ui_CalendarDataView.h" resolved

#include "calendardataview.hpp"
#include "ui_CalendarDataView.h"

namespace OpenScheduler {
CalendarDataView::CalendarDataView(QWidget *parent) :
    QWidget(parent), ui(new Ui::CalendarDataView) {
    ui->setupUi(this);
    table_ = ui->table;

    table_->setModel(&model_);
}

CalendarDataView::~CalendarDataView() {
    delete ui;
}
} // OpenScheduler
