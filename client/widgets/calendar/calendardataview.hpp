
#ifndef CALENDARDATAVIEW_HPP
#define CALENDARDATAVIEW_HPP

#include <QWidget>
#include <QTableView>
#include "models/CalendarModel.hpp"

namespace OpenScheduler {
QT_BEGIN_NAMESPACE
namespace Ui { class CalendarDataView; }
QT_END_NAMESPACE

class CalendarDataView final : public QWidget {
Q_OBJECT

public:
    explicit CalendarDataView(QWidget *parent = nullptr);
    ~CalendarDataView() override;

private:
    Ui::CalendarDataView *ui;
    QTableView * table_;
    CalendarModel model_;
};
} // OpenScheduler

#endif //CALENDARDATAVIEW_HPP
