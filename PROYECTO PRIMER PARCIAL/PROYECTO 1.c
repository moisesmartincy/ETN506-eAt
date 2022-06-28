//ETN506
//INGENIERIA ELECTRONICA-UMSA
//UNIV. MOISES MARTIN CONDORI YUJRA
//CI. 9103365 LP.
//Obtencion de la respuesta natural de un modelo de variables de estado}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Funcion aplicando recursividad para hallar el factorial de un numero*/
float factorial (int n)
{
    if(n==0)//Caso base
    {
        return 1;
    }
    else//Caso general
    {
        return n*factorial(n-1);
    }
}
/*Funcion aplicando recursividad para hallar el valor de un numero 'x' elevado a la potencia 'u'*/
float potencia (float x,float u)
{
    if (u==0)//caso base
    {
        return 1;
    }
    else //caso general
    {
        return x*potencia(x,u-1);
    }
}
int main()
{
    float t;
    long i,j,k,l,m,numero;
    float A[100][100],X_cero[100][2],E[100][100],O[100][100],X[100][2],P[100][100],Q[100][100];
    /*Introducimos la matriz A*/
    printf("Ingrese la dimension de la matriz cuadrada A\n");
    scanf("%d",&numero);
    printf("\nIntroduzca los datos de la matriz cuadrada A de orden %d\n",numero);
    for (i=1;i<=numero;i++)
    {
          for (j=1;j<=numero;j++)
          {
              printf("Introduzca la entrada (%d,%d) de la matriz A\n",i,j);
              scanf("%f",&A[i][j]);
          }
    }
    printf("La matriz introducida A es:\n");
        for (i=1;i<=numero;i++)
    {
          for (j=1;j<=numero;j++)
          {
              printf("%1.f\t",A[i][j]);
              if(j==numero)
              {
                  printf("\n");
              }
          }
    }
    printf("\nIntroduzca el vector de condiciones iniciales X(0) que es una matriz columna %dx1\n",numero);
    for(k=1;k<=numero;k++)
    {
        printf("Introduzca la entrada (%d,1) de la matriz X(0)\n",k);
        scanf("%f",&X_cero[k][1]);
    }
    printf("El vector de condiciones iniciales X(0) introducido es:\n");
    for(k=1;k<=numero;k++)
    {
        printf("%4.f\n",X_cero[k][1]);
    }
    printf("Introduzca el valor de t sobre el cual desea trabajar\n");
    scanf("%f",&t);
    /*Hallamos la matriz e^At*/
    for (i=1;i<=numero;i++)
    {
        for(j=1;j<=numero;j++)
        {
            if(i==j)
            {
                E[i][j]=A[i][j]*t+1;
            }
            else
            {
                E[i][j]=A[i][j]*t;
            }
        }
    }
    /*Utilizamos 10 iteraciones para hallar el valor de la matriz e^At por series*/
    /*Hallamos para las aproximaciones la matriz A elevada a una potencia*/
    for(i=1;i<=numero;i++)
    {
        for(j=1;j<=numero;j++)
        {
            P[i][j]=A[i][j];
        }
    }
    for(l=2;l<=10;l++)
    {
        for (i=1;i<=numero;i++)
        {
            for(j=1;j<=numero;j++)
            {
                Q[i][j]=0;
                for(k=1;k<=numero;k++)
                {
                    Q[i][j]=Q[i][j]+P[i][k]*A[k][j];
                }
            }
        }
        for(i=1;i<=numero;i++)
        {
            for(j=1;j<=numero;j++)
            {
                E[i][j]=E[i][j]+Q[i][j]*(potencia(t,l)/factorial(l));
            }
        }
        for(i=1;i<=numero;i++)
        {
            for(j=1;j<=numero;j++)
            {
                P[i][j]=Q[i][j];
            }
        }
    }
    printf("La matriz e^At es:\n");
    for(i=1;i<=numero;i++)
    {
        for(j=1;j<=numero;j++)
        {
            printf("%.4f\t",E[i][j]);
            if(j==numero)
            {
                printf("\n");
            }
        }
    }
    for(i=1;i<=numero;i++)
    {
        X[i][1]=0;
        for(k=1;k<=numero;k++)
        {
                X[i][1]=X[i][1]+E[i][k]*X_cero[k][1];
        }
    }
    printf("\nLa solucion de e^At*X(0) expresada matricialmente es:\n");
    for(i=1;i<=numero;i++)
    {
        printf("%.4f\n",X[i][1]);
    }
}
