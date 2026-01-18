#ifndef RECORDMODEL_HPP
#define RECORDMODEL_HPP

#include <QAbstractTableModel>
#include "../dao/RecordDao.hpp"
#include <database/Database.hpp>
#include <vector>

#include "table/QueryProcessor.hpp"


namespace OpenScheduler::Models {
    class RecordModel final : public QAbstractTableModel {
        Q_OBJECT

    public:
        explicit RecordModel(QObject *parent = nullptr) : QAbstractTableModel(parent) {
            data_ = Database::QueryProcessor<Dao::RecordDao>::select("record");
        }

        int rowCount(const QModelIndex &parent) const override;
        int columnCount(const QModelIndex &parent) const override;

        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

        void insert(Dao::RecordDao);
    private:
        std::vector< Dao::RecordDao > data_;
    };
}


#endif //RECORDMODEL_HPP
