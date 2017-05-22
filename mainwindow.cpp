#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "funk.h"

#include <string>
#include <fstream>
#include <iostream>
#include <assert.h>


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	m_button = new QPushButton("=", this);

	clear_button = new QPushButton("CA", this);
	clear_button->move(190, 80);
	clear_button->resize(knappeBreidde, knappeBreidde );

	knapp_backspace = new QPushButton("C", this);
	knapp_backspace->move(190, 120);
	knapp_backspace->resize(knappeBreidde, knappeBreidde);



	knapp_pluss = new QPushButton("+", this);
	knapp_pluss->move(150, 80);
	knapp_pluss->resize(35,35);

	knapp_minus = new QPushButton("-", this);
	knapp_minus->move(150, 120);
	knapp_minus->resize(35,35);

	knapp_mult = new QPushButton("*", this);
	knapp_mult->move(150, 160);
	knapp_mult->resize(35,35);

	knapp_div = new QPushButton("/", this);
	knapp_div->move(150, 200);
	knapp_div->resize(35,35);

	knapp_exp = new QPushButton("^", this);
	knapp_exp->move(230, 80);
	knapp_exp->resize(knappeBreidde, knappeBreidde);

	knapp_punktum = new QPushButton(".", this);
	knapp_punktum->move(110, 200);
	knapp_punktum->resize(knappeBreidde, knappeBreidde);

	knapp_cos = new QPushButton("cos",this);
	knapp_cos->move(230, 120);
	knapp_cos->resize(knappeBreidde, knappeBreidde);

	knapp_sin = new QPushButton("sin", this);
	knapp_sin->move(230, 160);
	knapp_sin->resize(knappeBreidde, knappeBreidde);


	knapp_0 = new QPushButton("0", this);
	knapp_0->move(30, 200);
	knapp_0->resize(knappeBreidde * 2 + 5, knappeBreidde);

	knapp_1 = new QPushButton("1", this);
	knapp_1->move(30,160);
	knapp_1->resize(35,35);

	knapp_2 = new QPushButton("2", this);
	knapp_2->move(70,160);
	knapp_2->resize(35,35);

	knapp_3 = new QPushButton("3", this);
	knapp_3->move(110,160);
	knapp_3->resize(35,35);

	knapp_4 = new QPushButton("4", this);
	knapp_4->move(30,120);
	knapp_4->resize(35,35);

	knapp_5 = new QPushButton("5", this);
	knapp_5->move(70,120);
	knapp_5->resize(35,35);

	knapp_6 = new QPushButton("6", this);
	knapp_6->move(110,120);
	knapp_6->resize(35,35);

	knapp_7 = new QPushButton("7", this);
	knapp_7->move(30,80);
	knapp_7->resize(35,35);

	knapp_8 = new QPushButton("8", this);
	knapp_8->move(70,80);
	knapp_8->resize(35,35);

	knapp_9 = new QPushButton("9", this);
	knapp_9->move(110,80);
	knapp_9->resize(35,35);

	lineEdit = new QLineEdit(this);

	lineEdit->setMaxLength(100);
	lineEdit->move(30, 30);
	lineEdit->resize(250, 50);



	m_button->move(190,160);
	m_button->resize(35, 2* 35 + 5);

       QObject::connect(m_button, SIGNAL (released()), this, SLOT (inputFerdig()));
       QObject::connect(clear_button, SIGNAL (released()), this, SLOT (slett()));
       QObject::connect(knapp_backspace, SIGNAL (released()), this, SLOT (backspace()));

       QObject::connect(lineEdit, SIGNAL (returnPressed()), this, SLOT(inputFerdig()));


       QObject::connect(knapp_0, SIGNAL (released()), this, SLOT(on_knapp0_trykt()));
       QObject::connect(knapp_1, SIGNAL (released()), this, SLOT(on_knapp1_trykt()));
       QObject::connect(knapp_2, SIGNAL (released()), this, SLOT(on_knapp2_trykt()));
       QObject::connect(knapp_3, SIGNAL (released()), this, SLOT(on_knapp3_trykt()));
       QObject::connect(knapp_4, SIGNAL (released()), this, SLOT(on_knapp4_trykt()));
       QObject::connect(knapp_5, SIGNAL (released()), this, SLOT(on_knapp5_trykt()));
       QObject::connect(knapp_6, SIGNAL (released()), this, SLOT(on_knapp6_trykt()));
       QObject::connect(knapp_7, SIGNAL (released()), this, SLOT(on_knapp7_trykt()));
       QObject::connect(knapp_8, SIGNAL (released()), this, SLOT(on_knapp8_trykt()));
       QObject::connect(knapp_9, SIGNAL (released()), this, SLOT(on_knapp9_trykt()));

       QObject::connect(knapp_pluss, SIGNAL (released()), this, SLOT(add_pluss()));
       QObject::connect(knapp_minus, SIGNAL (released()), this, SLOT(add_minus()));
       QObject::connect(knapp_mult, SIGNAL (released()), this, SLOT(add_mult()));
       QObject::connect(knapp_div, SIGNAL (released()), this, SLOT(add_div()));
       QObject::connect(knapp_punktum, SIGNAL (released()), this, SLOT(add_punktum()));
       QObject::connect(knapp_exp, SIGNAL (released()), this, SLOT(add_exp()));
       QObject::connect(knapp_cos, SIGNAL (released()), this, SLOT(add_cos()));
       QObject::connect(knapp_sin, SIGNAL (released()), this, SLOT(add_sin()));

}

void MainWindow::add_minus()
{
	lineEdit->insert("-");
}

void MainWindow::add_pluss()
{
	lineEdit->insert("+");
}

void MainWindow::add_mult()
{
	lineEdit->insert("*");
}

void MainWindow::add_div()
{
	lineEdit->insert("/");
}

void MainWindow::add_punktum()
{
	lineEdit->insert(".");
}

void MainWindow::add_exp()
{
	lineEdit->insert("^");
}

void MainWindow::add_cos()
{
	lineEdit->setText("cos " + lineEdit->text());
}

void MainWindow::add_sin()
{
	lineEdit->setText("sin " + lineEdit->text());
}

void MainWindow::add_funk(const char *input)
{
	lineEdit->insert(input);
}

void MainWindow::handleButton()
{
	m_button->setText("eksempel");
}

void MainWindow::inputFerdig()
{
	auto svar = reknut(lineEdit->text().toStdString());
	lineEdit->setText(QString::fromStdString(svar));
}

void MainWindow::slett()
{
	lineEdit->setText("");
}

void MainWindow::backspace()
{
	lineEdit->backspace();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_knapp0_trykt()
{
	lineEdit->insert("0");
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

void MainWindow::on_pushButton_clicked()
{
    lineEdit->resize(90,90);
    lineEdit->update();
}
