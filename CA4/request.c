#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utility.h"
typedef struct student std;
typedef struct teacher teach;
int request(teach* head, std* ptr){
	char* name;
	struct teacher* tptr = head;
	tptr = tptr->next;
	//std* point = tptr->reqhead;
	name = malloc(sizeof(char));
	if (tptr == NULL || ptr == NULL){
		printf("Course not found\n");
	return;
	}
	scanf("%s", name);
	while (strcmp(tptr->name, name)){
		tptr = tptr->next;
		if (tptr == NULL){
			printf("Course not found\n");
			return;
		}
	}
	std* point = &tptr->reqhead;
	if (point == NULL){
		point = malloc(sizeof(std));
		*point = *ptr;
		printf("You requested to this course\n");
		return 1;
	}
	while (point->next != NULL){
		point = point->next;
		if (!strcmp(point->name, ptr->name)){
			printf("You have already requested to this course\n");
			return 0;
		}
	}
	point->next = malloc(sizeof(std));
	*point->next = *ptr;
	point = point->next;
	printf("You requested to this course\n");
	point->next = NULL;
	return 1;
}