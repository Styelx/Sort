#ifndef SORT_SORT_H
#define SORT_SORT_H

void swap(int* data, int i, int j);
void bubble_sort(int* data, int len);
void insert_sort(int* data, int len);
void select_sort(int* data, int len);
void heap_build(int* data, int root, int len);
void heap_sort(int* data, int len);

#endif //SORT_SORT_H
