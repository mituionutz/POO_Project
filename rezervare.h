#pragma once
#include <string>
using namespace std;

class Rezervare {
private:
	const int id;
	char* nume;
	char* film;
	string data;
	string ora;
	int nrSala;
	int nrBilete;
	float* pret;
public:
	static int nrRezervari;

	//constructor implicit
	Rezervare() :id(nrRezervari++)
	{
		this->nume = new char[strlen("N/A") + 1];
		strcpy_s(this->nume, 4, "N/A");
		this->film = new char[strlen("N/A") + 1];
		strcpy_s(this->film, 4, "N/A");
		this->data = "01.01.2000";
		this->ora = "00:00";
		this->nrSala = 0;
		this->nrBilete = 0;
		this->pret = nullptr;
	}

	//constructor cu 1 parametru
	Rezervare(int idNou) :id(idNou)
	{
		this->nume = new char[strlen("N/A") + 1];
		strcpy_s(this->nume, 4, "N/A");
		this->film = new char[strlen("N/A") + 1];
		strcpy_s(this->film, 4, "N/A");
		this->data = "01.01.2000";
		this->ora = "00:00";
		this->nrSala = 0;
		this->nrBilete = 0;
		this->pret = nullptr;
		nrRezervari++;
	}

	//constructor cu 8 parametri
	Rezervare(int idNou, const char* nume, const char* film, string data, string ora, int nrSala, int nrBilete, float* pret) :id(idNou)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->film = new char[strlen(film) + 1];
		strcpy_s(this->film, strlen(film) + 1, film);
		this->data = data;
		this->ora = ora;
		this->nrSala = nrSala;
		this->nrBilete = nrBilete;
		this->pret = new float[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			this->pret[i] = pret[i];
		}
		nrRezervari++;
	}

	//constructor de copiere
	Rezervare(const Rezervare& r) :id(r.id)
	{
		this->nume = new char[strlen(r.nume) + 1];
		strcpy_s(this->nume, strlen(r.nume) + 1, r.nume);
		this->film = new char[strlen(r.film) + 1];
		strcpy_s(this->film, strlen(r.film) + 1, r.film);
		this->data = r.data;
		this->ora = r.ora;
		this->nrSala = r.nrSala;
		this->nrBilete = r.nrBilete;
		this->pret = new float[r.nrBilete];
		for (int i = 0; i < r.nrBilete; i++)
		{
			this->pret[i] = r.pret[i];
		}
	}

	//supraincarcare operator=
	Rezervare& operator=(Rezervare& r)
	{
		if (this->nume != nullptr)
			delete[] this->nume;
		if (this->film != nullptr)
			delete[] this->film;
		if (this->pret != nullptr)
			delete[] this->pret;
		this->nume = new char[strlen(r.nume) + 1];
		strcpy_s(this->nume, strlen(r.nume) + 1, r.nume);
		this->film = new char[strlen(r.film) + 1];
		strcpy_s(this->film, strlen(r.film) + 1, r.film);
		this->data = r.data;
		this->ora = r.ora;
		this->nrSala = r.nrSala;
		this->nrBilete = r.nrBilete;
		this->pret = new float[r.nrBilete];
		for (int i = 0; i < r.nrBilete; i++)
		{
			this->pret[i] = r.pret[i];
		}
		return *this;
	}

	//destructor
	~Rezervare()
	{
		if (this->nume != nullptr)
			delete[] this->nume;
		if (this->film != nullptr)
			delete[] this->film;
		if (this->pret != nullptr)
			delete[] this->pret;
	}

	//metoda pentru calcularea valorii rezervarii
	float calculeazaValoareRezervare()
	{
		float valoare = 0;
		for (int i = 0; i < nrBilete; i++)
		{
			valoare += pret[i];
		}
		return valoare;
	}

	//supraincarcare operator pentru indexare []
	float& operator [](int index)
	{
		return pret[index];
	}

	//supraincarcare operator matematic +
	Rezervare operator+(int value)
	{
		if (value < 0)
		{
			throw 500;
		}
		Rezervare copie = *this;
		copie.nrSala += value;
		return copie;
	}

	//supraincarcare operator ++ (preincrementare)
	Rezervare operator++()
	{
		this->nrSala++;
		return *this;
	}

	//supraincarcare operator ++ (postincrementare)
	Rezervare operator++(int i)
	{
		Rezervare copie = *this;
		this->nrSala++;
		return copie;
	}

	//supraincarcare operator implicit de cast la int
	operator int()
	{
		return nrBilete;
	}

	//supraincarcare operator pentru negatie !
	bool operator !()
	{
		if (this->nrBilete > 0)
			return true;
		else return false;
	}

	//supraincarcare operator conditional >=
	bool operator >= (Rezervare& r)
	{
		if (this->calculeazaValoareRezervare() >= r.calculeazaValoareRezervare())
			return true;
		else return false;
	}

	//supraincarcare operator pentru testarea egalitatii dintre doua obiecte ==
	bool operator==(Rezervare r)
	{
		if (this->nrBilete == r.nrBilete)
		{
			return true;
		}
		else
			return false;
	}

	//metoda de acces pentru campul static - obtinere valoare
	static int getNrRezervari()
	{
		return nrRezervari;
	}

	//metoda de acces pentru campul static - modificare valoare
	static void setNrRezervari(int nrRezervari)
	{
		if (nrRezervari > 0) {
			Rezervare::nrRezervari = nrRezervari;
		}
		else
			throw "Numarul trebuie sa fie mai mare de zero!";
	}

	//metoda de acces pentru pret - obtinere valoare
	float* getPret()
	{
		return this->pret;
	}

	//metoda de acces pentru pret - modificare valoare
	void setPret(float* pret, int nrBilete)
	{
		if (this->pret != nullptr)
			delete[] this->pret;
		if (nrBilete > 0) {
			this->nrBilete = nrBilete;
			this->pret = new float[nrBilete];
			for (int i = 0; i < nrBilete; i++)
			{
				this->pret[i] = pret[i];
			}
		}
		else
			throw "Numarul de bilete trebuie sa fie mai mare de zero!";
	}

	//metoda de acces pentru data - obtinere valoare
	string getData()
	{
		return data;
	}

	//metoda de acces pentru data - modificare valoare
	void setData(string data)
	{
		if (data.length() > 0)
		{
			this->data = data;
		}
	}

	//metoda de acces pentru ora - obtinere valoare
	string getOra()
	{
		return ora;
	}

	//metoda de acces pentru ora - modificare valoare
	void setOra(string ora)
	{
		if (ora.length() > 0)
		{
			this->ora = ora;
		}
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

	//metoda de acces pentru film - obtinere valoare
	char* getFilm()
	{
		return film;
	}

	//metoda de acces pentru film - modificare valoare
	void setFilm(char* film)
	{
		if (this->film != nullptr)
		{
			delete[] this->film;
		}
		this->film = new char[strlen(film) + 1];
		strcpy_s(this->film, strlen(film) + 1, film);
	}

	friend ostream& operator<<(ostream&, Rezervare);
	friend istream& operator>>(istream&, Rezervare&);
	friend Rezervare operator+(int, Rezervare);

};

