#include <malloc.h>
#include "aatree.h"

static AATreeNode* skew(AATreeNode* node)
{
    if (node->left != NULL && node->left->level == node->level)
    {
        AATreeNode* temp = node;
        node = node->left;
        temp->left = node->right;
        node->right = temp;
    }

    return node;
}

static AATreeNode* split(AATreeNode* node)
{
    if (node->right != NULL && node->right->right != NULL && node->right->right->level == node->level)
    {
        AATreeNode* temp = node;
        node = node->right;
        temp->right = node->left;
        node->left = temp;
        node->level = node->level + 1;
    }

    return node;
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

AATreeNode* AATreeInsert(const uint8_t key, void* data, AATreeNode* root)
{
    if (root == NULL)
    {
        root = malloc(sizeof(AATreeNode));
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
            root->left = AATreeInsert(key, data, root->left);
        }
        else if (key > root->key)
        {
            root->right = AATreeInsert(key, data, root->right);
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

void AATreeDelete(uint8_t key, AATreeNode* root, bool* success)
{

}