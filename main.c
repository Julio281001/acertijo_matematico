#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define STR_MAX_SIZE 256

int nusuarios = 2;
char usuarios[100][STR_MAX_SIZE] = {"julio", "cesar"};

void registro()
{
    char usuario[STR_MAX_SIZE];
    int i;
    bool existe = false;
    do
    {
        printf("Ingresa tu nombre de usuario:");
        scanf("%s", usuario); // cesar

        for (i = 0; i < nusuarios; i++) // i = 1
        {
            if (strcmp(usuario, usuarios[i]) == 0)
            {
                printf("Ese usuario ya existe\n");
                existe = true;
                break;
            }
            if (i == nusuarios - 1)
            {
                existe = false;
            }
        }
    } while (existe);
    strcpy(usuarios[nusuarios], usuario);
    nusuarios++;
}

int main()
{
    char letra = 'a';
    int opcion;
    bool seguirJugando = true;
    do
    {
        printf("1.Registrar jugador\n2.Verificar puntuaciones\n3.Jugar\n4.Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            registro();
            break;
        case 2:
            printf("verificando");
            break;
        case 3:
            printf("jugando");
            break;
        case 4:
            printf("buen dia");
            seguirJugando = false;
            break;
        default:
            printf("%d no es una opción del menu", opcion);
        }
        printf("\n");
    } while (seguirJugando);
    return 0;
}
