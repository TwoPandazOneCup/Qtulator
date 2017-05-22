
#define DEBUG true

#include "mainwindow.h"
#include "funk.h"
#include <QApplication>

#include <iostream>





int main(int argc, char *argv[])
{
	if(DEBUG)std::cout << "er i main " << std::endl;
	QApplication a(argc, argv);
	MainWindow w;
	if(DEBUG)
	try
	{
		w.show();
	}
	catch(...)
	{
		std::cout << "fant eit unntak" <<std::endl;
	}

	return a.exec();
}
