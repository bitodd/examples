#include "stdio.h"
#include "stdlib.h"

void print_ret(int arr[10]) {
    int i = 0;
    for(;i<10;++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    fflush(stdout);
}

void bubble_sort(int arr[10]) {
    int temp = 0, i = 0, j = 0;
    for(;i<9;++i) {
        for(j=i+1;j<10;++j) {
            if(arr[i]>arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    print_ret(arr);
}

int main(int argc, char* argv[]) {

    int i = 0, j =0;
    int array[10] = {10,3,5,8,9,6,1,2,66,88};
    bubble_sort(array);
    return 0;
}
