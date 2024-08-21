#ifndef AATREE_H_
#define AATREE_H_

/*
 * AA Tree
 *
 * A basic implementation of the AA Tree, as described in "Balanced Search Trees Made Simple" (Andersson, 1993).
 * aaTreeCreate and aaTreeInsert allocate memory on the heap, so make sure that you call aaTreeDestroy
 * when finished with the structure to avoid memory leaks.
 *
 * Data stored inside nodes is not copied - the pointer is directly assigned to the data variable. Freeing the node
 * does not free the data pointer.
 */

#include "definitions.h"

typedef struct aaTreeNode
{
  uint8_t key;
  void* data;

  uint8_t level;
  struct aaTreeNode* left;
  struct aaTreeNode* right;
} aaTreeNode;

aaTreeNode* aaTreeCreate(uint8_t key, void* data);
void aaTreeDestroy(aaTreeNode* root);

aaTreeNode* aaTreeInsert(uint8_t key, void* data, aaTreeNode* root);
aaTreeNode* aaTreeFind(uint8_t key, aaTreeNode* root);

#endif