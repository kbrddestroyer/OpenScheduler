#pragma once

#include <QWidget>
#include <QCalendarWidget>
#include <QDateTimeEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>

namespace OpenScheduler {
    struct Event {
        QDateTime start;
        QDateTime end;
        QString text;
    };

    class CalendarWidget : public QWidget {
    Q_OBJECT

    public:
        explicit CalendarWidget(QWidget *parent = nullptr);

        void addEvent(const QDateTime &start, const QDateTime &end, const QString &text);

    private slots:
        void handleAddEvent();
        void updateView();

    private:
        void fetchByDate(const QDate &);
        void setupTable();

        QCalendarWidget *calendar;
        QDateTimeEdit *startEdit;
        QDateTimeEdit *endEdit;
        QLineEdit *eventInput;
        QPushButton *addButton;
        QTableWidget *table;

        QList<Event> events;
    };
}