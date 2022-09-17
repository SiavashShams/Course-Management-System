#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utility.h"
typedef struct student std;
typedef struct teacher teach;
int deletenode(std* head, char* name){
	std* prev = head;
	if (head == NULL){
		return 0;
	}
	while (head->next != NULL){
		prev = head;
		head = head->next;
		if (!strcmp(head->name, name)){
			prev->next = head->next;
			free(head);
			return 1;
		}
	}
	return 0;
}
int accept(teach* ptr){
	char* name;
	
	std* point = &ptr->reqhead;
	name = malloc(sizeof(char));
	scanf("%s", name);
	std* temp = point;
	point = point->next;
	if (ptr == NULL || point==NULL){
		printf("Student not found\n");
		return;
	}
	
	
	while (strcmp(point->name, name)){
		point =point->next;
		if (point == NULL){
			printf("Student not found\n");
			return;
		}
	}
	std* sptr = ptr->stdptr;
	while (sptr->next != NULL){
		sptr= sptr->next;
	}
		sptr->next = malloc(sizeof(std));
		*sptr->next = *point;
		sptr->next->next = NULL;
		deletenode(temp, name);			
		printf("Student accepted\n");
		return 1;
	}
