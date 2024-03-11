#include "game.h"
int main()
{
  // 菜单
  menu();
  return 0;
}
void menu()
{
  int input;
  do
  {
    printf("***********************************\n");
    printf("********1.game******0.exit*********\n");
    printf("***********************************\n");
    scanf("%d", &input);
    switch (input)
    {
    case 1:
      printf("三子棋\n");
      game();
      break;
    case 0:
      printf("退出游戏\n");
      break;
    default:
      printf("输入错误，请重新输入\n");
      break;
    }
    if (input == 1)
      break;
  } while (input);
}
void csplate(char plate[ROW][COL], int row, int col)
{
  int i, j;
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
      plate[i][j] = ' ';
    }
  }
}
void dyplate(char plate[ROW][COL])
{
  int i, j;
  for (i = 0; i < ROW; i++)
  {
    for (j = 0; j < COL; j++)
    {
      printf("  %c ", plate[i][j]);
      if (j < COL - 1)
      {
        printf("|");
      }
    }
    printf("\n");
    if (i < ROW - 1)
    {
      for (j = 0; j < COL; j++)
      {
        printf("----");
        if (j < COL - 1)
        {
          printf("|");
        }
      }
      printf("\n");
    }
  }
}
void player(char plate[ROW][COL], int row, int col)
{
  int x;
  int y;
  printf("玩家下\n");
  printf("请输入坐标（行列）:>");
  while (1)
  {
    scanf("%d%d", &x, &y);
    if (x >= 1 && x <= row && y >= 1 && y <= col)
    {
      if (plate[x - 1][y - 1] != ' ')
      {
        printf("该坐标已被占位,请重新输入:>");
        continue;
      }
      else
      {
        plate[x - 1][y - 1] = '*';
        break;
      }
    }
    else
    {
      printf("输入非法，请重新输入:>");
      continue;
    }
  }
}
void computer(char plate[ROW][COL], int row, int col)
{
  printf("电脑下\n");
  int x = rand() % row;
  int y = rand() % col;
  while (1)
  {
    if (plate[x][y] == ' ')
    {
      plate[x][y] = 'O';
      break;
    }
    else
    {
      x = rand() % row;
      y = rand() % col;
    }
  }
}
char iffull(char plate[ROW][COL], int row, int col)
{
  int i, j;
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
      if (plate[i][j] == ' ')
        return 'c';
    }
  }
  return 'n';
}
char ifwin(char plate[ROW][COL], int row, int col)
{
  int i;
  // 三列
  for (i = 0; i < row; i++)
  {
    if (plate[0][i] == plate[1][i] && plate[1][i] == plate[2][i] && plate[1][i] != ' ')
      return plate[2][i];
  }
  // 三行
  for (i = 0; i < col; i++)
  {
    if (plate[i][0] == plate[i][1] && plate[i][1] == plate[i][2] && plate[i][1] != ' ')
    {
      return plate[i][1];
    }
  }
  // 对角线
  if (plate[0][0] == plate[1][1] && plate[1][1] == plate[2][2] && plate[1][1] != ' ')
    return plate[0][0];
  if (plate[0][2] == plate[1][1] && plate[1][1] == plate[2][0] && plate[1][1] != ' ')
    return plate[1][1];
  // 全满
  if (iffull(plate, ROW, COL) == 'n')
    return 'n';
  return 'c';
}
void game()
{
  srand((unsigned int)time(NULL));
  char plate[ROW][COL] = {0};
  // 初始化棋盘
  csplate(plate, ROW, COL);
  // 打印棋盘
  dyplate(plate);
  // 下棋
  char ret;
  while (1)
  {
    // 玩家下
    player(plate, ROW, COL);
    dyplate(plate);
    ret = ifwin(plate, ROW, COL);
    if (ret != 'c')
      break;
    // 电脑下
    computer(plate, ROW, COL);
    dyplate(plate);
    char ret = ifwin(plate, ROW, COL);
    if (ret != 'c')
      break;
  }
  if (ret == '*')
    printf("玩家赢\n");
  else if (ret == 'O')
    printf("电脑赢\n");
  else if (ret == 'n')
    printf("平局\n");
}