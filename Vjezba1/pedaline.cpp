/*
Vlasnik ste koncerna za iznajmljivanje pedalina diljem Jadrana. Imate niz lokacija na kojima iznamljujete, te vam je već pomalo nespretno voditi evidenciju o tome gdje su koje pedaline te ste se odlučili baciti na posao i napraviti C++ program koji će vam u tome pomoći.

Odlučili ste definirati niz lokacija gdje iznamljujete, i za svaku lokaciju bilježiti koje pedaline iznamljujete (kako vam ne bi nestale).

Klasa Lokacija ima sljedeća svojstva:

ime i prezime odgovorne osobe
GPS koordinate (double X i double Y)
niz predmeta koji su dostupni
Klasa Pedalina ima sljedeća svojstva:
 * boja
 * kapacitet
U main programu potrebno je od korisnika tražiti unos broja N, nakon kojeg se unose podaci o N lokacija. Nakon što se unesu sva polja, potrebno je tražiti unos broja M, koji označava broj pedalina, te je potrebno unijeti tih M pedalina (neka lokacija može nuditi više pedalina).

Primjer izvođenja:
Unesite broj lokacija (N):2
Unesite odgovornu osobu i GPS koordinate za 1. lokaciju:
Pero Jankovic
43.346216 16.734324
Unesite odgovornu osobu i GPS koordinate za 2. lokaciju:
Danko Stankovic
43.246216 16.834324
Unesite broj pedalina (M): 1
Unesite redni broj lokacije kojoj pripada 1. pedalina: 2
Unesite boju i kapacitet pedaline: Crvena 7

Ispis lokacija i pedalina:
1. 43.346216 16.734324 Pero Jankovic – pedaline:
2. 43.246216 16.834324 Danko Stankovic – pedaline: Crvena (7)
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pedalina {
public:
	string boja;
	int kapacitet;

	Pedalina(string _boja, int _kapacitet) : boja(_boja), kapacitet(_kapacitet) {}

	~Pedalina() {};
};

class Lokacija {
public:
	string ime, prezime;
	double GPS_x, GPS_y;
	vector<Pedalina> Pedaline;

	Lokacija(string _ime, string _prezime, double _GPS_x, double _GPS_y) : ime(_ime), prezime(_prezime), GPS_x(_GPS_x), GPS_y(_GPS_y) {}

	~Lokacija() {};

	void ispis() {
		cout << GPS_x << " " << GPS_y << " " << ime << " " << prezime << " - pedaline: ";

		for (int i = 0; i < Pedaline.size(); i++) {
			cout << Pedaline[i].boja << " (" << Pedaline[i].kapacitet << ") ";
		}

		cout << "\n";
	}
};

int main() {
	int N, M;
	cout << "Unesite broj lokacija (N): ";
	cin >> N;

	string temp_ime, temp_prezime;
	double temp_GPS_x, temp_GPS_y;

	vector<Lokacija> Lokacije;

	for (int i = 0; i < N; i++) {
		cout << "Unesite odgovornu osobu i GPS koordinate za " << i + 1 << ". lokaciju: \n";
		cin >> temp_ime >> temp_prezime >> temp_GPS_x >> temp_GPS_y;
		Lokacije.push_back(Lokacija(temp_ime, temp_prezime, temp_GPS_x, temp_GPS_y));
	}

	int temp_indeks, temp_kapacitet;
	string temp_boja;
	cout << "Unesite broj pedalina (M): ";
	cin >> M;
	for (int i = 0; i < M; i++) {
		cout << "Unesite redni broj lokacije kojoj pripada " << i + 1 << ". pedalina: ";
		cin >> temp_indeks;
		cout << "Unesite boju i kapacitet pedaline: ";
		cin >> temp_boja >> temp_kapacitet;

		Lokacije[temp_indeks - 1].Pedaline.push_back(Pedalina(temp_boja, temp_kapacitet));
	}

	cout << "\nIspis lokacija i pedalina:\n";
	for (int i = 0; i < N; i++) {
		cout << i + 1 << ". ";
		Lokacije[i].ispis();
	}

	return 0;
}
