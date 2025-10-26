#ifndef GAMB_H
#define GAMB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <windows.h>

#ifdef _WIN32
#define LIMPAR system("cls")
#else
#define LIMPAR system("clear")
#endif

#define COR_RESET    "\x1b[0m"
#define COR_VERDE    "\x1b[32m"
#define COR_AMARELO  "\x1b[33m"
#define COR_VERMELHO "\x1b[31m"
#define COR_CIANO    "\x1b[36m"

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
int valor4x = 2;

int ganhoAtual = 1;

void menu();
void rolar();
void verificarGanhos();

#endif