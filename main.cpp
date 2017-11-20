#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cstdio>
#include <fstream>

using namespace std;

struct OsobaWKsiazceAdresowej{
    int id;
    string imie;
    string nazwisko;
    int numerTelefonu;
    string email;
    string adres;
};

int wprowadzanieNowychOsobDoKsiazki (OsobaWKsiazceAdresowej zapisaneOsoby[], int liczbaOsobZapisanychWKsiazceAdresowej){
    string imie,nazwisko, email, adres;
    int id, numerTelefonu;
    int i = 0;
    cout << "Podaj Imie: "<<endl;
    cin>> imie;
    cout <<"Podaj nazwisko: "<<endl;
    cin >> nazwisko;
    while (i <liczbaOsobZapisanychWKsiazceAdresowej){
        if (zapisaneOsoby[i].imie == imie && zapisaneOsoby[i].nazwisko==nazwisko ){
            cout << "Taki uzytkownik juz istnieje"<<endl;
            cout << "Podaj Imie: "<<endl;
            cin>> imie;
            cout<<endl;
            cout <<"Podaj nazwisko: "<<endl;
            cin >> nazwisko;
            i=0;
        }else{
            i++;
        }
    }
    cout <<"Podaj email: "<<endl;
    cin >> email;
    cout <<"Podaj numer telefonu: "<<endl;
    cin >> numerTelefonu;
    cout <<"Podaj adres: "<<endl;
    cin.sync();
    getline(cin,adres);

    zapisaneOsoby[liczbaOsobZapisanychWKsiazceAdresowej].imie = imie;
    zapisaneOsoby[liczbaOsobZapisanychWKsiazceAdresowej].nazwisko = nazwisko;
    zapisaneOsoby[liczbaOsobZapisanychWKsiazceAdresowej].email = email;
    zapisaneOsoby[liczbaOsobZapisanychWKsiazceAdresowej].numerTelefonu = numerTelefonu;
    zapisaneOsoby[liczbaOsobZapisanychWKsiazceAdresowej].adres = adres;
    zapisaneOsoby[liczbaOsobZapisanychWKsiazceAdresowej].id = liczbaOsobZapisanychWKsiazceAdresowej+1;
    cout << "Osoba zapisana w ksiazce adresowej pod numerem "<<zapisaneOsoby[liczbaOsobZapisanychWKsiazceAdresowej].id<<endl;
    Sleep(3000);

    fstream plik;
    plik.open("Ksiazka_Adresowa.txt", ios::out | ios::app);
    if (plik.good()==false && liczbaOsobZapisanychWKsiazceAdresowej!=0){
        cout <<"plik nie istnieje!";
        exit(0);
    }
    plik<<zapisaneOsoby[liczbaOsobZapisanychWKsiazceAdresowej].id<<endl;
    plik<<zapisaneOsoby[liczbaOsobZapisanychWKsiazceAdresowej].imie<<endl;
    plik<<zapisaneOsoby[liczbaOsobZapisanychWKsiazceAdresowej].nazwisko<<endl;
    plik<<zapisaneOsoby[liczbaOsobZapisanychWKsiazceAdresowej].email<<endl;
    plik<<zapisaneOsoby[liczbaOsobZapisanychWKsiazceAdresowej].numerTelefonu<<endl;
    plik<<zapisaneOsoby[liczbaOsobZapisanychWKsiazceAdresowej].adres<<endl;
    plik.close();


    return liczbaOsobZapisanychWKsiazceAdresowej+1;
}

void wyszukiwaniePoImieniu (OsobaWKsiazceAdresowej zapisaneOsoby[], int liczbaOsobZapisanychWKsiazceAdresowej)
{
    string imie;
    cout << "Podaj Imie: "<<endl;
    cin>> imie;
    int i = 0;
    system ("cls");
    while (i <liczbaOsobZapisanychWKsiazceAdresowej){
        if (zapisaneOsoby[i].imie == imie){
            cout << zapisaneOsoby[i].imie<<endl;
            cout << zapisaneOsoby[i].nazwisko<<endl;
            cout << zapisaneOsoby[i].adres<<endl;
            cout << zapisaneOsoby[i].email<<endl;
            cout << zapisaneOsoby[i].numerTelefonu<<endl;
            cout << "-----------------------"<<endl;
            i++;
        }else{
            i++;
        }
    }
    system ("pause");
}

