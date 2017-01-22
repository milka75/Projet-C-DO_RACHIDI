#include "data.h"

Data::Data()
{

}

void Data::setData(Data myData)
{
    NCandidats = myData.NCandidats;
    NVotes = myData.NVotes;
    ListeBulletin = myData.ListeBulletin;
    ListeCandidats = myData.ListeCandidats;
    ListeScores = myData.ListeScores;
}
