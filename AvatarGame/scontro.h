#ifndef SCONTRO_H
#define SCONTRO_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class Scontro : public QWidget
{
    Q_OBJECT
private:
    QLabel* vs;
    QLabel* nomeAvatarSx;
    QLabel* nomeAvatarDx;
    QLabel* terreno;
    QPushButton* bottoneCombatti;

public:
    Scontro(QWidget * = nullptr);

public slots:

};

#endif // SCONTRO_H
