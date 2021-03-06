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
    QPushButton* azzeraRicerca;
    QLineEdit* cercaNome;
    QCheckBox* tipoElfo;
    QCheckBox* tipoNano;
    QCheckBox* tipoUmano;
    QCheckBox* tipoAlieno;
    QCheckBox* tipoMostro;
    QPushButton* bottoneModifica;
    QPushButton* bottoneRimuovi;
    QPushButton* bottoneAvvioGioco;
    QPushButton* bottoneInfoLista;
    item* elenco;

public:
    ListaAvatar(QWidget * = nullptr);
    QCheckBox* getTipoElfo() const;
    QCheckBox* getTipoNano() const;
    QCheckBox* getTipoUmano() const;
    QCheckBox* getTipoAlieno() const;
    QCheckBox* getTipoMostro() const;
    QLineEdit* getCercaNome() const;
    QPushButton* getAvviaRicerca() const;
    QPushButton* getAzzeraRicerca() const;
    QPushButton* getBottoneModifica() const;
    QPushButton* getBottoneRimuovi() const;
    QPushButton* getBottoneGioca() const;
    QPushButton* getBottoneHome() const;
    QPushButton* getBottoneInfoLista() const;
    item* getElenco() const;


public slots:
    void avatarSelezionato() const;
    void resetLista() const;
};

#endif // LISTAAVATAR_H
