#ifndef OPENSCHEDULER_CALENDARWIDGET_H
#define OPENSCHEDULER_CALENDARWIDGET_H

#include <QWidget>
#include <QDateTime>
#include <QVector>


namespace OpenScheduler {
    struct CalendarEvent {
        QDateTime start_;
        QDateTime end_;
        QString text_;
    };

    QT_BEGIN_NAMESPACE
    namespace Ui { class CalendarWidget; }
    QT_END_NAMESPACE

    class CalendarWidget : public QWidget {
    Q_OBJECT

    public:
        explicit CalendarWidget(QWidget *parent = nullptr);

        ~CalendarWidget() override;
    private slots:
        void updateView();
        void onCellDoubleClicked(int, int);
    private:
        void fetchByDate(const QDate &);
        void setupTable();
    private:
        Ui::CalendarWidget *ui;
        QVector<CalendarEvent> events_;
    };
} // OpenScheduler

#endif //OPENSCHEDULER_CALENDARWIDGET_H
