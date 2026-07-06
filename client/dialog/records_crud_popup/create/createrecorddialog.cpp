#include "createrecorddialog.hpp"
#include "ui_CreateRecordDialog.h"
#include "dao/RecordDao.hpp"
#include "registry/g_registry.hpp"

#include <database/table/QueryProcessor.hpp>

namespace OpenScheduler {
    CreateRecordDialog::CreateRecordDialog(const QDateTime &selection, QWidget *parent) :
            QDialog(parent), ui(new Ui::CreateRecordDialog) {
        ui->setupUi(this);

        auto * assigneePicker = ui->assigneePicker;

        for ( const Dao::WorkerDao &dao : g_workers ) {
            assigneePicker->addItem(QString::fromStdString(dao.DISPLAY_NAME()));
        }

        ui->start->setDateTime(selection);
        ui->end->setTime(selection.time().addSecs(60 * 15));

        connect(
                ui->apply,
                &QPushButton::clicked,
                this,
                &CreateRecordDialog::createBtnClicked
                );
    }

    void CreateRecordDialog::createBtnClicked() {
        uint16_t assignee_id = 0;

        for ( const Dao::WorkerDao &dao : g_workers ) {
            if (dao.DISPLAY_NAME() == ui->assigneePicker->currentText())
            {
                assignee_id = dao.ID();
                break;
            }
        }

        auto dao = Dao::RecordDao(
                0, assignee_id,
                ui->start->dateTime(), QDateTime(ui->start->date(), ui->end->time()),
                ui->comment->text().toStdString()
                );

        Database::QueryProcessor<Dao::RecordDao>::insert(
                "record", dao
                );

        this->accept();
    }

    CreateRecordDialog::~CreateRecordDialog() {
        delete ui;
    }
} // OpenScheduler
