#include "funk.h"

<<<<<<< HEAD
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
		if(!isdigit(i))
		{

			vek.push_back(jobbestring);
			if(DEBUG)std::cout <<"jobbestring = "<< jobbestring << std::endl;
			jobbestring = "";
			opArray[k] = i;
			++k;
		}
	}
	vek.push_back(jobbestring);


	double res = atoi(vek[0].c_str()) + atoi(vek[1].c_str());

	std::cout << res << std::endl;

	std::ostringstream strs;
	strs << res;
	std::string resultat = strs.str();


	return resultat;
=======
Svar::Svar(std::string input)
{
	stykke = input;
	rekn_ut();
}

void Svar::rekn_ut()
{
	std::string tal_1 = "";
	std::string tal_2 = "";

	char op;

	int stykkeNr = 1;


	for(auto i : stykke)
	{
		if(i != '+' && i != '-' && stykkeNr == 1)
			tal_1 += i;

		if(i != '+' && i != '-' && stykkeNr == 2)
			tal_2 += i;

		if(i == '+' || i == '-')
			op = i;
	}
}
std::string Svar::getSvar();
{
	return svarResultat;
>>>>>>> c085935271eb61b72f1a7ca9eaa75af888a3cec3
}
