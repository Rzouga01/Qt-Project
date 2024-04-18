import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.6


Rectangle {
    id: window

    property bool clearMap: false
    property double oldLat: 25.6585
    property double oldLng: 100.3658
    property Component comMarker: mapMarker
    property Component secondMarker: mapSecondMarker

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: mapView
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(oldLat, oldLng);
        zoomLevel: 6

        MouseArea {
            anchors.fill: parent
            onClicked: {
                var coord = mapView.toCoordinate(Qt.point(mouse.x, mouse.y));
                window.mapClickedSignal(coord.latitude, coord.longitude);
            }
        }
    }

    function setCenter(lat, lng) {
        mapView.pan(oldLat - lat, oldLng - lng)
        oldLat = lat
        oldLng = lng
    }

    function addMarker(lat, lng) {
        var item = comMarker.createObject(window, {
                                           coordinate: QtPositioning.coordinate(lat, lng)
                                          })
        mapView.addMapItem(item)
    }

    function addSecondMarker(lat, lng) {
        var item = secondMarker.createObject(window, {
                                           coordinate: QtPositioning.coordinate(lat, lng)
                                          })
        mapView.addMapItem(item)
    }
    function clear(){
        mapView.clearMapItems()
    }
    function getItemCount() {
        console.log(mapView.mapItems.length)
        return mapView.mapItems.lengthz
    }
    Component {
        id: mapMarker
        MapQuickItem {
            id: markerImg
            anchorPoint.x: image.width/4
            anchorPoint.y: image.height
            coordinate: position

            sourceItem: Image {
                id: image
                source: "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_red.png"
            }
        }
    }

    Component {
        id: mapSecondMarker
        MapQuickItem {
            id: secondMarkerImg
            anchorPoint.x: image.width/4
            anchorPoint.y: image.height
            coordinate: position

            sourceItem: Image {
                id: image
                source: "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_blue.png"
            }
        }
    }

    signal mapClickedSignal(var lat, var lng);
}

