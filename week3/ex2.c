#include <stdio.h>


void Bubble_Sort(int *arr, int n){
    int i = 0,j;
    for(;i < n;++i){
        for(j = i+1;j < n;++j){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

    }

}
int main(){
    int n,i = 0;
    scanf("%d",&n);
    int arr[n];
    for(;i < n;++i){
        scanf("%d",arr+i);
    }
    Bubble_Sort(arr , n);
    for(i = 0;i < n;++i){
       printf("%d ",arr[i]);
    }
}
