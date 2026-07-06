#ifndef OPENSCHEDULER_ADDCUSTOMER_H
#define OPENSCHEDULER_ADDCUSTOMER_H

#include <QDialog>

namespace OpenScheduler {
    QT_BEGIN_NAMESPACE
    namespace Ui { class AddCustomer; }
    QT_END_NAMESPACE

    class AddCustomer : public QDialog {
    Q_OBJECT

    public:
        explicit AddCustomer(QWidget *parent = nullptr);

        ~AddCustomer() override;

    private:
        Ui::AddCustomer *ui;
    };
} // OpenScheduler

#endif //OPENSCHEDULER_ADDCUSTOMER_H
