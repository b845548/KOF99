#include<stdio.h>
struct ad_hoc{
  ullint ull;
  float somp;
};
typedef struct ad_hoc ad_hoc;

int appartient(float x, arbre a){
  int i;
  if(!a)return 0;
  if(x==a->val)return 1;
  for(i=0; i<NBF;i++)
    if(appartient(x,a->fils[i]))
       return 1;
  return 0;
      
}

float somme_arbre(arbre a){
  float i,somme=0;
  if(!a)return somme;
  somme+=a->val;
  for(i=0;i<NBF;i++)somme+=somme_arbre(a->fils[i]);
  return somme;
}



int combien_appartient(float x,arbre a){
  if(!a)return 0;
  int i,count=0;
  if(x==a->val)count++;
  for(i=0;i<NBF;i++)if(combien_appartient(x,a->fils[i]))count++;
  return count;
}


float moyenne_pondérée(arbre a){
  ad_hoc st;
  st.somp=0.0;
  st.ull=0.0;
  st=moyenne_pondérée_it(a, st);
  return st.somp / (float)st.ull;
}

ad_hoc moyenne_pondérée_it(arbre a,ad_hoc st){
  int i;
  if(!a)return ad_hoc;
  st.somp+= a->go * a->val;
  st.ull+= a->go;
  for(i=0;i<NBF;i++)st=moyenne_pondérée_it(a->fils[i],st);

  return ad_hoc;
}
