#ifndef RECORDMODEL_HPP
#define RECORDMODEL_HPP

#include <QAbstractTableModel>
#include "../dao/RecordDao.hpp"
#include <database/Database.hpp>
#include <vector>

#include "table/QueryProcessor.hpp"

#define DAY_SIZE_MINUTES 24 * 60
#define ROW_SIZE_MINUTES 30


namespace OpenScheduler::Models {
    class RecordModel final : public QAbstractTableModel {
        Q_OBJECT

    public:
        explicit RecordModel(QObject *parent = nullptr) : QAbstractTableModel(parent), date_( QDate::currentDate() ) {}

        int rowCount(const QModelIndex &parent) const override;
        int columnCount(const QModelIndex &parent) const override;

        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

        void insert(Dao::RecordDao);

        QDate getDate() const { return date_; }
        void setDate( const QDate & date ) { this->date_ = date; resync(); }
        void resync();
    private:
        std::vector< Dao::RecordDao > data_;
        QDate date_;
    };
}


#endif //RECORDMODEL_HPP
