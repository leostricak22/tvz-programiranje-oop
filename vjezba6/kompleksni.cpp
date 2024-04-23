/*
[VJ-6] Kompleksni broj
Neka je zadana sljedeća funkcija main. Napišite klasu Kompleksni koja u sebi ima sve
potrebne podatkovne članove i metode kako bi glavni program (funkcija main) mogla raditi
kao što je to u kodu i predviđeno.

#include <iostream>
#include "kompleksni.h"

using namespace std;

ostream& operator << (ostream& izlaz, Kompleksni Z) {
	izlaz << Z.re << ((Z.im >= 0) ? "+" : "") << Z.im << "i";
	return izlaz;
}

int main() {
	// Z1 = 1, Z2 = 2 - i
	Kompleksni Z1(1, 0), Z2(2, -1);
	// članska operatorska funkcija + (Kompleksni)
	Kompleksni Suma = Z1 + Z2;
	cout << Suma << endl; // 3 - 1i
	// članska operatorska funkcija * (Kompleksni)
	Kompleksni Umnozak = Z1 * Z2;
	cout << Umnozak << endl; // 2 - 1i
	// ne-članska operatorska funkcija - (Kompleksni, double)
	Kompleksni Razlika = Suma - 3;
	cout << Razlika << endl; // 0 - 1i
	// ne-članska operatorska funkcija - (double, Kompleksni)
	Kompleksni Razlika2 = 3 - Suma;
	cout << Razlika2 << endl; // 0 - 1i
	return 0;
}

Upute: Deklarirajte klasu Kompleksni koja kao privatne članove sadrži re i im tj. realni i
imaginarni dio kompleksnog broja. U javnom dijelu klase napišite konstruktor s dva
parametra kojim se inicijaliziraju ti podatkovni članovi, a zatim i deklaracije potrebnih
operatora (operatorskih funkcija). Deklaraciju klase, njenih metoda i friend funkcija napišite
u Kompleksni.h a tijela metoda i funkcija u Kompleksni.cpp.
Dodatni zadatak: Deklarirajte i napišite tijela postfiks i prefiks operatora ++ za klasu
Kompleksni te u funkciji main na primjeru prikažite njihovu upotrebu. Oba operatora
povećavaju imaginarni dio i realni dio kompleksnog broja za 1.
*/

#include <iostream>

using namespace std;

class Kompleksni {
public:
	double re, im;

	Kompleksni(double _re, double _im) : re(_re), im(_im) {}

	Kompleksni& operator ++() {
		++re;
		++im;
		return *this;
	}


	Kompleksni& operator ++(int) {
		re++;
		im++;
		return *this;
	}
};

ostream& operator << (ostream& izlaz, Kompleksni Z) {
	izlaz << Z.re << ((Z.im >= 0) ? "+" : "") << Z.im << "i";
	return izlaz;
}

Kompleksni operator + (const Kompleksni& Z1, const Kompleksni& Z2) {
	return Kompleksni(Z1.re + Z2.re, Z1.im + Z2.im);
}

Kompleksni operator * (const Kompleksni& Z1, const Kompleksni& Z2) {
	return Kompleksni(Z1.re * Z2.re - Z1.im * Z2.im, Z1.re * Z2.im - Z1.im * Z2.re);
}

Kompleksni operator - (const Kompleksni& Z, const double re) {
	return Kompleksni(Z.re - re, Z.im);
}

Kompleksni operator - (const double re, const Kompleksni& Z) {
	return Kompleksni(re - Z.re, Z.im);
}

int main() {
	// Z1 = 1, Z2 = 2 - i 
	Kompleksni Z1(1, 0), Z2(2, -1);

	// članska operatorska funkcija + (Kompleksni)
	Kompleksni Suma = Z1 + Z2;
	cout << Suma << endl; // 3 - 1i

	// članska operatorska funkcija * (Kompleksni)
	Kompleksni Umnozak = Z1 * Z2;
	cout << Umnozak << endl; // 2 - 1i

	// ne-članska operatorska funkcija - (Kompleksni, double)
	Kompleksni Razlika = Suma - 3;
	cout << Razlika << endl; // 0 - 1i

	// ne-članska operatorska funkcija - (double, Kompleksni)
	Kompleksni Razlika2 = 3 - Suma;
	cout << Razlika2 << endl; // 0 - 1i

	// prefiks ++
	cout << ++Razlika2 << endl;

	// postfiks ++
	cout << Razlika2++ << endl;

	return 0;
}
