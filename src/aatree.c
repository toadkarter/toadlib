#include "aatree.h"
#include <malloc.h>
#include <stddef.h>

inline static void skew(Node* node)
{
    Node *temp;

    if (node->left != NULL && node->left->level == node->level)
    {
        temp = node;
        node = node->left;
        temp->left = node->right;
        node->right = temp;
    }
}

inline static void split(Node* node)
{
    Node *temp;

    if (node->right != NULL && node->right->right != NULL && node->right->right->level == node->level)
    {
        temp = node;
        node = node->right;
        temp->right = node->left;
        node->left = temp;
        node->level = node->level + 1;
    }
}

void insert(uint8_t key, Node *tree, bool *success)
{
    if (tree == NULL)
    {
        tree = malloc(sizeof(Node));
        tree->left = NULL;
        tree->right = NULL;
        tree->level = 1;
        *success = true;
    }
    else
    {
        if (key < tree->key)
        {
            insert(key, tree->left, success);
        }
        else if (key > tree->key)
        {
            insert(key, tree->right, success);
        }
        else
        {
            *success = false;
        }

        skew(tree);
        split(tree);
    }
}