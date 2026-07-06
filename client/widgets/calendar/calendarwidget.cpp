#include "calendarwidget.hpp"
#include "ui_CalendarWidget.h"

#include "dao/RecordDao.hpp"
#include "table/QueryProcessor.hpp"
#include "dialog/records_crud_popup/create/createrecorddialog.hpp"

#include <QDialog>
#include <format>

namespace OpenScheduler {
    CalendarWidget::CalendarWidget(QWidget *parent) :
            QWidget(parent), ui(new Ui::CalendarWidget) {
        ui->setupUi(this);

        setupTable();
        connect(ui->calendar, &QCalendarWidget::selectionChanged, this, &CalendarWidget::updateView);
        connect(ui->table, &QTableWidget::cellDoubleClicked, this, &CalendarWidget::onCellDoubleClicked);
        updateView();
    }

    void CalendarWidget::fetchByDate(const QDate &date) {
        events_.clear();
        auto vecRecords = Database::QueryProcessor<Dao::RecordDao>::selectCondition(
                "record",
                std::format("DATE(start)=\"{}\" or DATE(end)=\"{}\"",
                            date.toString("yyyy-MM-dd").toStdString(),
                            date.toString("yyyy-MM-dd").toStdString())
        );

        for ( const auto &record : vecRecords )
        {
            events_.append({ record.START(), record.END(), QString::fromStdString(record.COMMENT()) });
        }
    }


    void CalendarWidget::updateView() {
        this->fetchByDate(ui->calendar->selectedDate());
        ui->table->clearContents();
        ui->table->clearSpans();

        QDate selected = ui->calendar->selectedDate();

        for (const auto &e : events_) {
            if (e.start_.date() != selected) continue;

            int rowStart = e.start_.time().hour();
            int durationSec = e.start_.secsTo(e.end_);
            int rowSpan = qMax(1, qCeil(durationSec / 3600.0));

            if (rowStart < 0 || rowStart >= 24) continue;
            if (rowStart + rowSpan > 24)
                rowSpan = 24 - rowStart;

            auto *item = new QTableWidgetItem(
                    e.start_.time().toString("HH:mm") + " - " +
                    e.end_.time().toString("HH:mm") + "\n" + e.text_
            );

            item->setBackground(Qt::cyan);

            ui->table->setItem(rowStart, 0, item);
            ui->table->setSpan(rowStart, 0, rowSpan, 1);
        }
    }

    void CalendarWidget::setupTable() {
        ui->table->setRowCount(24);
        ui->table->setColumnCount(1);

        QStringList hours;
        for (int i = 0; i < 24; ++i)
            hours << QString("%1:00").arg(i, 2, 10, QChar('0'));

        ui->table->setVerticalHeaderLabels(hours);
        ui->table->horizontalHeader()->hide();
        ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->table->verticalHeader()->setDefaultSectionSize(40);
    }

    CalendarWidget::~CalendarWidget() {
        delete ui;
    }

    void CalendarWidget::onCellDoubleClicked(int row, int col) {
        QDate currDate = ui->calendar->selectedDate();
        QTime currTime = QTime(row, 0, 0);

        auto *dialog = new CreateRecordDialog(QDateTime(currDate, currTime), qobject_cast<QWidget *>(parent()));

        connect(qobject_cast<const QDialog *>(dialog), &QDialog::finished, [this](int result){
            if (result == QDialog::Accepted) {
                // Success
                this->updateView();
            }
        });

        dialog->show();
    }
} // OpenScheduler
