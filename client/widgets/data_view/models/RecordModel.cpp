#include "RecordModel.hpp"


namespace OpenScheduler::Models {
    int RecordModel::rowCount(const QModelIndex &parent) const {
        return DAY_SIZE_MINUTES / ROW_SIZE_MINUTES;
    }

    int RecordModel::columnCount(const QModelIndex &parent) const {
        return 4;
    }

    QVariant RecordModel::data(const QModelIndex &index, int role) const {
        if (role != Qt::DisplayRole)
            return {};

        // Here we should select records, that suit current date/time.
        // Date selection is delegated to MySQL Query processor
        // selectCondition<> function.
        // But now we need to determine record time bounds.

        // 1. Determine current row time (in minutes)

        std::uint16_t currTimeMinutes = index.row() * ROW_SIZE_MINUTES;

        // 2. Select all records that suit current time interval
        // | There are some conditions when we can determine a record as suitable
        // | a) start_ <= currTimeMinutes + ROW_SIZE_MINUTES
        // | b) start_ > currTimeMinutes + ROW_SIZE_MINUTES but end > currTimeMinutes + ROW_SIZE_MINUTES
        // |        in this condition we should mark this row as busy
        // | c) end <= currTimeMinutes + ROW_SIZE_MINUTES - same as above

        // Actually here we need some kind of custom binary tree container.

        if ( ! index.isValid() || index.row() >= data_.size() )
            return {};

        auto & data = data_.at(index.row());

        // TODO: Change
        switch (index.column()) {
            case 0:
                return data.VISITOR();
            case 1:
                return  QString(data.START().toString());
            case 2:
                return QString(data.END().toString());
            case 3:
                return QString(data.COMMENT().c_str());
            default:
                return {};
        }
    }

    QVariant RecordModel::headerData(int section, Qt::Orientation orientation, int role) const {
        if ( role != Qt::DisplayRole )
            return QAbstractTableModel::headerData(section, orientation, role);

        // TODO: Change
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

    void RecordModel::resync() {
        data_.clear();
        QDate tomorrow = date_.addDays(1);

        data_ = Database::QueryProcessor<Dao::RecordDao>::selectCondition(
            "record",
            std::format(
                "start >= \"{}-{}-{}\" AND start < \"{}-{}-{}\"",
                date_.year(), date_.month(), date_.day(),
                tomorrow.year(), tomorrow.month(), tomorrow.day()
                )
            );
    }
}
