/*
 * hslcipher.c
 * reverse routine for hslcipher()
 * eduardo.ruiz@hypersec.co.uk
 */
#include "localdefs.h"
#include <sys/types.h>

	void
hsldecipher (char *buf, size_t nbytes, char *key)
{
  hsl_ctx c; 
  unsigned int i = 0;
  register int xpy_mutate = 0;
  int help_shift = 0;
  unsigned short perbyte = nbytes%4;
  long *cbuf;
  cbuf = (long *)buf;
  if(buf == 0x0) { write(2,"hcldecipher(): null value received\n",33); exit(-1); }
cook_key_expand (&c, key);
  xpy_mutate = (c.x + c.y)^c.z;
  if(perbyte != 0) nbytes += (4 - perbyte);
  for (; i < nbytes/4; i++)
    {
	xpy_mutate += (c.z & c.x);
	help_shift = (xpy_mutate >> 8) & 0x0000001fL;
	cbuf[i] -= xpy_mutate << 24;
        // (useless) rotr32(cbuf[i],help_shift);
        cbuf[i] ^= (xpy_mutate + c.y);
	cbuf[i] ^= c.z;
	cbuf[i] -= c.x;
	cbuf[i] += c.y;
	c.z += xpy_mutate;
    } 
    memcpy(buf,cbuf,nbytes);
    _destroy(&key,8);
}
