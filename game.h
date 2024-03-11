#ifndef __GAME_H__
#define __GAME_H__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
void game();
void menu();
void csplate(char plate[ROW][COL], int row, int col);
void dyplate(char plate[ROW][COL]);
void player(char plate[ROW][COL], int row, int col);
void computer(char plate[ROW][COL], int row, int col);
char ifwin(char plate[ROW][COL], int row, int col);
char iffull(char plate[ROW][COL], int row, int col);
#endif