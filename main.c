#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ESC 27
void partida();
void mostrarMatrix (char matrix [3][3]);
int buscarPosicionFila (int posicion);
int buscarPosicionColumna (int posicion);
void jugadaUsuario_X (char matrix [3][3],int arregloJugadasX[], int *validosX,int arregloJugadasO[], int *validosO);
void jugadaUsuario_O (char matrix [3][3],int arregloJugadasO[], int *validosO,int arregloJugadasX[], int *validosX);
int verificacionJugada (int posicion, int arregloJugadasX[], int *validosX, int arregloJugadasO[], int *validosO);
int verificarIfGanador(int arr[], int v, int posA, int posB, int posC);
int verificarVictoria(int arr[],int v);
char ganadorPartida(int arrX[], int arrO[], int vX, int vO);
int mostrarGanador(char ganador);

int main()
{
    char option=0;
    while(option!=ESC)
    {
        partida();
        system("pause");
        system("cls");
        printf ("DESEA JUGAR NUEVAMENTE? PRESIONE ESC PARA SALIR\n");
        option = getch();
    }
}

void jugadaUsuario_X (char matrix [3][3],int arregloJugadasX[], int *validosX,int arregloJugadasO[], int *validosO)
{
    int posicion=0;
    int fila;
    int columna;
    int verificacionPosicion;

    while (verificacionPosicion == 0)
    {
        system("cls");
        mostrarMatrix(matrix);
        printf ("\n Jugador X Ingrese posicion desde teclado numerico:\n");
        scanf ("%d", &posicion);
        verificacionPosicion = verificacionJugada(posicion, arregloJugadasX, validosX, arregloJugadasO, validosO); //0 : Jugada invalida,  1: juagada valida
        if (verificacionPosicion == 1)
        {
            arregloJugadasX[*validosX] = posicion;
            (*validosX)++;
            fila = buscarPosicionFila (posicion);
            columna = buscarPosicionColumna (posicion);
            matrix [fila][columna] = 'X';
        }
        else
        {
            printf ("Jugada Invalida. Intente nuevamente\n");
            system("pause");
        }

    }


}

void jugadaUsuario_O (char matrix [3][3],int arregloJugadasO[], int *validosO,int arregloJugadasX[], int *validosX)
{
    int posicion = 0;
    int fila;
    int columna;
    int verificacionPosicion=0;

    while (verificacionPosicion == 0)
    {
        system("cls");
        mostrarMatrix(matrix);
        printf("\n Jugador O Ingrese posicion desde teclado numerico:\n");
        scanf ("%d", &posicion);
        verificacionPosicion = verificacionJugada (posicion, arregloJugadasO, validosO,arregloJugadasX,validosX); //0 : Jugada invalida,  1: juagada valida
        if (verificacionPosicion == 1)
        {
            arregloJugadasO[*validosO] = posicion;
            (*validosO)++;
            fila = buscarPosicionFila (posicion);
            columna = buscarPosicionColumna (posicion);
            matrix [fila][columna] = 'O';
        }
        else
        {
            printf ("Jugada Invalida!. Intente nuevamente\n");
            system("pause");
        }
    }

}

int buscarPosicionFila (int posicion)
{
    int fila;

    if (posicion == 7 || posicion ==8 || posicion ==9)
    {
        fila = 0;
    }
    else if (posicion == 4 || posicion ==5 || posicion ==6)
    {
        fila = 1;
    }
    else if (posicion == 1 || posicion ==2 || posicion ==3)
    {
        fila = 2;
    }
    return fila;
}

int buscarPosicionColumna (int posicion)
{
    int columna;

    if (posicion == 7 || posicion ==4 || posicion ==1)
    {
        columna = 0;
    }
    else if (posicion == 8 || posicion ==5 || posicion ==2)
    {
        columna = 1;
    }
    else if (posicion == 9 || posicion ==6 || posicion ==3)
    {
        columna = 2;
    }
    return columna;
}

