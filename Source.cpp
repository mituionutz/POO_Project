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
    cout << "----------- CLASA FILM -----------" << endl;
	int rating[] = {10};
	//Film f1;
	//Film f2 = f1;
 //   Film f3(rating, "Greenland", "VIP", 17, 12.15, 90);
	Film f4( "Creed", "Terra", 1, rating, 25.16, 105);
    cout <<f4;
	//f1.setSala("Gold");
	//cout << f1.getSala() << endl;
	//cout << f3.getSpectatori() << endl;
	//cout <<"Incasari:"<< f3.getIncasari() << " Ron"<<endl;
	//cout << f1.getTip() << endl;
	//Film::setTip("Drama");
	//cout << f4.getTip() << endl;
	////cout << f1 << f2 << f3;
	//Film f5 = f1;
	//cout << endl;
	cout << "----------- CLASA CLIENT -----------" << endl;
	int filmeVazute[] = { 7 };
	Client c1;
	Client c2 = c1;
	Client c3(4,"ionut","no mail",1, filmeVazute, 1952);
	Client c4(c3);
	cout << c3 << c4;
	
	
}
