/*
[VJ-4] Učenik i razred

Neka u programu postoje sljedeće klase:
struct Ucenik {
	string ime, prezime;
};

class Razred {
public:
	vector<Ucenik*> ucenik;
	float prosjecnaOcjena;
};

Napišite sve potrebne metode unutar klase Razred kojima ćete demonstrirati semantiku
kopiranja u funkciji main. Također, u funkciji main demonstrirajte primjerima kako bi
izgledala semantika prijenosa (nije potrebno pisati metode unutar klase Razred)
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Ucenik {
	string ime;
	string prezime;
};

class Razred {
public:
	vector<Ucenik> ucenik;
	float prosjecnaOcjena;

	Razred(const Razred& other) {
		ucenik = other.ucenik;
		prosjecnaOcjena = other.prosjecnaOcjena;
	}

	Razred() {}

	Razred& operator=(const Razred& other) {
		if (this != &other) {
			delete[] &ucenik;
			ucenik = other.ucenik;
			prosjecnaOcjena = other.prosjecnaOcjena;
		}
		return *this;
	}

	Razred(Razred&& other) noexcept {
		ucenik = move(other.ucenik);
		prosjecnaOcjena = other.prosjecnaOcjena;
		other.ucenik.clear();
	}

	Razred& operator=(Razred&& other) noexcept {
		if (this != &other) {
			ucenik = move(other.ucenik);
			prosjecnaOcjena = other.prosjecnaOcjena;
			other.ucenik.clear();
		}
		return *this;
	}
};


int main() {
	Ucenik u1{ "Marko", "Horvat" };
	Razred razred1;
	razred1.ucenik.push_back(u1);
	razred1.prosjecnaOcjena = 4.5;

	Razred razred2 = razred1;

	razred2.ucenik[0].ime = "Ana";
	razred2.prosjecnaOcjena = 5.0;

	cout << "Razred 1: " << razred1.ucenik[0].ime << " " << razred1.prosjecnaOcjena << endl;
	cout << "Razred 2: " << razred2.ucenik[0].ime << " " << razred2.prosjecnaOcjena << endl;

	Ucenik u2{ "Ivan", "Kovačić" };
	Razred razred3;
	razred3.ucenik.push_back(u2);
	razred3.prosjecnaOcjena = 3.8;

	Razred razred4(move(razred3));

	cout << "Razred 3: " << razred3.ucenik.size() << " " << razred3.prosjecnaOcjena << endl;
	cout << "Razred 4: " << razred4.ucenik[0].ime << " " << razred4.prosjecnaOcjena << endl;

	return 0;
}
