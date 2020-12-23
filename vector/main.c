#include <stdio.h>
#include "vector.h"

void testPushAndBack(void) {
    printf("First practice at vector setup\n");
    printf("Let us do integers first!\n");

    printf("What first integer do you want in the array?\n");
    int first;
    scanf("%d", &first);

    printf("What is the second integer do you want in the array?\n");
    int second;
    scanf("%d", &second);

    printf("What is the third letter you want in the array?\n");
    int third;
    scanf("%d", &third);

    struct vec_t *myVector = Vector(sizeof(int), 3);

    PushBack((void *)&first, myVector);
    PushBack((void *)&second, myVector);
    PushBack((void *)&third, myVector);

    printf("\nArray Contains:\n");
    for (int i= 0; i < 3; i++) {
        printf("%d\n", *((int *)At(i, myVector)));
    }

    DestroyVector(myVector);
}

void testSwap(void) {
    struct vec_t *vec1 = Vector(sizeof(int), 5);
    struct vec_t *vec2 = Vector(sizeof(int), 5);

    int a1[5] = {0, 1, 2, 3, 4};
    int a2[5] = {5, 6, 7, 8, 9};

    for (int i = 0; i < 5; i++) {
        PushBack((void *)&a1[i], vec1);
        PushBack((void *)&a2[i], vec2);
    }

    printf("Before Swamp\n");
    printf("Vector1:\tVector2:\n");
    for (int i = 0; i < Size(vec1); i++) {
        int elem1 = *((int *)At(i, vec1));
        int elem2 = *((int *)At(i, vec2));

        printf("%d\t\t%d\n", elem1, elem2);
    }

    Swap(vec1, vec2);

    printf("\nAfter Swap\n");
    printf("Vector1:\tVector2:\n");
    for (int i = 0; i < Size(vec1); i++) {
        int elem1 = *((int *)At(i, vec1));
        int elem2 = *((int *)At(i, vec2));

        printf("%d\t\t%d\n", elem1, elem2);
    }

    DestroyVector(vec1);
    DestroyVector(vec2);
}

int main(void) {
    testPushAndBack();
    testSwap();

    return 0;
}