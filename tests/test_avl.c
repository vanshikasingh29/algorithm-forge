#include <stdio.h>
#include <stdlib.h>

#include "../include/avl.h"


int main(void)
{
    int passed = 0;
    int failed = 0;


    printf("\nAVL Tree Tests\n");
    printf("============================\n\n");


    AVLNode *root = NULL;


    int values[] =
    {
        30,
        20,
        10,
        25,
        40,
        50
    };


    for (size_t i = 0; i < 6; i++)
    {
        root =
            avl_insert(
                root,
                values[i]
            );
    }


    if (avl_search(root, 25) != NULL)
    {
        printf("[PASS] AVL search\n");
        passed++;
    }
    else
    {
        printf("[FAIL] AVL search\n");
        failed++;
    }


    if (avl_search(root, 999) == NULL)
    {
        printf("[PASS] Missing key detection\n");
        passed++;
    }
    else
    {
        printf("[FAIL] Missing key detection\n");
        failed++;
    }


    if (avl_height(root) <= 3)
    {
        printf("[PASS] AVL balancing\n");
        passed++;
    }
    else
    {
        printf("[FAIL] AVL balancing\n");
        failed++;
    }


    avl_free(root);


    printf("\nPassed: %d\n", passed);
    printf("Failed: %d\n", failed);


    return failed == 0
        ? EXIT_SUCCESS
        : EXIT_FAILURE;
}