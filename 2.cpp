#include <iostream>

using namespace std;

enum TipMreze{DUBOKA,OBICNA};

class NeuronskaMreza{
private:
    int brSkrivenihSlojeva;
    int brNeuronaPoSloju;

public:
    NeuronskaMreza(int a, int b){
        brSkrivenihSlojeva=0;
        brNeuronaPoSloju=0;
        if(a>0)
            brSkrivenihSlojeva=a;
        if(b>0)
            brNeuronaPoSloju=b;
    }

    void dodajSkriveniSloj(){
        cout<<"brSkrivenihSlojeva: "<<++brSkrivenihSlojeva<<endl;
    }

    void dodajNeuron(){
        cout<<"brNeuronaPoSloju: "<<++brNeuronaPoSloju<<endl;
    }

    double izracunajUspeh()const{
        cout<<"!!!!!!!!!!!!!!"<<endl;
        cout<<"NEMA NIKAKVE FORMULE ZA USPEH"<<endl;
        cout<<"!!!!!!!!!!!!!!"<<endl;
        return brSkrivenihSlojeva*brNeuronaPoSloju/800.0;
    }

    TipMreze getTipMreze()const{
        if(brSkrivenihSlojeva*brNeuronaPoSloju*2>=1000)
            return DUBOKA;
        return OBICNA;
    }
};

enum StanjeTesta{START,PROCESIRANJE,OPTIMIZACIJA,KRAJ};

enum TipOptimizacije{DODAJ_SLOJ,DODAJ_NEURON};

class Test{
private:
    NeuronskaMreza nm;
    double zeljeniProcenatUspesnosti;
    int brOptimizacija;
    StanjeTesta stanje;

public:
    Test(double a): nm(3,200){
        zeljeniProcenatUspesnosti=0.85;
        if(0<=a && a<=1)
            zeljeniProcenatUspesnosti=a;
        stanje=START;
        brOptimizacija=0;
    }

    bool procesiraj(){
        if(stanje==START || stanje==OPTIMIZACIJA){
            if(zeljeniProcenatUspesnosti>nm.izracunajUspeh())
                stanje=PROCESIRANJE;
            else{
                stanje=KRAJ;
                cout<<"Test uspesno zavrsen!"<<endl;
            }
            return true;
        }
        return false;
    }

    bool potrebnoOptimizovati(){
        if(stanje==PROCESIRANJE){
            stanje=OPTIMIZACIJA;
            return true;
        }
        return false;
    }

    bool optimizuj(TipOptimizacije a){
        if(a==DODAJ_SLOJ){
            nm.dodajSkriveniSloj();
            return true;
        }
        else{
            nm.dodajNeuron();
            return true;
        }
        return false;
    }

    double izracunajUspeh()const{
        return nm.izracunajUspeh();
    }

    TipMreze getTipMreze()const{
        return nm.getTipMreze();
    }

    StanjeTesta getStanje()const{
        return stanje;
    }
};

void ispisiTest(const Test &p){
    cout<<"---------------"<<endl;
    cout<<"Stanje: ";
    if(p.getStanje()==START)
        cout<<"START"<<endl;
    else if(p.getStanje()==PROCESIRANJE)
        cout<<"PROCESIRANJE"<<endl;
    else if(p.getStanje()==OPTIMIZACIJA)
        cout<<"OPTIMIZACIJA"<<endl;
    else
        cout<<"KRAJ"<<endl;
    cout<<"Tip: ";
    if(p.getTipMreze()==DUBOKA)
        cout<<"DUBOKA"<<endl;
    else
        cout<<"OBICNA"<<endl;
    cout<<"Uspeh: "<<fixed<<p.izracunajUspeh()<<endl;
    cout<<"---------------"<<endl;
}

int meni(){
    int a;
    cout<<"1. Procesiraj"<<endl;
    cout<<"2. Potrebno optimizovati"<<endl;
    cout<<"3. Optimizuj"<<endl;
    cout<<"4. Kraj"<<endl;
    cin>>a;
    return a;
}

int main()
{
    Test abc(0.94);
    int a;
    while(1)
        switch(meni()){
            case 1:
                if(abc.procesiraj())
                    ispisiTest(abc);
                break;
            case 2:
                if(abc.potrebnoOptimizovati())
                    ispisiTest(abc);
                break;
            case 3:
                if(abc.getStanje()==OPTIMIZACIJA){
                    cout<<"1. DODAJ_SLOJ"<<endl;
                    cout<<"2. DODAJ_NEURON"<<endl;
                    cin>>a;
                    if(a==1){
                        if(abc.optimizuj(DODAJ_SLOJ))
                            ispisiTest(abc);
                    }
                    else if(a==2){
                        if(abc.optimizuj(DODAJ_NEURON))
                            ispisiTest(abc);
                    }
                }
                break;
            case 4:
                return 0;
                break;
            default:
                cout<<"Pokusajte ponovo."<<endl;
                break;

        }
}
