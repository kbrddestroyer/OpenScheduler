// You may need to build the project (run Qt uic code generator) to get "ui_LoginWidget.h" resolved

#include "loginwidget.hpp"

#include "login/Login.hpp"
#include <Windows.h>
// Generated
#include "ui_LoginWidget.h"

namespace OpenSchedulerUI {
    LoginWidget::LoginWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::LoginWidget) {
        ui->setupUi(this);
    }

    LoginWidget::~LoginWidget() {
        delete ui;
    }

    void LoginWidget::loginButtonClicked() {
        const QString login = ui->loginInput->text();
        const QString password = ui->passwordInput->text();

        Login::Credentials credentials = { login.toStdString(), password.toStdString() };
        auto loginEnt = Login::Login(credentials);

        if (!loginEnt.tryLogin()) {
            MessageBox(
                NULL,
                L"Login was not successfull!", L"Error!",
                MB_OK | MB_ICONERROR
                );
        }
        else {
            MessageBox(
                NULL,
                L"Login was successfull!", L"Ok!",
                MB_OK | MB_ICONINFORMATION
            );
        }
    }

} // OpenSchedulerUI
