#include "calculatorwindow.h"
#include <QApplication>
#include <iostream>

#include "api/josh/circleEquation.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    CalculatorWindow w;
    w.show();

	circumference myCircle;
	myCircle.set_values(5,3.141592654);
	myCircle = 6;

	std:cout << myCircle.SetCircumference() << std::endl;

    return a.exec();
}
