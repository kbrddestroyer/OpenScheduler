
#include "RecordModel.hpp"


namespace OpenScheduler::Models {
    int RecordModel::rowCount(const QModelIndex &parent) const {
        return data_.size();
    }

    int RecordModel::columnCount(const QModelIndex &parent) const {
        return 4;
    }

    QVariant RecordModel::data(const QModelIndex &index, int role) const {
        if (role != Qt::DisplayRole)
            return {};

        if ( ! index.isValid() || index.row() >= data_.size() )
            return {};

        auto & data = data_.at(index.row());
        switch (index.column()) {
            case 0:
                return data.VISITOR();
            case 1:
                return  QString(data.START().c_str());
            case 2:
                return QString(data.END().c_str());
            case 3:
                return QString(data.COMMENT().c_str());
            default:
                return {};
        }
    }

    QVariant RecordModel::headerData(int section, Qt::Orientation orientation, int role) const {
        if ( role != Qt::DisplayRole )
            return QAbstractTableModel::headerData(section, orientation, role);

        switch ( section ) {
            case 0:
                return QString("Visitor");
            case 1:
                return QString("Start");
            case 2:
                return QString("End");
            case 3:
                return QString("Comment");
            default:
                return {};
        }
    }

    void RecordModel::insert(Dao::RecordDao dao) {
        data_.push_back( std::move(dao) );
    }
}
