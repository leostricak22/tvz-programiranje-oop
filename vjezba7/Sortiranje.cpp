/*
Definirajte potrebne dijelove da bi funkcija "main" radila kako je opisano.

class Sortiranje {
public:
    virtual void sortiraj(vector<int>* vec) final {
        for (int i = 0; i < vec->size() - 1; ++i)
            for (int j = i + 1; j < vec->size(); ++j)
                if (!usporedba((*vec)[i], (*vec)[j])) {
                    swap((*vec)[i], (*vec)[j]);
                }
    }

    virtual bool usporedba(int e1, int e2) = 0;
};

int main() {
    vector<int> v = {8, 17, 1, 14, 5, 2, 19, 3, 15, 11};

    Sortiranje* sort1 = new SortVeciPremaManjem();
    sort1->sortiraj(&v);
    cout << v;        // ispisuje 19 17 15 14 11 8 5 3 2 1
    delete sort1;

    Sortiranje* sort2 = new SortManjiPremaVecem();
    sort2->sortiraj(&v);
    cout << v;        // ispisuje 1 2 3 5 8 11 14 15 17 19
    delete sort2;

    return 0;
}
*/

#include <iostream>
#include <vector>

using namespace std;

class Sortiranje {
public:
    virtual void sortiraj(vector<int>* vec) final {
        for (int i = 0; i < vec->size() - 1; ++i)
            for (int j = i + 1; j < vec->size(); ++j)
                if (!usporedba((*vec)[i], (*vec)[j])) {
                    swap((*vec)[i], (*vec)[j]);
                }
    }

    virtual bool usporedba(int e1, int e2) = 0;
};

ostream& operator<<(ostream& os, const vector<int>& vec) {
    for (int i = 0; i < vec.size();i++) {
        os << vec[i] << " ";
    }

    os << endl;

    return os;
}

class SortVeciPremaManjem : public Sortiranje {
public:
    virtual bool usporedba(int e1, int e2) override {
        return e1 > e2;
    }
};

class SortManjiPremaVecem : public Sortiranje {
public:
    virtual bool usporedba(int e1, int e2) override {
        return e1 < e2;
    }
};

int main() {
    vector<int> v = { 8, 17, 1, 14, 5, 2, 19, 3, 15, 11 };

    Sortiranje* sort1 = new SortVeciPremaManjem();
    sort1->sortiraj(&v);
    cout << v;        // ispisuje 19 17 15 14 11 8 5 3 2 1
    delete sort1;

    Sortiranje* sort2 = new SortManjiPremaVecem();
    sort2->sortiraj(&v);
    cout << v;        // ispisuje 1 2 3 5 8 11 14 15 17 19
    delete sort2;

    return 0;
}
