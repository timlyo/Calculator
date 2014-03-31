#include <QVector>
#include <QString>
#include <QList>
#include <iostream>
#include <string>


#ifndef MEMORY_H
#define MEMORY_H

class memory
{
public:
int i =0;
static QList<QString> memoryRecall;
void saveMemory(std::string answer);

};

#endif // MEMORY_H
