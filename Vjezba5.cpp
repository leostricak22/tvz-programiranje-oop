/*
Sva slika ima svoju cijenu izraženu u eurima. 
Slijedeći programski kod u nastavku napišite klasu Slika i sve potrebne podatkovne članove i metode kojima se dobije očekivano ponašanje programskog koda.

Slika Slika1(2000); // 2000 eura
Slika Slika2(3000); // 3000 eura
Slika Slika3(1800); // 1800 eura
cout << Slika::ProsjecnaCijena() << " eura"; // 2266.67 eura
*/

#include <iostream>
#include <vector>

using namespace std;

class Slika {
public:
	static vector<double> cijene;

	Slika(double _cijene) {
		cijene.push_back(_cijene);
	}

	static double prosjecnaCijena() {
		double suma = 0;

		for (int i = 0; i < cijene.size(); i++)
			suma += cijene[i];

		return suma / cijene.size();
	}
};

vector<double> Slika::cijene;

int main() {
	Slika Slika1(2000); // 2000 
	Slika Slika2(3000); // 3000 eura
	Slika Slika3(1800); // 1800 eura

	cout << Slika::prosjecnaCijena() << " eura"; // 2266.67 eura

	return 0;
}
