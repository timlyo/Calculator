#include "calculatorwindow.h"
#include <QApplication>
#include <iostream>

#include "api/josh/circleEquation.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    CalculatorWindow w;
    w.show();

    return a.exec();
}
