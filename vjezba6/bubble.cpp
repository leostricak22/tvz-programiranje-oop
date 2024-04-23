/*
[VJ-6] Bubble
Potrebno je napisati klasu Bubble sa svojstvima boja i radijus. Implementacijom operatora
zbrajanja (+) potrebno je omogućiti "spajanje" dva bubble-a u jedan. Novi bubble ima
obujam jednak zbroju obujama bubble-a od kojih je nastao, a preuzima boju većeg bubblea. 
Pri izdvajanju novog bubble-a iz postojećeg (operator -) nastaje novi sa smanjenim
obujmom. Boja ostaje od originalnog bubble-a.

Obujam se računa prema obujmu kugle - V = 4/3 * r * r * r * PI. Također, treći korjen se
računa kao pow(x, 1.0/3) (potrebno pri izračunavanju radijusa iz obujma).
Potrebno je dodati i operator == koji uspoređuje dva Bubble objekta. Dva bubble-a su isti
ako imaju istu boju, i ako im se radijus razlikuje za ne više od 0.0001.

int main(){
	Bubble a("blue", 10.4);
	Bubble b("red", 7.2);
	Bubble c("green", 18.8);
	Bubble x = a + b; //nastat će novi bubble obujma 6275.27
	cout << x; //blue: 11.44
	Bubble y = x + c;
	cout << y; //green: 20.12
	Bubble z = y - x;
	cout << z; //green: 18.8
	if (z == c)
		cout << "OK" << endl; //OK
	return 0;
}
*/

#include <iostream>
#include <cmath>

using namespace std;

class Bubble {
public:
	string boja;
	double r, obujam;

	Bubble(string _boja, double _r) {
		boja = _boja;
		r = _r;
		obujam = 4 / 3 * r * r * r * 3.14;
	}
};

ostream& operator << (ostream& izlaz, Bubble bubble) {
	izlaz << bubble.boja << ": " << bubble.r << endl;
	return izlaz;
}

Bubble operator + (const Bubble& bubble1, const Bubble& bubble2) {
	double obujam = bubble1.obujam + bubble2.obujam;
	Bubble novi = Bubble((bubble1.r > bubble2.r ? bubble1.boja : bubble2.boja), pow((obujam/((4/3)*3.14)), 1.0 / 3));

	return novi;
}

Bubble operator - (const Bubble& bubble1, const Bubble& bubble2) {
	double obujam = bubble1.obujam - bubble2.obujam;
	Bubble novi = Bubble((bubble1.r > bubble2.r ? bubble1.boja : bubble2.boja), pow((obujam / ((4 / 3) * 3.14)), 1.0 / 3));

	return novi;
}

bool operator == (const Bubble& bubble1, const Bubble& bubble2) {
	return bubble1.boja == bubble2.boja && bubble1.r - bubble2.r < 0.0001;
}



int main() {
	Bubble a("blue", 10.4);
	Bubble b("red", 7.2);
	Bubble c("green", 18.8);

	Bubble x = a + b; //nastat će novi bubble obujma 6275.27
	cout << x; //blue: 11.44
	
	Bubble y = x + c;
	cout << y; //green: 20.12
	

	Bubble z = y - x;
	cout << z; //green: 18.8
	
	if (z == c)
		cout << "OK" << endl; //OK
	return 0;
}
