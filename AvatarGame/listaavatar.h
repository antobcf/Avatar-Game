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
    QPushButton* bottoneHome;
    QLabel* ordinaLista;
    QPushButton* ordinaNome;
    QPushButton* ordinaLivello;
    QPushButton* ordinaMedia;
    QScrollArea* scrollLista;
    QScrollBar* scrollbarLista;
    QCheckBox* checkAvatar1;
    QLabel* nomeAvatar1;
    QPushButton* bottoneDescrizione1;
    QLabel* forzaAvatar1;
    QLabel* magiaAvatar1;
    QLabel* difesaAvatar1;
    QLabel* scienzaAvatar1;
    QCheckBox* checkAvatar2;
    QLabel* nomeAvatar2;
    QPushButton* bottoneDescrizione2;
    QLabel* forzaAvatar2;
    QLabel* magiaAvatar2;
    QLabel* difesaAvatar2;
    QLabel* scienzaAvatar2;
    QCheckBox* checkAvatar3;
    QLabel* nomeAvatar3;
    QPushButton* bottoneDescrizione3;
    QLabel* forzaAvatar3;
    QLabel* magiaAvatar3;
    QLabel* difesaAvatar3;
    QLabel* scienzaAvatar3;

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

public:
    ListaAvatar(QWidget * = nullptr);
    QFormLayout* getFormLista() const;
    QPushButton* getBottoneHome() const;
    QPushButton* getBottoneModifica() const;
    QPushButton* getBottoneGioca() const;
    QLineEdit* getCercaNome() const;

public slots:
    //void on_bottoneModifica_clicked();

};

#endif // LISTAAVATAR_H
