#include <string>
#include <vector>
#include <QList>
#include <iostream>

#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"

#include "api/tim/input.h"
#include "api/tim/strings.h"
#include "api/andrew/memory.h"


CalculatorWindow::CalculatorWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::CalculatorWindow)
{
	ui->setupUi(this);
}

CalculatorWindow::~CalculatorWindow(){
	delete ui;
}

void CalculatorWindow::on_inputBox_textEdited(const QString &arg1){
	std::string inputString = arg1.toStdString();
	std::string formattedString;
	std::vector <std::string> inputList;

	ui->progressBar->setValue(0);
	ui->progressBar->setMaximum(3);

	if(inputString.compare("\0") == 0)
		ui->formatOutput->setText("Enter your equation above");
	else{
		inputList = input.vectoriseInput(inputString);
		ui->progressBar->setValue(1);
		inputList = input.formatInput(inputList);
		ui->progressBar->setValue(2);

		for(unsigned int i = 0; i < inputList.size(); i++){
			if(input.valid(inputList.at(i)) != 1)
				break;
			formattedString.append(inputList[i]);

		}

		formattedString.append(" = ");
		answer = input.calculate(inputList);
		ui->progressBar->setValue(3);
		answer = input.formatOutput(answer);
		formattedString.append(answer);

		ui->formatOutput->setText(QString::fromStdString(formattedString));
	}
}

void CalculatorWindow::on_saveMemory_clicked(){
	memory memory1;
	memory1.saveMemory(answer);
	ui->viewMemory->addItem(memory1.memoryRecall.last());
}

void CalculatorWindow::on_clearInput_clicked(){
	ui->inputBox->clear();
}

void CalculatorWindow::on_clearMemory_clicked(){
	ui->viewMemory->clear();
}

void CalculatorWindow::on_viewMemory_itemClicked(QListWidgetItem *item){
	std::cout << "Click" << std::endl;
	ui->inputBox->setText(ui->inputBox->text()+ ui->viewMemory->currentItem()->text());
}

void CalculatorWindow::on_viewMemory_currentRowChanged(int currentRow)
{
	std::cout << "Click" << std::endl;
}
