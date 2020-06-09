#ifndef LISTAAVATAR_H
#define LISTAAVATAR_H

#include "item.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QScrollArea>
#include <QScrollBar>

class ListaAvatar : public QWidget
{
    Q_OBJECT
private:
    QPushButton* bottoneHome;
    QLabel* ordinaLista;
    QPushButton* ordinaNome;
    QPushButton* ordinaLivello;
    QPushButton* ordinaMedia;

    QFormLayout* formLista;
    QLineEdit* cercaNome;
    QCheckBox* tipoElfo;
    QCheckBox* tipoNano;
    QCheckBox* tipoUmano;
    QCheckBox* tipoAlieno;
    QCheckBox* tipoMostro;
    QPushButton* bottoneModifica;
    QPushButton* bottoneRimuovi;
    QPushButton* bottoneRimuoviTutto;
    QPushButton* bottoneAvvioGioco;
    QPushButton* bottoneInfoLista;

    item* elenco;

public:
    ListaAvatar(QWidget * = nullptr);
    QFormLayout* getFormLista() const;
    QPushButton* getBottoneHome() const;
    QPushButton* getBottoneModifica() const;
    QPushButton* getBottoneGioca() const;
    QLineEdit* getCercaNome() const;
    QPushButton* getBottoneInfoLista() const;
    item* getElenco() const;

public slots:
    //void on_bottoneModifica_clicked();

};

#endif // LISTAAVATAR_H
