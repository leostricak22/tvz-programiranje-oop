/*
Potrebno je napisati program za praćenje bodovnog stanja studenata na određenom kolegiju. Slijedeći programski odsječak u nastavku napišite sve potrebne klase i metode kojima se dobije očekivano ponašanje programskog koda.

int main(){

vector<Bodovi> OOPBodovi{
	Bodovi(Student("Ivana Ivic", "0246002475"), 25),
	Bodovi(Student("Ivica Ivanovic", "0246005654"), 20),
	Bodovi(Student("Marko Markic", "0246004234"), 32)
};

Kolegij OOP("Objektno orijentirano programiranje", OOPBodovi);

 //  Preko objekta OOP ispišite bodove svih studenata tog kolegija počevši od
 //  onih s najmanjim brojem bodova prema većim. Npr.;
 //  Objektno orijentirano programiranje bodovi:
 //  Ivica Ivanovic  0246005654      20
 //  Ivana Ivic      0246002475      25
 //  Marko Markic    0246004234      32

return 0;
}
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Student {
public:
    string imePrezime, JMBAG;

    Student(string _imePrezime, string _JMBAG) : imePrezime(_imePrezime), JMBAG(_JMBAG) {}
    ~Student() {}
};

class Bodovi {
public:
    Student student;
    int brojBodova;

    Bodovi(Student _student, int _brojBodova) : student(_student), brojBodova(_brojBodova) {}
    ~Bodovi() {}
};

class Kolegij {
public:
    string nazivKolegija;
    vector<Bodovi> bodoviKolegija;

    Kolegij(string _nazivKolegija, vector<Bodovi> _bodoviKolegija) : nazivKolegija(_nazivKolegija), bodoviKolegija(_bodoviKolegija) {}
    ~Kolegij() {}

    void sortiraj() {
        sort(bodoviKolegija.begin(), bodoviKolegija.end(), [](Bodovi bodovi1, Bodovi bodovi2) {
            return (bodovi1.brojBodova < bodovi2.brojBodova);
        });
    }

    void ispisi() {
        sortiraj();
        for (int i = 0; i < bodoviKolegija.size(); i++) {
            cout << bodoviKolegija[i].student.imePrezime << " " << bodoviKolegija[i].student.JMBAG << " " << bodoviKolegija[i].brojBodova << endl;
        }
    }
};

int main() {
    vector<Bodovi> OOPBodovi{
        Bodovi(Student("Ivana Ivic", "0246002475"), 25),
        Bodovi(Student("Ivica Ivanovic", "0246005654"), 20),
        Bodovi(Student("Marko Markic", "0246004234"), 32)
    };

    Kolegij OOP("Objektno orijentirano programiranje", OOPBodovi);

    OOP.ispisi();

    return 0;
}
