#ifndef LISTAAVATAR_H
#define LISTAAVATAR_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QCheckBox>

class ListaAvatar : public QWidget
{
    Q_OBJECT
private:
    QPushButton* bottoneHome;
    QPushButton* bottoneModifica;
    QPushButton* bottoneRimuovi;
    QPushButton* bottoneRimuoviTutto;
    QCheckBox* tipoElfo;
    QCheckBox* tipoNano;
    QCheckBox* tipoUmano;
    QCheckBox* tipoAlieno;
    QCheckBox* tipoMostro;
    QGroupBox* boxLista;

public:
    ListaAvatar(QWidget * = nullptr);
    QPushButton* getBottoneHome() const;

public slots:

};

#endif // LISTAAVATAR_H
