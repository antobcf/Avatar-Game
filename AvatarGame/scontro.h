#ifndef SCONTRO_H
#define SCONTRO_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

class Scontro : public QWidget
{
    Q_OBJECT
private:
    QLabel* vs;
    QLabel* nomeAvatarSx;
    QLabel* nomeAvatarDx;
    QLabel* terreno;
    QPushButton* bottoneCombatti;
    QPushButton* bottoneCambioAvatar;
    QPushButton* bottoneHomeScontro;
    QLabel* mediaSx;
    QLabel* mediaDx;

public:
    Scontro(QWidget * = nullptr);
    QPushButton* getBottoneCombatti() const;
    QPushButton* getBottoneCambioAvatar() const;
    QPushButton* getBottoneHomeScontro() const;

public slots:

};

#endif // SCONTRO_H
