#ifndef __CONTACT_H__
#define __CONTACT_H__
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
struct PeoInfo
{
  char name[MAX_NAME];
  int age;
  char sex[MAX_SEX];
  char tele[MAX_TELE];
  char addr[MAX_ADDR];
};

enum Option
{
  EXIT,
  ADD,
  DEL,
  SEARCH,
  MODIFY,
  SHOW,
  SORT
};
// 通讯录类型
struct contact
{
  struct PeoInfo *data;
  int size;     // 记录当前的通讯录人数
  int capacity; // 记录当前通讯录的最大容纳
};
// 初始化
void InitContact(struct contact *ps);

// 检查是否容纳满
void checkCapacity(struct contact *ps);

// 增加
void AddContact(struct contact *ps);

// 展示
void ShowContact(struct contact *ps);

// 删除
void DelContact(struct contact *ps);

// 查找并打印
void SearchContact(struct contact *ps);

// 修改指定内容
void ModifyContact(struct contact *ps);

// 排序
void SortContact(struct contact *ps);
#endif