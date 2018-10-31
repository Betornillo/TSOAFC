#include <stdio.h>
#include <string.h>

struct Miembros{

  char nombre[50];
  char puesto[50];
  int edad;
  
};

int main(int argc, char** argv[])
{
  struct Miembros mem;

  strcpy(mem.nombre,"Paco Memo Ochoa");
  printf("%s\n",mem.nombre);
  return (0);
}
