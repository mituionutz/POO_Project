#pragma once
#include <string>
#include <iostream>
using namespace std;

class Client
{
private:
	const int idClient;
	char* nume;
	string email;
	int nrFilme;
	int* filmeVazute;
	int anNastere;
	static int nrClienti;

public:

	// constructor implicit
Client() :idClient(nrClienti++)

	{
		this->nume = new char[strlen("NoName") + 1];
		strcpy_s(this->nume, strlen("NoName") + 1, "NoName");
		this->email = "noMail";
		this->nrFilme = 0;
		this->filmeVazute = nullptr;
		this->anNastere = 1989;
	}

//constructor cu 1 parametru
	Client(int idNouClient) :idClient(idNouClient)
	{
	this->nume = new char[strlen("NoName") + 1];
	strcpy_s(this->nume, strlen("NoName") + 1, "NoName");
	this->email = "noMail";
	this->nrFilme = 0;
	this->filmeVazute = nullptr;
	this->anNastere = 1989;
	nrClienti++;
	}

//constructor cu parametri
	Client(int idNouClient, const char* nume, string email, int nrFilme, int* filmeVazute, int anNastere) :idClient(idNouClient)
	{
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->email = email;
	this->nrFilme = nrFilme;
	this->filmeVazute = new int[nrFilme];
	for (int i = 0; i < nrFilme; i++)
	{
		this->filmeVazute[i] = filmeVazute[i];
	}
	this->anNastere = anNastere;
	nrClienti++;
	}

	//constructor de copiere
	Client(const Client& c) :idClient(c.idClient)
	{
		this->nume = new char[strlen(c.nume) + 1];
		strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);
		this->email = c.email;
		this->nrFilme = c.nrFilme;
		this->filmeVazute = new int[c.nrFilme];
		for (int i = 0; i < c.nrFilme; i++)
		{
			this->filmeVazute[i] = c.filmeVazute[i];
		}
		this->anNastere = c.anNastere;
	}

	//supraincarcare operator =
	Client& operator=(Client& c)
	{
		if (this->nume != nullptr)
			delete[] this->nume;
		if (this->filmeVazute != nullptr)
			delete[] this->filmeVazute;

		this->nume = new char[strlen(c.nume) + 1];
		strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);
		this->email = c.email;
		this->nrFilme = c.nrFilme;
		this->filmeVazute = new int[c.nrFilme];
		for (int i = 0; i < c.nrFilme; i++)
		{
			this->filmeVazute[i] = c.filmeVazute[i];
		}
		this->anNastere = c.anNastere;
		return *this;
	}

	//destructor
	~Client()
	{
		cout << "S-a apelat destructorul!" << endl;
		if (this->nume != nullptr)
			delete[] this->nume;
		if (this->filmeVazute != nullptr)
			delete[] this->filmeVazute;
	}

	//supraincarcare operator pentru indexare []
	int& operator [](int index)
	{
		return filmeVazute[index];
	}

	//supraincarcare operator matematic *
	Client operator*(int valoare)
	{
		Client copie = *this;
		copie.anNastere *= valoare;
		return copie;
	}

	//supraincarcare operator ++ (preincrementare)
	Client operator++()
	{
		this->nrFilme++;
		return *this;
	}

	//supraincarcare operator ++ (postincrementare)
	Client operator++(int i)
	{
		Client copie = *this;
		this->nrFilme++;
		return copie;
	}

	//supraincarcare operator explicit de cast la int
	explicit operator int()
	{
		return nrFilme;
	}

	//supraincarcare operator pentru negatie !
	bool operator !()
	{
		if (this->nrFilme > 0)
			return true;
		else 
			return false;
	}

	//metoda pentru calcularea numarului de filme vizionate
	int calculeazaNumarFilme()
	{
		int valoare = 0;
		for (int i = 0; i < nrFilme; i++)
		{
			valoare += filmeVazute[i];
		}
		return valoare;
	}

	//supraincarcare operator conditional >=
	bool operator >= (Client& c)
	{
		if (this->calculeazaNumarFilme() >= c.calculeazaNumarFilme())
			return true;
		else 
			return false;
	}

	//supraincarcare operator pentru testarea egalitatii dintre doua obiecte ==
	bool operator==(Client c)
	{
		if (this->nrFilme == c.nrFilme)
		{
			return true;
		}
		else
			return false;
	}

	//metoda de acces pentru campul static - obtinere valoare
	static int getNrClienti()
	{
		return nrClienti;
	}

	//metoda de acces pentru campul static - modificare valoare
	static void setNrClienti(int nrClienti)
	{
		if (nrClienti > 0) {
			Client::nrClienti = nrClienti;
		}
		else
			throw "Numarul trebuie sa fie > 0!";
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

	//metoda de acces Get pentru filme vizionate 
	int* getFilmeVazute()
	{
		return this->filmeVazute;
	}

	//metoda de acces Set pentru filfilmeVazuteme vizionate
	void setFilmeVazute(int* filmeVazute, int nrFilme)
	{
		if (this->filmeVazute != nullptr)
			delete[] this->filmeVazute;

		if (nrFilme > 0) {
			this->nrFilme = nrFilme;
			this->filmeVazute = new int[nrFilme];
			for (int i = 0; i < nrFilme; i++)
			{
				this->filmeVazute[i] = filmeVazute[i];
			}
		}
		else
			throw "Numarul de filme trebuie sa fie > 0 pentru a obtine card de fidelitate!";
	}

	//metoda Get pentru an nastere
	int getAnNastere()
	{
		return this->anNastere;
	}

	//metoda Get pentru email
	void setAnNastere(int anNastere)
	{
		this->anNastere = anNastere;
	}

	 string getEmail()
	{
		return email;
	}

	 //metoda Set pentru email
	 void setEmail(string email)
	{
		 this->email = email;
	}

	 friend ostream& operator<<(ostream&, Client);
	 friend istream& operator>>(istream&, Client&);
};

//supraincarcare operator <<
ostream& operator<<(ostream& out, Client c)
{
	out << "Id Client: " << c.idClient << endl;
	if (c.nume != nullptr)
	{
		out << "Nume: " << c.nume << endl;
	}
	out << "Filme preferate: " << c.nrFilme << endl;
	out << "Filme Vizionate: ";
	if (c.filmeVazute != nullptr && c.nrFilme > 0)
	{
		for (int i = 0; i < c.nrFilme; i++)
		{
			out << c.filmeVazute[i] << " ";
		}
	} 
	out << endl << "Email: " << c.email << endl;
	out << "An Nastere: " << c.anNastere << endl;
	return out;
}

	//supraincarcare operator >>
	istream& operator>>(istream& in, Client& c)
	{
		cout << "Nume: ";
		delete[] c.nume;
		char buffer[100];
		in >> ws;
		in.getline(buffer, 99);
		c.nume = new char[strlen(buffer) + 1];
		strcpy_s(c.nume, strlen(buffer) + 1, buffer);

		if (c.filmeVazute != nullptr)
		{
			delete[] c.filmeVazute;
		}
		cout << "Numar de filme: ";
		in >> c.nrFilme;
		if (c.nrFilme > 0)
		{
			c.filmeVazute = new int[c.nrFilme];
			for (int i = 0; i < c.nrFilme; i++)
			{
				cout << "Film[" << i << "] = ";
				in >> c.filmeVazute[i];
			}
		}
		else
		{
			c.nrFilme = 0;
			c.filmeVazute = nullptr;
		}
		cout << "Email: ";
		in >> c.email;
		cout << "An Nastere: ";
		in >> c.anNastere;
		return in;
	}

	int Client::nrClienti = 0;

