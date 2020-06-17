#ifndef INFOSISTEMA_H
#define INFOSISTEMA_H

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>

class infoSistema : public QDialog
{
    Q_OBJECT
private:
    QLabel* testoSistema;

public:
    infoSistema(QWidget * = nullptr);

public slots:

};

#endif // INFOSISTEMA_H
