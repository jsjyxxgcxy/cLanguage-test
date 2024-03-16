#ifndef __GAME_H__
#define __GAME_H__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define row 9
#define col 9
#define mine 10
void menu();
void game();
void makemine(char arr[row][col], int rows, int cols);
void showboard(char arr[row][col], int rows, int cols);
void Initboard(char arr[row][col], int rows, int cols, char set);
#endif