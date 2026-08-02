#include <iostream>
#include "alist.h"
using namespace std;



void append(alist* a, const alist* b)
{
    int* rei= new int[a->size + b->size];
    int i ;
    for(i=0; i < a->size; i++)
    {
        rei[i] = a->elements[i]       ; 
    }
    for(int k = 0; k< b->size; k++)
    {
        rei[i] = b->elements[k];
        i++;
    }
    delete[] a->elements;
    a->size += b->size;
    a->elements = rei; 
}

int main()
{
    { const int nA = 4;
  int eA[nA] = { 1, 2, 3, 4 };
  alist* a = build(nA, eA);
  const int nB = 3;
  int eB[nB] = { 5, 6, 7 };
  const alist* b = build(nB, eB);
  append(a, b);
  print(a);
  destroy(a);
  destroy(b); }
    return 0;
}