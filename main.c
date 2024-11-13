#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define STR_MAX_SIZE 256

int nUsuarios = 2;
char usuarios[100][STR_MAX_SIZE] = {"julio", "cesar"};
int puntuaciones[100] = {100, 30};

int obtenerIndiceUsuario(char usuario[])
{
    // Checa si usuario existe en el arreglo de usuarios,
    // si sí existe retorna su índice, si no existe retorna -1
    for (int i = 0; i < nUsuarios; i++)
    {
        if (strcmp(usuario, usuarios[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

void registro()
{
    char usuario[STR_MAX_SIZE];
    int indiceUsuario;
    do
    {
        printf("Ingresa tu nombre de usuario:");
        scanf("%s", usuario);
        indiceUsuario = obtenerIndiceUsuario(usuario);
        if (indiceUsuario >= 0)
        {
            printf("%s ya existe, ingresa otro\n", usuario);
        }
    } while (indiceUsuario >= 0);
    strcpy(usuarios[nUsuarios], usuario);
    nUsuarios++;
    printf("%s ha sido registrado correctamente\n", usuario);
}

void verificarPuntuaciones()
{
    char usuario[STR_MAX_SIZE];
    int indiceUsuario;
    do
    {
        printf("Ingresa tu nombre de usuario:");
        scanf("%s", usuario);
        indiceUsuario = obtenerIndiceUsuario(usuario);
        if (indiceUsuario == -1)
        {
            printf("%s Usuario no existente, ingrese otro\n", usuario);
        }
    } while (indiceUsuario == -1);
    printf("%s tiene %d puntos", usuarios[indiceUsuario], puntuaciones[indiceUsuario]);
    printf(", su posicion en el ranking es %d\n", indiceUsuario + 1);
    printf("\nRanking:\n");
    for (int i = 0; i < nUsuarios; i++)
    {
        printf("%d.) %s: %d puntos\n", i + 1, usuarios[i], puntuaciones[i]);
    }
}

int main()
{
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
            verificarPuntuaciones();
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
