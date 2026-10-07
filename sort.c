#include <stdio.h>
#include "sort.h"

void swap(int* data, int i, int j){
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

//冒泡排序
void bubble_sort(int* data, int len){
    for(int i = 0;i < len-1;i++){
        for(int j = 0;j < len-i-1;j++){
            if(data[j] > data[j+1]){
                swap(data, j, j+1);
            }
        }
    }
}

//插入排序
void insert_sort(int* data, int len){
    for(int i = 1;i < len;i++){
        if(data[i] < data[i-1]){
            int temp = data[i];
            int j = i-1;
            while(data[j] > temp && j >= 0){
                data[j+1] = data[j];
                j--;
            }
            data[j+1] = temp;
        }
    }
}

//选择排序
void select_sort(int* data, int len){
    for(int i = 0;i < len-1;i++){
        int max = data[0];
        int pos = 0;
        for(int j = 0;j < len-i;j++){
            if(data[j] >= max){
                max = data[j];
                pos = j;
            }
        }
        swap(data,pos,len-1-i);
    }
}

//堆排序建堆(大根堆/最大堆)
void heap_build(int* data, int root, int len){
    int temp = data[root];
    int child = 2 * root;//左孩子 = 2*root，右孩子 = 2*root+1
    while(child <= len-1){
        //说明有右孩子且右孩子大于左孩子
        if(child < len-1 && data[child+1] > data[child]){
           child++;
        }
        if(data[child] > temp){
            data[child/2] = data[child];
        }
        else{
            break;
        }
        child = 2 * child;
    }
    data[child/2] = temp;
}
//堆排序
//data[]={-1,44,27,78,56,15,65,95,32,88}
void heap_sort(int* data, int len){
    for(int i = (len-1)/2;i >= 1;i--){
        heap_build(data,i,len);
    }
    for(int i = 0;i < len-1;i++){
        swap(data,1,len-1-i);
        heap_build(data,1,len-1-i);
    }
}
