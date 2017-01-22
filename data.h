#ifndef DATA_H
#define DATA_H

#include "bulletin.h"
#include "candidat.h"
#include <QStringList>

class Data
{
public:
    Data();
    void setData(Data);

    int NCandidats;
    int NVotes;
    QVector<Bulletin> ListeBulletin;
    QVector<Candidat> ListeCandidats;
    QVector<QVector<int> > ListeScores;
    QStringList ListeNoms;
};

#endif // DATA_H
