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

//希尔排序
void shell_sort(int* data, int len){
    int step = len/2;
    while(step >= 1){
        for(int i = step;i < len;i++){
            int temp = data[i];
            int j = i;
            while(j-step >= 0){
                if(temp < data[j-step]){
                    data[j] = data[j-step];
                    j = j - step;
                }
                else{
                    break;
                }
            }
            data[j] = temp;
        }
        step = step/2;
    }
}

//子数组归并
void merge(int* data, int left, int mid, int right){
    int temp[100];
    int i = left;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= right){
        if(data[i] <= data[j]){
            temp[k++] = data[i++];
        }
        else{
            temp[k++] = data[j++];
        }
    }
    //后半没填完
    while(j <= right){
        temp[k++] = data[j++];
    }
    //前半没填完
    while(i <= mid){
        temp[k++] = data[i++];
    }
    for(int m = 0;m < k;m++){
        data[left] = temp[m];
        left++;
    }
}
//归并排序
void merge_sort(int* data, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge_sort(data,left,mid);
        merge_sort(data,mid+1,right);
        merge(data,left,mid,right);
    }
}


//快速排序基准数
int shift(int* data, int low, int high){
    int base = data[low];
    int len = sizeof(data)/ sizeof(data[0]);
    while(low < high){
        while(low < high && data[high] >= base){
            high--;
        }
        data[low] = data[high];
        while(low < high && data[low] <= base){
            low++;
        }
        data[high] = data[low];
    }
    data[low] = base;
    int k = low;
    return low;
}
//快速排序
void shift_sort(int* data, int low, int high){
    int base_pos;
    if(low < high){
        base_pos = shift(data,low,high);
        shift_sort(data,low,base_pos);
        shift_sort(data,base_pos+1,high);
    }
}