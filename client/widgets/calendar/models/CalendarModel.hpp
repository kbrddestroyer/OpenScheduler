#ifndef CALENDARMODEL_HPP
#define CALENDARMODEL_HPP

#include <map>
#include <QDateTime>
#include <QAbstractTableModel>

#include <compile_utils.h>

namespace OpenScheduler {

class CalendarModel final : public QAbstractTableModel {
public:
    CalendarModel() = default;

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    void append(const QDateTime &, const QString &);
    void remove(const QDateTime &);
    void clear();

    GETTER( QString get(const QDateTime & date) ) { return data_.at(date); }
private:
    std::map <QDateTime, QString> data_;
};

} // OpenScheduler

#endif //CALENDARMODEL_HPP
