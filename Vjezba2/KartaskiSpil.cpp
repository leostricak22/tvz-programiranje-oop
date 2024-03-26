/*
[VJ-2] Kartaški špil
U kartaškom špilu se nalaze 52 karte a svaka od karti je označena brojem 1-52. Napišite
program koji će za N igrača (N <= 13) podijeliti po 4 karte iz kartaškog špila. Prilikom
kreiranja kartaškog špila sve karte mogu biti poredane po redu (1-52) ili izmiješane
slučajnim redoslijedom (random_shuffle, zaglavlje algorithm).

Na početku programa potrebno je unijeti N igrača te kreirati novi (izmiješani) špil karata.
Upotrebom metode void Spil::Podijeli4Karte(Igrac *igrac) svakom od igrača treba podijeliti
po 4 karte sa vrha špila. Svaki igrač ima svoje ime te popis karti koje su mu podijeljene.
Program treba ispisati karte koje su podijeljene svakom od igrača a zatim i karte koje su
ostale u špilu.

Primjer izvođenja (izmiješani špil karata):
Unesi broj igraca: 2
Unesi ime 1.igraca: Ante
Unesi ime 2.igraca: Ivica
Karte u spilu (52):
10 7 5 6 4 41 26 8 31 42
2 33 47 37 14 16 51 35 24 38
18 25 21 36 11 49 52 29 45 13
19 44 43 32 12 3 30 17 34 9
40 22 1 20 27 39 15 46 50 23
48 28
Ante je dobio sljedece karte: 10 7 5 6
Ivica je dobio sljedece karte: 4 41 26 8
Preostale karte u spilu (44):
31 42 2 33 47 37 14 16 51 35 24
38 18 25 21 36 11 49 52 29 45 13
19 44 43 32 12 3 30 17 34 9 40
22 1 20 27 39 15 46 50 23 48 28
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Igrac {
public:
	string ime;
	vector<int> karte;

	Igrac(string _ime) : ime(_ime) {}

	void ispis() {
		cout << ime << " je dobio sljedece karte: \t";

		for (int i = 0; i < karte.size(); i++) {
			cout << karte[i] << "\t";
		}
		
		cout << endl;
	}
};

class Spil {
private: 
	void popuniSpil() {
		for (int i = 1; i <= 52; i++)
			this->karte.push_back(i);
	}
public:
	vector<int> karte;

	Spil() {
		popuniSpil();
	}

	void izmjesaj() {
		random_shuffle(karte.begin(), karte.end());
	}

	void ispis() {
		cout << endl << "Karte u spilu (" << karte.size() << "):" << endl;
		for (int i = 0; i < karte.size(); i++) {
			cout << karte[i] << "\t";
		}
		cout << endl;
	}

	void Podijeli4Karte(Igrac* igrac) {
		for (int i = 0; i < 4; i++) {
			igrac->karte.push_back(karte[0]);
			karte.erase(karte.begin() + 0);
		}
	}
};

int main() {
	int brojIgraca;
	cout << "Unesi broj igraca: ";
	cin >> brojIgraca;

	vector<Igrac> igraci;
	string imeIgraca;

	for (int i = 0; i < brojIgraca; i++) {
		cout << "Unesi ime " << i + 1 << ". igraca: ";
		cin >> imeIgraca;
		igraci.push_back(Igrac(imeIgraca));
	}

	Spil spil = Spil();
	spil.izmjesaj();
	spil.ispis();

	for (int i = 0; i < brojIgraca; i++)
		spil.Podijeli4Karte(&igraci[i]);

	cout << endl;

	for (int i = 0; i < brojIgraca; i++) {
		igraci[i].ispis();
	}

	spil.ispis();

	return 0;
}
