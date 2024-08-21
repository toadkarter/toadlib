#include <malloc.h>
#include "aatree.h"

static aaTreeNode* skew(aaTreeNode* node)
{
    if (node->left != NULL && node->left->level == node->level)
    {
        aaTreeNode* temp = node;
        node = node->left;
        temp->left = node->right;
        node->right = temp;
    }

    return node;
}

static aaTreeNode* split(aaTreeNode* node)
{
    if (node->right != NULL && node->right->right != NULL && node->right->right->level == node->level)
    {
        aaTreeNode* temp = node;
        node = node->right;
        temp->right = node->left;
        node->left = temp;
        node->level = node->level + 1;
    }

    return node;
}

aaTreeNode* aaTreeCreate(const uint8_t key, void* data)
{
    aaTreeNode* root = malloc(sizeof(aaTreeNode));
    root->key = key;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    root->level = 1;

    return root;
}

void aaTreeDestroy(aaTreeNode *root)
{
    if (root != NULL)
    {
        aaTreeDestroy(root->left);
        aaTreeDestroy(root->right);
        free(root);
    }
}

aaTreeNode* aaTreeInsert(const uint8_t key, void* data, aaTreeNode* root)
{
    if (root == NULL)
    {
        root = malloc(sizeof(aaTreeNode));
        root->key = key;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->level = 1;

        return root;
    }
    else
    {
        if (key < root->key)
        {
            root->left = aaTreeInsert(key, data, root->left);
        }
        else if (key > root->key)
        {
            root->right = aaTreeInsert(key, data, root->right);
        }
        else
        {
            return NULL;
        }

        root = skew(root);
        root = split(root);

        return root;
    }
}

aaTreeNode* aaTreeFind(uint8_t key, aaTreeNode* root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->key == key)
    {
        return root;
    }

    if (root->key > key)
    {
        aaTreeFind(key, root->right);
    }
    else if (root->key < key)
    {
        aaTreeFind(key, root->left);
    }
}