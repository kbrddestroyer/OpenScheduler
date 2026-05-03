#include "calendar.hpp"
#include <QVBoxLayout>
#include <QHeaderView>
#include <QtMath>

#include "dao/RecordDao.hpp"
#include "table/QueryProcessor.hpp"
#include <database/Database.hpp>
#include <format>


namespace OpenScheduler {
    CalendarWidget::CalendarWidget(QWidget *parent)
            : QWidget(parent)
    {
        auto *layout = new QVBoxLayout(this);

        calendar = new QCalendarWidget(this);

        startEdit = new QDateTimeEdit(QDateTime::currentDateTime(), this);
        endEdit = new QDateTimeEdit(QDateTime::currentDateTime().addSecs(3600), this);

        startEdit->setCalendarPopup(true);
        endEdit->setCalendarPopup(true);

        eventInput = new QLineEdit(this);
        addButton = new QPushButton("Добавить", this);

        table = new QTableWidget(this);
        setupTable();

        layout->addWidget(calendar);
        layout->addWidget(startEdit);
        layout->addWidget(endEdit);
        layout->addWidget(eventInput);
        layout->addWidget(addButton);
        layout->addWidget(table);

        connect(addButton, &QPushButton::clicked, this, &CalendarWidget::handleAddEvent);
        connect(calendar, &QCalendarWidget::selectionChanged, this, &CalendarWidget::updateView);

        updateView();
    }

    void CalendarWidget::fetchByDate(const QDate &date) {
        // Clear cache
        events.clear();
        auto vecRecords = Database::QueryProcessor<Dao::RecordDao>::selectCondition(
                "record",
                std::format("DATE(start)=\"{}\" or DATE(end)=\"{}\"",
                            date.toString("yyyy-MM-dd").toStdString(),
                            date.toString("yyyy-MM-dd").toStdString())
            );

        for ( const auto &record : vecRecords )
        {
            events.append({ record.START(), record.END(), QString::fromStdString(record.COMMENT()) });
        }
    }

    void CalendarWidget::setupTable() {
        table->setRowCount(24);
        table->setColumnCount(1);

        QStringList hours;
        for (int i = 0; i < 24; ++i)
            hours << QString("%1:00").arg(i, 2, 10, QChar('0'));

        table->setVerticalHeaderLabels(hours);
        table->horizontalHeader()->hide();
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        table->verticalHeader()->setDefaultSectionSize(40);
    }

    void CalendarWidget::addEvent(const QDateTime &start, const QDateTime &end, const QString &text) {
        if (text.isEmpty() || start >= end) return;

        events.append({start, end, text});

        // Add event to database for persistent storage
        Dao::RecordDao dao(0, start, end, text.toStdString());
        Database::QueryProcessor<Dao::RecordDao>::insert("record", dao);

        updateView();
    }

    void CalendarWidget::handleAddEvent() {
        addEvent(startEdit->dateTime(), endEdit->dateTime(), eventInput->text());
        eventInput->clear();
    }

    void CalendarWidget::updateView() {
        this->fetchByDate(calendar->selectedDate());
        table->clearContents();
        table->clearSpans();

        QDate selected = calendar->selectedDate();

        for (const auto &e : events) {
            if (e.start.date() != selected) continue;

            int rowStart = e.start.time().hour();

            int durationSec = e.start.secsTo(e.end);
            int rowSpan = qMax(1, qCeil(durationSec / 3600.0));

            if (rowStart < 0 || rowStart >= 24) continue;
            if (rowStart + rowSpan > 24)
                rowSpan = 24 - rowStart;

            auto *item = new QTableWidgetItem(
                    e.start.time().toString("HH:mm") + " - " +
                    e.end.time().toString("HH:mm") + "\n" + e.text
            );

            item->setBackground(Qt::cyan);

            table->setItem(rowStart, 0, item);
            table->setSpan(rowStart, 0, rowSpan, 1);
        }
    }
}