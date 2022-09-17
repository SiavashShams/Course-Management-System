#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utility.h"
typedef struct student std;
typedef struct teacher teach;
int showreqs(teach* head){
	int i = 0;
	if (head == NULL){
		return 0;
	}
	std* curr = &head->reqhead;
	if (curr->next == NULL){
		printf("Request list is empty\n");
		return 0;
	}
	printf("Request list\n----------------------------\n");
	while (curr->next != NULL){
		i++;
		curr = curr->next;
		printf("Student username: %s", curr->name);
		printf("\n");
	}
	printf("----------------------------\n");
	return i;
}