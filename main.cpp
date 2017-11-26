#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cstdio>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

string konwersjaIntNaString (int cyfra){
    ostringstream ss;
    ss << cyfra;
    string str = ss.str();

    return str;
}

vector <string> zapiszWKsiazceAdresowej(vector <string> ksiazkaAdresowa, string imie,string nazwisko,string email, string numerTelefonu,string adres){
    string rekordWKsiazceAdresowej = "";
    rekordWKsiazceAdresowej =  konwersjaIntNaString(ksiazkaAdresowa.size()+1)+ "|" + imie + "|" + nazwisko + "|" +email+ "|" +numerTelefonu+ "|" +adres + "|";
    ksiazkaAdresowa.push_back(rekordWKsiazceAdresowej);

    return ksiazkaAdresowa;
}

vector <string> wprowadzanieNowychOsobDoKsiazki (vector <string> ksiazkaAdresowa){

    string imie,nazwisko, email, adres, numerTelefonu;
    int id;
    int i = 0;
    cout << "Podaj Imie: "<<endl;
    cin>> imie;
    cout <<"Podaj nazwisko: "<<endl;
    cin >> nazwisko;
   while (i <ksiazkaAdresowa.size()){
        size_t pozycja = ksiazkaAdresowa[i].find(imie);
        size_t pozycja2 = ksiazkaAdresowa[i].find(nazwisko);
        if (pozycja!=string::npos && pozycja2!=string::npos){
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

    ksiazkaAdresowa = zapiszWKsiazceAdresowej(ksiazkaAdresowa, imie, nazwisko, email, numerTelefonu, adres);

    cout << "Osoba zapisana w ksiazce adresowej pod numerem "<<ksiazkaAdresowa.size()<<endl;
    Sleep(3000);

    fstream plik;
    plik.open("Ksiazka_Adresowa.txt", ios::out | ios::app);
    if (plik.good()==false && ksiazkaAdresowa.size()!=0){
        cout <<"plik nie istnieje!";
        exit(0);
    }
    plik<<ksiazkaAdresowa[ksiazkaAdresowa.size()-1]<<endl;
    plik.close();

    return ksiazkaAdresowa;
}

void wyszukiwaniePoImieniu (vector <string> ksiazkaAdresowa){
    string imie;
    cout << "Podaj Imie: "<<endl;
    cin>> imie;
    int i = 0;
    system ("cls");
    while (i < ksiazkaAdresowa.size()){
            size_t pozycja = ksiazkaAdresowa[i].find(imie);
            if (pozycja!=string::npos){
                cout<<ksiazkaAdresowa[i]<<endl;
                cout<<"----------------"<<endl;
                i++;
            } else{
                i++;
            }
           }
system("pause");
}

void wyszukiwaniePoNazwisku (vector <string> ksiazkaAdresowa){
    string nazwisko;
    cout << "Podaj Nazwisko: "<<endl;
    cin>> nazwisko;
    int i = 0;
    system ("cls");
    while (i < ksiazkaAdresowa.size()){
            size_t pozycja = ksiazkaAdresowa[i].find(nazwisko);
            if (pozycja!=string::npos){
                cout<<ksiazkaAdresowa[i]<<endl;
                cout<<"----------------"<<endl;
                i++;
            } else{
                i++;
            }
           }
system("pause");
}

void pokazWszystkich (vector <string> ksiazkaAdresowa){
    int i = 0;
    system ("cls");
    while (i <ksiazkaAdresowa.size()){
        cout << ksiazkaAdresowa[i]<<endl;
        cout << "-----------------------"<<endl;
        i++;
    }
    system ("pause");
}

bool sprawdzCzyMiesciSieWZakresieLiczbyZapisanychOsob (int rekordDoUsuniecia, vector <string> ksiazkaAdresowa){
        if (rekordDoUsuniecia<=ksiazkaAdresowa.size()){
            return true;
        }else if (rekordDoUsuniecia>ksiazkaAdresowa.size()){
           return false;
        }
}

string wyciagnijLiczbeZRekordu (string rekordPomocniczy){
    int numer=0;
    int i=0;
    string id;
    while (rekordPomocniczy[i] !=124){
        while (rekordPomocniczy[i]>=48 && rekordPomocniczy[i]<=57){
            numer = numer + rekordPomocniczy[i]-48;
                if (rekordPomocniczy[i+1]>=48 && rekordPomocniczy[i+1]<=57){
                    numer = numer * 10;
                }
             i++;
        }
    }
    numer = numer - 1;
    id = konwersjaIntNaString(numer);
return id;
}

vector <string> zmniejszIDoJeden (vector <string> ksiazkaAdresowa, int wybranyRekordDoUsuniecia){
 string rekordPomocniczy, id;
 int i=wybranyRekordDoUsuniecia-1;
 while (i<ksiazkaAdresowa.size()){
    rekordPomocniczy = ksiazkaAdresowa[i];
    id = wyciagnijLiczbeZRekordu (rekordPomocniczy);
        while (rekordPomocniczy[0]!=124){
            rekordPomocniczy.erase(0,1);
        }
        rekordPomocniczy.insert(0,id);
        ksiazkaAdresowa.erase(ksiazkaAdresowa.begin()+i);
        ksiazkaAdresowa.insert(ksiazkaAdresowa.begin()+i, rekordPomocniczy);
        i++;
 }
return ksiazkaAdresowa;
}

vector <string> usuwanieRekorduZPliku (vector <string> ksiazkaAdresowa){
    fstream plik;
    int i=0;
    int wybranyRekordDoUsuniecia;

    cout <<"Ktora osobe chcesz usunac z ksiazki adresowej? ";

        while(cin>>wybranyRekordDoUsuniecia){
           if (sprawdzCzyMiesciSieWZakresieLiczbyZapisanychOsob (wybranyRekordDoUsuniecia, ksiazkaAdresowa)==true){
            break;
           }
           else if (sprawdzCzyMiesciSieWZakresieLiczbyZapisanychOsob (wybranyRekordDoUsuniecia, ksiazkaAdresowa)==false){
            cout << "wartosc poza zakresem, wprowadz ponownie"<<endl;
            continue;
           }
        }

    ksiazkaAdresowa.erase(ksiazkaAdresowa.begin()+wybranyRekordDoUsuniecia-1);
    ksiazkaAdresowa = zmniejszIDoJeden(ksiazkaAdresowa, wybranyRekordDoUsuniecia);
    plik.open("Ksiazka_Adresowa.txt", ios::out);

    if (plik.good()==false){
        cout <<"plik nie istnieje!";
        exit(0);
    } while (i<ksiazkaAdresowa.size()){
        plik<<ksiazkaAdresowa[i]<<endl;
        i++;
    }
    plik.close();

    return ksiazkaAdresowa;
}

vector <string> wczytajOsobyZPliku (vector <string> ksiazkaAdresowa){
    int nr_linii=1;
    int x=0;
    string linia;
    fstream plik;

    plik.open("Ksiazka_Adresowa.txt", ios::in);

    while (getline(plik,linia)){
        switch(nr_linii){
        case 1:
            ksiazkaAdresowa.push_back(linia);
            break;
        }
        if (nr_linii==1){
            nr_linii=0;
        }
        nr_linii++;
    }

    plik.close();
   return ksiazkaAdresowa;

}

vector <string> edytujRekord (vector <string> ksiazkaAdresowa){
    int wybor, i=0, j=0;
    string imie,nazwisko, email, adres, numerTelefonu;
    cout << "Ktory rekord chcesz edytowac?"<<endl;
    cin >> wybor;

    cout << "Podaj Imie: "<<endl;
    cin>> imie;
    cout <<"Podaj nazwisko: "<<endl;
    cin >> nazwisko;
    while (i <ksiazkaAdresowa.size()){
        size_t pozycja = ksiazkaAdresowa[i].find(imie);
        size_t pozycja2 = ksiazkaAdresowa[i].find(nazwisko);
        if (pozycja!=string::npos && pozycja2!=string::npos){
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

    string rekordWKsiazceAdresowej = "";
    rekordWKsiazceAdresowej =  konwersjaIntNaString(wybor)+ "|" + imie + "|" + nazwisko + "|" +email+ "|" +numerTelefonu+ "|" +adres + "|";
    ksiazkaAdresowa.erase(ksiazkaAdresowa.begin()+wybor-1);
    ksiazkaAdresowa.insert(ksiazkaAdresowa.begin()+wybor-1, rekordWKsiazceAdresowej);

    fstream plik;
    plik.open("Ksiazka_Adresowa.txt", ios::out);

    if (plik.good()==false){
        cout <<"plik nie istnieje!";
        exit(0);
    } while (j<ksiazkaAdresowa.size()){
        plik<<ksiazkaAdresowa[j]<<endl;
        j++;
    }
    plik.close();

    cout << "Zedytowano rekord nr: "<<wybor;
    Sleep(3000);

    return ksiazkaAdresowa;
}

int main(){
    vector <string> ksiazkaAdresowa;

    char wybor=0;

    ksiazkaAdresowa = wczytajOsobyZPliku(ksiazkaAdresowa);

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
            ksiazkaAdresowa = wprowadzanieNowychOsobDoKsiazki(ksiazkaAdresowa);
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
           ksiazkaAdresowa = usuwanieRekorduZPliku (ksiazkaAdresowa);
        } else if (wybor == '4'){
            ksiazkaAdresowa = edytujRekord(ksiazkaAdresowa);
        } else if (wybor = '9'){
            cout << "Dziekuje za skorzystanie z ksiazki adresowej. Do zobaczenia."<<endl;
            Sleep(2500);
            exit(0);
        }
    }
    return 0;
}
