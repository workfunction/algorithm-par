#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE 6
char CircularQueue[MAX_QUEUE];
int front = 0, rear = 0, tmp = 0;

int isFull(){
	return ((rear+1) % MAX_QUEUE == front);
}

int isEmpty(){
	return front == rear;
}

void Add(char* queue, char item){
	if (isFull()) {
		printf("Circular Queue is full!\n");
		return;
	}
	printf("Circular Queue add: %c\n", item);
	rear = (rear + 1) % MAX_QUEUE;
	queue[rear] = item;
}

void Delete(char* queue){
	if (isEmpty()){
		printf("Circular Queue is empty!\n");
		return;
	}
	front = (front + 1) % MAX_QUEUE;
	printf("%c is deleted.\n", queue[front]);
}

void printQueue(char* queue){
	if (isEmpty()){
		printf("Circular Queue is empty!\n");
		return;
	}
	printf("Circular Queue: ");
    tmp = front;
	while (tmp != rear) {
        tmp = (tmp + 1) % MAX_QUEUE;
	    printf("%c ", queue[tmp]);
    }
	printf("\n\n");
}

int main(){
	Add(CircularQueue, '1');
	Add(CircularQueue, '2');
	Add(CircularQueue, '3');
	Add(CircularQueue, '4');
	Add(CircularQueue, '5');
	Add(CircularQueue, '6'); //shows "Circular Queue is full!"
    Delete(CircularQueue);
    Add(CircularQueue, '6');
    Add(CircularQueue, '7');
    Delete(CircularQueue);
    Delete(CircularQueue);
    Add(CircularQueue, '7');
    Add(CircularQueue, '8');
    printQueue(CircularQueue);
    printf("Circular Queue: ");
	for (int i = 0; i < MAX_QUEUE; i++)
		printf("%c ", CircularQueue[i]);
	printf("\n\n");
	return 0;
}