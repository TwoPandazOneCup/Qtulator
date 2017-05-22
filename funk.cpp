#include "funk.h"


#define DEBUG false


std::string reknut(std::string input)
{
	std::vector<std::string> vek;


	std::cout << input;

	std::string jobbestring = "";





	int k = 0;
	auto opArray = new char[20];

	std::cout << "provar å sette";


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
	std::string resultat = strs.str();;


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
