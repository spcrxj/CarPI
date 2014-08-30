#include "wndvolume.h"
#include "ui_wndvolume.h"

WndVolume::WndVolume(QWidget *parent) : QDialog(parent), _ui(new Ui::WndVolume) {
    _ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    _showPoint = QPoint(parent->width() / 2 - width() / 2, parent->height() - height());

    _timer = new QTimer(this);
    _timer->setInterval(3000);
    connect(_timer, SIGNAL(timeout()), this, SLOT(hide()));
}

WndVolume::~WndVolume() {
    delete _ui;
    delete _timer;
}

void WndVolume::showVolume(int volume) {
    _ui->pbVolume->setValue(volume);

    if (!isVisible()) {
        show();
        move(_showPoint);
    }

    _timer->start();
}

void WndVolume::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        _ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
