#include "topsearch.hpp"

#include <QDebug>

TopSearch::TopSearch()
{

}

void TopSearch::calculateWordsRepeats(QStringList list)
{
    //wordsRepeatsMap.clear();
    for ( QString word: list )
        wordsRepeatsMap[word]++;
}

int TopSearch::findMaximum()
{
    int max = 0;
    foreach(int value, wordsRepeatsMap)
    {
        if ( value > max )
            max = value;
    }
    return max;
}

QStringList TopSearch::getTopWords(QStringList list, int number)
{
    calculateWordsRepeats(list);

    for ( auto e: wordsRepeatsMap.keys() )
        qDebug() << e << " - " <<  wordsRepeatsMap.value(e) << "\n";

    QStringList topWordsList;
    int max = findMaximum();

    while (max != 0)
    {
        foreach (QString key, wordsRepeatsMap.keys())
        {
            if ( topWordsList.count() == number)
                return topWordsList;

            int value = wordsRepeatsMap.value(key);
            if ( value == max)
                topWordsList << key;
        }
        max--;
    }
    return topWordsList;
}
