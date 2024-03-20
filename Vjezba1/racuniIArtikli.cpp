/*
Potrebno je napisati program za evidenciju računa. Primjerice, u dućanu svaki kupac ima
račun s jedinstvenim rednim brojem, a na tom računu se nalazi popis kupljenih stavki
(naziv, količina, jedinična cijena). Slijedeći programski odsječak u nastavku napišite sve
potrebne klase i metode kojima se dobije očekivano ponašanje programskog koda.

int main(){
	Kupac Ante(Racun(1)); // Ante ima račun broj 1
	Ante.racun.dodaj(Artikl("Jabuka", 1, 6)); // 1 kg, 6 kn/kg
	Ante.racun.dodaj(Artikl("Banana", 2, 7.5)); // 2 kg, 7.5 kn/kg
	Ante.racun.dodaj(Artikl("Coca cola 2l", 2, 10)); // 2 boce, 10 kn/boca
	cout << "Ukupno: " << Ante.racun.ukupnaCijena << " kn" << endl; // 41 kn
	
	// U nastavku ispišite koji je najskuplji artikl kojeg je Ante platio
	// (naziv i ukupna cijena). Npr.
	// Najskuplje placeni artikl je Coca cola 2l (20kn)
	
	return 0;
}
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Artikl {
public:
	string naziv;
	int kolicina;
	float cijena;

	Artikl(string _naziv, int _kolicina, float _cijena) : naziv(_naziv), kolicina(_kolicina), cijena(_cijena) {}
	Artikl() = default;
};

class Racun {
public:
	int redniBroj;
	vector<Artikl> kupljeneStavke;
	float ukupnaCijena = 0;

	Racun(int _redniBroj) : redniBroj(_redniBroj) {}

	void dodaj(Artikl stavka) {
		kupljeneStavke.push_back(stavka);
		ukupnaCijena += (stavka.cijena*stavka.kolicina);
	}

	Artikl najskuplji() {
		if (kupljeneStavke.size() == 0)
			return Artikl();

		Artikl stavkaNajskuplji = kupljeneStavke[0];
		float najskuplji = kupljeneStavke[0].cijena*kupljeneStavke[0].kolicina;

		for (int i = 0; i < kupljeneStavke.size(); i++) {
			if (najskuplji < (kupljeneStavke[i].cijena * kupljeneStavke[i].kolicina)) {
				stavkaNajskuplji = kupljeneStavke[i];
				najskuplji = kupljeneStavke[i].cijena * kupljeneStavke[i].kolicina;
			}
		}

		return stavkaNajskuplji;
	}
};

class Kupac {
public:
	Racun racun;

	Kupac(Racun _racun) : racun(_racun) {}
};

int main() {
	Kupac Ante(Racun(1));
	Ante.racun.dodaj(Artikl("Jabuka", 1, 6));
	Ante.racun.dodaj(Artikl("Banana", 2, 7.5));
	Ante.racun.dodaj(Artikl("Coca cola 2l", 2, 10));
	cout << "Ukupno: " << Ante.racun.ukupnaCijena << " kn" << endl;

	Artikl najskupljiArtikl = Ante.racun.najskuplji();
	cout << "Najskuplje placeni artikl je " << najskupljiArtikl.naziv << " " << "(" << najskupljiArtikl.cijena * najskupljiArtikl.kolicina << "kn)" << endl;

	return 0;
}
