#pragma once
#include <string>
#include <iostream>
using namespace std;

class Film
{
private:
	const int id;
	static string tip;
	int* rating;
	int durata;
	string nume;
	char* sala;
	int numarSpectatori;
	float pret;

public:
	//constructor implicit
	Film() :id(0)
	{
		this->sala = new char[strlen("Sala") + 1];
		strcpy_s(this->sala, strlen("Sala") + 1, "Sala");
		this->numarSpectatori = 0;
		this->pret = 0.0;
		this->durata = 0;
		this->nume = nume;
		this->rating = nullptr;
	}

	//constructor cu parametri
	Film(int* rating, string nume, const char* sala, int numarSpectatori, float pret, int durata) :id(id)
	{
		this->rating = new int[numarSpectatori];
		for (int i = 0; i < numarSpectatori; i++) {
			this->rating[i] = rating[i];
		}
		this->nume = nume;
		this->sala = new char[strlen(sala) + 1];
		strcpy_s(this->sala, strlen(sala) + 1, sala);
		this->numarSpectatori = numarSpectatori;
		this->pret = pret;
		this->durata = durata;

	}
	
	//constructor de copiere
	Film(const Film& f) :id(f.id)
	{
		this->nume = f.nume;
		this->sala = new char[strlen(f.sala) + 1];
		strcpy_s(this->sala, strlen(f.sala) + 1, f.sala);
		this->numarSpectatori = f.numarSpectatori;
		this->pret = f.pret;
		this->durata = f.durata;
		if (f.rating != nullptr && f.numarSpectatori > 0)
		{
			numarSpectatori = f.numarSpectatori;
			rating = new int[f.numarSpectatori];
			for (int i = 0; i < f.numarSpectatori; i++)
			{
				rating[i] = f.rating[i];
			}
		}
		else
		{
			rating = nullptr;
			numarSpectatori = 0;
		}
	}

	//supraincarcare operator =
	Film& operator =(const Film& f)
	{
		if (this->sala != NULL)
		{
			delete[] this->sala;
		}
		this->nume = f.nume;
		this->sala = new char[strlen(f.sala) + 1];
		strcpy_s(this->sala, strlen(f.sala) + 1, f.sala);
		this->numarSpectatori = f.numarSpectatori;
		this->pret = f.pret;
		this->durata = f.durata;
		if (rating != nullptr)
		{
			delete[] rating;
		}
		if (f.rating != nullptr && f.numarSpectatori > 0)
		{
			numarSpectatori = f.numarSpectatori;
			rating = new int[f.numarSpectatori];
			for (int i = 0; i < f.numarSpectatori; i++)
			{
				rating[i] = f.rating[i];
			}
		}
		else
		{
			rating = nullptr;
			numarSpectatori = 0;
		}
		return *this;
	}

	//destructor
	~Film()
	{
		cout << "S-a apelat destructorul!" << endl;
		if (this->sala != NULL)
		{
			delete[] this->sala;
		}
		if (rating != nullptr)
		{
			delete[] rating;
		}
	}

	//metoda Set pentru sala
	void setSala(const char* s)
	{
		if (this->sala != NULL)
		{
			delete[] this->sala;
		}
		this->sala = new char[strlen(s) + 1];
		strcpy_s(this->sala, strlen(s) + 1, s);

	}

	//metoda Set pentru rating
	void setRating(int* rating, int numarSpectatori) {
		if (rating != nullptr && numarSpectatori > 0)
		{
			this->rating = new int[numarSpectatori];
			for (int i = 0; i < numarSpectatori; i++)
			{
				this->rating[i] = rating[i];
			}
			this->numarSpectatori = numarSpectatori;
		}
		else
		{
			this->rating = nullptr;
			numarSpectatori = 0;
		}
	}

	//metoda de acces pentru rating
	int* getRating()
	{
		if (rating != nullptr)
		{
			int* copie = new int[numarSpectatori];
			for (int i = 0; i < numarSpectatori; i++)
			{
				copie[i] = rating[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	//metoda de acces pentru spectatori
	int getSpectatori()
	{
		return numarSpectatori;
	}

	//metoda de acces pentru sala
	char* getSala()
	{
		return this->sala;
	}

	//metoda de returnare a incasarilor
	float getIncasari()
	{

		int a = pret * numarSpectatori;

		return a;
	}

	//metoda Get pentru campul static
	static string getTip()
	{
		return tip;
	}

	//metoda Set pentru campul static
	static void setTip(string tip)
	{
		Film::tip = tip;
	}

	//supraincarcare operator explicit de cast la int
	explicit operator int()
	{
		return numarSpectatori;
	}

	//supraincarcare operator pentru negatie !
	bool operator !()
	{
		if (this->numarSpectatori > 0)
			return true;
		else
			return false;
	}
	//supraincarcare operator conditional >=
	bool operator >= (Film& f)
	{
		if (this->getIncasari() >= f.getIncasari())
			return true;
		else
			return false;
	}

	//supraincarcare operator pentru testarea egalitatii dintre doua obiecte ==
	bool operator==(Film f)
	{
		if (this->numarSpectatori == f.numarSpectatori)
			return true;
		else
			return false;
	}

	//supraincarcare operator ++ (preincrementare)
	Film operator++()
	{
		this->numarSpectatori++;
		return *this;
	}

	//supraincarcare operator ++ (postincrementare)
	Film operator++(int i)
	{
		Film copie = *this;
		this->numarSpectatori++;
		return copie;
	}


	//supraincarcare operator matematic +
	Film operator+(int numarBilete)
	{
		if (numarBilete < 0)
		{
			throw 500;
		}
		Film copie = *this;
		copie.numarSpectatori += numarBilete;
		return copie;
	}

	//supraincarcare operator pentru indexare []
	int& operator[](int index) throw (exception)
	{
		if (index >= 0 && index < numarSpectatori && rating != nullptr)
		{
			return rating[index];
		}
		else
		{
			throw exception("index invalid!");
		}
	}

	friend ostream& operator<<(ostream&, Film);
	friend istream& operator>>(istream&, Film&);
};


ostream& operator<<(ostream& out, Film f)
{
	out << "Numele filmului:" << f.nume << endl;
	out << "Sala unde ruleaza:" << f.sala << endl;
	out << "Numar spectatori:" << f.numarSpectatori << endl;
	out << "Pret bilet:" << f.pret << endl;
	out << "Durata filmului:" << f.durata << endl;
	out << "Id-ul filmului:" << f.id << endl;
	return out;
}

istream& operator>>(istream& in, Film& f)
{
	cout << "Nume film:" << endl;
	in >> f.nume;
	char aux[100];
	in >> aux;
	if (f.sala != NULL)
	{
		delete[] f.sala;
	}
	f.sala = new char[strlen(aux) + 1];
	strcpy_s(f.sala, strlen(aux), aux);
	cout << "Nume sala:" << endl;
	cout << "Numar spectatori:" << endl;
	in >> f.numarSpectatori;
	cout << "Pret bilet:" << endl;
	in >> f.pret;
	cout << "Durata filmului" << endl;
	in >> f.durata;
	if (f.rating != nullptr)
	{
		delete[] f.rating;
	}
	cout << "Numar spectatori: ";
	in >> f.numarSpectatori;
	if (f.numarSpectatori > 0)
	{
		f.rating = new int[f.numarSpectatori];
		for (int i = 0; i < f.numarSpectatori; i++)
		{
			cout << "rating[" << i << "] = ";
			in >> f.rating[i];
		}
	}
	else
	{
		f.numarSpectatori = 0;
		f.rating = nullptr;
	}
	return in;

}

 string Film::tip ="nothing";


