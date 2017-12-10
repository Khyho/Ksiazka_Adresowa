#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cstdio>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

struct Adresat{
    int id = 0, idUzytkownika = 0;
    string imie = "", nazwisko = "", numerTelefonu = "", email = "", adres = "";
};

struct Uzytkownik{
    int idUzytkownika = 0;
    string login = "", haslo = "";
};

string zamienWielkoscLiter (string tekstDoZamiany){
    transform(tekstDoZamiany.begin(),tekstDoZamiany.begin()+1,tekstDoZamiany.begin(),::toupper);
    transform(tekstDoZamiany.begin()+1,tekstDoZamiany.end(),tekstDoZamiany.begin()+1,::tolower);
return tekstDoZamiany;
}

void wczytajOsobyZPlikuDlaDanegoUzytkownika (vector <Adresat> &ksiazkaAdresowa, int idUzytkownika){
    Adresat osoba;
    int nr_linii=1;
    int x=0;
    int licznik = 0;
    string linia;
    string rekordPomocniczy="";
    string wyrazPomocniczy="";
    fstream plik;

    ksiazkaAdresowa.clear();

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
                            osoba.idUzytkownika = atoi(wyrazPomocniczy.c_str());
                            wyrazPomocniczy ="";
                            break;
                        case 3:
                            osoba.imie = wyrazPomocniczy;
                            wyrazPomocniczy ="";
                            break;
                        case 4:
                            osoba.nazwisko = wyrazPomocniczy;
                            wyrazPomocniczy ="";
                            break;
                        case 5:
                            osoba.email = wyrazPomocniczy;
                            wyrazPomocniczy = "";
                            break;
                        case 6:
                            osoba.numerTelefonu = wyrazPomocniczy;
                            wyrazPomocniczy = "";
                            break;
                        case 7:
                            osoba.adres = wyrazPomocniczy;
                            wyrazPomocniczy = "";
                            break;
                    }
                }
            }
            break;

        }
        if (nr_linii==1 && osoba.idUzytkownika==idUzytkownika){
            ksiazkaAdresowa.push_back(osoba);
            licznik = 0;
            nr_linii=0;
        }
        else {
            licznik = 0;
            nr_linii=0;
        }
        nr_linii++;
    }
    plik.close();
}

void zapiszOsobyDoPliku (Adresat osoba, vector <Adresat> &ksiazkaAdresowa){
    fstream plik;
    plik.open("Ksiazka_Adresowa.txt", ios::out | ios::app);
    if (plik.good()==false && ksiazkaAdresowa.size()!=0){
        cout <<"plik nie istnieje!";
        exit(0);
    }
    plik<<osoba.id<<"|"<<osoba.idUzytkownika<<"|"<<osoba.imie<<"|"<<osoba.nazwisko<<"|"<<osoba.email<<"|"<<osoba.numerTelefonu<<"|"<<osoba.adres<<"|"<<endl;
    plik.close();
}

