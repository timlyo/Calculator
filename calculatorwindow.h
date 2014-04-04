#include <string>
#include <vector>
#include <QListWidgetItem>

#include "api/tim/input.h"
#include "api/tim/strings.h"

#include "helpwindow.h"
#include "aboutwindow.h"

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

	void on_saveMemory_clicked();
	void on_clearInput_clicked();
	void on_clearMemory_clicked();
	void on_listWidget_itemClicked(QListWidgetItem *item);
	void on_viewMemory_itemClicked(QListWidgetItem *item);

	void on_viewMemory_currentRowChanged(int currentRow);

	void on_actionCommand_triggered();

	void on_actionAbout_triggered();

private:
	Input input;
    Ui::CalculatorWindow *ui;
	std::string answer;

	HelpWindow helpWindow;
	AboutWindow aboutWindow;
};

#endif // CALCULATORWINDOW_H
