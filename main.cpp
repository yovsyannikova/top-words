#include <QCoreApplication>
#include <QString>
#include <QTextStream>
#include <QDebug>

#include "topsearch.hpp"

QTextStream cout (stdout);
QTextStream cin (stdin);

bool isTop(QString newWord)
{
    bool isNumber = false;
    QString rightPart = newWord.mid(3);

    if ( newWord.left(3) == "top" )
    {
        for (auto symbol : rightPart)
        {
            if ( !symbol.isDigit() )
            {
                isNumber = false;
                break;
            }
            else
                isNumber = true;
        }
    }
    return isNumber;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString newWord;
    QStringList wordsList;

    TopSearch * search = new TopSearch();

    while(true)
    {
        newWord = cin.readLine();

        if ( isTop(newWord) )
        {
            qDebug() << search->getTopWords(wordsList, newWord.mid(3).toInt());
            wordsList.clear();
        }
        else
            wordsList << newWord;
    }

    return a.exec();
}
