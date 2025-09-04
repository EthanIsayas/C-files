#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define CHUNK 10
#define DEBUG true

typedef struct {
	int *data;
	int listSize; // current number of cells in array
	int count; // current number of items in list
} intList;

void addItem(intList*,int);
void printList(intList*);

int main(void) {

	intList *l = malloc(sizeof(intList));
	l->data = NULL;
	l->count = l->listSize = 0;
	for (int i=1; i <= 112; i++)
		addItem(l,i*2);
	printList(l);
	printf("\n");
	return 0;
}

void addItem(intList *l, int item) {
// your code goes here
	if (l->count >= l->listSize) {                                                   //If array is full, move all files to temp array
	
		int *temp = (int*)malloc((l->listSize += CHUNK) * sizeof(int));
		int counter=0;
		for (int i=0; i<l->count; i++) {

			temp[i] = l->data[i];
			//printf("This is run #%d", counter);
			//counter+= 1;
		}
		int * old = l->data;
		l->data = temp;
		free(old);                      //now our old array is empty
	}                                  //endif
	
	l->data[l->count] = item;
	l->count++;
}

void printList(intList *l) {
	for (int i=0; i<l->count; i++) {
		printf("%d ",l->data[i]);
	}
}