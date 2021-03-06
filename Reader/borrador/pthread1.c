#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *imprimeMensaje( void *apuntador);

void main(void)
{
  pthread_t hilo1, hilo2;
  const char *mensaje1 = "Hilo 1";
  const char *mensaje2 = "Hilo 2";
  int iret1, iret2;

  iret1 = pthread_create( &hilo1, NULL, imprimeMensaje, (void*)mensaje1);
  if(iret1)
    {
      fprintf(stderr, "Error - pthread_create código de regreso: %d\n", iret1);
      exit(EXIT_FAILURE);
    }
  
  iret2 = pthread_create( &hilo2, NULL, imprimeMensaje, (void*)mensaje2);
  if(iret2)
    {
      fprintf(stderr, "Error - pthread_create código de regreso: %d\n", iret2);
      exit(EXIT_FAILURE);
    }

  printf("Phtread_create() para el hilo1 regresa: %d\n", iret1);
  printf("Phtread_create() para el hilo2 regresa: %d\n", iret2);

  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);

  exit(EXIT_SUCCESS);
  
}

void *imprimeMensaje( void *apuntador )
{
  char *mensaje;
  mensaje = (char *) apuntador;
  printf("%s \n", mensaje);
}

