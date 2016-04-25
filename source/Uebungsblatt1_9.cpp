#include <iostream>
int sum35 = 0;
int main()
{	
	for (int i = 1; i > 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum35 = sum35 + i;
		else
			sum35 = sum35 + 0;
	}
	std::cout << "Die Summe betraegt" << sum35 << ".";
	return 0;
}



