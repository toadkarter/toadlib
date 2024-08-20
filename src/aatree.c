#include <malloc.h>
#include "aatree.h"

static void skew(AATreeNode* node)
{
    if (node->left != NULL && node->left->level == node->level)
    {
        AATreeNode* temp = node;
        node = node->left;
        temp->left = node->right;
        node->right = temp;
    }
}

static void split(AATreeNode* node)
{
    if (node->right != NULL && node->right->right != NULL && node->right->right->level == node->level)
    {
        AATreeNode* temp = node;
        node = node->right;
        temp->right = node->left;
        node->left = temp;
        node->level = node->level + 1;
    }
}

AATreeNode* AATreeCreate(const uint8_t key, void* data)
{
    AATreeNode* root = malloc(sizeof(AATreeNode));
    root->key = key;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    root->level = 1;

    return root;
}

void AATreeDestroy(AATreeNode *root)
{
    if (root != NULL)
    {
        AATreeDestroy(root->left);
        AATreeDestroy(root->right);
        free(root);
    }
}

void AATreeInsert(const uint8_t key, void* data, AATreeNode* root, bool* success)
{
    if (root == NULL)
    {
        root = malloc(sizeof(AATreeNode));
        root->key = key;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->level = 1;
        *success = true;
    }
    else
    {
        if (key < root->key)
        {
            AATreeInsert(key, data, root->left, success);
        }
        else if (key > root->key)
        {
            AATreeInsert(key, data, root->right, success);
        }
        else
        {
            *success = false;
        }

        skew(root);
        split(root);
    }
}

void AATreeDelete(uint8_t key, AATreeNode* root, bool* success)
{

}