void wyszukiwaniePoNazwisku (OsobaWKsiazceAdresowej zapisaneOsoby[], int liczbaOsobZapisanychWKsiazceAdresowej){
    string nazwisko;
    cout << "Podaj Nazwisko: "<<endl;
    cin>> nazwisko;
    int i = 0;
    system ("cls");
    while (i <liczbaOsobZapisanychWKsiazceAdresowej){
        if (zapisaneOsoby[i].nazwisko == nazwisko){
            cout << zapisaneOsoby[i].imie<<endl;
            cout << zapisaneOsoby[i].nazwisko<<endl;
            cout << zapisaneOsoby[i].adres<<endl;
            cout << zapisaneOsoby[i].email<<endl;
            cout << zapisaneOsoby[i].numerTelefonu<<endl;
            cout << "-----------------------"<<endl;
            i++;
        }else{
            i++;
        }
    }
    system ("pause");
}

void pokazWszystkich (OsobaWKsiazceAdresowej zapisaneOsoby[], int liczbaOsobZapisanychWKsiazceAdresowej){
    int i = 0;
    system ("cls");
    while (i <liczbaOsobZapisanychWKsiazceAdresowej){
        cout << zapisaneOsoby[i].imie<<endl;
        cout << zapisaneOsoby[i].nazwisko<<endl;
        cout << zapisaneOsoby[i].adres<<endl;
        cout << zapisaneOsoby[i].email<<endl;
        cout << zapisaneOsoby[i].numerTelefonu<<endl;
        cout << "-----------------------"<<endl;
        i++;
    }
    system ("pause");
}
bool sprawdzCzyMiesciSieWZakresieLiczbyZapisanychOsob (int rekordDoUsuniecia, int liczbaOsobZapisanychWKsiazceAdresowej){
        if (rekordDoUsuniecia<=liczbaOsobZapisanychWKsiazceAdresowej){
            return true;
        }else if (rekordDoUsuniecia>liczbaOsobZapisanychWKsiazceAdresowej){
           return false;
        }
}

int usuwanieRekorduZPliku (OsobaWKsiazceAdresowej zapisaneOsoby[], int liczbaOsobZapisanychWKsiazceAdresowej){
    fstream plik;
    int i=0, j=0;
    int rekordDoUsuniecia;

    cout <<"Ktora osobe chcesz usunac z ksiazki adresowej? ";

        while(cin>>rekordDoUsuniecia){
           if (sprawdzCzyMiesciSieWZakresieLiczbyZapisanychOsob (rekordDoUsuniecia, liczbaOsobZapisanychWKsiazceAdresowej)==true){
            break;
           }
           else if (sprawdzCzyMiesciSieWZakresieLiczbyZapisanychOsob (rekordDoUsuniecia, liczbaOsobZapisanychWKsiazceAdresowej)==false){
            cout << "wartosc poza zakresem, wprowadz ponownie"<<endl;
            continue;
           }
        }

    plik.open("Ksiazka_Adresowa.txt", ios::out);

    if (plik.good()==false){
        cout <<"plik nie istnieje!";
        exit(0);
    }
    while (i<liczbaOsobZapisanychWKsiazceAdresowej){
        if (i!=(rekordDoUsuniecia-1) && i<(rekordDoUsuniecia-1)){
            plik<<zapisaneOsoby[i].id<<endl;
            plik<<zapisaneOsoby[i].imie<<endl;
            plik<<zapisaneOsoby[i].nazwisko<<endl;
            plik<<zapisaneOsoby[i].email<<endl;
            plik<<zapisaneOsoby[i].numerTelefonu<<endl;
            plik<<zapisaneOsoby[i].adres<<endl;
            i++;
        }else if (i!=(rekordDoUsuniecia-1) && i>(rekordDoUsuniecia-1)){
            plik<<zapisaneOsoby[i].id-1<<endl;
            plik<<zapisaneOsoby[i].imie<<endl;
            plik<<zapisaneOsoby[i].nazwisko<<endl;
            plik<<zapisaneOsoby[i].email<<endl;
            plik<<zapisaneOsoby[i].numerTelefonu<<endl;
            plik<<zapisaneOsoby[i].adres<<endl;

            zapisaneOsoby [i-1].id=zapisaneOsoby[i].id;
            zapisaneOsoby [i-1].imie=zapisaneOsoby[i].imie;
            zapisaneOsoby [i-1].nazwisko=zapisaneOsoby[i].nazwisko;
            zapisaneOsoby [i-1].email=zapisaneOsoby[i].email;
            zapisaneOsoby [i-1].numerTelefonu=zapisaneOsoby[i].numerTelefonu;
            zapisaneOsoby [i-1].adres=zapisaneOsoby[i].adres;
            i++;
        }else if (i==(rekordDoUsuniecia-1)){
            i++;
        }
    }
    plik.close();

    return (liczbaOsobZapisanychWKsiazceAdresowej-1);
}

