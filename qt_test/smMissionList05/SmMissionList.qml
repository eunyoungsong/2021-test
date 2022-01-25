import QtQuick          2.3
import smsoft.mission 1.0

ListModel {
    function creatList() {
        path = "/home/eunyoung/.config/smMission/smMissionList.json";
        smMissionManager.newList();
        smMissionManager.loadList(path);
        smMissionManager.saveList(path);
    }

    Component.onCompleted: {
        createList()
    }

    SmMissionManager {
        id: smMissionManager
    }

    SmMission {
        id: smMission
    }


//    ListElement {
//        title: "aaaa"
//        path: "a-path"
//    }
//    ListElement {
//        title: "bbbb"
//        path: "b-path"
//    }
//    ListElement {
//        title: "cccc"
//        path: "file:///home/eunyoung/Documents/00000000.plan"
//    }

}


