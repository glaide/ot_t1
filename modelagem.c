#include <stdio.h>
#include <stdlib.h>
#define SIZE_HIDRO 4
#define SIZE_TERMO 2
#include "modelagem.h"

void print_func_obj(int entrada)
{
    // printa funcao objetivo
    printf("min: ");
    for (int i = 0; i < entrada; i++)
    {
        if (i != entrada - 1)
        {
            printf("termo%i + hidro%i + ", i + 1, i + 1);
        }
        else
            printf("termo%i + hidro%i", i + 1, i + 1);
    }
    printf(";\n");
}
void print_hidro(int entrada, float ca)
{
    printf("\n");
    for (int i = 0; i < entrada; i++)
    {
        printf("hidro%i = %fvar%i;\n", i + 1, ca, i + 1);
    }
}

void print_termo(int entrada, float termo)
{
    printf("\n");
    for (int i = 0; i < entrada; i++)
    {
        printf("termo%i = %fv_termo%i;\n", i + 1, termo, i + 1);
    }
}
void print_restricoes(int entrada, float termo[], float hidro[], float hidroV, int demanda[])
{

    printf("\n");

    for (int i = 0; i < entrada; i++)
    {
        printf("%fv_agua_turbinada%i + v_termo%i >= %i;\n", hidroV, i + 1, i + 1, demanda[i]);
    }
    for (int i = 1; i < entrada + 1; i++)
    {
        printf("V%i >= %f", i, hidro[1]);
        printf(";\n");
    }

    for (int i = 1; i < entrada + 1; i++)
    {
        printf("V%i <= %f", i, hidro[2]);
        printf(";\n");
    }

    for (int i = 1; i < entrada + 1; i++)
    {
        printf("v_termo%i <= %f", i, termo[0]);
        printf(";\n");
    }

    for (int i = 1; i < entrada + 1; i++)
    {
        printf("v_termo%i >= 0", i);
        printf(";\n");
    }

    for (int i = 1; i < entrada + 1; i++)
    {
        printf("v_agua_turbinada%i >= 0", i);
        printf(";\n");
    }
}

void print_volume(int entrada, int afluencia[])
{
    printf("\n");
    for (int i = 0; i < entrada; i++)
    {
        printf("Y%i = %i;\n", i + 1, afluencia[i]);
    }
    printf("\n");
    printf("V1 = Vini + Y1 - v_agua_turbinada1;\n");

    for (int i = 2; i <= entrada; i++)
    {
        printf("V%d = V%d + Y%d- v_agua_turbinada%d;\n", i, i - 1, i, i);
    }
    printf("\n");

    printf("mvar1 + dif1 = Vini - V1;\n");
    printf("mvar1 - dif1 = V1 - Vini;\n");

    for (int i = 2; i < entrada + 1; i++)
    {
        printf("mvar%i + dif%i = V%i - V%i;\n", i, i, i - 1, i);
        printf("mvar%i - dif%i = V%i - V%i;\n", i, i, i, i - 1);
    }
    printf("\n");

    for (int i = 0; i < entrada; i++)
    {
        printf("mvar%i >= 0;\n", i + 1);
    }
    printf("\n");

    for (int i = 0; i < entrada; i++)
    {
        printf("dif%i >= 0;\n", i + 1);
    }
    printf("\n");

    for (int i = 1; i < entrada + 1; i++)
    {
        printf("var%i = mvar%i + dif%i;\n", i, i, i);
    }
}

void print_lp(int entrada, float ca, int *afluencia, float termo[], float hidro[], float termoV, float hidroV, int *demanda)
{
    print_func_obj(entrada);
    print_hidro(entrada, ca);
    printf("\nVini = %.0f;\n", hidro[0]);
    print_volume(entrada, afluencia);
    print_termo(entrada, termoV);

    printf("\n");

    print_restricoes(entrada, termo, hidro, hidroV, demanda);
}

void ler_demanda(int n, int *demanda)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &j);
        demanda[i] = j;
    }
}

void imprime_demanda(int n, int *demanda)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", demanda[i]);
    }
    printf("\n");
}

void ler_afluencia(int n, int afluencia[])
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &afluencia[i]);
    }
}

void ler_hidro(int n, float hidro[])
{
    for (int i = 0; i < SIZE_HIDRO; i++)
    {
        scanf("%f", &hidro[i]);
    }
}
void ler_termo(int n, float termo[])
{
    for (int i = 0; i < SIZE_TERMO; i++)
    {
        scanf("%f", &termo[i]);
    }
}

int main()
{
    int entrada;
    float ca, hidro[SIZE_HIDRO], termo[SIZE_TERMO];
    scanf("%d", &entrada);

    int *afluencia = malloc(entrada * sizeof(int));
    int *demanda = malloc(entrada * sizeof(int));
    ler_demanda(entrada, demanda);
    ler_afluencia(entrada, afluencia);
    ler_hidro(entrada, hidro);
    ler_termo(entrada, termo);

    scanf("%f", &ca);

    print_lp(entrada, ca, afluencia, termo, hidro, termo[SIZE_TERMO - 1], hidro[SIZE_HIDRO - 1], demanda);
    // print_entrada(entrada, demanda, afluencia, hidro, termo);
    // printf("%f \n", ca);
}
