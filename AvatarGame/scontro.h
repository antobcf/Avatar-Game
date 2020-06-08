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

public:
    Scontro(QWidget * = nullptr);
    QPushButton* getBottoneCombatti() const;
    QPushButton* getBottoneCambioAvatar() const;
    QPushButton* getBottoneHomeScontro() const;

public slots:

};

#endif // SCONTRO_H
