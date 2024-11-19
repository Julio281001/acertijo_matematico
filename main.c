#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define STR_MAX_SIZE 256
#define ACERTIJOS_POR_PARTIDA 8

int nUsuarios = 2;
char usuarios[100][STR_MAX_SIZE] = {"julio", "cesar"};
int puntuaciones[100] = {100, 30};
const char ACERTIJOS[100][STR_MAX_SIZE] = {"¿Cuánto es 3 + 5?",
                                           "Si tienes 10 manzanas y das 3, ¿cuántas te quedan?",
                                           "¿Cuánto es 7 - 2?",
                                           "Si un reloj marca las 12 y pasan 3 horas, ¿qué hora es?",
                                           "¿Cuánto es 2 * 3?",
                                           "¿Cuánto es 12 / 4 + 3 * 2?",
                                           "Si tienes 4 pares de zapatos y compras 3 pares más, ¿cuántos zapatos tienes en total?",
                                           "La mitad de 64 es igual a la mitad de 32 multiplicada por 2. ¿Es cierto? (1 para Sí, 0 para No)",
                                           "Si un tren recorre 60 km en una hora, ¿cuánto recorrerá en 3.5 horas?",
                                           "¿Cuánto es 15 + 15 / 3?",
                                           "Si x + 2x = 90, ¿cuánto vale x?",
                                           "¿Cuál es el valor de x si 3x - 15 = 30?",
                                           "Si un cubo tiene un volumen de 125 cm³, ¿cuál es la longitud de su lado?",
                                           "Si la suma de dos números es 50 y su diferencia es 20, ¿cuáles son esos números? (Suma los dos números)",
                                           "Si 8x = 64, ¿cuánto es x * 5?"};
const int REPUESTAS[] = {8, 7, 5, 3, 6, 9, 14, 1, 210, 20, 30, 15, 5, 35, 40};
const int DIFICULTADES[] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3};

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

int randomNumber(int minNum, int maxNum)
{
    // Retorna un número random entre minNum y maxNum inclusivo
    maxNum++; // Hay que incrementar maxNum para poder incluirlo en el rango
    return (rand() % (maxNum - minNum)) + minNum;
}

bool existe(int target, int array[], int size)
{
    // Checa si target existe en array, si sí existe
    // retorna true, si no existe retorna false
    for (int i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            return true;
        }
    }
    return false;
}

void obtenerAcertijos(int indicesAcertijos[])
{
    srand(time(NULL));
    const int NUMERO_DE_CATEGORIAS = 3;
    const int CANTIDADES[] = {3, 3, 2};
    // CANTIDADES[0] es la cantidad de acertijos sencillos
    // CANTIDADES[1] es la cantidad de acertijos medios
    // CANTIDADES[2] es la cantidad de acertijos avanzados
    int size = 0;
    // size es el tamaño del arreglo indicesAcertijos, el cual guardará los índices de los acertijos
    // que se preguntarán en la partida. En es este punto el arreglo está vacío, por lo tanto size es cero.
    int inicio = 0, final = 4;
    // inicio y final servirán para establecer el rango para generar un índice aleatorio.
    int randomIndex;
    // randonIndex guardará el índice aleatorio.

    // El siguiente for es para obtener, de forma aleatoria, los ocho acertijos para la partida, pero teniendo
    // en cuenta que una partida debe de tener acertijos de todas las categorías: sencillo, medio y avanzado.
    //
    // En la primera iteración, cuando i es cero, se seleccionan los acertijos sencillos, cuando esta termine,
    // puesto que previemente se estableció en el arreglo CANTIDADES que una partida siempre tendrá tres acertijos
    // sencillos, tendremos tres enteros distintos que se encuentran en el rango [0-4] y que fueron seleccionados
    // de manera aleatoria, estos enteros son los índices de tres acertijos sencillos del arreglo acertijos.
    // Hay que tener en cuenta que los primeros cinco acertijos del arreglo de acertijos son acertijos sencillos,
    // es por esto que el rango debe de ser [0-4], el cual es determinado por las variables inicio y final.
    //
    // En la segunda iteración, cuando i es uno, toca escoger los acertijos medios, es por esto que el rango debe de
    // ser [5-9], ya que los acertijos medios van desde la posición cinco hasta la posición nueve del arreglo de acertijos.
    // Una vez establecido el rango, sólo resta generar tres números aleatorios distintos que se encuentren en el rango
    // establecido, en este caso también se deben generar tres números, ya que CANTIDADES[1], entero que representa la
    // cantidad de acertijos medios por partida, es tres.
    //
    // Ya tenemos seis acertijos, tres sencillos y tres medios, necesitamos ocho, por lo que ahora hay que escoger dos
    // acertijos avanzados, estos van desde la posición diez hasta la posición catorce del arreglo de acertijos, por lo
    // que los dos números aleatorios distintos que serán generados deben de estar en el rango [10-14].
    for (int i = 0; i < NUMERO_DE_CATEGORIAS; i++)
    {
        // El siguiente for es para generar la cantidad necesaria de acertijos según su categoría, esta cantidad
        // es determinada por CANTIDADES[i]
        for (int j = 0; j < CANTIDADES[i]; j++)
        {
            // No sólo basta con generar un número random dentro de un rango dado, también hay que asegurarse que
            // el número generado no haya sido generado anteriormente, esto con el fin de que no haya preguntas
            // repetidas.
            // El siguiente bucle se ejecuta si el número aleatorio generado ya existe en arreglo indicesAcertijos.
            do
            {
                randomIndex = randomNumber(inicio, final);
            } while (existe(randomIndex, indicesAcertijos, size));
            // Cuando el do-while termina es porque el valor de randomIndex es válido, es decir, no es un valor repetido,
            // por lo que ya puede ser agregado a al arreglo indicesAcertijos.
            indicesAcertijos[size] = randomIndex;
            size++;
        }
        // En este punto ya fueron generados todos los índices de X categoría, por lo que, con el fin de que en la
        // siguiente iteración se escogan acertijos de la siguiente categoría, hay que incrementar modificar el rango.
        inicio += 5;
        final += 5;
    }
}