int verificacionJugada (int posicion, int arregloJugadasX[], int *validosX, int arregloJugadasO[], int *validosO)
{
    int verificacionPosicion = 1;

    for (int i=0; i<*validosX; i++)
    {
        if (posicion == arregloJugadasX [i])
        {
            verificacionPosicion =0;
        }
    }
    for (int j=0; j<*validosO; j++)
    {
        if (posicion == arregloJugadasO [j])
        {
            verificacionPosicion =0;
        }
    }
    return verificacionPosicion;
}


void mostrarMatrix (char matrix [3][3])
{

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            printf ("%c ",matrix[i][j]);
        }
        printf ("\n");
    }
}
int verificarIfGanador(int arr[], int v, int posA, int posB, int posC)
{
    int ganador=0;


    for(int i=0; i<v; i++)
    {
        if(arr[i] == posA)
        {
            ganador++;
        }
        else if (arr[i] == posB)
        {
            ganador++;
        }
        else if (arr[i] == posC)
        {
            ganador++;
        }
    }

    if(ganador==3)
    {
        ganador=1;
    }
    else
    {
        ganador=0;
    }
    return ganador;
}
int verificarVictoria(int arr[],int v)
{
    int flag=0;
    int counter=0;
    if(flag==0 && counter==0)
    {
        flag=verificarIfGanador(arr, v, 7, 8, 9);
        if(flag==0 && counter==0)
            flag=verificarIfGanador(arr, v, 4, 5, 6);
        if(flag==0 && counter==0)
            flag=verificarIfGanador(arr, v, 1, 2, 3);
        if(flag==0 && counter==0)
            flag=verificarIfGanador(arr, v, 7, 4, 1);
        if(flag==0 && counter==0)
            flag=verificarIfGanador(arr, v, 8, 5, 2);
        if(flag==0 && counter==0)
            flag=verificarIfGanador(arr, v, 9, 6, 3);
        if(flag==0 && counter==0)
            flag=verificarIfGanador(arr, v, 7, 5, 3);
        if(flag==0 && counter==0)
            flag=verificarIfGanador(arr, v, 9, 5, 1);
        counter=1;
    }
    return flag;
}
char ganadorPartida(int arrX[], int arrO[], int vX, int vO)
{
    int winnerX=0;
    int winnerO=0;
    char ganador='n';

    winnerX=verificarVictoria(arrX, vX);
    winnerO=verificarVictoria(arrO, vO);


    if(winnerX==1)
    {
        ganador='X';
    }
    else if(winnerO==1)
    {
        ganador='O';
    }

    return ganador;
}
int mostrarGanador(char ganador)
{
    int win=0;

    if(ganador=='X')
    {
        printf("\nFELICITACIONES JUGADOR X GANASTE\n\n");
        win=1;

    }
    if(ganador=='O')
    {
        printf("\nFELICITACIONES JUGADOR O GANASTE\n\n");
        win=1;
    }
    return win;
}
void partida()
{

    char Tablero [3][3] = {'7', '8', '9', '4', '5', '6', '1', '2', '3'};
    int arregloJugadasX [8];
    int vX=0;
    int arregloJugadasO [8];
    int vO=0;
    int win=0;
    int jugadas=0;

    mostrarMatrix(Tablero);
    while(win==0 && jugadas<9)
    {
        jugadaUsuario_X(Tablero,arregloJugadasX,&vX,arregloJugadasO,&vO);

        jugadas++;

        win=mostrarGanador(ganadorPartida(arregloJugadasX, arregloJugadasO, vX, vO));

        if(win==1)

            break;

        if(jugadas<9)
        {

            jugadaUsuario_O(Tablero,arregloJugadasO,&vO,arregloJugadasX,&vX);

            jugadas++;

            win=mostrarGanador(ganadorPartida(arregloJugadasX, arregloJugadasO, vX, vO));
        }
    }
    if (win == 0 && jugadas == 9)
    {
        system("cls");
        mostrarMatrix(Tablero);
        printf("\nEMPATE\n\n");
    }
}
