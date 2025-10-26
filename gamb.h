#ifndef GAMB_H
#define GAMB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define LIMPAR system("cls")

int op = 0;

int rodando = 1;

int preco = 1;

int roleta[3][3] = {
    {0,0,0},
    {0,0,0},
    {0,0,0},
};

int chanceQntd = 3;
int chances[10] = {1,5,7,0,0,0,0,0,0,0};

int dinheiro = 0;

float multiplicadorDeGanho = 1;
int dinheiroAGanhar = 0;

int valor3x = 1;

int ganhoAtual = 1;

void menu();
void rolar();
void verificarGanhos();

#endif