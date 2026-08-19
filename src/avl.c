#include "../include/avl.h"

#include <stdlib.h>


static int max(
    int a,
    int b
)
{
    return a > b ? a : b;
}


int avl_height(
    AVLNode *root
)
{
    if (root == NULL)
    {
        return 0;
    }

    return root->height;
}


static void update_height(
    AVLNode *node
)
{
    node->height =
        1 + max(
            avl_height(node->left),
            avl_height(node->right)
        );
}


static int balance_factor(
    AVLNode *node
)
{
    if (node == NULL)
    {
        return 0;
    }

    return
        avl_height(node->left) -
        avl_height(node->right);
}


static AVLNode *rotate_right(
    AVLNode *root
)
{
    AVLNode *new_root =
        root->left;

    AVLNode *subtree =
        new_root->right;

    new_root->right = root;

    root->left = subtree;

    update_height(root);

    update_height(new_root);

    return new_root;
}


static AVLNode *rotate_left(
    AVLNode *root
)
{
    AVLNode *new_root =
        root->right;

    AVLNode *subtree =
        new_root->left;

    new_root->left = root;

    root->right = subtree;

    update_height(root);

    update_height(new_root);

    return new_root;
}


static AVLNode *create_node(
    int key
)
{
    AVLNode *node =
        malloc(sizeof(AVLNode));

    if (node == NULL)
    {
        return NULL;
    }

    node->key = key;

    node->height = 1;

    node->left = NULL;

    node->right = NULL;

    return node;
}


AVLNode *avl_insert(
    AVLNode *root,
    int key
)
{
    if (root == NULL)
    {
        return create_node(key);
    }

    if (key < root->key)
    {
        root->left =
            avl_insert(
                root->left,
                key
            );
    }
    else if (key > root->key)
    {
        root->right =
            avl_insert(
                root->right,
                key
            );
    }
    else
    {
        return root;
    }

    update_height(root);

    int balance =
        balance_factor(root);

    /* Left Left */
    if (balance > 1 &&
        key < root->left->key)
    {
        return rotate_right(root);
    }

    /* Right Right */
    if (balance < -1 &&
        key > root->right->key)
    {
        return rotate_left(root);
    }

    /* Left Right */
    if (balance > 1 &&
        key > root->left->key)
    {
        root->left =
            rotate_left(root->left);

        return rotate_right(root);
    }

    /* Right Left */
    if (balance < -1 &&
        key < root->right->key)
    {
        root->right =
            rotate_right(root->right);

        return rotate_left(root);
    }

    return root;
}


AVLNode *avl_search(
    AVLNode *root,
    int key
)
{
    if (root == NULL ||
        root->key == key)
    {
        return root;
    }

    if (key < root->key)
    {
        return avl_search(
            root->left,
            key
        );
    }

    return avl_search(
        root->right,
        key
    );
}


void avl_free(
    AVLNode *root
)
{
    if (root == NULL)
    {
        return;
    }

    avl_free(root->left);

    avl_free(root->right);

    free(root);
}