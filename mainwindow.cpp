#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "funk.h"

#include <string>
#include <fstream>
#include <iostream>
#include <assert.h>

void lagre(const std::string &streng)
{
	std::fstream ost;
	ost.open("hei.txt");
	assert(ost.is_open());
	ost << streng;
	ost.close();
}


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	m_button = new QPushButton("knapp", this);

	knapp_pluss = new QPushButton("+", this);
	knapp_pluss->move(150, 80);
	knapp_pluss->resize(35,35);

	knapp_minus = new QPushButton("-", this);
	knapp_minus->move(150, 120);
	knapp_minus->resize(35,35);

	knapp_1 = new QPushButton("1", this);
	knapp_1->move(30,80);
	knapp_1->resize(35,35);

	knapp_2 = new QPushButton("2", this);
	knapp_2->move(30,120);
	knapp_2->resize(35,35);

	knapp_3 = new QPushButton("3", this);
	knapp_3->move(30,160);
	knapp_3->resize(35,35);

	knapp_4 = new QPushButton("4", this);
	knapp_4->move(70,80);
	knapp_4->resize(35,35);

	knapp_5 = new QPushButton("5", this);
	knapp_5->move(70,120);
	knapp_5->resize(35,35);

	knapp_6 = new QPushButton("6", this);
	knapp_6->move(70,160);
	knapp_6->resize(35,35);

	knapp_7 = new QPushButton("7", this);
	knapp_7->move(110,80);
	knapp_7->resize(35,35);

	knapp_8 = new QPushButton("8", this);
	knapp_8->move(110,120);
	knapp_8->resize(35,35);

	knapp_9 = new QPushButton("9", this);
	knapp_9->move(110,160);
	knapp_9->resize(35,35);

	lineEdit = new QLineEdit(this);

	lineEdit->setMaxLength(100);
	lineEdit->move(30, 30);
	lineEdit->resize(250, 50);



	m_button->move(300,30);
	m_button->resize(100, 50);

       QObject::connect(m_button, SIGNAL (released()), this, SLOT (inputFerdig();));

       QObject::connect(lineEdit, SIGNAL (returnPressed()), this, SLOT(inputFerdig()));

       QObject::connect(knapp_1, SIGNAL (released()), this, SLOT(on_knapp1_trykt()));
       QObject::connect(knapp_2, SIGNAL (released()), this, SLOT(on_knapp2_trykt()));
       QObject::connect(knapp_3, SIGNAL (released()), this, SLOT(on_knapp3_trykt()));
       QObject::connect(knapp_4, SIGNAL (released()), this, SLOT(on_knapp4_trykt()));
       QObject::connect(knapp_5, SIGNAL (released()), this, SLOT(on_knapp5_trykt()));
       QObject::connect(knapp_6, SIGNAL (released()), this, SLOT(on_knapp6_trykt()));
       QObject::connect(knapp_7, SIGNAL (released()), this, SLOT(on_knapp7_trykt()));
       QObject::connect(knapp_8, SIGNAL (released()), this, SLOT(on_knapp8_trykt()));
       QObject::connect(knapp_9, SIGNAL (released()), this, SLOT(on_knapp9_trykt()));

       QObject::connect(knapp_pluss, SIGNAL (released()), this, SLOT(add_funk()));
       QObject::connect(knapp_minus, SIGNAL (released()), this, SLOT(add_minus()));

}

void MainWindow::add_minus()
{
	lineEdit->insert("-");
}

void MainWindow::add_funk(char a)
{
	lineEdit->insert(&a);
	lineEdit->insert("+");
}

void MainWindow::add_funk()
{
	lineEdit->insert("+");
}

void MainWindow::handleButton()
{
	m_button->setText("eksempel");
}

void MainWindow::inputFerdig()
{
<<<<<<< HEAD


	auto svar = reknut(lineEdit->text().toStdString());

	lineEdit->setText(QString::fromStdString(svar));
=======
	m_button->setText("hei");
	lineEdit->setText("trykt");

	QString send = lineEdit->text();

	Svar x();
>>>>>>> c085935271eb61b72f1a7ca9eaa75af888a3cec3
}


MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_knapp1_trykt()
{
	lineEdit->insert("1");
}

void MainWindow::on_knapp2_trykt()
{
	lineEdit->insert("2");
}
void MainWindow::on_knapp3_trykt()
{
	lineEdit->insert("3");
}
void MainWindow::on_knapp4_trykt()
{
	lineEdit->insert("4");
}
void MainWindow::on_knapp5_trykt()
{
	lineEdit->insert("5");
}
void MainWindow::on_knapp6_trykt()
{
	lineEdit->insert("6");
}
void MainWindow::on_knapp7_trykt()
{
	lineEdit->insert("7");
}
void MainWindow::on_knapp8_trykt()
{
	lineEdit->insert("8");
}
void MainWindow::on_knapp9_trykt()
{
	lineEdit->insert("9");
}

void MainWindow::on_m_button_clicked()
{
	m_button->setText("trykt");
	QString send = lineEdit->text();
	std::string stdSend = send.toStdString();
	lineEdit->insert("1");
	lineEdit->update();
	lagre(stdSend);
}

void MainWindow::on_pushButton_clicked()
{
    lineEdit->resize(90,90);
    lineEdit->update();
}
