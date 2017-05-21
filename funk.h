
#include <string>
#include <vector>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <fstream>

std::string reknut(std::string input);

#ifndef FUNK_H
#define FUNK_H

#include <string>
#include <iterator>

class Svar{


private:
	std::string stykke;
	std::string svarResultat;
	void rekn_ut();
public:
	Svar(std::string input);
	std::string getSvar();

};


#endif // FUNK_H
