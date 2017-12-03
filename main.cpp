#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cstdio>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Adresat{
    int id = 0;
    string imie = "", nazwisko = "", numerTelefonu = "", email = "", adres = "";
};

string zamienWielkoscLiter (string tekstDoZamiany){
    transform(tekstDoZamiany.begin(),tekstDoZamiany.begin()+1,tekstDoZamiany.begin(),::toupper);
    transform(tekstDoZamiany.begin()+1,tekstDoZamiany.end(),tekstDoZamiany.begin()+1,::tolower);
return tekstDoZamiany;
}

void zapiszOsobyDoPliku (Adresat osoba, vector <Adresat> &ksiazkaAdresowa){
    fstream plik;
    plik.open("Ksiazka_Adresowa.txt", ios::out | ios::app);
    if (plik.good()==false && ksiazkaAdresowa.size()!=0){
        cout <<"plik nie istnieje!";
        exit(0);
    }
    plik<<osoba.id<<"|"<<osoba.imie<<"|"<<osoba.nazwisko<<"|"<<osoba.email<<"|"<<osoba.numerTelefonu<<"|"<<osoba.adres<<"|"<<endl;
    plik.close();
}

void zapiszOsobyDoPlikuNadpisujacPlik (vector <Adresat> &ksiazkaAdresowa){
    fstream plik;
    int i=0;
    plik.open("Ksiazka_Adresowa.txt", ios::out);
    if (plik.good()==false && ksiazkaAdresowa.size()!=0){
        cout <<"plik nie istnieje!";
        exit(0);
    }
    while (i<ksiazkaAdresowa.size()){
    plik<<ksiazkaAdresowa[i].id<<"|"<<ksiazkaAdresowa[i].imie<<"|"<<ksiazkaAdresowa[i].nazwisko<<"|"<<ksiazkaAdresowa[i].email<<"|"<<ksiazkaAdresowa[i].numerTelefonu<<"|"<<ksiazkaAdresowa[i].adres<<"|"<<endl;
    i++;
    }
    plik.close();
}

void wprowadzanieNowychOsobDoKsiazki (vector <Adresat> &ksiazkaAdresowa){
    Adresat osoba;
    int i=0;
    system ("cls");
    if (ksiazkaAdresowa.empty()==true){
        osoba.id = 1;
    }
    else{
        osoba.id = ksiazkaAdresowa.back().id + 1;
    }

    cout << "Podaj Imie: "<<endl;
    cin>> osoba.imie;
    osoba.imie = zamienWielkoscLiter(osoba.imie);
    cout <<"Podaj nazwisko: "<<endl;
    cin >> osoba.nazwisko;
    osoba.nazwisko = zamienWielkoscLiter(osoba.nazwisko);
    while (i <ksiazkaAdresowa.size()){
        if (ksiazkaAdresowa[i].imie == osoba.imie && ksiazkaAdresowa[i].nazwisko==osoba.nazwisko ){
            system ("cls");
            cout << "Taki uzytkownik juz istnieje. Wprowadz ponownie."<<endl;
            cout << "Podaj imie:"<<endl;
            cin>> osoba.imie;
            osoba.imie = zamienWielkoscLiter(osoba.imie);
            cout <<"Podaj nazwisko:"<<endl;
            cin >> osoba.nazwisko;
            osoba.nazwisko = zamienWielkoscLiter(osoba.nazwisko);
            i=0;
        }else{
            i++;
        }
    }
    cout <<"Podaj email: "<<endl;
    cin >> osoba.email;
    cout <<"Podaj numer telefonu: "<<endl;
    cin.sync();
    getline(cin,osoba.numerTelefonu);
    cout <<"Podaj adres: "<<endl;
    cin.sync();
    getline(cin,osoba.adres);

    ksiazkaAdresowa.push_back(osoba);

    zapiszOsobyDoPliku(osoba, ksiazkaAdresowa);

    cout << "Osoba zapisana w ksiazce adresowej pod numerem "<<ksiazkaAdresowa.size()<<endl;
    Sleep(3000);
}

void wyszukiwaniePoImieniu (vector <Adresat> &ksiazkaAdresowa){
    string imie;
    cout << "Podaj Imie: "<<endl;
    cin>> imie;
    int i = 0;
    system ("cls");
    while (i <ksiazkaAdresowa.size()){
        if (ksiazkaAdresowa[i].imie == imie){
            cout <<ksiazkaAdresowa[i].id<<"|"<<ksiazkaAdresowa[i].imie<<"|"<<ksiazkaAdresowa[i].nazwisko<<"|"<<ksiazkaAdresowa[i].email<<"|"<<ksiazkaAdresowa[i].numerTelefonu<<"|"<<ksiazkaAdresowa[i].adres<<"|"<<endl;
            cout << "-----------------------"<<endl;
            i++;
        }else{
            i++;
        }
    }
    system ("pause");
}

