#include "game.h"
int main()
{
  menu();
  return 0;
}
void Initboard(char arr[row][col], int rows, int cols, char set)
{
  int i, j;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j++)
    {
      arr[i][j] = set;
    }
  }
}
void showboard(char arr[row][col], int rows, int cols)
{
  int i, j;
  for (i = 0; i <= rows; i++)
  {
    printf("%d ", i);
  }
  printf("\n");
  for (i = 0; i < rows; i++)
  {
    printf("%d ", i + 1);
    for (j = 0; j < cols; j++)
    {
      printf("%c ", arr[i][j]);
    }
    printf("\n");
  }
}
void makemine(char arr[row][col], int rows, int cols)
{
  int x, y;
  int count = mine;
  while (count)
  {
    x = rand() % row + 1;
    y = rand() % col + 1;
    if (arr[x - 1][y - 1] != '0')
    {
      continue;
    }
    else
    {
      arr[x - 1][y - 1] = '1';
    }
    count--;
  }
}
int nummine(char arr[row][col], int x, int y)
{
  return arr[x - 1][y - 1] +
         arr[x - 1][y] +
         arr[x - 1][y + 1] +
         arr[x][y - 1] +
         arr[x][y + 1] +
         arr[x + 1][y - 1] +
         arr[x + 1][y] +
         arr[x + 1][y + 1] - 8 * '0';
}
void game()
{
  int x, y;
  int count = mine;
  srand((unsigned int)time(NULL));
  // 布置雷的信息
  char mines[row][col] = {0};
  // 排查雷的信息
  char show[row][col] = {0};
  // 初始化
  Initboard(mines, row, col, '0');
  Initboard(show, row, col, '*');
  // showboard(mines, row, col);
  showboard(show, row, col);
  // 生成雷
  makemine(mines, row, col);
  // showboard(mines, row, col);
  while (count)
  {
    printf("请输入坐标:>");
    scanf("%d%d", &x, &y);
    if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
    {
      // 是否踩雷
      if (mines[x - 1][y - 1] == '1')
      {
        showboard(mines, row, col);
        printf("你踩到雷了，游戏结束\n");
        break;
      }
      else
      {
        int count = nummine(mines, x - 1, y - 1);
        show[x - 1][y - 1] = count + '0';
        showboard(show, row, col);
        // showboard(mines, row, col);
      }
    }
    else
    {
      printf("坐标非法，请重新输入\n");
      continue;
    }
  }
}
void menu()
{
  int input;
  do
  {
    printf("****************************************************\n");
    printf("**************        1. game           ************\n");
    printf("**************        0. exit           ************\n");
    printf("****************************************************\n");
    printf("请输入:>");
    scanf("%d", &input);
    switch (input)
    {
    case 1:
      printf("扫雷\n");
      game();
      break;
    case 0:
      printf("退出游戏\n");
      break;
    default:
      printf("输入错误，请重新输入\n");
      break;
    }
  } while (input);
}