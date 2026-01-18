
// You may need to build the project (run Qt uic code generator) to get "ui_MainWnd.h" resolved

#include "mainwnd.hpp"
#include "ui_MainWnd.h"

namespace OpenScheduler {
MainWnd::MainWnd(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWnd) {
    ui->setupUi(this);
}

MainWnd::~MainWnd() {
    delete ui;
}
} // OpenScheduler
