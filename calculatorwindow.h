#include <string>
#include <vector>

#include "api/tim/input.h"
#include "api/tim/strings.h"

#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>

namespace Ui {
	class CalculatorWindow;
}

class CalculatorWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit CalculatorWindow(QWidget *parent = 0);
    ~CalculatorWindow();

private slots:
	void on_inputBox_textEdited(const QString &arg1);
	void on_memoryBox_clicked(const QModelIndex &index);
	void on_saveButton_clicked();

	void on_actionHelp_triggered();

private:
	Input input;
    Ui::CalculatorWindow *ui;
	std::string answer;
};

#endif // CALCULATORWINDOW_H
