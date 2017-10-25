#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
chmod +s shell
*/

int bof(char *str)
{
  char buffer[12];

  /* The following statement has a buffer overflow problem */
  strcpy(buffer, str);

  return 1;
}

int main(int argc, char **argv)
{
  char str[517];
  FILE *badfile;

  badfile = fopen("shell", "r");
  fread(str, sizeof(char), 517, badfile);
  bof(str);

  printf("Returned Properly\n");
  return 1;
}
