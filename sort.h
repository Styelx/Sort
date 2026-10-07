#ifndef SORT_SORT_H
#define SORT_SORT_H

void swap(int* data, int i, int j);
void bubble_sort(int* data, int len);
void insert_sort(int* data, int len);
void select_sort(int* data, int len);
void heap_build(int* data, int root, int len);
void heap_sort(int* data, int len);
void shell_sort(int* data, int len);
void merge(int* data, int left, int mid, int right);
void merge_sort(int* data, int left, int right);
int shift(int* data, int low, int high);
void shift_sort(int* data, int low, int high);

#endif //SORT_SORT_H
