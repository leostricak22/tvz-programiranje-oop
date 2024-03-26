/*
[VJ-3] Bankovni račun
Neka u klasi BankovniRacun postoje podatkovni članovi brojRacuna (string), tipKlijenta
(string) i tipRacuna (string). 
Potrebno je demonstrirati svojstvo enkapsulacije na način da
se nametnu sljedeća pravila:
* Broj računa mora imati točno 8 znamenki te mora početi znamenkom 0.
* Tip klijenta može biti isključivo fizička ili privatna osoba
* Tip računa može biti tekući, žiro-račun ili devizni

Ukoliko se prekrši bilo koje od pravila potrebno je odustati od postavljanja vrijednosti te
korisniku ispisati odgovarajuću poruku.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BankovniRacun {
private:
	string brojRacuna = "", tipKlijenta = "", tipRacuna = "";
public:
	BankovniRacun(string _brojRacuna, string _tipKlijenta, string _tipRacuna) {
		if (setBrojRacuna(_brojRacuna) ||
			setTipKlijenta(_tipKlijenta) ||
			setTipRacuna(_tipRacuna)) {
			brojRacuna = "";
			tipKlijenta = "";
			tipRacuna = "";
			cout << "Pogreska, podatci nisu upisani." << endl;
		} else {
			cout << "Uspjeh, podatci su upisani." << endl;
		}
	}

	BankovniRacun() = default;

	bool setBrojRacuna(string _brojRacuna) {
		if (_brojRacuna[0] == '0' && _brojRacuna.size() == 8) {
			brojRacuna = _brojRacuna;
			return false;
		}

		return true;
	}

	bool setTipKlijenta(string _tipKlijenta) {
		vector<string> tipoviKlijenta = { "Fizicka osoba", "Privatna osoba" };

		for (int i = 0; i < tipoviKlijenta.size(); i++) {
			if (_tipKlijenta.compare(tipoviKlijenta[i]) == 0) {
				tipKlijenta = _tipKlijenta;
				return false;
			}
		}

		return true;
	}

	bool setTipRacuna(string _tipRacuna) {
		vector<string> tipoviRacuna = { "Tekuci", "Ziro-racun", "devizni"};

		for (int i = 0; i < tipoviRacuna.size(); i++) {
			if (_tipRacuna.compare(tipoviRacuna[i]) == 0) {
				tipRacuna = _tipRacuna;
				return false;
			}
		}

		return true;
	}
};

int main() {
	// BankovniRacun("01234567", "Privatna osoba", "Tekduci");

	BankovniRacun racun1;

	string brojRacuna, tipKlijenta, tipRacuna;
	bool tocneVrijednosti = false;
	
	cout << "Unesi broj racuna: ";
	cin >> brojRacuna;
	tocneVrijednosti = racun1.setBrojRacuna(brojRacuna);

	if (!tocneVrijednosti) {
		cout << "Unesi tip klijenta: ";

		cin.ignore();
		getline(cin, tipKlijenta);

		tocneVrijednosti = racun1.setTipKlijenta(tipKlijenta);
	}

	if (!tocneVrijednosti) {
		cout << "Unesi tip racuna: ";
		cin >> tipRacuna;
		tocneVrijednosti = racun1.setTipRacuna(tipRacuna);
	}

	if (!tocneVrijednosti)
		cout << "Uspjeh, podatci su upisani." << endl;
	else
		cout << "Pogreska, podatci nisu upisani." << endl;

	return 0;
}
