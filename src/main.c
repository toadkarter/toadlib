#include <aatree.h>

int main(void)
{
    uint8_t key = 5;
    uint8_t data = 15;
    aaTreeNode* tree = aaTreeCreate(5, (void*)data);

    aaTreeInsert(7, (void*)data, tree);
    aaTreeNode* newRoot = aaTreeInsert(8, (void*)data, tree);

    aaTreeNode* found = aaTreeFind(8, newRoot);

    aaTreeDestroy(tree);
}
