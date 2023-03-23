#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l;
        char bin[32];
        cin >> l;
        int x = 1;

        for (int j = 0; j < 32; j++) {
            if (l & (1 << (31 - j)))
                bin[j] = '1';
            else
                bin[j] = '0';
        }

        short mark = 0;
        if(bin[0] != 0)
            for (int j = 1; j < 32; j++) {
            if (bin[j] == '1'){
                mark = j;
                break;
            }
        }

        int licznik = 0;

        for (int j = mark; j < 32; j++) {
            cout << bin[j];
        }

        for (int j = mark; j < mark+((32-mark)/2); j++) {
            if (bin[j] != bin[31 - (j - mark)])
                licznik++;
        }
        cout << " - " << licznik << endl;
    }

}

/*
void zad1() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        if (i % 3 == 0)
            cout << endl << i;
    }
}

void zad2() {
    int n, licznik = 0;
    cin >> n;
    cout << "bin: ";
    while (n) {
        if (n % 2 == 1)
            licznik++;
        cout << n % 2;
        n /= 2;
    }
    cout << "\nLiczba jedynek: " << licznik << endl;
}

void zad3() {
    int n, licznik = 0;
    cin >> n;
    if (n & (1<<2))
        cout << "bit ustawiony\n";

    for (int i = 0; i < 32; i++) {
        if (n & (1 << (31 - i)))
            cout << "1";
        else
            cout << "0";
    }
}

int main()
{
    cout << "zad3\n";
    zad3();

    return 0;
}*/