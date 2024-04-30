#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int TareaID;
    char *Descripcion;
    int Duracion;
} Tarea;

typedef struct Nodo
{
    Tarea T;
    struct Nodo *siguiente;
    int longuitud;
} Nodo;

Nodo *CrearNodo(Tarea Tarea);
void insertarNodo(Nodo **start, Nodo *nuevoNodo);
void mostarLista(Nodo **start);

int main()
{
    Nodo *tareaPendientes = NULL, *tareaRealizadas = NULL;
    int opcion, cargaTareas = 0, opcionMenu = 0;
    char *descripcion = (char *)malloc(100 * sizeof(char));

    while (opcionMenu == 0)
    {
        printf("### MENU ###\n1_Agregar Tareas\n2_Mostrar Tareas pendientes\n3_Mostrar Tareas realizadas\n");
        scanf("%d", &opcion);

        if (opcion == 1)
        {
            cargaTareas=0;
            while (cargaTareas == 0)
            {
                Tarea newTarea;

                Nodo *newNodo;
                printf("\nIngresar Descripcion de la tarea: ");
                scanf("%s", descripcion);
                fflush(stdin);
                newTarea.Descripcion = (char *)malloc((strlen(descripcion) + 1) * sizeof(char));
                strcpy(newTarea.Descripcion, descripcion);
                printf("\nIngredar la duracion de la tarea: ");
                scanf("%d", &newTarea.Duracion);
                fflush(stdin);

                newNodo = CrearNodo(newTarea);
                insertarNodo(&tareaPendientes, newNodo);

                printf("0_Seguir Agregando Tareas\n1_Terminar de agregar\n");
                scanf("%d", &cargaTareas);
            }
        }
        if (opcion == 2)
        {
            mostarLista(&tareaPendientes);
        }
        if (opcion == 3)
        {
        }

        printf("\nDESEA SEGUIR EN LA INTERFAZ?\n0_SI\n1_NO\n");
        scanf("%d", &opcionMenu);
    }
}

Nodo *CrearNodo(Tarea Tarea)
{
    Nodo *newNodo = (Nodo *)malloc(sizeof(Nodo));
    newNodo->T.Descripcion = Tarea.Descripcion;
    newNodo->T.Duracion = Tarea.Duracion;
    newNodo->T.TareaID = Tarea.TareaID;
    newNodo->siguiente = NULL;

    return newNodo;
}

void insertarNodo(Nodo **start, Nodo *nuevoNodo)
{
    nuevoNodo->siguiente = *start;
    *start = nuevoNodo;
    (*start)->longuitud++;
}

void mostarLista(Nodo **start)
{
    Nodo *aux = *start;
    int i = 0;

    while (aux != NULL)
    {
        printf("\nTarea pendiente[%d]: %s, Tiempo Necesario: %d",i,aux->T.Descripcion,aux->T.Duracion);
        aux = aux->siguiente;
        i++;
    }
}