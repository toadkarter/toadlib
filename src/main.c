#include <aatree.h>

int main(void)
{
    uint8_t key = 5;
    uint8_t data = 15;
    AATreeNode* tree = AATreeCreate(5, (void*)data);

    AATreeInsert(7, (void*)data, tree);
    AATreeNode* newRoot = AATreeInsert(8, (void*)data, tree);

    AATreeDestroy(tree);
}
