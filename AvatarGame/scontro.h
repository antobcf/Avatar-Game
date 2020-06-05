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
    QLabel* nomeAvatarSx;
    QLabel* mediaSx;
    QLabel* vs;
    QLabel* terreno;
    QPushButton* bottoneHomeScontro;
    QPushButton* bottoneCambioAvatar;
    QPushButton* bottoneCombatti;
    QLabel* nomeAvatarDx;
    QLabel* mediaDx;

public:
    Scontro(QWidget * = nullptr);
    QPushButton* getBottoneCombatti() const;
    QPushButton* getBottoneCambioAvatar() const;
    QPushButton* getBottoneHomeScontro() const;

public slots:

};

#endif // SCONTRO_H