int wczytajOsobyZPliku (OsobaWKsiazceAdresowej zapisaneOsoby[], int liczbaOsobZapisanychWKsiazceAdresowej){
    int nr_linii=1;
    int x=0;
    string linia;
    fstream plik;

    plik.open("Ksiazka_Adresowa.txt", ios::in);

    while (getline(plik,linia)){
        switch(nr_linii){
        case 1:
            zapisaneOsoby[x].id=atoi(linia.c_str());
            break;
        case 2:
            zapisaneOsoby[x].imie = linia;
            break;
        case 3:
            zapisaneOsoby[x].nazwisko=linia;
            break;
        case 4:
            zapisaneOsoby[x].email=linia;
            break;
        case 5:
            zapisaneOsoby[x].numerTelefonu=atoi(linia.c_str());
            break;
        case 6:
            zapisaneOsoby[x].adres=linia;
            break;
        }
        if (nr_linii==6){
            nr_linii=0;
            x++;
        }
        nr_linii++;
    }

    plik.close();
    liczbaOsobZapisanychWKsiazceAdresowej = zapisaneOsoby[x-1].id;
    return liczbaOsobZapisanychWKsiazceAdresowej;
}


int main(){
    OsobaWKsiazceAdresowej zapisaneOsoby[1000];
    int liczbaOsobZapisanychWKsiazceAdresowej = 0;
    char wybor=0;

    liczbaOsobZapisanychWKsiazceAdresowej = wczytajOsobyZPliku(zapisaneOsoby, liczbaOsobZapisanychWKsiazceAdresowej);

    while (1){
        system ("cls");
        cout << "Witaj w ksiazce adresowej. Co chcesz zrobic?"<<endl;
        cout << "1. Wprowadzenie nowej osoby do ksiazki"<<endl;
        cout << "2. Wyszukiwarka"<<endl;
        cout << "3. Usuniecie osoby z ksiazki adresowej"<<endl;
        cout << "9. Exit"<<endl;
        cin >> wybor;
        if (wybor =='1'){
            liczbaOsobZapisanychWKsiazceAdresowej = wprowadzanieNowychOsobDoKsiazki (zapisaneOsoby, liczbaOsobZapisanychWKsiazceAdresowej);
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
                    wyszukiwaniePoImieniu (zapisaneOsoby, liczbaOsobZapisanychWKsiazceAdresowej);
                } else if (wybor2 == 2){
                    wyszukiwaniePoNazwisku (zapisaneOsoby, liczbaOsobZapisanychWKsiazceAdresowej);
                } else if (wybor2 == 3){
                    pokazWszystkich (zapisaneOsoby, liczbaOsobZapisanychWKsiazceAdresowej);
                } else if (wybor2 == 9){
                    break;
                }else {
                    cout << "Podano zly numer, wybierz ponownie."<<endl;
                    Sleep(2500);
                }
            }
        } else if (wybor =='3'){
            liczbaOsobZapisanychWKsiazceAdresowej = usuwanieRekorduZPliku (zapisaneOsoby, liczbaOsobZapisanychWKsiazceAdresowej);
        } else if (wybor = '9'){
            cout << "Dziekuje za skorzystanie z ksiazki adresowej. Do zobaczenia."<<endl;
            Sleep(2500);
            exit(0);
        }
    }
    return 0;
}
