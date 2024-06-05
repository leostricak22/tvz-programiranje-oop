#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

namespace Sastanak {
    class NeispravnaTocka : public exception {
    private:
        string message;
    public:
        NeispravnaTocka(const string& msg) : message(msg) {}

        virtual const char* what() const noexcept override {
            return message.c_str();
        }

    };

    class Odgovor {
    private:
        string text;
    public:
        Odgovor(const string& _text) : text(_text) {}

        void nadodaj(const string& additional) {
            text += "; " + additional;
        }

        string tekst() const {
            return text;
        }
    };

    class ElementDnevnogReda {
    public:
        virtual string tekstualno() const = 0;
        virtual ~ElementDnevnogReda() = default;
    };

    class Tocka : public ElementDnevnogReda {
    private:
        int redni_broj;
        string naziv, opis;
        Odgovor* odgovorPtr;
    public:
        static int unisteno;
        Tocka(int _redni_broj, string _naziv, string _opis) {
            setRedni_broj(_redni_broj);
            setNaziv(_naziv);
            setOpis(_opis);
            odgovorPtr = nullptr;
        }

        Tocka(int _redni_broj, string _naziv, string _opis, Odgovor* _odgovor) {
            setRedni_broj(_redni_broj);
            setNaziv(_naziv);
            setOpis(_opis);
            odgovorPtr = _odgovor;
        }

        Tocka() {
            redni_broj = 0;
            naziv = "Tocka 0";
            opis = "Razno";
            odgovorPtr = nullptr;
        }

        ~Tocka() {
            odgovorPtr = nullptr;
            unisteno++;
        }

        Odgovor* odgovor() const {
            return odgovorPtr;
        }

        int getRedni_broj() const {
            return redni_broj;
        }

        void setRedni_broj(int _redni_broj) {
            if (_redni_broj > 0)
                redni_broj = _redni_broj;
            else
                throw NeispravnaTocka("Neispravan redni broj");
        }

        void setNaziv(string _naziv) {
            if (!_naziv.empty())
                naziv = _naziv;
            else
                throw NeispravnaTocka("Neispravan naziv");
        }

        void setOpis(string _opis) {
            if (!_opis.empty())
                opis = _opis;
            else
                throw NeispravnaTocka("Neispravan opis");
        }

        operator string() const {
            return naziv + " - " + opis;
        }

        friend ostream& operator << (ostream& os, const Tocka& t) {
            os << "Ad" << t.redni_broj << ";" << t.naziv << ";" << t.opis;
            return os;
        }

        // sortiranje i semantika prijenosa
        Tocka& operator=(const Tocka& other) {
            if (this != &other) {
                redni_broj = other.redni_broj;
                naziv = other.naziv;
                opis = other.opis;
            if (odgovorPtr) {
                delete odgovorPtr; // Delete existing resource
                odgovorPtr = nullptr;
            }
            if (other.odgovorPtr) {
                odgovorPtr = new Odgovor(*other.odgovorPtr);
            }
            }
            return *this;
        }

        bool operator<(const Tocka& other) const {
            return redni_broj < other.redni_broj;
        }

        // polimorfizam
        string tekstualno() const override {
            return naziv + " - " + opis;
        }
    };

    template<typename T>
    class Zapisnik {
    private:
        vector<T> toc;

    public:
        // Function to add elements to the zapisnik
        template<typename... Args>
        void nadodaj(const Args&... args) {
            (toc.push_back(args), ...);
        }

        // Function to print the elements
        void ispisi() const {
            for (const auto& tocka : toc) {
                cout << tocka << endl;
            }
        }
    };

    auto slaganje_tocaka = [](const Tocka& a, const Tocka& b) {
        return a.getRedni_broj() > b.getRedni_broj();
    };

    auto usporedba_tocaka = [](const ElementDnevnogReda* a, const ElementDnevnogReda* b) {
        return dynamic_cast<const Tocka*>(a)->getRedni_broj() < dynamic_cast<const Tocka*>(b)->getRedni_broj();
    };

    void ispisi(const vector<Tocka>& tocke) {
        for (const auto& tocka : tocke) {
            cout << tocka << endl;
        }
    }

    int Tocka::unisteno= 0;
};

/*
Napišite sve što je neophodno da bi se funkcija "main" izvršavala kako je
navedeno s komentarima. Također slijedite sve ostale upute s komentarima za
pisanje koda. Svaki dio označen između crta nosi navedeni broj bodova ako je s
potpunosti implementiran. Djelomična implementacija boduje se prema procjeni
nastavnika.

Napomena: Funkciju "main" nije dozvoljeno modificirati! Za uočenu promjenu s
nekom dijelu ove funkcije taj se dio poništava.
*/

