#include <iostream>
using namespace std;
class employe
{
protected :
    int id ;
public :
    employe(int ID )
    { id=ID ;}
void saisie()
    {cout<<"entrer votre ID : " ; cin>> id ; }
};

class medecin: public employe {
    protected  :
         int nb_heures ;
public :
medecin(int ID, int nb_hr) : employe(ID) {nb_heures=nb_hr ; }
void saisie()
{ employe :: saisie() ; cout<<"entrer le nombre d'heures : " ; cin>> nb_heures ; }

};

class chirurgien : public medecin {
    private :
        int nb_operations ;
public :
chirurgien(int ID, int nb_hr, int nb_op) : medecin(ID, nb_hr)
{
     nb_operations= nb_op ;
}
void saisie()
{ medecin :: saisie () ; cout<<"entrer le nombre d'operations : " ; cin>> nb_operations ; }
void display(int id, int nb_heures, int nb_operations)
{
 cout<< " votre id est :"<<id<< endl ;
 cout<<"le nombre d'heure est:" <<nb_heures <<endl;
 cout<<"le nombre d'operations est:" <<nb_operations<< endl;
}
} ;

class administration : public employe {
    protected :
        int nb ;
public :
    administration(int ID, int NB) :  employe(ID)
    {
        nb=NB ;
    }
 void saisie() { employe :: saisie() ; cout<<"entrer le nombre d'heure de bureau : " ; cin>> nb; }
} ;

class chefservice: public administration , medecin {
    protected :
        int prime ;
    public :
chefservice(int ID, int NB, int nb_hr, int prm ): administration(ID,NB) , medecin(ID,nb_hr)
{
    prime=prm ;
}
 void calcul_prime(int ph )
{

   prime= ph*(nb + nb_heures)  ;
}
 void display1(int id, int nb , int nb_heures, int prm )
{
cout<<"votre id est :"<<id<< endl ;
cout<<"le nombre d'heure de bureau est :" <<nb <<endl;
cout<<"le prime :" <<prime<< endl;
}
 } ;

int main()
{
    chirurgien c(65234,2,3) ;
    c.saisie() ;
    c.display(65234,2,3) ;
    int x ;
    cout<<"entrer le prix de l'heure" ; cin>>x ;
    chefservice ch(64515,9,5,0) ;
    ch.calcul_prime(x) ;
    ch.display1(65234,9,3,265) ;
return 0;
}
