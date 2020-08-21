#ifndef INFORMAZIONISISTEMA_H
#define INFORMAZIONISISTEMA_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>

class InformazioniSistema : public QDialog
{
    Q_OBJECT
private:
    QLabel* testoSistema;
public:
    InformazioniSistema(QWidget * = nullptr);
};

#endif // INFORMAZIONISISTEMA_H
