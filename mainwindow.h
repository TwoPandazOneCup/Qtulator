#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void handleButton();
	void inputFerdig();
	void on_m_button_clicked();


	void on_pushButton_clicked();

	void on_knapp1_trykt();
	void on_knapp2_trykt();
	void on_knapp3_trykt();
	void on_knapp4_trykt();
	void on_knapp5_trykt();
	void on_knapp6_trykt();
	void on_knapp7_trykt();
	void on_knapp8_trykt();
	void on_knapp9_trykt();

	void add_funk(char a);
	void add_funk();
	void add_minus();
	void add_mult();
	void add_div();

private:
	char pluss = '+';

	Ui::MainWindow *ui;

	QPushButton *m_button;

	QPushButton *knapp_1;
	QPushButton *knapp_2;
	QPushButton *knapp_3;
	QPushButton *knapp_4;
	QPushButton *knapp_5;
	QPushButton *knapp_6;
	QPushButton *knapp_7;
	QPushButton *knapp_8;
	QPushButton *knapp_9;

	QPushButton *knapp_pluss;
	QPushButton *knapp_minus;
	QPushButton *knapp_div;
	QPushButton *knapp_mult;

	QLineEdit *lineEdit;
};
#endif // MAINWINDOW_H
