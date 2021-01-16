#pragma once
#include <string>
using namespace std;

class Sala {
private:
	const int idSala;
	char* nume;
	int nrLocuri;
	int* locuri;
	bool sunetDolby;
	int iesiriUrgenta;
	int scauneVip;
	float marimeEcran;

public:
	static string tipCinema;
	static int nrSali;

	//constructor implicit
	Sala() :idSala(nrSali++)
	{
		this->nume = new char[strlen("N/A") + 1];
		strcpy_s(this->nume, 1, "N/A");
		this->nrLocuri = 0;
		this->locuri = nullptr;
		this->sunetDolby = false;
		this->iesiriUrgenta = 0;
		this->scauneVip = 0;
		this->marimeEcran = 0;
	}

	//constructor cu 1 parametru
	Sala(int idNouSala) :idSala(idNouSala)
	{
		this->nume = new char[strlen("N/A") + 1];
		strcpy_s(this->nume, 1, "N/A");
		this->nrLocuri = 0;
		this->locuri = nullptr;
		this->sunetDolby = false;
		this->iesiriUrgenta = 0;
		this->scauneVip = 0;
		this->marimeEcran = 0;
		nrSali++;
	}

	//constructor cu 8 parametri
	Sala(int idNouSala, char* nume, int nrLocuri, int* locuri, bool sunetDolby, int iesiriUrgenta, int scauneVip, float marimeEcran) :idSala(idNouSala)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->nrLocuri = nrLocuri;
		this->locuri = new int[nrLocuri];
		for (int i = 0; i < nrLocuri; i++)
		{
			this->locuri[i] = locuri[i];
		}
		this->sunetDolby = sunetDolby;
		this->iesiriUrgenta = iesiriUrgenta;
		this->scauneVip = scauneVip;
		this->marimeEcran = marimeEcran;
		nrSali++;
	}

	//constructor de copiere
	Sala(const Sala& s) :idSala(s.idSala)
	{
		this->nume = new char[strlen(s.nume) + 1];
		strcpy_s(this->nume, strlen(s.nume) + 1, s.nume);
		this->nrLocuri = s.nrLocuri;
		this->locuri = new int[s.nrLocuri];
		for (int i = 0; i < s.nrLocuri; i++)
		{
			this->locuri[i] = s.locuri[i];
		}
		this->sunetDolby = s.sunetDolby;
		this->iesiriUrgenta = s.iesiriUrgenta;
		this->scauneVip = s.scauneVip;
		this->marimeEcran = s.marimeEcran;
	}

	//destructor
	~Sala()
	{
		if (this->nume != nullptr)
			delete[] this->nume;
		if (this->locuri != nullptr)
			delete[] this->locuri;
	}

	//supraincarcare operator =
	Sala& operator=(Sala& s)
	{
		if (this->nume != nullptr)
			delete[] this->nume;
		if (this->locuri != nullptr)
			delete[] this->locuri;
		this->nume = new char[strlen(s.nume) + 1];
		strcpy_s(this->nume, strlen(s.nume) + 1, s.nume);
		this->nrLocuri = s.nrLocuri;
		this->locuri = new int[s.nrLocuri];
		for (int i = 0; i < s.nrLocuri; i++)
		{
			this->locuri[i] = s.locuri[i];
		}
		this->sunetDolby = s.sunetDolby;
		this->iesiriUrgenta = s.iesiriUrgenta;
		this->scauneVip = s.scauneVip;
		this->marimeEcran = s.marimeEcran;
		return *this;
	}

	//supraincarcare operator pentru indexare []
	int& operator [](int index)
	{
		return locuri[index];
	}

	//supraincarcare operator matematic *
	Sala operator*(float value) 
	{
		Sala copie = *this;
		copie.marimeEcran *= value;
		return copie;
	}

	//supraincarcare operator ++ (preincrementare)
	Sala operator++()
	{
		this->scauneVip++;
		return *this;
	}

	//supraincarcare operator ++ (postincrementare)
	Sala operator++(int i)
	{
		Sala copie = *this;
		this->scauneVip++;
		return copie;
	}

	//supraincarcare operator implicit de cast la float
	operator float()
	{
		return marimeEcran;
	}

	//supraincarcare operator pentru negatie !
	bool operator !()
	{
		if (this->nrLocuri > 0)
			return true;
		else return false;
	}

	//metoda pentru calcularea numarului total de locuri ocupate
	int calculeazaNumarTotalLocuri()
	{
		int valoare = 0;
		for (int i = 0; i < nrLocuri; i++)
		{
			valoare += locuri[i];
		}
		return valoare;
	}

	//supraincarcare operator conditional >=
	bool operator >= (Sala& s)
	{
		if (this->calculeazaNumarTotalLocuri() >= s.calculeazaNumarTotalLocuri())
			return true;
		else return false;
	}

	//supraincarcare operator pentru testarea egalitatii dintre doua obiecte ==
	bool operator==(Sala s)
	{
		if (this->nrLocuri == s.nrLocuri)
		{
			return true;
		}
		else
			return false;
	}

	//metoda de acces pentru campul static - obtinere valoare
	static int getNrSali()
	{
		return nrSali;
	}

	//metoda de acces pentru campul static - modificare valoare
	static void setNrSali(int nrSali)
	{
		if (nrSali > 0) {
			Sala::nrSali = nrSali;
		}
		else
			throw "Numarul trebuie sa fie mai mare de zero!";
	}

	//metoda de acces pentru nume - obtinere valoare
	char* getNume()
	{
		return nume;
	}

	//metoda de acces pentru nume - modificare valoare
	void setNume(char* nume)
	{
		if (this->nume != nullptr)
		{
			delete[] this->nume;
		}
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}

	//metoda de acces pentru locuri - obtinere valoare
	int* getLocuri()
	{
		return this->locuri;
	}

	//metoda de acces pentru locuri - modificare valoare
	void setLocuri(int* locuri, int nrLocuri)
	{
		if (this->locuri != nullptr)
			delete[] this->locuri;
		if (nrLocuri > 0) {
			this->nrLocuri = nrLocuri;
			this->locuri = new int[nrLocuri];
			for (int i = 0; i < nrLocuri; i++)
			{
				this->locuri[i] = locuri[i];
			}
		}
		else
			throw "Numarul de locuri trebuie sa fie mai mare de zero!";
	}

	//metoda de acces pentru sunet Dolby - obtinere valoare
	bool GetSunetDolby() 
	{
		return this->sunetDolby;
	}

	//metoda de acces pentru sunet Dolby - modificare valoare
	void setSunetDolby(bool sunetDolby)
	{
		this->sunetDolby = sunetDolby;
	}

	//metoda de acces pentru iesiri de urgenta - obtinere valoare
	int getIesiriUrgenta()
	{
		return this->iesiriUrgenta;
	}

	//metoda de acces pentru iesiri de urgenta - modificare valoare
	void setIesiriUrgenta(int iesiriUrgenta) 
	{
		if (iesiriUrgenta > 0 && iesiriUrgenta < 10) {
			this->iesiriUrgenta = iesiriUrgenta;
		}
		else 
			throw "Numarul este incorect! trebuie sa fie intre 1 si 10";
	}

	//metoda de acces pentru scaune VIP - obtinere valoare
	int getScauneVip()
	{
		return this->scauneVip;
	}

	//metoda de acces pentru scaune VIP - modificare valoare
	void setScauneVip(int scauneVip)
	{
		if (scauneVip > 0 && scauneVip < 20) {
			this->scauneVip = scauneVip;
		}
		else
			throw "Numarul este incorect! trebuie sa fie intre 1 si 20";
	}

	//metoda de acces pentru marime ecran - obtinere valoare
	float getMarimeEcran()
	{
		return this->marimeEcran;
	}

	//metoda de acces pentru marime ecran - modificare valoare
	void setMarimeEcran(float marimeEcran)
	{
		if (marimeEcran > 0 && marimeEcran < 40) {
			this->marimeEcran = marimeEcran;
		}
		else
			throw "Numarul este incorect! trebuie sa fie intre 1m si 40m";
	}
	
	friend ostream& operator<<(ostream&, Sala);
	friend istream& operator>>(istream&, Sala&);
};

