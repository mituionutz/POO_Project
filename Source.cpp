#include <iostream>
#include <string>
#include"film.h"
#include"rezervare.h"
#include"sala.h"
#include"client.h"
#include"card.h"
using namespace std;

int main()
{
	int optiune;
	while (1)
	{
		cout << "\n             CINEMA BUCURESTI\n\n";
		cout << "\n   Optiune                 Descriere";
		cout << "\n -----------------------------------------------------";
		cout << "\n     [1]    |  EMITERE BILET                         |\n";
		cout << "     [2]    |  SITUATIE LOCURI LIBERE                |\n";
		cout << "     [3]    |  SITUATIE FILME        		     |\n";
		cout << "     [4]    |  OPERATIUNI                            |\n";
		cout << "     [0]    |  INCHIDE PROGRAM                       |\n";
		cout << " ----------------------------------------------------- \n\n";
		cout << "\n Alegeti o optiune din meniu: "; 
		cin >> optiune;
		switch (optiune) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "\n Optiunea introdusa este gresita!\n";
		}
	}
	return 0;
	
 //   cout << "----------- CLASA FILM -----------" << endl;
	//int rating[] = {10};
	//Film f1;
	//Film f2 = f1;
	//Film f3(rating, "Greenland", "VIP", 17, 12.15, 90);
	//Film f4(rating, "Creed", "Terra", 1, 25.16, 105);
 //   cout << f4;
	//f1.setSala("Gold");
	//cout << f1.getSala() << endl;
	//cout << f3.getSpectatori() << endl;
	//cout <<"Incasari:"<< f3.getIncasari() << " Ron"<<endl;
	//cout << f1.getTip() << endl;
	//Film::setTip("Drama");
	//cout << f4.getTip() << endl;
	//cout << f1 << f2 << f3;
	//Film f5 = f1;
	//cout << endl;
	//cout << "----------- CLASA CLIENT -----------" << endl;
	//int filmeVazute[] = { 7 };
	//Client c1;
	//Client c2 = c1;
	//Client c3(4,"ionut","no mail",1, filmeVazute, 1952);
	//Client c4(c3);
	//cout << c3 << c4;
	//
	//
	//float vect[]{ 1100.0,700.0,2300.0,3000.0 };
	//int vector[]{ 1100, 700, 2300, 3000 };
	//float vect2[]{ 1100.0,700.0,2300.0,3000.0, 3200.0 };

	//Rezervare r1; // testare constructor implicit
	//CardFidelitate cf1; // testare constructor implicit
	//Sala s1; // testare constructor implicit

	//Rezervare r2(10); // testare constructor cu un parametru
	//CardFidelitate cf2(10); // testare constructor cu un parametru
	//Sala s2(10); // testare constructor cu un parametru

	//Rezervare r3(56, "cata", "Avengers", "01.02.2021", "20:00", 5, 4, vect); // testare constructor cu 8 parametri
	//CardFidelitate cf3(2, "Urs", "Gold", 5, vect2, 10); // testare constructor cu 6 parametri
	//Sala s3(4, "Atlantis", 4, vector, false, 3, 3, 30); // testare constructor cu 8 parametri

	//Rezervare r4 = r1; // testare constructor de copiere
	//CardFidelitate cf4 = cf1; // testare constructor de copiere
	//Sala s4 = s1; // testare constructor de copiere

	//r4 = r3; // testare operator =;
	//cf4 = cf3; // testare operator =;
	//s4 = s3; // testare operator =;

	//r4[0] = 5; // testare operator pentru indexare
	//cf4[0] = 5; // testare operator pentru indexare
	//s4[0] = 5; // testare operator pentru indexare

	//Rezervare r5 = ++r3; // testare operator++ (preincrementare)
	//Rezervare r6 = r3++; // testare operator++ (postincrementare)
	//CardFidelitate cf5 = ++cf3; // testare operator++ (preincrementare)
	//CardFidelitate cf6 = cf3++; // testare operator++ (postincrementare)
	//Sala s5 = ++s3; // testare operator++ (preincrementare)
	//Sala s6 = s3++; // testare operator++ (postincrementare)

	//Rezervare r7 = r3 + 3;  // testare operator +
	//Rezervare r8 = 4 + r3; // testare operator +
	//CardFidelitate cf7 = cf3 - 2; // testare operator -
	//CardFidelitate cf8 = 25 - cf3; // testare operator -
	//Sala s7 = s3 * 2; // testare operator *
	//Sala s8 = 3 * s3; // testare operator *

	//int bilete = r3; // testare operator implicit de cast la int
	//float vechime = cf3; // testare operator implicit de cast la float
	//float marime = s3; // testare operator implicit de cast la float

	//// testare operator pentru negatie !
	//if (!r3)
	//{
	//	cout << "Are bilete"<< endl;
	//}
	//else
	//{
	//	cout << "Nu are bilete" << endl;
	//}

	//if (!cf3)
	//{
	//	cout << "Are vechime" << endl;
	//}
	//else
	//{
	//	cout << "Nu are vechime" << endl;
	//}

	//if (!s3)	
	//{
	//	cout << "Are locuri" << endl;
	//}
	//else
	//{
	//	cout << "Nu are locuri" << endl;
	//}

	//// testare operator conditional >=
	//if (r3>=r1)
	//{
	//	cout << "Valoarea rezervarii pe numele " << r3.getNume() << " este mai mare sau egala cu valoarea rezervarii lui " << r1.getNume() << endl;
	//}
	//else
	//{
	//	cout << "Valoarea rezervarii pe numele " << r1.getNume() << " este mai mare decat valoarea rezervarii lui  " << r3.getNume() << endl;
	//}

	//if (cf3 >= cf1)
	//{
	//	cout << "Vechimea clientului cu id card " << cf3.getId() << " este mai mare sau egala cu vechimea clientului cu id card " << cf1.getId() << endl;
	//}
	//else
	//{
	//	cout << "Vechimea clientului cu id card" << cf1.getId() << " este mai mare decat vechimea clientului cu id card " << cf3.getId() << endl;
	//}

	//if (s3 >= s1)
	//{
	//	cout << "Numarul total de locuri al salii " << s3.getNume() << " este mai mare sau egala cu cel al salii " << s1.getNume() << endl;
	//}
	//else
	//{
	//	cout << "Numarul total de locuri al salii  " << s1.getNume() << " este mai mare decat cel al salii " << s3.getNume() << endl;
	//}

	//// testare operator ==
	//if (r3 == r1)
	//{
	//	cout << "Numarul de bilete este egal " << endl;
	//}
	//else
	//{
	//	cout << "Numarul de bilete nu este egal " << endl;
	//}

	//if (cf3 == cf1)
	//{
	//	cout << "Numarul de cumparaturi este egal " << endl;
	//}
	//else
	//{
	//	cout << "Numarul de cumparaturi nu este egal " << endl;
	//}

	//if (s3 == s1)
	//{
	//	cout << "Numarul de locuri este egal " << endl;
	//}
	//else
	//{
	//	cout << "Numarul de locuri nu este egal " << endl;
	//}

	//// testare operator <<
	//cout << r3 << endl << endl;
	//cout << cf3 << endl << endl;
	//cout << s3 << endl << endl;

	////testare operator >>
	//Rezervare r9;
	//cin >> r9;
	//cout << r9 << endl << endl;

	//CardFidelitate cf9;
	//cin >> cf9;
	//cout << cf9 << endl << endl;

	//Sala s9;
	//cin >> s9;
	//cout << s9 << endl << endl;
}
