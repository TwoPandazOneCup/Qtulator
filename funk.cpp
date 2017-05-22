#include "funk.h"


#define DEBUG true


std::string reknut(std::string input)
{
	std::vector<std::string> vek;


	std::cout << input;

	std::string jobbestring = "";
	std::string resultat;






	int k = 0;
	auto opArray = new char[20];

	std::cout << "provar å sette";

	if(input.find("cos ") != -1)
	{
		return getcos(input);
	}

	if(input.find("sin ") != -1)
	{
		return getsin(input);
	}




	for(auto i : input)
	{
		if(DEBUG)
			std::cout << "input = "<< i << std::endl;
		if(isdigit(i) || i == '.')
			jobbestring += i;
		else if(i == '-' && k == 0 && jobbestring == "")
			jobbestring = i + jobbestring;
		else if(!isdigit(i))
		{

			vek.push_back(jobbestring);
			if(DEBUG)std::cout <<"jobbestring = "<< jobbestring << std::endl;
			jobbestring = "";
			opArray[k] = i;
			++k;
		}
	}
	if(DEBUG)std::cout <<"jobbestring = "<< jobbestring << std::endl;
	vek.push_back(jobbestring);

		if(DEBUG)std::cout << "svar1 fo strtod = " << vek[0] <<std::endl;
	double svar1 = std::stod(vek[0], nullptr);
		if(DEBUG)std::cout << "svar1 = " << svar1 <<std::endl;
	double svar2 = std::stod(vek[1], nullptr);
		if(DEBUG)std::cout << "svar2 = " << svar2 <<std::endl;

	auto res = red(svar1, svar2, opArray);



	std::cout << res << std::endl;

	std::ostringstream strs;
	strs << res;
	resultat = strs.str();;


	return resultat;
}

double red(const double svar1, const double svar2, const char *op)
{

	switch(op[0])
	{
	case '+':
		return svar1 + svar2;
	case '-':
		return svar1 - svar2;
	case '*':
		return svar1 * svar2;
	case '/':
		return svar1 / svar2;
	case '^':
		return pow(svar1, svar2);
	}
}

std::string getcos(const std::string &input)
{
	if(DEBUG) std::cout<< "cos" <<std::endl;
	std::string substr = "";
	std::string resultat = "";
	for(int i = 4; i < input.length(); ++i)
	{
		substr += input[i];
	}
	std::cout << "cosinus til : "<< substr << std::endl;

	double cosinus = cos(std::stod(substr) * 3.14 / 180);

	std::ostringstream trs;
	trs << cosinus;
	resultat = trs.str();
	return resultat;
}
std::string getsin(const std::string &input)
{
	std::string substr = "";
	std::string resultat = "";
	for(int i = 4; i < input.length(); ++i)
	{
		substr += input[i];
	}
	std::cout << "sin til : "<< substr << std::endl;

	double sinus = sin(std::stod(substr) * 3.14 / 180);

	std::ostringstream trs;
	trs << sinus;
	resultat = trs.str();
	return resultat;
}