//supraincarcare operator <<
ostream& operator<<(ostream& out, Rezervare r)
{
	out << "Id: " << r.id << endl;
	if (r.nume != nullptr)
	{
		out << "Nume: " << r.nume << endl;
	}
	if (r.film != nullptr)
	{
		out << "Film: " << r.film << endl;
	}
	out << "Data: " << r.data << endl;
	out << "Ora: " << r.ora << endl;
	out << "Numar sala: " << r.nrSala << endl;
	out << "Numar bilete: " << r.nrBilete << endl;
	out << "Pret per bilet:";
	if (r.pret != nullptr && r.nrBilete > 0)
	{
		for (int i = 0; i < r.nrBilete; i++)
		{
			out << r.pret[i] << " ";
		}
	}
	return out;
}

//supraincarcare operator >>
istream& operator>>(istream& in, Rezervare& r)
{
	cout << "Nume: ";
	delete[] r.nume;
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);
	r.nume = new char[strlen(buffer) + 1];
	strcpy_s(r.nume, strlen(buffer) + 1, buffer);

	cout << "Film: ";
	delete[] r.film;
	char buffer2[100];
	in >> ws;
	in.getline(buffer2, 99);
	r.film = new char[strlen(buffer2) + 1];
	strcpy_s(r.film, strlen(buffer2) + 1, buffer2);

	cout << "Data: ";
	in >> ws;
	getline(in, r.data);

	cout << "Ora: ";
	in >> ws;
	getline(in, r.ora);

	cout << "Numar sala: ";
	in >> r.nrSala;

	if (r.pret != nullptr)
	{
		delete[] r.pret;
	}
	cout << "Numar de bilete: ";
	in >> r.nrBilete;
	if (r.nrBilete > 0)
	{
		r.pret = new float[r.nrBilete];
		for (int i = 0; i < r.nrBilete; i++)
		{
			cout << "pretBilet[" << i << "] = ";
			in >> r.pret[i];
		}
	}
	else
	{
		r.nrBilete = 0;
		r.pret = nullptr;
	}
	return in;
}

//supraincarcare operator matematic + (comutativitate)
Rezervare operator+(int value, Rezervare r)
{
	r.nrSala += value;
	return r;
}

int Rezervare::nrRezervari = 1;
