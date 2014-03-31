#include <QString>
#include <QVector>
#include "api/andrew/memory.h"
#include <QList>
#include <iostream>
#include "calculatorwindow.h"
#include "calculatorwindow.cpp"

     QList<QString> memory::memoryRecall;
    void memory::saveMemory(std::string answer)
    {
       memory::memoryRecall.push_back(QString::fromStdString(answer));
        memory::i++;
   }


