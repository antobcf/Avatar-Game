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
    QLabel* powerupSx;
    QLabel* powerup1selezionatoSx;
    QLabel* powerup2selezionatoSx;
    QLabel* powerup3selezionatoSx;
    QLabel* powerup4selezionatoSx;
    QLabel* titoloMediaSx;
    QLabel* mediaSx;
    QLabel* vs;
    QLabel* terreno;
    QPushButton* bottoneHomeScontro;
    QPushButton* bottoneCambioAvatar;
    QPushButton* bottoneCambioAvversario;
    QPushButton* bottoneCombatti;
    QLabel* nomeAvatarDx;
    QLabel* powerupDx;
    QLabel* powerup1selezionatoDx;
    QLabel* powerup2selezionatoDx;
    QLabel* powerup3selezionatoDx;
    QLabel* powerup4selezionatoDx;
    QLabel* titoloMediaDx;
    QLabel* mediaDx;
    QLabel* fotoAvatar1;
    QLabel* fotoAvatar2;

public:
    Scontro(QWidget * = nullptr);
    QLabel* getNomeAvatarSx() const;
    QLabel* getPowerupSx() const;
    QLabel* getPowerup1selezionatoSx() const;
    QLabel* getPowerup2selezionatoSx() const;
    QLabel* getPowerup3selezionatoSx() const;
    QLabel* getPowerup4selezionatoSx() const;
    QLabel* getTitoloMediaSx() const;
    QLabel* getMediaSx() const;
    QLabel* getVs() const;
    QLabel* getTerreno() const;
    QPushButton* getBottoneCombatti() const;
    QPushButton* getBottoneCambioAvatar() const;
    QPushButton* getBottoneCambioAvversario() const;
    QPushButton* getBottoneHomeScontro() const;
    QLabel* getNomeAvatarDx() const;
    QLabel* getPowerupDx() const;
    QLabel* getPowerup1selezionatoDx() const;
    QLabel* getPowerup2selezionatoDx() const;
    QLabel* getPowerup3selezionatoDx() const;
    QLabel* getPowerup4selezionatoDx() const;
    QLabel* getTitoloMediaDx() const;
    QLabel* getMediaDx() const;
    QLabel* getFotoAvatar1() const;
    QLabel* getFotoAvatar2() const;

};

#endif // SCONTRO_H
