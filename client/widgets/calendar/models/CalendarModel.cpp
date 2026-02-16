#include "CalendarModel.hpp"

namespace OpenScheduler {
    namespace {
        constexpr uint8_t DAYS_COUNT = 7;
        constexpr const char * DAYS[DAYS_COUNT] = {
            "MONDAY",
            "TUESDAY",
            "WEDNESDAY",
            "THURSDAY",
            "FRIDAY",
            "SATURDAY",
            "SUNDAY"
        };
    }

    int CalendarModel::rowCount(const QModelIndex &parent) const {
        return 16;
    }

    int CalendarModel::columnCount(const QModelIndex &parent) const {
        return DAYS_COUNT;
    }

    QVariant CalendarModel::data(const QModelIndex &index, int role) const {
        if (role != Qt::DisplayRole)
            return {};
        return QString( "Nop" );
    }

    QVariant CalendarModel::headerData(int section, Qt::Orientation orientation, int role) const {
        if ( role != Qt::DisplayRole )
            return QAbstractTableModel::headerData(section, orientation, role);
        if (section >= DAYS_COUNT)
            return {};

        return QString( DAYS[section] );
    }
} // OpenScheduler