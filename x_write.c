/*
 * x_write.c
 * write() wrapper with hslc algorithm
 * eduardo.ruiz@hypersec.co.uk
 */
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "localdefs.h"
#include "destroy.h"
ssize_t
x_write (int fd, void *buf, size_t nbytes, char *key)
{
  hslcipher (buf, nbytes, key);
  if ((write (fd, buf, nbytes)) != nbytes)
    return EFDWRITED;
  return nbytes;
}
