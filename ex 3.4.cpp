#include<iostream>
#include<cmath>
using namespace std;

struct pol
{
    int grad, coef;
    pol *urm;
};
   pol *prim , *ultim;

   int x,y,n,k;
       pol *q, *d;

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
        int m, sum=0;
        pol *l=0, *r=0;
       cout<<"Nr termeni polinom 1 : ";
       cin>>n;
       for(int i=1;i<=n;i++)
       {
           cout<<"Coeficinet : ";
           cin>>x;
           cout<<"Grad : ";
           cin>>y;
           if(x!=0)
            creare(prim,ultim,x,y);
       }

       cout<<"Nr termeni polinom 2 :";
       cin>>m;

       for(int i=1;i<=m;i++)
       {
           cout<<"Coeficinet : ";
           cin>>x;
           cout<<"Grad : ";
           cin>>y;
           if(x!=0)
            creare(q,d,x,y);
       }

             afisare(prim);
             cout<<"\n";
             afisare(q);
             cout<<"\n";

       pol * c, *v;
       c=prim;
       v=q;

       while(c)
      {
          sum=0;
           v=q;
            while(v)
            {
          if(c->grad == v->grad)
          {sum=c->coef+v->coef;
           creare(l,r, sum, c->grad);
          }
                    v=v->urm;
            }
            if(sum==0)
            creare(l,r, c->coef, c->grad);
          c=c->urm;
          cout<<endl;
      }
      c=q;
       v=prim;
             while(c)
      {
          sum=0;
           v=prim;
            while(v)
            {
          if(c->grad == v->grad)
          sum=c->coef+v->coef;
                    v=v->urm;
            }
            if(sum==0)
            creare(l,r, c->coef, c->grad);
          c=c->urm;
         cout<<endl;
      }
       afisare(l);
       cout<<"\n";




             return 0;


   }