void wyszukiwaniePoNazwisku(vector <Adresat> &ksiazkaAdresowa){
    string nazwisko;
    cout << "Podaj Nazwisko: "<<endl;
    cin>> nazwisko;
    int i = 0;
    system ("cls");
    while (i <ksiazkaAdresowa.size()){
        if (ksiazkaAdresowa[i].nazwisko == nazwisko){
            cout <<ksiazkaAdresowa[i].id<<"|"<<ksiazkaAdresowa[i].imie<<"|"<<ksiazkaAdresowa[i].nazwisko<<"|"<<ksiazkaAdresowa[i].email<<"|"<<ksiazkaAdresowa[i].numerTelefonu<<"|"<<ksiazkaAdresowa[i].adres<<"|"<<endl;
            cout << "-----------------------"<<endl;
            i++;
        }else{
            i++;
        }
    }
    system ("pause");
}

void pokazWszystkich (vector <Adresat> &ksiazkaAdresowa){
    int i = 0;
    system ("cls");
    while (i <ksiazkaAdresowa.size()){
        cout <<ksiazkaAdresowa[i].id<<"|"<<ksiazkaAdresowa[i].imie<<"|"<<ksiazkaAdresowa[i].nazwisko<<"|"<<ksiazkaAdresowa[i].email<<"|"<<ksiazkaAdresowa[i].numerTelefonu<<"|"<<ksiazkaAdresowa[i].adres<<"|"<<endl;
        cout << "-----------------------"<<endl;
        i++;
    }
    system ("pause");
}

void usuwanieRekorduZPliku (vector <Adresat> &ksiazkaAdresowa){
string imie, nazwisko;
int i=0;

cout << "Wprowadz imie i nazwisko osoby do usuniecia z ksiazki adresowej:"<<endl;
cin >> imie; cin>> nazwisko;
imie = zamienWielkoscLiter(imie);
nazwisko = zamienWielkoscLiter(nazwisko);

    while (i <ksiazkaAdresowa.size()){
        if (ksiazkaAdresowa[i].imie == imie && ksiazkaAdresowa[i].nazwisko==nazwisko ){
            ksiazkaAdresowa.erase(ksiazkaAdresowa.begin()+i);
            cout << "Usuwanie zakonczone";
            Sleep(3000);
        }else if (i==ksiazkaAdresowa.size()-1 && (ksiazkaAdresowa[i].imie != imie || ksiazkaAdresowa[i].nazwisko!=nazwisko)){
            cout << "Brak takiej osoby. Wprowadz ponownie imie i nazwisko:";
            cin >> imie; cin>> nazwisko;
            imie = zamienWielkoscLiter(imie);
            nazwisko = zamienWielkoscLiter(nazwisko);
            i=0;
        }else{
            i++;
        }

    }
    zapiszOsobyDoPlikuNadpisujacPlik(ksiazkaAdresowa);
}

void edytujRekord (vector <Adresat> &ksiazkaAdresowa){
string imie, nazwisko, email, numerTelefonu, adres;
int i=0, wybor;

cout << "Wprowadz imie i nazwisko osoby do edycji:"<<endl;
cin >> imie; cin>> nazwisko;
imie = zamienWielkoscLiter(imie);
nazwisko = zamienWielkoscLiter(nazwisko);

    while (i <ksiazkaAdresowa.size()){
        if (ksiazkaAdresowa[i].imie == imie && ksiazkaAdresowa[i].nazwisko == nazwisko ){
            cout << "Jaka dane chcesz zmienic?"<<endl;
            cout << "1. Imie"<<endl;
            cout << "2. Nazwisko"<<endl;
            cout << "3. eMail"<<endl;
            cout << "4. Numer Telefonu"<<endl;
            cout << "5. Adres"<<endl;
            cout << "9. Cofnij"<<endl;

            cin >> wybor;
            system ("cls");
            switch(wybor){
                case 1:
                    cout <<"Wprowadz nowe imie:"<< endl;
                    cin >> imie;
                    imie = zamienWielkoscLiter(imie);
                    ksiazkaAdresowa[i].imie = imie;
                    cout << "Edycja zakonczona";
                    Sleep(3000);
                    break;
                case 2:
                    cout <<"Wprowadz nowe nazwisko:"<< endl;
                    cin >> nazwisko;
                    nazwisko = zamienWielkoscLiter(nazwisko);
                    ksiazkaAdresowa[i].nazwisko = nazwisko;
                    cout << "Edycja zakonczona";
                    Sleep(3000);
                    break;
                case 3:
                    cout <<"Wprowadz nowy eMail:"<< endl;
                    cin >> email;
                    ksiazkaAdresowa[i].email = email;
                    cout << "Edycja zakonczona";
                    Sleep(3000);
                    break;
                case 4:
                    cout <<"Wprowadz nowy numer telefonu:"<< endl;
                    cin >> numerTelefonu;
                    ksiazkaAdresowa[i].numerTelefonu = numerTelefonu;
                    cout << "Edycja zakonczona";
                    Sleep(3000);
                    break;
                case 5:
                    cout <<"Wprowadz nowy adres:"<< endl;
                    cin >>adres;
                    ksiazkaAdresowa[i].adres = adres;
                    cout << "Edycja zakonczona";
                    Sleep(3000);
                    break;
                case 9:
                    i=ksiazkaAdresowa.size();
                    break;
            }
            zapiszOsobyDoPlikuNadpisujacPlik(ksiazkaAdresowa);
        } else if (i==ksiazkaAdresowa.size()-1 && (ksiazkaAdresowa[i].imie != imie || ksiazkaAdresowa[i].nazwisko!=nazwisko)){
            cout << "Brak takiej osoby. Wprowadz ponownie imie i nazwisko:";
            cin >> imie; cin>> nazwisko;
            imie = zamienWielkoscLiter(imie);
            nazwisko = zamienWielkoscLiter(nazwisko);
            i=0;
        }else{
            i++;
            }
        }
}