void registro()
{
    char usuario[STR_MAX_SIZE];
    int indiceUsuario;
    // El siguiente bucle tiene la tarea de pedir un nombre
    // de usuario hasta que se ingrese uno que no haya
    // sido registrado previamente.
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
    // Cuando el programa sale del bucle anterior significa que el usuario
    // ingresado no fue registrado previamente, por lo que sólo
    // resta agregarlo al arreglo de usuarios e incializar su puntaje en
    // cero en el arreglo puntuaciones.
    // Lo descrito anteriormente es lo que sucede a continuación.
    strcpy(usuarios[nUsuarios], usuario);
    puntuaciones[nUsuarios] = 0;
    nUsuarios++;
    printf("%s ha sido registrado correctamente\n", usuario);
}

void verificarPuntuaciones()
{
    char usuario[STR_MAX_SIZE];
    int indiceUsuario;
    // El siguiente bucle tiene la tarea de pedir un nombre
    // de usuario hasta que se ingrese uno que haya sido
    // registrado previamente.
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
    // Cuando el programa sale del bucle anterior significa que el usuario
    // ingresado fue registrado previamente, o, en otras palabras,
    // que el usuario ingresado sí existe en el arreglo de usuarios.
    // La variable indiceUsuario guardaría el índice del usuario ingresado dentro
    // del arreglo de usuarios. Gracias a este índice se puede acceder al puntaje
    // del usuario, ya que los usuarios están mapeados a sus puntuaciones por medio
    // su índice. Por ejemplo, el puntaje del usuario en la posición cero del arreglo de
    // usuarios sería el entero almacenado en la posición cero del arreglo de puntuaciones.
    // Sólo restaría mostrar la información del usuario ingresado y el ranking. Esto
    // sucede a continuación.
    printf("%s tiene %d puntos", usuarios[indiceUsuario], puntuaciones[indiceUsuario]);
    printf(", su posicion en el ranking es %d\n", indiceUsuario + 1);
    printf("\nRanking:\n");
    for (int i = 0; i < nUsuarios; i++)
    {
        printf("%d.) %s: %d puntos\n", i + 1, usuarios[i], puntuaciones[i]);
    }
}

void jugar()
{
    char usuario[STR_MAX_SIZE];
    int indiceUsuario, respuesta, errores = 0, aciertos = 0;
    printf("Ingresa tu nombre de usuario:");
    scanf("%s", usuario);
    indiceUsuario = obtenerIndiceUsuario(usuario);
    if (indiceUsuario == -1)
    {
        printf("%s Usuario no existente, ingrese otro\n", usuario);
        return;
    }
    int indicesAcertijos[ACERTIJOS_POR_PARTIDA], puntajePartida = 0;
    obtenerAcertijos(indicesAcertijos);
    for (int i = 0; i < ACERTIJOS_POR_PARTIDA; i++)
    {
        while (errores < 3)
        {
            printf("(%d) %s\n", DIFICULTADES[indicesAcertijos[i]], ACERTIJOS[indicesAcertijos[i]]);
            scanf("%d", &respuesta);
            if (respuesta == REPUESTAS[indicesAcertijos[i]])
            {
                printf("Respuesta Correcta!\n");
                aciertos++;
                switch (DIFICULTADES[indicesAcertijos[i]])
                {
                case 1:
                    puntajePartida += 10;
                    break;

                case 2:
                    puntajePartida += 20;
                    break;

                case 3:
                    puntajePartida += 30;
                    break;
                }
                break;
            }
            else
            {
                errores++;
                printf("Resputa incorrecta\n");
            }
        }
    }
    if (errores == 3)
    {
        printf("\nIntentos agotados\n");
    }
    if (aciertos == 8 && errores == 0)
    {
        puntajePartida *= 2;
    }
    else if (aciertos == 8 && errores == 1)
    {
        puntajePartida += 30;
    }
    else if (aciertos == 8 && errores == 2)
    {
        puntajePartida += 25;
    }
    else if (aciertos == 7)
    {
        puntajePartida += 20;
    }
    else if (aciertos == 6)
    {
        puntajePartida += 15;
    }
    else if (aciertos == 5)
    {
        puntajePartida += 10;
    }
    else if (aciertos == 4)
    {
        puntajePartida -= 5;
    }
    else if (aciertos == 3)
    {
        puntajePartida -= 10;
    }
    else if (aciertos == 2)
    {
        puntajePartida -= 15;
    }
    else if (aciertos == 1)
    {
        puntajePartida = 1;
    }
    printf("\nTu puntaje final es: %d\n", puntajePartida);
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
            jugar();
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
