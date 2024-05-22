/*
[VJ-9] Matematika
Neka postoji sljedeći programski odsječak:

int main(){
	Matematika Racun;
	cout << Racun.suma(2, 4.3) << endl; // 6.3
	cout << Racun.suma(2.3, 4) << endl; // 6.3
	cout << Racun.suma(Kompleksni(2.5, 1), 4) << endl; // 6.5 1i
	return 0;
}

Napišite sve potrebne klase, metode i funkcije kako bi prikazani programski odsječak
radio kao što je to u komentarima i predviđeno. Napomena: metoda suma vraća sumu
bilo koja dva podatka koje je moguće zbrojiti operatorom +. Za tipove podatka koje nije
moguće direktno zbrojiti operatorom + potrebno je preopteretiti taj operator za navedeni
tip
*/

#include <iostream>

using namespace std;

class Matematika {
public:
	template <typename T, typename U>
	auto suma(const T& broj1, const U& broj2) const -> decltype(broj1 + broj2) {
		return broj1 + broj2;
	}
};

class Kompleksni {
public:
	double re, im;

	Kompleksni(double _re = 0, double _im = 0) : re(_re), im(_im) {}

	Kompleksni operator+(const Kompleksni& other) const {
		return Kompleksni(re + other.re, im + other.im);
	}

	Kompleksni operator+(double other) const {
		return Kompleksni(re + other, im);
	}

	friend Kompleksni operator+(double lhs, const Kompleksni& rhs) {
		return Kompleksni(lhs + rhs.re, rhs.im);
	}

	friend std::ostream& operator<<(std::ostream& os, const Kompleksni& k) {
		os << k.re;
		if (k.im >= 0) os << " + " << k.im << "i";
		else os << " - " << -k.im << "i";
		return os;
	}
};

int main() {
	Matematika Racun;
	cout << Racun.suma(2, 4.3) << endl; // 6.3
	cout << Racun.suma(2.3, 4) << endl; // 6.3
	cout << Racun.suma(Kompleksni(2.5, 1), 4) << endl; // 6.5 1i
	return 0;
}
