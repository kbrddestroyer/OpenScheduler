// You may need to build the project (run Qt uic code generator) to get "ui_LoginWidget.h" resolved

#include "loginwidget.hpp"

#include "login/Login.hpp"
#include <Singleton.hpp>
#include <QMessageBox>
// Generated
#include "ui_loginwidget.h"
#include "widgets/register/register.hpp"
#include "windows/main/mainwnd.hpp"


namespace OpenSchedulerUI {
    LoginWidget::LoginWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::LoginWidget) {
        ui->setupUi(this);
    }

    LoginWidget::~LoginWidget() {
        delete ui;
    }

    void LoginWidget::loginButtonClicked() const {
        const QString login = ui->loginInput->text();
        const QString password = ui->passwordInput->text();


        if (! processLogin(login, password)) {
            QMessageBox mbox;
            mbox.setText("Could not login!");
            mbox.exec();

            return;
        }
        QMessageBox mbox;
        mbox.setText("Successful logon");
        mbox.exec();

        // Process to main window and destroy current

        auto main_wnd = Utils::Singleton<OpenScheduler::MainWnd>::instance();
        main_wnd->activateWindow();
        main_wnd->show();
    }

    void LoginWidget::registerButtonClicked() {
        // TODO: Replace with something more user-friendly...

        auto *qParentPtr = qobject_cast<QWidget *>(parent());
        auto *layout = qParentPtr->layout();
        this->deleteLater();

        QWidget *registerWidgetPtr = new OpenScheduler::Register(qParentPtr);
        layout->replaceWidget(this, registerWidgetPtr);
    }

    bool LoginWidget::processLogin(const QString & login, const QString & password) {
        return Login::Login({ login.toStdString(), password.toStdString() }).tryLogin();
    }
} // OpenSchedulerUI
