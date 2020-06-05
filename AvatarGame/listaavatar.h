#ifndef LISTAAVATAR_H
#define LISTAAVATAR_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QDialog>
#include <QScrollArea>
#include <QScrollBar>

class ListaAvatar : public QWidget
{
    Q_OBJECT
private:
    QFormLayout* formLista;
    QPushButton* bottoneHome;
    QPushButton* bottoneModifica;
    QPushButton* bottoneRimuovi;
    QPushButton* bottoneRimuoviTutto;
    QPushButton* bottoneAzzera;
    QPushButton* bottoneAvvioGioco;
    QCheckBox* tipoElfo;
    QCheckBox* tipoNano;
    QCheckBox* tipoUmano;
    QCheckBox* tipoAlieno;
    QCheckBox* tipoMostro;
    QLineEdit* cercaNome;
    QScrollArea* scrollLista;
    QScrollBar* scrollbarLista;
    QLabel* ordinaLista;
    QPushButton* ordinaNome;
    QPushButton* ordinaLivello;
    QPushButton* ordinaMedia;
    QLabel* nomeAvatar1;
    QLabel* forzaAvatar1;
    QLabel* magiaAvatar1;
    QLabel* difesaAvatar1;
    QLabel* scienzaAvatar1;
    QCheckBox* checkAvatar1;
    QPushButton* bottoneDescrizione1;
    QLabel* nomeAvatar2;
    QLabel* forzaAvatar2;
    QLabel* magiaAvatar2;
    QLabel* difesaAvatar2;
    QLabel* scienzaAvatar2;
    QCheckBox* checkAvatar2;
    QPushButton* bottoneDescrizione2;
    QLabel* nomeAvatar3;
    QLabel* forzaAvatar3;
    QLabel* magiaAvatar3;
    QLabel* difesaAvatar3;
    QLabel* scienzaAvatar3;
    QCheckBox* checkAvatar3;
    QPushButton* bottoneDescrizione3;

public:
    ListaAvatar(QWidget * = nullptr);
    QFormLayout* getFormLista() const;
    QPushButton* getBottoneHome() const;
    QPushButton* getBottoneModifica() const;
    QPushButton* getBottoneGioca() const;
    QLineEdit* getCercaNome() const;

public slots:
    void azzeraTutto() const;
    void azzeraCheck() const;
    //void on_bottoneModifica_clicked();

};

#endif // LISTAAVATAR_H
