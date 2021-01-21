#include<iostream>
using namespace std;

struct nod
{
    float val;
    nod *urm;
};
   nod *prim , *ultim;

   void afisare(nod *prim)
   {
       nod*b=prim;
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

   void inserare_dupa(nod *prim, nod *ultim, int valoare, float media)

    { nod *b,*nou;

      b=prim;

            while(b->val!=valoare &&b!=NULL)

                b=b->urm;

            nou=new nod;


            nou->val=media;

            nou->urm=b->urm;

            b->urm=nou;

            if(b==ultim)
                ultim=nou;
  }
     int main()
{
nod *prim=0, *ultim=0;
int n,x, a[100];
float media;
cout<<"n= ";
cin>>n;
 for(int i=1;i<=n;i++)
                    {
                        cin>>x;
                        a[i]=x;
                         creare(prim,ultim,x);
                    }
            for(int j=1;j<n;j++)
            {
                media= float((a[j]+a[j+1])/2.0);
                inserare_dupa(prim,ultim,a[j],media);
            }

            afisare(prim);
            return 0;
}
