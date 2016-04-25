#include <iostream>
#include <string>
using namespace std;

int main()
{
	double meilen;
	std::cout << "Bitte geben sie die Meilen an" << std:: endl;
	std::cin >> meilen;
	double km = meilen * 1.60934;
	std::cout << meilen <<" Meilen sind " << km << " Kilometer."<< std::endl;

	return 0;
}
	


