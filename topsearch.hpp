#ifndef FINDTOP_HPP
#define FINDTOP_HPP

#include <QString>
#include <QStringList>
//#include <QList>
#include <QMap>
//#include <QSet>

class TopSearch
{
public:
    TopSearch();
    QStringList getTopWords(QStringList list, int number);

private:
    void calculateWordsRepeats(QStringList list);
    int findMaximum();

private:
    QMap<QString, int> wordsRepeatsMap;
};

#endif // FINDTOP_HPP
