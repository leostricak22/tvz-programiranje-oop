/*
Za klasu Pijesak napišite konstruktore i operatore pridruživanja s semantikom kopiranja i semantikom prijenosa. 
U funkciji main demonstrirajte njihove pozive.

#include <iostream>
#include <string>

using namespace std;

class Zrno{
public:
    string boja;
    float promjer;
};

class Pijesak{
public:
    int kolicina;
    Zrno* zrno;

    Pijesak(int _kolicina) : kolicina(_kolicina){
        // dinamički alocirajte polje 'zrno'
    }
    ~Pijesak(){
        // ?
    }
};

int main(){
    Pijesak igraliste(1000000);
    cout << "Na igralistu ima " << igraliste.kolicina << " zrna pijeska!\n";

    // Demonstrirajte pozive oba konstruktora i oba operatora pridruživanja
    return 0;
}
*/

#include <iostream>
#include <string>

using namespace std;

class Zrno{
public:
    string boja;
    float promjer;
};

class Pijesak{
public:
    int kolicina;
    Zrno* zrno;

    // konstruktor s semantikom kopiranja
    Pijesak(const Pijesak& drugi) : kolicina(drugi.kolicina) {
        zrno = new Zrno[kolicina];
        for (int i = 0; i < kolicina; i++) {
            zrno[i] = drugi.zrno[i];
        }
    }

    // konstruktor s semantikom prijenosa
    Pijesak(Pijesak&& drugi) : kolicina(drugi.kolicina), zrno(drugi.zrno) {
        drugi.zrno = nullptr;
    }

    // semantika kopiranja
    Pijesak& operator = (const Pijesak& drugi) {
        if (this != &drugi) {
            delete[] zrno;                     
            zrno = new Zrno[kolicina];
            kolicina = drugi.kolicina;
            for (int i = 0; i < drugi.kolicina; i++)
                zrno[i] = drugi.zrno[i];
        }
        return *this;
    }

    // semantika prijenosa
    Pijesak& operator=(Pijesak&& drugi) {
        if (this != &drugi) {
            delete[] zrno;
            kolicina = drugi.kolicina;
            zrno = drugi.zrno;
            drugi.zrno = nullptr;
        }
        return *this;
    }

    Pijesak(int _kolicina) : kolicina(_kolicina){
        zrno = new Zrno[kolicina];
    }
    ~Pijesak(){
        delete[] zrno;
    }
};

int main(){
    Pijesak igraliste(1000000);
    cout << "Na igralistu ima " << igraliste.kolicina << " zrna pijeska!\n";

    // konstruktor s semantikom kopiranja
    Pijesak igralisteKopija(igraliste);
    
    // pridruzivanje s semantikom kopiranja
    Pijesak igralisteKopija2 = igraliste;

    // konstruktor s semantikom prijenosa
    Pijesak igralistePrijenos(move(igraliste));

    // pridruzivanje s semantikom prijenosa
    Pijesak igralistePrijenos2 = move(igraliste);

    cout << "Nakon kopiranja i prijenosa..." << endl;
    cout << "Igraliste: " << igraliste.kolicina << " zrna pijeska" << "\t adresa: " << &igraliste << endl;
    cout << "Kopija: " << igralisteKopija.kolicina << " zrna pijeska" << "\t adresa: " << &igralisteKopija << endl;
    cout << "Kopija 2: " << igralisteKopija2.kolicina << " zrna pijeska" << "\t adresa: " << &igralisteKopija2 << endl;
    cout << "Prijenos: " << igralistePrijenos.kolicina << " zrna pijeska" << "\t adresa: " << &igralistePrijenos << endl;
    cout << "Prijenos2: " << igralistePrijenos2.kolicina << " zrna pijeska" << "\t adresa: " << &igralistePrijenos2 << endl;

    return 0;
}
