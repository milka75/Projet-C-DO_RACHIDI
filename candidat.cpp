#include "candidat.h"

Candidat::Candidat()
{
    m_ListeResultats.clear();
    m_ListeResultats.resize(7);
}

QString Candidat::nom()
{
    return m_nom;
}

QVector<int> Candidat::ListeResultats()
{
    return m_ListeResultats;
}

void Candidat::rename(QString nouveauNom)
{
    m_nom = nouveauNom;
}

void Candidat::addVote(int i)
{
    m_ListeResultats[i]++;
}
