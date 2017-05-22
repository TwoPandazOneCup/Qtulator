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
		if(isdigit(i))
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
	vek.push_back(jobbestring);


	double svar1 = atoi(vek[0].c_str());
	double svar2 = atoi(vek[1].c_str());

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
	}
}
