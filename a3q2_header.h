#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef HEAP
#define HEAP

void downHeap(int key[20], int pos, int array[20][10]);
bool isParent(int keyPos);
void swap(int key1Pos, int key2Pos, int key[20], int array[20][10]);

#endif