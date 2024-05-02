/*
U učionici se nalazi nekoliko prenosivih računala. 
Riječ je tablet i laptop računalima različitih proizvođača na kojima se nalaze različiti operacijski sustavi. 
Slijedeći programski kod u nastavku napišite sve potrebne klase, metode i funkcije koje su potrebne da bi funkcija main radila kao što je to i predviđeno.

int main(){
    int brTableta, brLaptopa;
    int brAndroida, brWindowsa, brLinuxa;

    Tablet Acer("Android"), Prestigio("Windows");
    Laptop Dell("Linux"), IBM("Windows"), Toshiba("Windows");

    vector<Racunalo*> Ucionica1 = { &Acer, &Prestigio, &Dell, &IBM, &Toshiba };
    AnalizaUcionice(Ucionica1, &brTableta, &brLaptopa, &brAndroida, &brWindowsa, &brLinuxa);


    // u nastavku ispisite dobivenu analizu ucionice u sljedecem obliku:

    //U ucionici se nalazi 5 racunala
    //Broj tablet racunala : 2
    //Broj laptop racunala : 3
    //Android OS : 1
    //Windows OS : 3
    //Linux OS : 1
    
    return 0;
}

Napomena: Klasa Racunalo  je apstraktna - demonstrirati polimorfizam unutar funkcije AnalizaUcionice prilikom provjere tipa računala (tablet ili laptop).
*/

#include <iostream>
#include <vector>

using namespace std;

class Racunalo {
public:
    Racunalo(const string& os) : operacijskiSustav(os) {}
    virtual ~Racunalo() {}

    string getOperacijskiSustav() const {
        return operacijskiSustav;
    }

    virtual string getType() const = 0;

private:
    string operacijskiSustav;
};

class Tablet : public Racunalo {
public:
    Tablet(const string& os) : Racunalo(os) {}

    string getType() const override {
        return "Tablet";
    }
};

class Laptop : public Racunalo {
public:
    Laptop(const string& os) : Racunalo(os) {}

    string getType() const override {
        return "Laptop";
    }
};

void AnalizaUcionice(const vector<Racunalo*>& racunala, int* brTableta, int* brLaptopa, int* brAndroida, int* brWindowsa, int* brLinuxa) {
    *brTableta = 0;
    *brLaptopa = 0;
    *brAndroida = 0;
    *brWindowsa = 0;
    *brLinuxa = 0;

    for (const auto& racunalo : racunala) {
        if (racunalo->getType() == "Tablet") {
            (*brTableta)++;
        }
        else if (racunalo->getType() == "Laptop") {
            (*brLaptopa)++;
        }

        if (racunalo->getOperacijskiSustav() == "Android") {
            (*brAndroida)++;
        }
        else if (racunalo->getOperacijskiSustav() == "Windows") {
            (*brWindowsa)++;
        }
        else if (racunalo->getOperacijskiSustav() == "Linux") {
            (*brLinuxa)++;
        }
    }
}

int main() {
    int brTableta, brLaptopa;
    int brAndroida, brWindowsa, brLinuxa;

    Tablet Acer("Android"), Prestigio("Windows");
    Laptop Dell("Linux"), IBM("Windows"), Toshiba("Windows");

    vector<Racunalo*> Ucionica1 = { &Acer, &Prestigio, &Dell, &IBM, &Toshiba };
    AnalizaUcionice(Ucionica1, &brTableta, &brLaptopa, &brAndroida, &brWindowsa, &brLinuxa);


    /* u nastavku ispisite dobivenu analizu ucionice u sljedecem obliku:

    U ucionici se nalazi 5 racunala
    Broj tablet racunala : 2
    Broj laptop racunala : 3
    Android OS : 1
    Windows OS : 3
    Linux OS : 1
    */

    cout << "U ucionici se nalazi " << Ucionica1.size() << " racunala" << endl;
    cout << "Broj tablet racunala : " << brTableta << endl;
    cout << "Broj laptop racunala : " << brLaptopa << endl;
    cout << "Android OS : " << brAndroida << endl;
    cout << "Windows OS : " << brWindowsa << endl;
    cout << "Linux OS : " << brLinuxa << endl;
    return 0;
}
