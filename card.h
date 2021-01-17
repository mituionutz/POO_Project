#pragma once
#include <string>
using namespace std;

class CardFidelitate {
private:
	const int idCard;
	char* tipCard;
	string descriere;
	int nrCumparaturi;
	float* cumparaturi;
	float vechimeClient;
public:
	static int nrCarduri;

	//constructor implicit
	CardFidelitate() :idCard(nrCarduri++)
	{
		this->tipCard = new char[strlen("N/A") + 1];
		strcpy_s(this->tipCard, 4, "N/A");
		this->descriere = "";
		this->nrCumparaturi = 0;
		this->cumparaturi = nullptr;
		this->vechimeClient = 0;
	}

	//constructor cu 1 parametru
	CardFidelitate(int idNouCard) :idCard(idNouCard)
	{
		this->tipCard = new char[strlen("N/A") + 1];
		strcpy_s(this->tipCard, 4, "N/A");
		this->descriere = "";
		this->nrCumparaturi = 0;
		this->cumparaturi = nullptr;
		this->vechimeClient = 0;
		nrCarduri++;
	}

	//constructor cu 6 parametri
	CardFidelitate(int idNouCard, const char* tipCard, string descriere, int nrCumparaturi, float* cumparaturi, float vechimeClient) :idCard(idNouCard)
	{
		this->tipCard = new char[strlen(tipCard) + 1];
		strcpy_s(this->tipCard, strlen(tipCard) + 1, tipCard);
		this->descriere = descriere;
		this->nrCumparaturi = nrCumparaturi;
		this->cumparaturi = new float[nrCumparaturi];
		for (int i = 0; i < nrCumparaturi; i++)
		{
			this->cumparaturi[i] = cumparaturi[i];
		}
		this->vechimeClient = vechimeClient;
		nrCarduri++;
	}

	//constructor de copiere
	CardFidelitate(const CardFidelitate& cf) :idCard(cf.idCard)
	{
		this->tipCard = new char[strlen(cf.tipCard) + 1];
		strcpy_s(this->tipCard, strlen(cf.tipCard) + 1, cf.tipCard);
		this->descriere = cf.descriere;
		this->nrCumparaturi = cf.nrCumparaturi;
		this->cumparaturi = new float[cf.nrCumparaturi];
		for (int i = 0; i < cf.nrCumparaturi; i++)
		{
			this->cumparaturi[i] = cf.cumparaturi[i];
		}
		this->vechimeClient = cf.vechimeClient;
	}

	//destructor
	~CardFidelitate()
	{
		if (this->tipCard != nullptr)
			delete[] this->tipCard;
		if (this->cumparaturi != nullptr)
			delete[] this->cumparaturi;
	}

	//supraincarcare operator=
	CardFidelitate& operator=(CardFidelitate& cf)
	{
		if (this->tipCard != nullptr)
			delete[] this->tipCard;
		if (this->cumparaturi != nullptr)
			delete[] this->cumparaturi;
		this->tipCard = new char[strlen(cf.tipCard) + 1];
		strcpy_s(this->tipCard, strlen(cf.tipCard) + 1, cf.tipCard);
		this->descriere = cf.descriere;
		this->nrCumparaturi = cf.nrCumparaturi;
		this->cumparaturi = new float[cf.nrCumparaturi];
		for (int i = 0; i < cf.nrCumparaturi; i++)
		{
			this->cumparaturi[i] = cf.cumparaturi[i];
		}
		this->vechimeClient = cf.vechimeClient;
		return *this;
	}

	//supraincarcare operator pentru indexare []
	float& operator [](int index)
	{
		return cumparaturi[index];
	}

	//supraincarcare operator matematic -
	CardFidelitate operator-(int value)
	{
		if (value < 0)
		{
			throw 500;
		}
		CardFidelitate copie = *this;
		copie.vechimeClient -= value;
		return copie;
	}

	//supraincarcare operator ++ (preincrementare)
	CardFidelitate operator++()
	{
		this->vechimeClient++;
		return *this;
	}

	//supraincarcare operator ++ (postincrementare)
	CardFidelitate operator++(int i)
	{
		CardFidelitate copie = *this;
		this->vechimeClient++;
		return copie;
	}

	//supraincarcare operator implicit de cast la float
	operator float()
	{
		return vechimeClient;
	}

	//supraincarcare operator pentru negatie !
	bool operator !()
	{
		if (this->vechimeClient > 0)
			return true;
		else return false;
	}

	//supraincarcare operator conditional >=
	bool operator >= (CardFidelitate& cf)
	{
		if (this->vechimeClient >= cf.vechimeClient)
			return true;
		else return false;
	}

	//supraincarcare operator pentru testarea egalitatii dintre doua obiecte ==
	bool operator==(CardFidelitate cf)
	{
		if (this->nrCumparaturi == cf.nrCumparaturi)
		{
			return true;
		}
		else
			return false;
	}

