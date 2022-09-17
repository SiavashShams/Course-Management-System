#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utility.h"
typedef struct student std;
typedef struct teacher teach;
std* insert_std(std* head, int* permision,int*per){
	char* name;
	char* pass;
	name = malloc(sizeof(char));
	pass = malloc(sizeof(char));
	if (head == NULL)
		return;
	struct student *ptr = head;
	while (ptr->next != NULL){
		ptr = ptr->next;
	}
	scanf("%s %s", name, pass);
	if (checknamestd(head, name) == 0){
	*permision = 0;
	*per = 0;
	return;
	}
	*permision = 1;
	ptr->next = malloc(sizeof(std));
	ptr = ptr->next;
	ptr->next = NULL;
	ptr->name = malloc(sizeof(char));
	ptr->pass = malloc(sizeof(char));
	ptr->grade = malloc(20*sizeof(float));
	ptr->name = name;
	ptr->pass = pass;
	printf("Student added succussfully\n");
	return ptr;
}