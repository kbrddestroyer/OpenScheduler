
#ifndef DATAVIEW_HPP
#define DATAVIEW_HPP

#include "models/RecordModel.hpp"

#include <QTableView>
#include <QWidget>

namespace OpenScheduler {
QT_BEGIN_NAMESPACE
namespace Ui { class dataview; }
QT_END_NAMESPACE

class dataview final : public QWidget {
    Q_OBJECT

public:
    explicit dataview(QWidget *parent = nullptr);
    ~dataview() override;

public slots:
    void onDateChanged(const QDate & /* date */);
private:
    Ui::dataview * ui;
    QTableView * table_;
    Models::RecordModel model_;
};
} // OpenScheduler

#endif //DATAVIEW_HPP