void wczytajWszystkieOsobyZPliku (vector <Adresat> &ksiazkaAdresowa){
    Adresat osoba;
    int nr_linii=1;
    int x=0;
    int licznik = 0;
    string linia;
    string rekordPomocniczy="";
    string wyrazPomocniczy="";
    fstream plik;

    ksiazkaAdresowa.clear();

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
                            osoba.idUzytkownika = atoi(wyrazPomocniczy.c_str());
                            wyrazPomocniczy ="";
                            break;
                        case 3:
                            osoba.imie = wyrazPomocniczy;
                            wyrazPomocniczy ="";
                            break;
                        case 4:
                            osoba.nazwisko = wyrazPomocniczy;
                            wyrazPomocniczy ="";
                            break;
                        case 5:
                            osoba.email = wyrazPomocniczy;
                            wyrazPomocniczy = "";
                            break;
                        case 6:
                            osoba.numerTelefonu = wyrazPomocniczy;
                            wyrazPomocniczy = "";
                            break;
                        case 7:
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

void zapiszOsobyDoPlikuNadpisujacPlik (vector <Adresat> &ksiazkaAdresowa, int idUzytkownika){

    fstream plik;
    int i=0;
    plik.open("Ksiazka_Adresowa.txt", ios::out);
    if (plik.good()==false && ksiazkaAdresowa.size()!=0){
        cout <<"plik nie istnieje!";
        exit(0);
    }
    while (i<ksiazkaAdresowa.size()){
    plik<<ksiazkaAdresowa[i].id<<"|"<<ksiazkaAdresowa[i].idUzytkownika<<"|"<<ksiazkaAdresowa[i].imie<<"|"<<ksiazkaAdresowa[i].nazwisko<<"|"<<ksiazkaAdresowa[i].email<<"|"<<ksiazkaAdresowa[i].numerTelefonu<<"|"<<ksiazkaAdresowa[i].adres<<"|"<<endl;
    i++;
    }
    plik.close();

    ksiazkaAdresowa.clear();

    wczytajOsobyZPlikuDlaDanegoUzytkownika (ksiazkaAdresowa, idUzytkownika);
}

int okreslID (vector <Adresat> &ksiazkaAdresowa, int idUzytkownika){
    int id = 0;
    ksiazkaAdresowa.clear();
    wczytajWszystkieOsobyZPliku(ksiazkaAdresowa);

    if (ksiazkaAdresowa.empty()==true){
        id = 1;
    }
    else{
        id = ksiazkaAdresowa.back().id + 1;
    }

    ksiazkaAdresowa.clear();
    wczytajOsobyZPlikuDlaDanegoUzytkownika (ksiazkaAdresowa, idUzytkownika);

    return id;
}

void wprowadzanieNowychOsobDoKsiazki (vector <Adresat> &ksiazkaAdresowa, int idUzytkownika){
    Adresat osoba;
    int i=0;
    system ("cls");

    osoba.id = okreslID(ksiazkaAdresowa, idUzytkownika);

    osoba.idUzytkownika = idUzytkownika;

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

    cout << "Osoba zapisana w ksiazce adresowej pod numerem "<<osoba.id<<endl;
    Sleep(3000);
}

void wyszukiwaniePoImieniu (vector <Adresat> &ksiazkaAdresowa){
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!ksiazkaAdresowa.empty())
    {   cout << "Wyszukaj osoby o imieniu: ";
        cin >> imiePoszukiwanegoAdresata;
        imiePoszukiwanegoAdresata = zamienWielkoscLiter(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = ksiazkaAdresowa.begin(); itr != ksiazkaAdresowa.end(); itr++)
        {
            if (itr -> imie == imiePoszukiwanegoAdresata)
            {
                cout << endl;
                cout << "Id:                 " << itr -> id << endl;
                cout << "Imie:               " << itr -> imie << endl;
                cout << "Nazwisko:           " << itr -> nazwisko << endl;
                cout << "Numer Telefonu:     " << itr -> numerTelefonu << endl;
                cout << "Nr Email:           " << itr -> email << endl;
                cout << "Adres:              " << itr -> adres << endl;
                iloscAdresatow++;
            }
        }
        if (iloscAdresatow == 0)
        {
            cout << endl << "Nie ma adresatow z tym imieniem w ksiazce adresowej" << endl;
        }
        else
        {
            cout << endl << "Ilosc adresatow z imieniem: >>> " << imiePoszukiwanegoAdresata << " <<<";
            cout << " w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
        }
    }
    else
    {
        cout << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void wyszukiwaniePoNazwisku(vector <Adresat> &ksiazkaAdresowa){
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!ksiazkaAdresowa.empty())
    {   cout << "Wyszukaj adresatow o nazwisku: ";
        cin >> nazwiskoPoszukiwanegoAdresata;
        nazwiskoPoszukiwanegoAdresata = zamienWielkoscLiter(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = ksiazkaAdresowa.begin(); itr != ksiazkaAdresowa.end(); itr++)
        {
            if (itr -> nazwisko == nazwiskoPoszukiwanegoAdresata)
            {
                cout << endl;
                cout << "Id:                 " << itr -> id << endl;
                cout << "Imie:               " << itr -> imie << endl;
                cout << "Nazwisko:           " << itr -> nazwisko << endl;
                cout << "Numer Telefonu:     " << itr -> numerTelefonu << endl;
                cout << "Nr Email:           " << itr -> email << endl;
                cout << "Adres:              " << itr -> adres << endl;
                iloscAdresatow++;
            }
        }
        if (iloscAdresatow == 0)
        {
            cout << endl << "Nie ma adresatow z tym imieniem w ksiazce adresowej" << endl;
        }
        else
        {
            cout << endl << "Ilosc adresatow z nazwiskiem: >>> " << nazwiskoPoszukiwanegoAdresata << " <<<";
            cout << " w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
        }
    }
    else
    {
        cout << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void pokazWszystkich (vector <Adresat> &ksiazkaAdresowa){
    system("cls");
    if (!ksiazkaAdresowa.empty())
    {
        for (vector <Adresat> :: iterator itr = ksiazkaAdresowa.begin(); itr != ksiazkaAdresowa.end(); itr++)
        {
            cout << "Id:                 " << itr -> id << endl;
            cout << "Imie:               " << itr -> imie << endl;
            cout << "Nazwisko:           " << itr -> nazwisko << endl;
            cout << "Numer telefonu:     " << itr -> numerTelefonu << endl;
            cout << "Email:              " << itr -> email << endl;
            cout << "Adres:              " << itr -> adres << endl << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "Ksiazka adresowa jest pusta." << endl << endl;
    }

    system("pause");
}

void usuwanieRekorduZPliku (vector <Adresat> &ksiazkaAdresowa, int idUzytkownika){
    int idUsuwanejOsoby = 0;
    char znak;
    bool czyIstniejeAdresat = false;

    system("cls");
    if (!ksiazkaAdresowa.empty())
    {
        cout << "Podaj numer ID osoby do usuniecia: ";
        cin >> idUsuwanejOsoby;

        if (cin.fail())
        {
            cout << endl << "Wprowadzono niepoprawne dane. Powrot do menu glownego" << endl;
            cin.clear();
            cin.sync();
        }
        else
        {
            for (vector <Adresat>::iterator itr = ksiazkaAdresowa.begin(); itr != ksiazkaAdresowa.end(); itr++)
            {
                if (itr -> id == idUsuwanejOsoby)
                {
                    czyIstniejeAdresat = true;
                    cout << endl << endl << "Potwierdz naciskajac klawisz 't': ";
                    cin >> znak;
                    if (znak == 't')
                    {   wczytajWszystkieOsobyZPliku (ksiazkaAdresowa);
                        ksiazkaAdresowa.erase(ksiazkaAdresowa.begin()+idUsuwanejOsoby-1);
                        cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                        zapiszOsobyDoPlikuNadpisujacPlik(ksiazkaAdresowa, idUzytkownika);
                        break;
                    }
                    else
                    {
                        cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                        break;
                    }
                }
            }
            if (czyIstniejeAdresat == false)
            {
                cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
            }
        }
    }
    else
    {
        cout << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    system("pause");
}

void edytujRekord (vector <Adresat> &ksiazkaAdresowa, int idUzytkownika){
    int idWybranegoAdresata = 0;
    char wybor;
    bool czyIstniejeAdresat = false;

    system("cls");
    if (!ksiazkaAdresowa.empty())
    {   wczytajWszystkieOsobyZPliku (ksiazkaAdresowa);
        cout << "Podaj numer ID osoby do edycji: ";
        cin >> idWybranegoAdresata;

        if (cin.fail())
        {
            cout << endl << "Wprowadzono niepoprawne dane. Powrot do menu glownego" << endl << endl;
            cin.clear();
            cin.sync();
        }
        else
        {
            for (vector <Adresat>::iterator itr = ksiazkaAdresowa.begin(); itr != ksiazkaAdresowa.end(); itr++)
            {
                if (itr -> id == idWybranegoAdresata)
                {
                    czyIstniejeAdresat = true;

                    cout << "Jaka dane chcesz zmienic?"<<endl;
                    cout << "1. Imie"<<endl;
                    cout << "2. Nazwisko"<<endl;
                    cout << "3. eMail"<<endl;
                    cout << "4. Numer Telefonu"<<endl;
                    cout << "5. Adres"<<endl;
                    cout << "9. Cofnij"<<endl;
                    cin >> wybor;

                    switch (wybor)
                    {
                    case '1':
                        cout << "Podaj nowe imie: ";
                        cin >> itr -> imie;
                        itr -> imie = zamienWielkoscLiter(itr -> imie);
                        cout << endl << "Imie zostalo zmienione" << endl << endl;
                        zapiszOsobyDoPlikuNadpisujacPlik(ksiazkaAdresowa, idUzytkownika);
                        break;
                    case '2':
                        cout << "Podaj nowe nazwisko: ";
                        cin >> itr -> nazwisko;
                        itr -> nazwisko = zamienWielkoscLiter(itr -> nazwisko);
                        cout << endl << "Nazwisko zostalo zmienione" << endl << endl;
                        zapiszOsobyDoPlikuNadpisujacPlik(ksiazkaAdresowa, idUzytkownika);
                        break;
                    case '3':
                        cout << "Podaj nowy numer telefonu: ";
                        cin >> itr -> numerTelefonu;
                        cout << endl << "Numer telefonu zostal zmieniony" << endl << endl;
                        zapiszOsobyDoPlikuNadpisujacPlik(ksiazkaAdresowa, idUzytkownika);
                        break;
                    case '4':
                        cout << "Podaj nowy email: ";
                        cin >> itr -> email;
                        cout << endl << "Email zostal zmieniony" << endl << endl;
                        zapiszOsobyDoPlikuNadpisujacPlik(ksiazkaAdresowa, idUzytkownika);
                        break;
                    case '5':
                        cout << "Podaj nowy adres zamieszkania: ";
                        cin >> itr -> adres;
                        itr -> adres = zamienWielkoscLiter(itr -> adres);
                        cout << endl << "Adres zostal zmieniony" << endl << endl;
                        zapiszOsobyDoPlikuNadpisujacPlik(ksiazkaAdresowa, idUzytkownika);
                        break;
                    case '6':
                        cout << endl << "Powrot do menu glownego" << endl << endl;
                        break;
                    default:
                        cout << endl << "Nie ma takiej opcji w menu! Powrot do menu glownego." << endl << endl;
                        break;
                    }
                }
            }
            if (czyIstniejeAdresat == false)
            {
                cout << endl << "Nie ma takiego adresata w ksiazce adresowej." << endl << endl;
            }
        }
    }
    else
    {
        cout << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

int logowanie (vector <Uzytkownik> &daneDoLogowania){
    string login, haslo;
    bool czyUdaloSieZalogowac = false;
    cout << "LOGOWANIE"<<endl;
    cout << "Wprowadz login: "<<endl;
    cin >> login;

    cout << "Wprowadz haslo: "<<endl;
    cin >> haslo;

    while (!daneDoLogowania.empty()){
        for (vector <Uzytkownik>::iterator itr = daneDoLogowania.begin(); itr != daneDoLogowania.end();itr++){
            if (itr -> login == login && itr -> haslo == haslo){
                cout << "Login i haslo poprawne. Zalogowano uzytkownika nr "<<itr -> idUzytkownika;
                Sleep(3000);
                system("cls");
                czyUdaloSieZalogowac=true;
                return itr -> idUzytkownika;
            }
        }
        if (czyUdaloSieZalogowac==false){
            cout << "Blednie wprowadzone dane. Nie udalo sie zalogowac."<<endl;
            Sleep(3000);
            system ("cls");
            cout << "Wprowadz login: "<<endl;
            cin >> login;

            cout << "Wprowadz haslo: "<<endl;
            cin >> haslo;
            vector <Uzytkownik>::iterator itr = daneDoLogowania.begin();
        }
    }
}

void zapiszUzytkownikowWPliku (Uzytkownik uzytkownikProgramu, vector <Uzytkownik> &daneDoLogowania){
    fstream plik;
    plik.open("Uzytkownicy.txt", ios::out | ios::app);
    if (plik.good()==false && daneDoLogowania.size()!=0){
        cout <<"plik nie istnieje!";
        exit(0);
    }
    plik<<uzytkownikProgramu.idUzytkownika<<"|";
    plik<<uzytkownikProgramu.login<<"|";
    plik<<uzytkownikProgramu.haslo<<"|"<<endl;
    plik.close();
}

void zapiszUzytkownikowWPlikuNadpisujacPlik (vector <Uzytkownik> &daneDoLogowania){
    fstream plik;
    plik.open("Uzytkownicy.txt", ios::out);
    if (plik.good()==false && daneDoLogowania.size()!=0){
        cout <<"plik nie istnieje!";
        exit(0);
    }
    for (vector <Uzytkownik>::iterator itr = daneDoLogowania.begin(); itr != daneDoLogowania.end(); itr++){
    plik<<itr -> idUzytkownika<<"|";
    plik<<itr -> login<<"|";
    plik<<itr -> haslo<<"|"<<endl;
    }
    plik.close();
}

void rejestracja (vector <Uzytkownik> &daneDoLogowania) {
    Uzytkownik uzytkownikProgramu;
    int i=0;
    system ("cls");
    if (daneDoLogowania.empty()==true){
        uzytkownikProgramu.idUzytkownika = 1;
    }
    else{
        uzytkownikProgramu.idUzytkownika = daneDoLogowania.back().idUzytkownika + 1;
    }

    cout << "Podaj Login: "<<endl;
    cin>> uzytkownikProgramu.login;

    cout <<"Podaj haslo: "<<endl;
    cin >> uzytkownikProgramu.haslo;

    while (i <daneDoLogowania.size()){
        if (daneDoLogowania[i].login == uzytkownikProgramu.login && daneDoLogowania[i].haslo==uzytkownikProgramu.haslo ){
            system ("cls");
            cout << "Taki uzytkownik juz istnieje. Wprowadz ponownie."<<endl;
            cout << "Podaj Login: "<<endl;
            cin>> uzytkownikProgramu.login;

            cout <<"Podaj haslo: "<<endl;
            cin >> uzytkownikProgramu.haslo;
        }else{
            i++;
        }
    }

    daneDoLogowania.push_back(uzytkownikProgramu);

    zapiszUzytkownikowWPliku(uzytkownikProgramu, daneDoLogowania);

    cout << "Utworzono nowego uzytkownika o numerze "<<uzytkownikProgramu.idUzytkownika<<endl;
    Sleep(3000);

}

void wczytajUzytkownikowProgramu (vector <Uzytkownik> &daneDoLogowania){
    Uzytkownik uzytkownikProgramu;
    int nr_linii=1;
    int x=0;
    int licznik = 0;
    string linia;
    string rekordPomocniczy="";
    string wyrazPomocniczy="";
    fstream plik;

    plik.open("Uzytkownicy.txt", ios::in);

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
                            uzytkownikProgramu.idUzytkownika = atoi(wyrazPomocniczy.c_str());
                            wyrazPomocniczy ="";
                            break;
                        case 2:
                            uzytkownikProgramu.login = wyrazPomocniczy;
                            wyrazPomocniczy ="";
                            break;
                        case 3:
                            uzytkownikProgramu.haslo = wyrazPomocniczy;
                            wyrazPomocniczy ="";
                            break;
                    }
                }
            }
            break;
        }
        if (nr_linii==1){
            daneDoLogowania.push_back(uzytkownikProgramu);
            licznik = 0;
            nr_linii=0;
        }
        nr_linii++;
    }
    plik.close();
}

void zmianaHasla (vector <Uzytkownik> &daneDoLogowania, int idUzytkownika){
    string noweHaslo;
    cout << "Wprowadz nowe haslo: ";
    cin >> noweHaslo;
    vector <Uzytkownik>::iterator itr = daneDoLogowania.begin()+idUzytkownika-1;
    itr -> haslo = noweHaslo;
    zapiszUzytkownikowWPlikuNadpisujacPlik(daneDoLogowania);

}

int main(){
    vector <Adresat> ksiazkaAdresowa;
    vector <Uzytkownik> daneDoLogowania;
    int wybor=0, idUzytkownika=0;

    wczytajUzytkownikowProgramu(daneDoLogowania);

    while (1){
        system ("cls");
        cout << "Witaj w ksiazce adresowej. Co chcesz zrobic?"<<endl;
        cout << "1. Logowanie"<<endl;
        cout << "2. Rejestracja"<<endl;
        cout << "3. Wyjscie"<<endl;
        cin>>wybor;

        if (wybor == 1){
            idUzytkownika = logowanie(daneDoLogowania);
            wczytajOsobyZPlikuDlaDanegoUzytkownika(ksiazkaAdresowa, idUzytkownika);
            while (idUzytkownika!=0){
                system ("cls");
                cout << "1. Wprowadzenie nowej osoby do ksiazki"<<endl;
                cout << "2. Wyszukiwarka"<<endl;
                cout << "3. Usuniecie osoby z ksiazki adresowej"<<endl;
                cout << "4. Edytuj wybrany rekord"<<endl;
                cout << "5. Zmien haslo"<<endl;
                cout << "6. Wyloguj"<<endl;
                cin >> wybor;
                if (wybor == 1){
                    wprowadzanieNowychOsobDoKsiazki(ksiazkaAdresowa, idUzytkownika);
                } else if (wybor == 2){
                    while (1){
                        int wybor2;
                        system ("cls");
                        cout << "Wybierz rodzaj wyszukiwania"<<endl;
                        cout << "1. Wyszukiwanie po imieniu"<<endl;
                        cout << "2. Wyszukiwanie po nazwisku"<<endl;
                        cout << "3. Pokaz cala ksiazke adresowa"<<endl;
                        cout << "9. Wroc do wczesniejszego menu"<<endl;

                        cin >> wybor2;

                        if (wybor2 == 1){
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
                } else if (wybor == 3){
                    usuwanieRekorduZPliku (ksiazkaAdresowa, idUzytkownika);
                } else if (wybor == 4){
                    edytujRekord(ksiazkaAdresowa, idUzytkownika);
                } else if (wybor == 5){
                    zmianaHasla(daneDoLogowania, idUzytkownika);
                } else if (wybor == 6){
                    idUzytkownika=0;
                    cout << "Wylogowano.";
                    Sleep(3000);
                } else {
                    cout << "Podano zly numer, wybierz ponownie."<<endl;
                    Sleep(2500);
                }
            }
        } else if (wybor == 2){
            rejestracja(daneDoLogowania);
        } else if (wybor == 3){
            cout << "Dziekuje za skorzystanie z ksiazki adresowej. Do zobaczenia."<<endl;
            Sleep(2500);
            exit(0);
        } else {
            cout << "Podano zly numer, wybierz ponownie."<<endl;
            Sleep(2500);
        }
    }
    return 0;
}
