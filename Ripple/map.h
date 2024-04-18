#ifndef MAP_H
#define MAP_H

#include <QDialog>
#include <QVariant>
#include <QObject>

namespace Ui {
class map;
}

class map : public QDialog
{
    Q_OBJECT

public:
    explicit map(QWidget *parent = nullptr);
    void hide();
    ~map();


signals:
    void setCenter(QVariant, QVariant);
    void addMarker(QVariant, QVariant);
    void addSecondMarker(QVariant, QVariant);
    void clear();
    void sendClickedCoords(QString coords);
    int getItemCount();
    void sendValues(double value1, double value2);


private:
    Ui::map *ui;
};
#endif // MAP_H

