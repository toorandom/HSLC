/*
 * cook_key_expand.c
 * Using key space of 64 bits lcipher will expand to 96 bits 
 * if non printable caracters are sent to cook_key_expand() ommit zeroes for more security
 * eduardo.ruiz@hypersec.co.uk
 */
#include "localdefs.h"
void
cook_key_expand (hsl_ctx *c, char *key)
{
  unsigned short handybyte;
  if(key == 0x0) return;
/* expanding 8 bits to 32 bits */
  c->x =  ((((key[0] + key[1])*0xf) << 24) + (key[2] << 8) ^ (key[3] * key[4] * key[5])) * ((key[6] * key[7])<< 2);
  c->y =  ((((key[2] + key[3])*0xf) << 16) + (key[4] << 16) ^ (key[5] * key[6] * key[7])) * ((key[0] * key[1])<< 4);
  c->z =  ((((key[4] + key[5])*0xf) << 20) + (key[6] << 12) ^ (key[7] * key[0] * key[1])) * ((key[2] * key[3])<< 6);
/* xored parallel assignment */
  c->x ^= c->z;
  c->y = ((c->z + c->x) ^ (c->y + c->x));
  c->z ^= c->x;
/* forcing 32 bits to c->z and filling zeroes with xored password using sums for evade zeroes */
  handybyte = ((((key[0]+key[1])^key[2])+(key[3]+key[4]+key[5])^(key[6]+key[7]))%8);
/* Adding byte if sequence of key is weak */
  c->y += handybyte<<2;
  c->z += handybyte<<3;
  c->x += handybyte<<4;
/*  printf("c->x = %08x\nc->y = %08x\nc->z = %08x\n",c->x,c->y,c->z); */
}
