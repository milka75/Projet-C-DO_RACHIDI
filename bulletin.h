#ifndef BULLETIN_H
#define BULLETIN_H

#include <QVector>

class Bulletin
{
public:
    Bulletin();

    void vote(int NCandidats);
    int CandidatFavoris();
    QVector<int> ListeResultats();


protected:
    int m_CandidatFavoris;
    QVector<int> m_ListeResultats;
};

#endif // BULLETIN_H