//supraincarcare operator <<
ostream& operator<<(ostream& out, Sala s)
{
	out << "Id Sala: " << s.idSala << endl;
	if (s.nume != nullptr)
	{
		out << "Nume: " << s.nume << endl;
	}
	out << "Numar locuri: " << s.nrLocuri << endl;
	out << "Loc:";
	if (s.locuri != nullptr && s.nrLocuri > 0)
	{
		for (int i = 0; i < s.nrLocuri; i++)
		{
			out << s.locuri[i] << " ";
		}
	}
	out << "Sunet Dolby: ";
	if (s.GetSunetDolby() == true)
	{
		out << "Da ";
	}
	else 
		out << "Nu ";
	out << "Iesiri urgenta: " << s.iesiriUrgenta << endl;
	out << "Scaune VIP: " << s.scauneVip << endl;
	out << "Marime ecran: " << s.marimeEcran << endl;
	return out;
}

//supraincarcare operator >>
istream& operator>>(istream& in, Sala& s)
{
	cout << "Nume: ";
	delete[] s.nume;
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);
	s.nume = new char[strlen(buffer) + 1];
	strcpy_s(s.nume, strlen(buffer) + 1, buffer);

	if (s.locuri != nullptr)
	{
		delete[] s.locuri;
	}
	cout << "Numar de locuri: ";
	in >> s.nrLocuri;
	if (s.nrLocuri > 0)
	{
		s.locuri = new int[s.nrLocuri];
		for (int i = 0; i < s.nrLocuri; i++)
		{
			cout << "Loc[" << i << "] = ";
			in >> s.locuri[i];
		}
	}
	else
	{
		s.nrLocuri = 0;
		s.locuri = nullptr;
	}
	cout << "Iesiri urgenta: ";
	in >> s.iesiriUrgenta;
	cout << "Scaune VIP: ";
	in >> s.scauneVip;
	cout << "Marime ecran: ";
	in >> s.marimeEcran;
	return in;
}

string Sala::tipCinema = "IMAX";