int main() {
    //**************************************************************************
    // [1] --- 1 BOD

    // sav kôd mora biti dio imenskog prostora Sastanak
    using namespace Sastanak;

    //**************************************************************************
    // [2] --- 2 BODA
    cout << "--- [2] ---\n";

    Tocka t1(1, "Tocka prva", "Citanje zapisnika");
    Tocka t2; // postavlja točku na: 0, "Točka 0", "Razno"
    Tocka t3(2, "Tocka druga", "Izvjesce povjerenika");
    Tocka t4(3, "Tocka treca", "Plan rada");
    vector<Tocka> tocke{ t1, t2, t3, t4 };

    // * ispisuje se "neispravna točka" 
    // (razred Tocka treba provjeravati jesu li svi podaci navedeni: redni broj, naziv i opis)
    // * razred NeispravnaTocka mora imati samo konstruktor koji prima tekst
    // poruke (nema drugih funkcija) i nasljeđivati od razreda "exception"
    try {
        Tocka t(4, "Tocka cetvrta", "");  // prazan opis - baca se iznimka
    }
    catch (NeispravnaTocka& e) {
        cout << e.what() << endl;
    }

    //**************************************************************************
    // [3] --- 2 BODA
    cout << "--- [3] ---\n";

    cout << (string)t1 << endl;  // ispisuje "Tocka prva - Citanje zapisnika"
    cout << t1 << endl;  // ispisuje "Ad1;Tocka prva;Citanje zapisnika"


    //**************************************************************************
    // [4] --- 4 BODA
    cout << "--- [4] ---\n";

    // * ovdje upotrijebiti funkciju "sort" zaglavlja "algorithm"
    // * za razred Tocka treba definirati i kopirni operator pridruživanja
    sort(tocke.begin(), tocke.end());
    ispisi(tocke);  // ispisuje točke sortirane po rednom broju

    //**************************************************************************
    // [5] --- 2 BODA
    cout << "--- [5] ---\n";

    // * ovdje upotrijebiti funkciju "sort" zaglavlja "algorithm"
    // * varijabla slaganje_tocaka mora sadrzavati lambda-izraz
    sort(tocke.begin(), tocke.end(), slaganje_tocaka);
    ispisi(tocke);  // ispisuje točke sortirane po rednom broju obratnim redoslijedom

    //**************************************************************************
    // [6] --- 6 BODOVA
    cout << "--- [6] ---\n";

    vector<ElementDnevnogReda*> red{ &t1, &t2, &t3, &t4 };
    sort(red.begin(), red.end(), usporedba_tocaka);

    // Funkcijom "tekstualno" demonstrirati polimorfizam; razred ElementDnevnogReda
    // mora biti apstraktan s jednom funkcijom "tekstualno"!

    // ispisuje točke sortirane po rednom broju
    for (vector<ElementDnevnogReda*>::const_iterator itr = red.begin();
        itr != red.end(); ++itr) {
        cout << (*itr)->tekstualno() << endl;
    }

    //**************************************************************************
    // [7] --- 6 BODOVA
    cout << "--- [7] ---\n";

    Tocka s(5, "Peta tocka", "Glasanje", new Odgovor("kolega A - za"));
    Tocka z = s;

    // nadovezuje tekst zadan s "nadodaj" s tekstom zadanim s konstruktoru
    s.odgovor()->nadodaj("kolega B - protiv");

    // ispisuje "kolega A - za; kolega B - protiv"
    cout << s.odgovor()->tekst() << endl;

    // ispisuje "kolega A - za"
    cout << z.odgovor()->tekst() << endl;

    //**************************************************************************
    // [8] --- 5 BODOVA
    cout << "--- [8] ---\n";

    Zapisnik<Tocka> zapisnik;
    // Funkcija "nadodaj" mora biti napisana kao funkcija 
    // s neograničenim brojem parametara!
    zapisnik.nadodaj(t1, t4, t2);

    // ispisuje "Ad1;Tocka prva;Citanje zapisnika", "Ad3;Tocka treca;Plan rada", "Ad0;Tocka 0;Razno" 
    // (jedno ispod drugoga)
    zapisnik.ispisi();


    //**************************************************************************
    // [9] --- 2 BODA
    cout << "--- [9] ---\n";

    // Na kraju se mora ispisati broj koliko je objekata tipa Tocka uništeno!
    cout << Tocka::unisteno << endl;
    //**************************************************************************
}
