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
} Nodo;

int main()
{
    Nodo *starPendientes = NULL, *starRealizar = NULL;
    Nodo *tareaPendientes, *tareaRealizadas;
    int opcion, cargaTareas = 0, opcionMenu = 0;
    char *descripcion = (char *)malloc(100 * sizeof(char));

    while (opcionMenu == 0)
    {
        printf("### MENU ###\n1_Agregar Tareas\n2_Mostrar Tareas pendientes\n3_Mostrar Tareas realizadas\n");
        scanf("%d", &opcion);

        if (opcion == 1)
        {
            while (cargaTareas == 0)
            {
                tareaPendientes = (Nodo *)malloc(sizeof(Nodo));
                printf("\nIngresar la tarea a realizar: ");
                scanf("%s", descripcion);
                fflush(stdin);
                tareaPendientes->T.Descripcion = (char *)malloc((strlen(descripcion) + 1) * sizeof(char));
                strcpy(tareaPendientes->T.Descripcion, descripcion);
                printf("\nIngresar el tiempo de duracion de la tarea: ");
                scanf("%d", &tareaPendientes->T.Duracion);
                fflush(stdin);
                tareaPendientes->T.TareaID++;

                tareaPendientes->siguiente = NULL;
                starPendientes = tareaPendientes;

                printf("\n0_Seguir agregando tareas\n1_Terminar de agregar tareas\n");
                scanf("%d", &cargaTareas);
            }
        }
        if (opcion == 2)
        {
        }
        if (opcion == 3)
        {
        }

        printf("\nDESEA SEGUIR EN LA INTERFAZ?\n0_SI\n1_NO\n");
        scanf("%d", &opcionMenu);
    }
}
