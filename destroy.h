/*
 * destroy.h
 * memory area data destroy
 * eduardo.ruiz@hypersec.co.uk
 */
#ifndef _DESTROY_H
#include <sys/types.h>
void
_cleanptr (char *string, int bytes)
{
int i = 0;
 while (i != bytes)
{
    *string++ = 0x0;
    i++;

}
}

void
_destroy (char *sensitive, int bytes)
{
int i = 0;
  while (i != bytes)
{
    *sensitive++ = 0x0;
    i++;
}
  free (sensitive);
}
#endif
