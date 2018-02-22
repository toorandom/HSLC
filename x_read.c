/*
 * x_read.c
 * read() wrapper with hslc algorithm
 * eduardo.ruiz@hypersec.co.uk
 */
#include "localdefs.h"
#include <sys/types.h>
ssize_t
x_read (int fd, void *buf, size_t count, char *key)
{
  char *kbuf;
  unsigned int recount;
  if ( (kbuf = (char *) malloc (count)) == (void *) 0x0) return EMEMALLOC;
  if ((recount = read (fd, kbuf, count)) != count)
	  return EREADCOUNT;
  hsldecipher(kbuf,count,key);
  memcpy(buf,kbuf,count);
  return recount;
}
