#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv)
{
  void *m;
  char *s;
  int id;

  printf(1,"first dumpmap\n");
  dumpmap();
  printf(1,"\n");
  m = sharedmem();
  s = (char *) m;
  printf(1, "second dumpmap\n");
  dumpmap();
  printf(1, "\n");

  id = fork();

  if (id == 0) {
    printf(1, "third dumpmap\n");
    dumpmap();
    printf(1,"\n");
    strcpy(s, "Hello from child\n");
    exit();
  }

  wait();
  printf(1, "s = %s\n", s);
  exit();  
}
