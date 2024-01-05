#include <iostream>
#include "Pracownik.h"
#include "Klient.h"

using namespace std;

class Zajecia
{
	Pracownik prowadzacy;
	Klient uczestnicy[];

	string nazwa;
	string opis;
	int dataZajec;
	int czasTrwania;
	int liczbaMiejsc;
public:
	void modyfikujZajecia();

	Zajecia();
	~Zajecia();


};
