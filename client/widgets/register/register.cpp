// You may need to build the project (run Qt uic code generator) to get "ui_Register.h" resolved

#include "register.hpp"
#include "widgets/login/loginwidget.hpp"

#include "login/Login.hpp"
#include <QMessageBox>
#include "ui_register.h"

namespace OpenScheduler {
    Register::Register(QWidget *parent) :
            QWidget(parent), ui(new Ui::Register) {
        ui->setupUi(this);
    }

    void Register::registerUser() {
        if (
                ui->password->text().toStdString() != ui->passwordRep->text().toStdString()
                )
        {
            QMessageBox mbox;
            mbox.setWindowTitle("Error!");
            mbox.setText("Could not register: password does not match!");
            mbox.exec();

            return;
        }

        if ( !Login::Login( { ui->login->text().toStdString(), ui->password->text().toStdString() } ).tryRegister() )
        {
            QMessageBox mbox;
            mbox.setWindowTitle("Error!");
            mbox.setText("Could not register!");
            mbox.exec();

            return;
        }

        QMessageBox mbox;
        mbox.setText("Created new user!");
        mbox.exec();

        auto *qParentPtr = qobject_cast<QWidget *>(parent());
        auto *layout = qParentPtr->layout();
        this->deleteLater();

        QWidget *loginWidget = new OpenSchedulerUI::LoginWidget(qParentPtr);
        layout->replaceWidget(this, loginWidget);
    }

    Register::~Register() {
        delete ui;
    }
} // OpenScheduler
