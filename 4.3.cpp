#include<iostream>
using namespace std;
int n,i,r,m;

struct nod
{
    float val;
    nod *urm;
};
   nod *p , *u;

    void afisare(nod *p)
   {
       nod*c=p;
         while(c!=0)
         {
             cout<<c->val<<" ";
             c=c->urm;

         }
         cout<<"\n";
   }

     void creare( nod *&p, nod *&u, int n)
   {
       nod *c;
          if(p==0)
            {
              p=new nod;
              p->val=n;
              p->urm=0;
              u=p;
            }
          else
            {
              c=new nod;
              c->val=n;
              c->urm=0;
              u->urm=c;
              u=c;
            }
   }


   int main()
   {
       int x, nr=1;
       nod *p=0; nod *u=0;
       nod *l=0, *r=0;
       nod *d=0, *e=0;
       nod* aux=0;
       cout<<"Nr elemente C: ";
       cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>x;
            creare(p,u,x);
        }


        nod *c=p;
         while(c)
         {
             if(nr%2==1)
                creare(l,r,c->val);
                else
                creare(d,e,c->val);
                c=c->urm;
                nr++;
         }

        afisare(p);
        cout<<"\n";
        cout<<"Lista A: ";
            afisare(l);
        cout<<"\n";
        cout<<"Lista B: ";
            afisare(d);
        cout<<"\n";
        return 0;
   }
