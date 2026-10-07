#include <stdio.h>
#include "sort.h"

void data_print(int* data,int len){
    for(int i = 0;i < len;i++){
        printf("%d\t",data[i]);
    }
    printf("\n");
}

int main() {
    //冒泡排序
    int data_bubble[]={44,27,78,56,15,65,95,32,88};
    int len_bubble = sizeof(data_bubble)/sizeof(data_bubble[0]);
    bubble_sort(data_bubble,len_bubble);
    data_print(data_bubble,len_bubble);

    //插入排序
    int data_insert[]={44,27,78,56,15,65,95,32,88};
    int len_insert = sizeof(data_bubble)/sizeof(data_bubble[0]);
    insert_sort(data_insert,len_insert);
    data_print(data_insert,len_insert);

    //选择排序
    int data_select[]={44,27,78,56,15,65,95,32,88};
    int len_select = sizeof(data_bubble)/sizeof(data_bubble[0]);
    select_sort(data_select,len_select);
    data_print(data_select,len_select);

    //堆排序
    //待排序数组首位-1
    int data_heap[]={-1,44,27,78,56,15,65,95,32,88};
    int len_heap = sizeof(data_heap)/sizeof(data_heap[0]);
    heap_sort(data_heap,len_heap);
    data_print(data_heap,len_heap);
    return 0;
}
