import QtQuick          2.3

pragma Singleton

ListModel {
    property QtObject selection
    ListElement {
        MissionName: "aaaa"
    }

    ListElement {
        MissionName: "bbbb"
    }

    ListElement {
        MissionName: "cccc"
    }
}
