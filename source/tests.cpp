#define _USE_MATH_DEFINES
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>

//ggT berechnen	1.7
int gcd(int a, int b)
{
	a = abs(a);	//Betrag
	b = abs(b);	//Betrag
	if(b == 0)
		return a;
	else if(a == 0)
		return b;	//ggT von einer Zahl x und 0 ist x
	else
		return gcd(b, a % b);	//Euklidischer Alogrithmus

}
TEST_CASE("describe_gcd", "[gcd]")
{
	REQUIRE(gcd(2,4) == 2);
	REQUIRE(gcd(6,9) == 3);
	REQUIRE(gcd(3,7) == 1);
	REQUIRE(gcd(5,0) == 5);
	REQUIRE(gcd(0,5) == 5);
	REQUIRE(gcd(-4,-1) == 1);
}

//Quersumme ausrechnen	1.8
int checksum(int c)
{
	int Quer = 0;
	while (c > 0)
	{
	        Quer += c % 10;	//mod 10, Zahl wird durchgegangen
	        c /= 10;	//:10 um Zahl zu reduzieren
	}
	return Quer;
}
TEST_CASE("describe_checksum", "[checksum]")
{
	REQUIRE(checksum(1234) == 10);
	REQUIRE(checksum(69) == 15);
	REQUIRE(checksum(3456) == 18);
	REQUIRE(checksum(115692) == 24);
	REQUIRE(checksum(24) == 6);
}

//Zahlen addieren, die %3 %5 == 0 1.9
int sumMultiples(int z)
{
	int sum35 = 0;
	for (int i = 1; i <= z; i++)		//Zahlen von 1 bis z durchlaufen
	{
		if (i % 3 == 0 || i % 5 == 0)	//Zahl durch 3/5 teilbar?
		{			
			sum35 += i;		//Addieren
		}	
	}
	return sum35;				//Zurückgabe der Summe
}
TEST_CASE("describe_sumMultiples", "[sumMultiples]")
{
	REQUIRE(sumMultiples(10) == 33);
	REQUIRE(sumMultiples(1000) == 234168);
}

//Nachkomma-Anteil	1.10
float fract(float f)
{
	int a = f;		//Zahl casten
		return (f-a);	//Zahl ohne Kommastelle von den Zahl mit abziehen

}
TEST_CASE("describe_fact", "[fact]")
{
	REQUIRE(fract(5.65) == Approx (0.65));
	REQUIRE(fract(5.45) == Approx (0.45));
}

//Volumen eines Zylinders berechnen	1.11
double VolumenZ( double r, double h)	//Radius , Hoehe
{
	return M_PI*r*r*h;	//Formel
}
TEST_CASE("describe_VolumenZ", "[VolumenZ]")
{
	REQUIRE(VolumenZ(3 , 5 ) == Approx(141.3716694115));
	REQUIRE(VolumenZ(2.5 , 4.5) == Approx(88.357293382));
}

//Oberflaeche eines Zylinders berechnen 1.11
double OberfZ(double r, double h)
{
	return (2*M_PI*r*r + 2*M_PI*r*h);	//Formel
}
TEST_CASE("describe_OberfZ", "[OberfZ]")
{
	REQUIRE(OberfZ(3 , 5 ) == Approx(150.796447372));
	REQUIRE(OberfZ(2.5 , 4.5) == Approx(109.955742876));
}

//Meilen zu Kilometer 1.12
double MeKm(double m)
{
	return (m * 1.60934); //Verhältnis
}
TEST_CASE("describe_MeKM", "[MeKm]")
{
	REQUIRE(MeKm(50) == Approx(80.4672));
	REQUIRE(MeKm(26.863) == Approx(43.2318079));
	REQUIRE(MeKm(555) == Approx(893.186));
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}

