#include <iostream>

using namespace std;

enum TipPreliva{COKOLADNI,COKOLADNI_SA_SLAGOM};

class Preliv{
private:
    TipPreliva tip;

public:
    Preliv(){
        tip=COKOLADNI;
    }

    Preliv(TipPreliva a){
        tip=a;
    }

    bool dodajSlag(){
        if(tip==COKOLADNI){
            tip=COKOLADNI_SA_SLAGOM;
            return true;
        }
        return false;
    }

    bool ukloniSlag(){
        if(tip==COKOLADNI_SA_SLAGOM){
            tip=COKOLADNI;
            return true;
        }
        return false;
    }

    TipPreliva get_tip()const{
        return tip;
    }
};

void ispisiPreliv(const Preliv &p){
    cout<<"---------------"<<endl;
    cout<<"Preliv: ";
    if(p.get_tip()==COKOLADNI)
        cout<<"COKOLADNI"<<endl;
    else
        cout<<"COKOLADNI_SA_SLAGOM"<<endl;
    cout<<"---------------"<<endl;
}

enum KolacStanje{U_PRIPREMI,PECE_SE,ZAGOREO,PRIPREMLJEN};

class Kolac{
private:
    KolacStanje stanje;
    int temperatura;
    Preliv preliv;

public:
    Kolac(): preliv(){
        temperatura=20;
        stanje=U_PRIPREMI;
        preliv=COKOLADNI;
    }

    Kolac(const Kolac &p){
        stanje=p.stanje;
        temperatura=p.temperatura;
        preliv=p.preliv;
    }

    bool staviDaSePece(){
        if(stanje==U_PRIPREMI && preliv.get_tip()==COKOLADNI){
            temperatura+=10;
            stanje=PECE_SE;
            return true;
        }
        return false;
    }

    bool ispeciKolac(){
        if(stanje==PECE_SE){
            stanje=U_PRIPREMI;
            temperatura=20;
            return true;
        }
        return false;
    }

    bool zavrsiKolac(){
        if(stanje==U_PRIPREMI){
            stanje=PRIPREMLJEN;
            return true;
        }
        return false;
    }

    bool povecajTemperaturu(){
        if(stanje==PECE_SE){
            temperatura+=10;
            if(temperatura>100){
                stanje=ZAGOREO;
                temperatura=20;
            }
            return true;
        return false;
        }
    }

    bool smanjiTemperaturu(){
        if(stanje==PECE_SE && temperatura>=30){
            temperatura-=10;
            return true;
        }
        return false;
    }

    bool dodajSlag(){
        if(stanje==U_PRIPREMI)
            return preliv.dodajSlag();
        return false;
    }

    bool ukloniSlag(){
        if(stanje==U_PRIPREMI)
            return preliv.ukloniSlag();
        return false;
    }

    KolacStanje get_stanje()const{
        return stanje;
    }

    int get_temperatura()const{
        return temperatura;
    }

    Preliv get_preliv()const{
        return preliv;
    }
};

int meni(){
    int a;
    cout<<"1. Stavi da se pece"<<endl;
    cout<<"2. Ispeci kolac"<<endl;
    cout<<"3. Zavrsi kolac"<<endl;
    cout<<"4. Povecaj temperaturu"<<endl;
    cout<<"5. Smanji temperaturu"<<endl;
    cout<<"6. Dodaj slag"<<endl;
    cout<<"7. Ukloni slag"<<endl;
    cout<<"8. Kraj"<<endl;
    cin>>a;
    return a;
}

void ispisiKolac(const Kolac &p){
    cout<<"---------------"<<endl;
    cout<<"Stanje: ";
    if(p.get_stanje()==U_PRIPREMI)
        cout<<"U_PRIPREMI"<<endl;
    else
    if(p.get_stanje()==PECE_SE)
        cout<<"PECE_SE"<<endl;
    else
    if(p.get_stanje()==ZAGOREO)
        cout<<"ZAGOREO"<<endl;
    else
        cout<<"PRIPREMLJEN"<<endl;
    cout<<"Temperatura: "<<p.get_temperatura()<<endl;
    cout<<"Preliv: ";
    if(p.get_preliv().get_tip()==COKOLADNI)
        cout<<"COKOLADNI"<<endl;
    else
        cout<<"COKOLADNI_SA_SLAGOM"<<endl;
    cout<<"---------------"<<endl;
    }

int main()
{
    Kolac abc;
    while(1)
        switch(meni()){
            case 1:
                if(abc.staviDaSePece())
                    ispisiKolac(abc);
                break;
            case 2:
                if(abc.ispeciKolac())
                    ispisiKolac(abc);
                break;
            case 3:
                if(abc.zavrsiKolac())
                    ispisiKolac(abc);
                break;
            case 4:
                if(abc.povecajTemperaturu())
                    ispisiKolac(abc);
                break;
            case 5:
                if(abc.smanjiTemperaturu())
                    ispisiKolac(abc);
                break;
            case 6:
                if(abc.dodajSlag())
                    ispisiKolac(abc);
                break;
            case 7:
                if(abc.ukloniSlag())
                    ispisiKolac(abc);
                break;
            case 8:
                return 0;
                break;
            default:
                cout<<"Pokusajte ponovo."<<endl;
                break;
            }
}
