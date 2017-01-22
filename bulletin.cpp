#include "bulletin.h"

Bulletin::Bulletin()
{

}

void Bulletin::vote(int NCandidats)
{
    // D'abord l'electeur choisi son candidat favoris (note de 1)
    // Il ne peut en avoir qu'un
    // Il est selectionne aleatoirement
    m_CandidatFavoris = qrand()%NCandidats + 1;

    // Ensuite l'electeur donne des notes aux autres candidats
    // Notes aleatoires entre 2 et 7
    for(int i=0; i<NCandidats; i++)
    {
        if(i + 1 == m_CandidatFavoris)
            m_ListeResultats.append(1);
        else
            m_ListeResultats.append(qrand()%6 + 2);
    }

}

int Bulletin::CandidatFavoris()
{
    return m_CandidatFavoris;
}

QVector<int> Bulletin::ListeResultats()
{
    return m_ListeResultats;
}

