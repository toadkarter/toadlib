#ifndef AATREE_H_
#define AATREE_H_

#include <bits/stdint-uintn.h>
#include <stdbool.h>

typedef struct Node
{
  uint8_t key;

  uint8_t level;
  struct Node *left;
  struct Node *right;
} Node;

void init();
void insert(uint8_t key, Node *tree, bool *success);

#endif