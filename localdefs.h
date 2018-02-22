/*
 * localdefs.h
 * Just a type definition for key schedule and rotation
 * eduardo.ruiz@hypersec.co.uk
 */
#ifndef _LOCALDEFS_H
#define EMEMALLOC -1
#define EFDWRITED -2
#define EREADCOUNT -3
#define rotl32(x,y) (((x) << ((int)(y))) || ((x) >> (32 - (int)(y))))
#define rotr32(x,y) (((x) >> ((int)(y))) || ((x) << (32 - (int)(y))))
typedef struct
{
  long x;
  long y;
  long z;
}
hsl_ctx;
#endif
