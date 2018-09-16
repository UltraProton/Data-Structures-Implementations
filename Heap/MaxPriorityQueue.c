#include <stdio.h>
#include<math.h>
#define maxsize 10000

int arr[maxsize];
int size=0;

void Max_Heapify(int * arr, int index){
    int l_in=index*2+1;
    int r_in=index*2+2;
    int largest=index;

    if(l_in<(size) && arr[largest]<arr[l_in])
        largest=l_in;

    if(r_in<(size) && arr[largest]<arr[r_in])
        largest=r_in;

    if(largest!=index){
        swap(&arr[largest],&arr[index]);
        Max_Heapify(arr,largest);
    }
}



int parent(int in){
    return ((in-1)/2);
}

void swap(int * a , int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void IncreaseKey(int * arr, int key, int index){
    int i=index;
    if(arr[index]>key){
        printf("Key is smaller than the key present at the index\n");
        return;
    }

    arr[index]=key;
    i=index;

    while(i>0 && arr[parent(i)] < key){
        swap(&arr[i],&arr[parent(i)]);
        i=parent(i);
    }
}


void InsertKey(int *arr, int key){
    size=size+1;
    arr[size-1]=-10000;  /* we are using increase key procedure which first compares the element present at the index
                                            before increasing the key at the position ....//cormen exercise problem
                                            */
    IncreaseKey(arr,key,size-1);
}

int ExtractMax(int *arr){
    int x=0;
    if(size==0){
        printf("Priority queue is empty\n");
        return;
    }

    x=arr[0];
    swap(&arr[0],&arr[size-1]);
    size=size-1;
    Max_Heapify(arr,0);
    return x;
}

int main(void){
    int i=0,n=0,x=0;
    printf("Enter size of Priority queue\n");
    scanf("%d",&n);

    printf("Enter elements\n");
    while(i<n){
        scanf("%d",&x);
        InsertKey(arr,x);
        i++;
    }

    printf("\n Max element is : %d\n",ExtractMax(arr));
    IncreaseKey(arr,800,3);
    printf("\n Max element is : %d\n",ExtractMax(arr));
    printf("Size : %d",size);
return 0;

}


