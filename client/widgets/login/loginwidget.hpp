
#ifndef LOGINWIDGET_HPP
#define LOGINWIDGET_HPP

#include <QWidget>

namespace OpenSchedulerUI {
QT_BEGIN_NAMESPACE
namespace Ui { class LoginWidget; }
QT_END_NAMESPACE

class LoginWidget : public QWidget {
Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget() override;

public slots:
    void loginButtonClicked();
private:
    Ui::LoginWidget *ui;
};
} // OpenSchedulerUI

#endif //LOGINWIDGET_HPP
