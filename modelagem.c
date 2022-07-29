#include <stdio.h>
#define SIZE_HIDRO 4
#define SIZE_TERMO 2
#include "modelagem.h"

void ler_entrada(int n, int demanda[], int afluencia[], float hidro[], float termo[])
{
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &demanda[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &afluencia[i]);
    }
    for (int i = 0; i < SIZE_HIDRO; i++)
    {
        scanf("%f", &hidro[i]);
    }
    for (int i = 0; i < SIZE_TERMO; i++)
    {
        scanf("%f", &termo[i]);
    }
}

void print_entrada(int n, int demanda[], int afluencia[], float hidro[], float termo[])
{

    for (int i = 0; i < n; i++)
    {
        printf("%i ", demanda[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%i ", afluencia[i]);
    }
    for (int i = 0; i < SIZE_HIDRO; i++)
    {
        printf("%.1f ", hidro[i]);
    }
    for (int i = 0; i < SIZE_TERMO; i++)
    {
        printf("%.1f ", termo[i]);
    }
}

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
void print_hidro(int entrada, float ca, float termo)
{
    printf("\n");
    for (int i = 0; i < entrada; i++)
    {
        printf("hidro%i = %fvar%i;\n", i + 1, ca, i + 1);
    }

    printf("\n");
    for (int i = 0; i < entrada; i++)
    {
        printf("termo%i = %fVterm%i;\n", i + 1, termo, i + 1);
    }
}

void print_restricoes(int entrada, float hidro, int demanda[])
{
    printf("\n");

    for (int i = 0; i < entrada; i++)
    {
        printf("%fVat%i + Vterm%i >= %i;\n", hidro, i + 1, i + 1, demanda[i]);
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

void print_lp(int entrada, float ca, int afluencia[], float hidro[], float termo, float hidroV, int demanda[])
{
    print_func_obj(entrada);
    print_hidro(entrada, ca, termo);
    printf("\n");
    printf("Vini = %.0f;\n", hidro[0]);
    print_volume(entrada, afluencia);
    print_restricoes(entrada, hidroV, demanda);
}

int main()
{
    int entrada, demanda[entrada], afluencia[entrada];
    float ca, hidro[SIZE_HIDRO], termo[SIZE_TERMO];
    scanf("%d", &entrada);
    ler_entrada(entrada, demanda, afluencia, hidro, termo);

    scanf("%f", &ca);
    float vMonth[entrada];
    print_lp(entrada, ca, afluencia, hidro, termo[SIZE_TERMO - 1], hidro[SIZE_HIDRO - 1], demanda);
    // print_entrada(entrada, demanda, afluencia, hidro, termo);
    // printf("%f \n", ca);
}