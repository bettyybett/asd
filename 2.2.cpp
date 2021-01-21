#include<iostream>
using namespace std;

struct nod
{
    int val;
    nod *urm;
};
   nod *prim , *ultim;

   void afisare(nod *prim)
   {
       nod *b=prim;
         while(b!=0)
         {
             cout<<b->val<<" ";
             b=b->urm;
         }
   }

   void creare( nod *&prim, nod *&ultim, int n)
   {
       nod *b;
          if(prim==0)
            {
              prim=new nod;
              prim->val=n;
              prim->urm=0;
              ultim=prim;
            }
          else
            {
              b=new nod;
              b->val=n;
              b->urm=0;
              ultim->urm=b;
              ultim=b;
            }
   }
   int main()
   {
       nod *prim=0, *ultim=0;
        int n,nr=0, s=0,x;
        cout<<"n = ";
        cin>>n;
          for(int i=1;i<=n;i++)
                    {
                        cin>>x;
                        creare(prim,ultim,x);
                        if(x%2==0)
                            nr++;
                            else
                                s=s+x;
                        }
                        cout<<"Lista contine "<<nr<<"  numere pare";
                        cout<<" \n Media aritmetica a celor impare este : "<< s/(n-nr);
        }

