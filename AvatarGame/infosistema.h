#ifndef INFOSISTEMA_H
#define INFOSISTEMA_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>

class InfoSistema : public QDialog
{
    Q_OBJECT
private:
    QLabel* testoSistema;

public:
    InfoSistema(QWidget * = nullptr);

public slots:

};

#endif // INFOSISTEMA_H
