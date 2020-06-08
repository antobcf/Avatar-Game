#include "modello.h"

Modello::Modello()
{

}

Modello::~Modello()
{
    delete lista;
}

void Modello::salva()
{
    QSaveFile file(QString::fromStdString(percorso));

    if(!file.open(QIODevice::WriteOnly)) {
        return;
    }

    QXmlStreamWriter reader(&file);
    reader.setAutoFormatting(true);
    reader.writeStartDocument();
    reader.writeComment("!!!Non commentare il documento!!!");
    reader.writeStartElement("root");

    auto it = begin();
    while(it != end()) {
        const Avatar* salvaElemento = *it;
        const QString tipo = QString::fromStdString(salvaElemento->getTerrNon());
        const QString tipoAvatar = QString::fromStdString(salvaElemento->getTipo());
        reader.writeEmptyElement(tipoAvatar);
        reader.writeAttribute("Nome", QString::fromStdString(salvaElemento->GetNome()));
        reader.writeAttribute("Livello", QString("1%").arg(salvaElemento->GetLiv()));
        reader.writeAttribute("Exp", QString("1%").arg(salvaElemento->GetExp()));
        reader.writeAttribute("Forza", QString("1%").arg(salvaElemento->getForza()));
        reader.writeAttribute("Magia", QString("1%").arg(salvaElemento->getMagia()));
        reader.writeAttribute("Difesa", QString("1%").arg(salvaElemento->getDifesa()));
        reader.writeAttribute("Scienza", QString("1%").arg(salvaElemento->getScienza()));
        reader.writeAttribute("Sesso", salvaElemento->GetSesso() ? "true" : "false");
        if(tipo == "Terrestre") {
            const Terrestre* tipoTerrestre = static_cast<const Terrestre*>(salvaElemento);
            reader.writeAttribute("Scudo", tipoTerrestre->GetScu() ? "true" : "false");
            reader.writeAttribute("Spada", tipoTerrestre->GetSpada() ? "true" : "false");
            reader.writeAttribute("Anello", tipoTerrestre->GetAnello() ? "true" : "false");
            reader.writeAttribute("Libro", tipoTerrestre->GetLibro() ? "true" : "false");
            if(tipoAvatar == "Elfo") {
                const Elfo* tipoElfo = static_cast<const Elfo*>(tipoTerrestre); //o salva elemento??
                reader.writeAttribute("Trasparentia", QString("1%").arg(tipoElfo->GetTrasparentia()));
                //reader.writeAttribute("Terreno preferito", QString::fromStdString(tipoElfo->get))
            }
        } else if (tipo == "Non terrestre") {
            const NOTerrestre* tipoNoTerrestre = static_cast<const NOTerrestre*>(salvaElemento);
            reader.writeAttribute("Barriera", tipoNoTerrestre->GetBar() ? "true" : "false");
            reader.writeAttribute("Laser", tipoNoTerrestre->GetLaser() ? "true" : "false");
            reader.writeAttribute("Amuleto", tipoNoTerrestre->GetAmuleto() ? "true" : "false");
            reader.writeAttribute("Chip", tipoNoTerrestre->GetChip() ? "true" : "false");
        }
    }
}

void Modello::carica()
{

}

void Modello::rimuovi(Avatar* a)
{
    lista->removeElement(a);
}

Container<Avatar *> *Modello::getLista() const
{
    return lista;
}

Container<Avatar*>::iteratore Modello::begin()
{
    return lista->begin(); //mi trasforma in automatico la freccia in punto
}

Container<Avatar*>::iteratore Modello::end()
{
    return lista->end();
}

Container<Avatar*>::iteratoreConst Modello::begin() const
{
    return lista->beginC();
}

Container<Avatar*>::iteratoreConst Modello::end() const
{
    return lista->endC();
}
