#include <stdio.h>

#define buffersize 10

int buffer[buffersize];
int in=0;                 // Pointer to the location where new elements is to be inserted
int out=0;               // Pointer to the location where element is present to be consumed
                         // Initially both are are pointing to 0
int sizeofqueue=0;

int isFull(){
    return ((in+1)%buffersize==out);
}

int isEmpty(){
    return in==out;
}

void Enqueue(int x){
    if(isFull()){
        printf("Queue is full\n");
        return;
    }

    buffer[in]=x;                                  //Insert element
    printf("Enqueued element : %d\n",buffer[in]);
    in=(in+1)%buffersize;                          // make 'in' point to the next valid location where new element will be inserted
    sizeofqueue++;                                 // increment size by 1
}

void Dequeue(){
    int x=0;
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }

    x=buffer[out];                                     // consume element
    out=(out+1)%buffersize;                           //  make 'out' point to the next location where element is present to be consumed
    printf("Dequeued element : %d\n",x);
    sizeofqueue--;
}

int size(){
    printf("Size: %d\n",sizeofqueue);
    return;
}

int main(void){

  Enqueue(16),Enqueue(15),Enqueue(14),Dequeue(),Enqueue(13),Enqueue(12),Enqueue(11),Enqueue(10),Dequeue(),Enqueue(9),Enqueue(8),Enqueue(7),Enqueue(6),Enqueue(5);
  size();

  Dequeue(),Dequeue(),Dequeue(),Dequeue(),Dequeue(),Dequeue(),Dequeue(),Dequeue(),Dequeue(),Dequeue(),Dequeue(),Dequeue();

return 0;
}


