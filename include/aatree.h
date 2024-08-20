#ifndef AATREE_H_
#define AATREE_H_

/*
 * AA Tree
 *
 * A basic implementation of the AA Tree, as described in "Balanced Search Trees Made Simple" (Andersson, 1993).
 * AATreeCreate, AATreeDestroy and AATreeInsert allocate memory on the heap, so make sure that you call AATreeDestroy
 * when finished with the structure to avoid memory leaks.
 *
 * Data stored inside nodes is not copied - the pointer is directly assigned to the data variable. Freeing the node
 * does not free the data pointer.
 */

#include "definitions.h"

typedef struct AATreeNode
{
  uint8_t key;
  void* data;

  uint8_t level;
  struct AATreeNode* left;
  struct AATreeNode* right;
} AATreeNode;

AATreeNode* AATreeCreate(uint8_t key, void* data);
void AATreeDestroy(AATreeNode* root);

AATreeNode* AATreeInsert(uint8_t key, void* data, AATreeNode* root);
void AATreeDelete(uint8_t key, AATreeNode* root, bool* success);

#endif