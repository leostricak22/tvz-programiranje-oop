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
		cout << "Unesite odgovornu osobu i GPS koordinate za " << i+1 << ". lokaciju: ";
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
 
		Lokacije[temp_indeks-1].Pedaline.push_back(Pedalina(temp_boja, temp_kapacitet));
	}
 
	cout << "\nIspis lokacija i pedalina:\n";
	for (int i = 0; i < N; i++) {
		cout << i + 1 << ". ";
		Lokacije[i].ispis();
	}
 
	return 0;
}
