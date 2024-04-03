/*
Napraviti klasu Knjiznica sa sljedećim (privatnim) poljima:
* adresa
* naziv
*kategorija (djecja, znanstvena, ...)

Omogućiti korisniku kreiranje nove knjiznice i postavljanje članova. Treba pripaziti na sljedeća pravila:
* Kategorija moze biti samo "djecja", "znanstvena", "citaonica", "opcenito"
* Naziv mora pocinjati velikim slovom
* Sve provjere pravila je potrebno napraviti unutar klase Knjiznica. (Gdje?)

Dodati klasu Knjiga s nekoliko proizvoljnih polja (autor, naslov, ISBN, ...). 
Neka klasa Knjiga ima samo jedan konstruktor, unutar kojeg je potrebno ispisati 
„Knjiga constructor called“ korisniku, te jedan destruktor u kojem treba ispisati 
"Knjiga destructor called" korisniku. 
Proširiti klasu Knjiznica s poljem vector<Knjiga> i dodati u klasu Knjiznica metode:
* dodajKnjigu1(Knjiga z)
* dodajKnjigu2(Knjiga& z)
* dodajKnjigu3(Knjiga* z)
Što se ispisuje prilikom poziva metoda 1,2 i 3? U kojim slučajevima se stvara novi objekt? 
Zašto se ispisuje više puta destruktor nego konstruktor?

Dodati u klasu Knjiznica metodu „ispisSvihKnjiga“.

Dodati u klasu Knjiznica metode:
* Knjiga nadjiKnjigu1(string isbn)
* Knjiga* nadjiKnjigu2(string isbn)
* Knjiga& nadjiKnjigu3(string isbn)

Koristeći nadjiKnjigu1 naći i zatim izmjeniti podatke o jednoj knjizi, a zatim koristeći metodu nadjiKnjigu2 naći i zatim izmjeniti podatke o drugoj knjizi, te koristeći metodu nadjiKnjigu3 naći i zatim izmjeniti podatke o trećoj knjizi. Pozvati „ispisSvihKnjiga“ za knjižnicu. Što zapažate?
Koje su prednosti a koji nedostaci u načinima pozivanja metoda s objektima kao parametrima i vraćanja objekata kao vrijednosti iz funkcije? Kada koristiti jedan način a kada drugi?
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Knjiga {
public:
	string autor;
	string naslov;
	string ISBN;

	Knjiga(string _autor, string _naslov, string _ISBN) {
		autor = _autor;
		naslov = _naslov;
		ISBN = _ISBN;

		cout << "Knjiga constructor called" << endl;
	}
	~Knjiga() {
		cout << "Knjiga destructor called" << endl;
	}
};

class Knjiznica {
private:
	string adresa;
	string naziv;
	string kategorija;
public:
	vector<Knjiga> knjige;

	void setAdresa(string _adresa) { 
		adresa = _adresa; 
	}

	string getAdresa() const { 
		return adresa; 
	}

	void setNaziv(string _naziv) {
		if (isupper(_naziv[0])) {
			naziv = _naziv;
		}
	}
	string getNaziv() const { return naziv; }

	void setKategorija(string _kategorija) {
		vector<string> kategorije = { "djecja", "znanstvena", "citaonica", "opcenito" };
		bool kategorijaPronadena = false;
		for (int i = 0; i < kategorije.size();i++) {
			if (kategorije[i] == _kategorija) {
				kategorijaPronadena = true;
				break;
			}
		}

		if(kategorijaPronadena)
			kategorija = _kategorija;
	}
	string getKategorija() const { 
		return kategorija; 
	}

	void dodajKnjigu1(Knjiga z) {
		knjige.push_back(z);
	}

	void dodajKnjigu2(Knjiga& z) {
		knjige.push_back(z);
	}

	void dodajKnjigu3(Knjiga* z) {
		knjige.push_back(*z);
	}

	void ispisSvihKnjiga() {
		cout << "-----------------------------------------------------------------------" << endl;
		for (int i = 0; i < knjige.size(); i++)
			cout << knjige[i].autor << "\t" << knjige[i].naslov << "\t" << knjige[i].ISBN << endl;
		cout << "-----------------------------------------------------------------------" << endl;
	}

	Knjiga nadjiKnjigu1(string ISBN) {
		for (int i = 0; i < knjige.size(); i++)
			if (knjige[i].ISBN == ISBN)
				return knjige[i];
		return Knjiga("", "", "");
	}

	Knjiga* nadjiKnjigu2(string ISBN) {
		for (int i = 0; i < knjige.size(); i++)
			if (knjige[i].ISBN == ISBN)
				return &knjige[i];
		return NULL;
	}

	Knjiga& nadjiKnjigu3(string ISBN) {
		for (int i = 0; i < knjige.size(); i++)
			if (knjige[i].ISBN == ISBN)
				return knjige[i];
	}
};


int main() {
	Knjiznica knjiznica1;

	knjiznica1.setAdresa("Franje Bucara 1 Cakovec");
	knjiznica1.setKategorija("znanstvena");
	knjiznica1.setNaziv("Djecja knjiznica Cakovec");

	cout << knjiznica1.getAdresa() << endl;
	cout << knjiznica1.getKategorija() << endl;
	cout << knjiznica1.getNaziv() << endl;

	Knjiga knjiga1 = Knjiga("Mato Lovrak", "Vlak u snijegu", "9788601010802");
	Knjiga knjiga2 = Knjiga("Anne Frank", "Dnevnik Anne Frank", "1234567890237");
	Knjiga knjiga3 = Knjiga("Miroslav Krleza", "Gospoda Glembajevi", "9876543234567");
	
	knjiznica1.dodajKnjigu1(knjiga1);
	/* OUTPUT:
		Knjiga constructor called
		Knjiga destructor called			-->		kopija koja se sprema u vektor knjige
		Knjiga destructor called			-->		originalni objekt
		Knjiga destructor called			-->		kopija originalnog objekta
	*/

	knjiznica1.dodajKnjigu2(knjiga2);
	/* OUTPUT:
		Knjiga constructor called
		Knjiga destructor called			-->		kopija koja se sprema u vektor knjige
		Knjiga destructor called			-->		originalni objekt
	*/

	knjiznica1.dodajKnjigu3(&knjiga3);
	/* OUTPUT:
		Knjiga constructor called
		Knjiga destructor called 			-->		kopija koja se sprema u vektor knjige
		Knjiga destructor called			-->		originalni objekt
	*/

	knjiznica1.ispisSvihKnjiga();

	Knjiga pronadjenaKnjiga1 = knjiznica1.nadjiKnjigu1("9788601010802");
	Knjiga* pronadjenaKnjiga2 = knjiznica1.nadjiKnjigu2("1234567890237");
	Knjiga& pronadjenaKnjiga3 = knjiznica1.nadjiKnjigu3("9876543234567");

	pronadjenaKnjiga1.naslov = "Vlak u snijegu 2";
	pronadjenaKnjiga2->naslov = "Dnevnik Anne Frank 2";
	pronadjenaKnjiga3.naslov = "Gospoda Glembajevi 2";

	knjiznica1.ispisSvihKnjiga();

	return 0;
}