	//metoda de acces pentru campul static - obtinere valoare
	static int getNrCarduri()
	{
		return nrCarduri;
	}

	//metoda de acces pentru campul static - modificare valoare
	static void setNrCarduri(int nrCarduri)
	{
		if (nrCarduri > 0) {
			CardFidelitate::nrCarduri = nrCarduri;
		}
		else
			throw "Numarul trebuie sa fie mai mare de zero!";
	}

	//metoda de acces pentru Id - obtinere valoare
	int getId()
	{
		return idCard;
	}

	//metoda de acces pentru tip card - obtinere valoare
	char* getTipCard()
	{
		return tipCard;
	}

	//metoda de acces pentru tip card - modificare valoare
	void setTipCard(char* tipCard)
	{
		if (this->tipCard != nullptr)
		{
			delete[] this->tipCard;
		}
		this->tipCard = new char[strlen(tipCard) + 1];
		strcpy_s(this->tipCard, strlen(tipCard) + 1, tipCard);
	}

	//metoda de acces pentru descriere - obtinere valoare
	string getDescriere()
	{
		return this->descriere;
	}

	//metoda de acces pentru descriere - modificare valoare
	void setDescriere(string descriere)
	{
		if (descriere.length() > 0)
		{
			this->descriere = descriere;
		}
	}

	//metoda de acces pentru cumparaturi - obtinere valoare
	float* getCumparaturi()
	{
		return this->cumparaturi;
	}

	//metoda de acces pentru cumparaturi - modificare valoare
	void setCumparaturi(float* cumparaturi, int nrCumparaturi)
	{
		if (this->cumparaturi != nullptr)
			delete[] this->cumparaturi;
		if (nrCumparaturi > 0) {
			this->nrCumparaturi = nrCumparaturi;
			this->cumparaturi = new float[nrCumparaturi];
			for (int i = 0; i < nrCumparaturi; i++)
			{
				this->cumparaturi[i] = cumparaturi[i];
			}
		}
		else
			throw "Numarul de cumparaturi trebuie sa fie mai mare de zero!";
	}

	//metoda de acces pentru vechime client - obtinere valoare
	float getVechimeClient()
	{
		return this->vechimeClient;
	}

	//metoda de acces pentru vechime client - modificare valoare
	void setVechimeClient(float vechimeClient)
	{
		if (vechimeClient > 0 && vechimeClient < 10) {
			this->vechimeClient = vechimeClient;
		}
		else
			throw "Numarul este incorect! trebuie sa fie intre 1 si 10";
	}

	friend ostream& operator<<(ostream&, CardFidelitate);
	friend istream& operator>>(istream&, CardFidelitate&);
	friend CardFidelitate operator-(int, CardFidelitate);
};

//supraincarcare operator <<
ostream& operator<<(ostream& out, CardFidelitate cf)
{
	out << "Id Card: " << cf.idCard << endl;
	if (cf.tipCard != nullptr)
	{
		out << "Tipul cardului: " << cf.tipCard << endl;
	}
	out << "Descriere: " << cf.descriere << endl;
	out << "Cumparaturi:";
	if (cf.cumparaturi != nullptr && cf.nrCumparaturi > 0)
	{
		for (int i = 0; i < cf.nrCumparaturi; i++)
		{
			out << cf.cumparaturi[i] << " ";
		}
		out << endl;
	}
	out << "Vechime client: " << cf.vechimeClient << endl;
	return out;
}

//supraincarcare operator >>
istream& operator>>(istream& in, CardFidelitate& cf)
{
	cout << "Tip card: ";
	delete[] cf.tipCard;
	char buffer[100];
	in >> ws;
	in.getline(buffer, 99);
	cf.tipCard = new char[strlen(buffer) + 1];
	strcpy_s(cf.tipCard, strlen(buffer) + 1, buffer);

	if (cf.cumparaturi != nullptr)
	{
		delete[] cf.cumparaturi;
	}
	cout << "Numar de cumparaturi: ";
	in >> cf.nrCumparaturi;
	if (cf.nrCumparaturi > 0)
	{
		cf.cumparaturi = new float[cf.nrCumparaturi];
		for (int i = 0; i < cf.nrCumparaturi; i++)
		{
			cout << "Cumparatura[" << i << "] = ";
			in >> cf.cumparaturi[i];
		}
	}
	else
	{
		cf.nrCumparaturi = 0;
		cf.cumparaturi = nullptr;
	}
	cout << "Vechime client: ";
	in >> cf.vechimeClient;
	return in;
}

//supraincarcare operator matematic - (comutativitate)
CardFidelitate operator-(int value, CardFidelitate cf)
{
	cf.vechimeClient = value - cf.vechimeClient;
	return cf;
}

int CardFidelitate::nrCarduri = 0;