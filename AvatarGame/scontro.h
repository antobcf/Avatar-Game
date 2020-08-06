#ifndef SCONTRO_H
#define SCONTRO_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QFormLayout>

class Scontro : public QWidget
{
    Q_OBJECT
private:
    QLabel* nomeAvatarSx;
    QFormLayout* formPowerupSx;
    QLabel* powerup1selezionatoSx;
    QLabel* powerup2selezionatoSx;
    QLabel* powerup3selezionatoSx;
    QLabel* powerup4selezionatoSx;
    QFormLayout* formMediaSx;
    QLabel* mediaSx;
    QLabel* vs;
    QLabel* terreno;
    QPushButton* bottoneHomeScontro;
    QPushButton* bottoneCambioAvatar;
    QPushButton* bottoneCombatti;
    QLabel* nomeAvatarDx;
    QFormLayout* formPowerupDx;
    QLabel* powerup1selezionatoDx;
    QLabel* powerup2selezionatoDx;
    QFormLayout* formMediaDx;
    QLabel* mediaDx;
    QString* forza;
    QString* magia;
    QString* difesa;
    QString* scienza;
    QString* lvl;
    QString* valoreSpeciale;
    QString* exp;
    QString* terrenoPreferito;
    QLabel* fotoAvatar;

public:
    Scontro(QWidget * = nullptr);
    QLabel* getNomeAvatarSx() const;
    QFormLayout* getFormPowerupSx() const;
    QLabel* getPowerup1selezionatoSx() const;
    QLabel* getPowerup2selezionatoSx() const;
    QLabel* getPowerup3selezionatoSx() const;
    QLabel* getPowerup4selezionatoSx() const;
    QFormLayout* getFormMediaSx() const;
    QLabel* getMediaSx() const;
    QLabel* getVs() const;
    QLabel* getTerreno() const;
    QPushButton* getBottoneCombatti() const;
    QPushButton* getBottoneCambioAvatar() const;
    QPushButton* getBottoneHomeScontro() const;
    QLabel* getNomeAvatarDx() const;
    QFormLayout* getFormPowerupDx() const;
    QLabel* getPowerup1selezionatoDx() const;
    QLabel* getPowerup2selezionatoDx() const;
    QFormLayout* getFormMediaDx() const;
    QLabel* getMediaDx() const;
    QString* getForza() const;
    QString* getMagia() const;
    QString* getDifesa() const;
    QString* getScienza() const;
    QString* getLvl() const;
    QString* getValoreSpeciale() const;
    QString* getExp() const;
    QString* getTerrenoPreferito() const;
    QLabel* getFotoAvatar() const;

public slots:

};

#endif // SCONTRO_H
