#include<iostream>
using namespace std;
int n,m,a,b;

struct pol
{
    int grad, coef;
    pol *urm;
};
   pol *prim , *ultim;

    void afisare(pol *prim)
   {
       pol *c=prim;
         while(c!=0)
         {
             cout<<c->coef<<"x^"<<c->grad<<" ";
             c=c->urm;

         }
         cout<<"\n";
   }
   void creare( pol *&prim, pol *&ultim, int n, int m)
   {
       pol *c;
          if(prim==0)
            {
              prim=new pol;
              prim->coef=n;
              prim->grad=m;
              prim->urm=0;
              ultim=prim;
            }
          else
            {
                pol *nou;
                nou= new pol;
                nou->coef=n;
                nou->grad=m;
                nou->urm=prim;
                prim=nou;
            }
   }



   int main()
   {
       int x,y,n,k;
       cout<<"Numar termeni polinom: ";
       cin>>n;
       for(int i=1;i<=n;i++)
       {
           cout<<"coeficinetul : ";
       cin>>x;
       cout<<"Gradul: ";
       cin>>y;
            if(x!=0)
            creare(prim,ultim,x,y);
       }
       cout<<"a ";
       cin>>k;




             afisare(prim);
             cout<<"\n";

                pol *c=prim;
                    while(c)
       {
           c->coef=c->coef*k;
           c=c->urm;
       }
        afisare(prim);
   }
