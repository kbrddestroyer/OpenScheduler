#ifndef OPENSCHEDULER_CREATERECORDDIALOG_HPP
#define OPENSCHEDULER_CREATERECORDDIALOG_HPP

#include <QDialog>

namespace OpenScheduler {
    QT_BEGIN_NAMESPACE
    namespace Ui { class CreateRecordDialog; }
    QT_END_NAMESPACE

    class CreateRecordDialog : public QDialog {
    Q_OBJECT

    public:
        CreateRecordDialog() = delete;
        explicit CreateRecordDialog(const QDateTime &selection, QWidget *parent = nullptr);

        ~CreateRecordDialog() override;

    private slots:
        void createBtnClicked();
    private:
        Ui::CreateRecordDialog *ui;
    };
} // OpenScheduler

#endif //OPENSCHEDULER_CREATERECORDDIALOG_HPP