void wczytajOsobyZPliku (vector <Adresat> &ksiazkaAdresowa){
    Adresat osoba;
    int nr_linii=1;
    int x=0;
    int licznik = 0;
    string linia;
    string rekordPomocniczy="";
    string wyrazPomocniczy="";
    fstream plik;

    plik.open("Ksiazka_Adresowa.txt", ios::in);

    while (getline(plik,linia)){
        switch(nr_linii){
        case 1:
            rekordPomocniczy = linia;
            for (int i = 0; i<rekordPomocniczy.length();i++){
                if (rekordPomocniczy[i]!=124){
                    wyrazPomocniczy+=rekordPomocniczy[i];
                } else if (rekordPomocniczy[i]==124){
                    licznik++;
                    switch(licznik){
                        case 1:
                            osoba.id = atoi(wyrazPomocniczy.c_str());
                            wyrazPomocniczy ="";
                            break;
                        case 2:
                            osoba.imie = wyrazPomocniczy;
                            wyrazPomocniczy ="";
                            break;
                        case 3:
                            osoba.nazwisko = wyrazPomocniczy;
                            wyrazPomocniczy ="";
                            break;
                        case 4:
                            osoba.email = wyrazPomocniczy;
                            wyrazPomocniczy = "";
                            break;
                        case 5:
                            osoba.numerTelefonu = wyrazPomocniczy;
                            wyrazPomocniczy = "";
                            break;
                        case 6:
                            osoba.adres = wyrazPomocniczy;
                            wyrazPomocniczy = "";
                            break;
                    }
                }
            }
            break;
        }
        if (nr_linii==1){
            ksiazkaAdresowa.push_back(osoba);
            licznik = 0;
            nr_linii=0;
        }
        nr_linii++;
    }
    plik.close();
}

int main(){
    vector <Adresat> ksiazkaAdresowa;

    char wybor=0;

    wczytajOsobyZPliku(ksiazkaAdresowa);

    while (1){
        system ("cls");
        cout << "Witaj w ksiazce adresowej. Co chcesz zrobic?"<<endl;
        cout << "1. Wprowadzenie nowej osoby do ksiazki"<<endl;
        cout << "2. Wyszukiwarka"<<endl;
        cout << "3. Usuniecie osoby z ksiazki adresowej"<<endl;
        cout << "4. Edytuj wybrany rekord"<<endl;
        cout << "9. Exit"<<endl;
        cin >> wybor;
        if (wybor =='1'){
            wprowadzanieNowychOsobDoKsiazki(ksiazkaAdresowa);
        } else if (wybor =='2'){
            while (1){
                int wybor2;
                system ("cls");
                cout << "Wybierz rodzaj wyszukiwania"<<endl;
                cout << "1. Wyszukiwanie po imieniu"<<endl;
                cout << "2. Wyszukiwanie po nazwisku"<<endl;
                cout << "3. Pokaz cala ksiazke adresowa"<<endl;
                cout << "9. Wroc do wczesniejszego menu"<<endl;

                cin >> wybor2;

                if (wybor2 ==1){
                    wyszukiwaniePoImieniu (ksiazkaAdresowa);
                } else if (wybor2 == 2){
                    wyszukiwaniePoNazwisku (ksiazkaAdresowa);
                } else if (wybor2 == 3){
                    pokazWszystkich (ksiazkaAdresowa);
                } else if (wybor2 == 9){
                    break;
                }else {
                    cout << "Podano zly numer, wybierz ponownie."<<endl;
                    Sleep(2500);
                }
            }
        } else if (wybor =='3'){
            usuwanieRekorduZPliku (ksiazkaAdresowa);
        } else if (wybor == '4'){
            edytujRekord(ksiazkaAdresowa);
        } else if (wybor = '9'){
            cout << "Dziekuje za skorzystanie z ksiazki adresowej. Do zobaczenia."<<endl;
            Sleep(2500);
            exit(0);
        }
    }
    return 0;
}
