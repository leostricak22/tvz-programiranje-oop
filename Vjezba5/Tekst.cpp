/*
Definirajte klasu Tekst koja predstavlja tekstualni tip podatka (kao string), s
tim da podrzava operacije *, - i +:
- operacija * umnozava tekst. Na primjer, ako je x = "abc" onda x * 3 daje novi
objekt tipa Tekst koji sadrzi tekst "abcabcabc". Ova operacija mora raditi i
kada je broj s lijeve strane, to jest x * 3 treba davati isti rezultat kao i
3 * x
- operacija - uklanja zadani znak iz teksta. Na primjer, ako je x = "uvala"
onda x - 'a' daje novi objekt tipa Tekst koji sadrzi tekst "uvl", to jest
bez slova 'a'
- operacija + spaja dva teksta u jedan novi tekst. Na primjer, ako je x = "ab"
i y = "cd", onda x + y daje novi objekt tipa Tekst koji sadrzi tekst "abcd"
- treba redefinirati i operator << da radi s objektima tipa Tekst

Ovu klasu treba definirati tako da funkcija main radi kako je ispod prikazano.

int main() {
    Tekst t = "abc";
    Tekst p = t * 3;                // "umnozavanje" teksta
    cout << p << endl;                // ispisuje abcabcabc
    cout << 2 * t << endl;            // ispisuje abcabc

    // t mora ostati nepromijenjen!!!
    cout << t << endl;                // ispisuje abc

    cout << t + p << endl;            // ispisuje abcabcabcabc
    cout << t + p - 'a' << endl;    // ispisuje bcbcbcbc

    // p i t moraju ostati nepromijenjeni!!!
    cout << p << endl;                // ispisuje abcabcabc
    cout << t << endl;                // ispisuje abc
}
*/

#include <iostream>
#include <string>

using namespace std;

class Tekst {
private:
    string tekst;
public:
    Tekst(const string& _tekst) : tekst(_tekst) {}

    Tekst(const char* _tekst) : tekst(_tekst) {}

    Tekst operator*(int n) const {
        string rezultat;
        for (int i = 0; i < n; ++i) {
            rezultat += tekst;
        }
        return Tekst(rezultat);
    }

    Tekst operator-(char znak) const {
        string rezultat = tekst;
        for (int i = 0; i < rezultat.size(); i++) {
            if (rezultat[i] == znak) {
                rezultat.erase(i, 1);
                i--;
            }
        }        
        
        return Tekst(rezultat);
    }

    Tekst operator+(const Tekst& drugi) const {
        return Tekst(tekst + drugi.tekst);
    }

    friend ostream& operator<<(ostream& izlaz, const Tekst& t) {
        izlaz << t.tekst;
        return izlaz;
    }

    friend Tekst operator*(int n, const Tekst& _tekst) {
        return _tekst * n;
    }
};

int main() {
    Tekst t = "abc";
    Tekst p = t * 3;                // "umnozavanje" teksta
    cout << p << endl;    // ispisuje abcabcabc
    cout << 2 * t << endl; // ispisuje abcabc

    // t mora ostati nepromijenjen!!!
    cout << t << endl;    // ispisuje abc

    cout << t + p << endl;            // ispisuje abcabcabcabc
    cout << (t + p - 'a') << endl;    // ispisuje bcbcbcbc

    // p i t moraju ostati nepromijenjeni!!!
    cout << p << endl;                // ispisuje abcabcabc
    cout << t << endl;                // ispisuje abc

    return 0;
}

