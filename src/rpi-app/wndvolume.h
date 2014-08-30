#ifndef WNDVOLUME_H
#define WNDVOLUME_H

#include <QDialog>
#include <QTimer>
#include <QPoint>

namespace Ui {
    class WndVolume;
}

class WndVolume : public QDialog {
    Q_OBJECT
    
public:
    explicit WndVolume(QWidget *parent = 0);
    ~WndVolume();
    
public slots:
    void showVolume(int volume);

protected:
    void changeEvent(QEvent *e);
    
private:
    Ui::WndVolume *_ui;
    QTimer * _timer;
    QPoint _showPoint;
};

#endif // WNDVOLUME_H
