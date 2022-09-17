#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utility.h"
typedef struct student std;
typedef struct teacher teach;
teach* insert_teacher(teach* head,int* permision,int* per){
	int i = 0;
	char* name;
	char* pass;
	name = malloc(sizeof(char));
	pass = malloc(sizeof(char));
	if (head == NULL)
		return;
	struct teacher *ptr = head;
	while (ptr->next != NULL){
		ptr = ptr->next;
		i++;
	}
	ptr->next = malloc(sizeof(teach));
	ptr = ptr->next;
	ptr->next = NULL;
	ptr->name = malloc(sizeof(char));
	ptr->pass = malloc(sizeof(char));
	scanf("%s %s", name, pass);
	if (checknameteach(head, name) == 0){
		*permision = 0;
		*per = 0;
		return;
	}
	*permision = 1;
	ptr->name = name;
	ptr->pass = pass;
	ptr->ID = i;
	ptr->reqhead.next=NULL;
	ptr->stdptr = malloc(sizeof(std));
	ptr->stdptr->next = NULL;
	printf("Teacher added succussfully\n");
	return ptr;
}