#ifndef AVL_H
#define AVL_H

typedef struct AVLNode
{
    int key;

    int height;

    struct AVLNode *left;
    struct AVLNode *right;

} AVLNode;


AVLNode *avl_insert(
    AVLNode *root,
    int key
);


AVLNode *avl_search(
    AVLNode *root,
    int key
);


void avl_free(
    AVLNode *root
);


int avl_height(
    AVLNode *root
);

#endif