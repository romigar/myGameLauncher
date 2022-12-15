#include <QObject>
#include <QString>
#include "tools.h"

static uint32_t distanceDamerauLevenshtein(QByteArray reference, QByteArray candidat)
{
    int i = 0;
    int j = 0;
    int coutSubstitution = 0;
    int a = reference.size()+1;
    int b = candidat.size()+1;
    int d[a][b];

    for (i = 0; i < a ; i++) {
        d[i][0] = i;
    }
    for (j = 0; j < b ; j++) {
        d[0][j] = j;
    }

    for ( j = 1 ; j < b ; j++)
    {
        for (i = 1; i < a; i++)
        {
            if (reference.at(i) == candidat.at(j)){
                coutSubstitution = 0;
            }
            else {
                coutSubstitution = 1;
            }

            d[i][j] = qMin(
                        d[i-1][j] + 1 ,
                  qMin( d[i][j-1] + 1 ,
                        d[i-1][j-1] + coutSubstitution ));


            // transposition
            if ( (i > 1 && j > 1)
                 && (reference.at(i) == candidat.at(j-1))
                 && (reference.at(i-1) == candidat.at(j)) ) {
                d[i][j] = qMin( d[i][j] , d[i-2][j-2] + coutSubstitution);
            }
        }
    }
    return d[a-1][b-1];
}

static double relativeDistance(QByteArray reference, QByteArray candidat)
{
    return (double)distanceDamerauLevenshtein(reference,candidat)/(double)reference.size();
}

bool validDistance(QByteArray reference, QByteArray candidat, double tolerance)
{
    return (relativeDistance(reference,candidat) <= tolerance);
}

