#ifndef SMMISSIONTABLEMODEL_H
#define SMMISSIONTABLEMODEL_H
#include <qqml.h>
#include <QAbstractTableModel>

#include "SmMissionManager.h"

class SmMissionTableModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_ADDED_IN_MINOR_VERSION(1)

    Q_PROPERTY(SmMissionManager *missionManager READ getMissionManager WRITE setMissionManager NOTIFY missionManagerChanged)

    //static const QString url ;

private:
    SmMissionManager *_missionManager;

public:
    SmMissionManager *getMissionManager()
    {
        return _missionManager;
    }

    void setMissionManager(SmMissionManager *missionManager)
    {
        if (_missionManager != missionManager) {

            _missionManager = missionManager;

            //QString url = "/home/eunyoung/.config/smMission/smMissionList.json";
           // _missionManager->loadList(url);
            _missionManager->loadList();

            emit missionManagerChanged(_missionManager);
        }
    }

signals:
    void missionManagerChanged(SmMissionManager *missionManager);

public:
    int rowCount(const QModelIndex & = QModelIndex()) const override
    {
        return _missionManager->getMissions()->length();
    }

    int columnCount(const QModelIndex & = QModelIndex()) const override
    {
        return 2;
    }

    QVariant data(const QModelIndex &index, int role) const override
    {
        if (role == Qt::DisplayRole) {
            SmMission mission = _missionManager->getMissions()->at(index.row());
            // title
            if (index.column() == 0)
            {
                return mission.title();
            }
            // path
            else if (index.column() == 1)
            {
                return mission.path();
            }
        }

        return QVariant();
    }

    QHash<int, QByteArray> roleNames() const override
    {
        return { {Qt::DisplayRole, "display"} };
    }
};

#endif // SMMISSIONTABLEMODEL_H
