#ifndef CANDIDAT_H
#define CANDIDAT_H

#include <QVector>
#include <QString>

class Candidat
{
public:
    Candidat();
    QString nom();
    QVector<int> ListeResultats();
    void rename(QString);
    void addVote(int);

protected:
    QString m_nom;
    QVector<int> m_ListeResultats;

};

#endif // CANDIDAT_H
