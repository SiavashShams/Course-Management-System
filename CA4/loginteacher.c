#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utility.h"
typedef struct student std;
typedef struct teacher teach;
teach* loginteach(teach* head, int* permision, int* per){
	char* name = malloc(sizeof(char));
	char* password = malloc(sizeof(char));
	scanf("%s %s", name, password);
	while (head->next != NULL){
		head = head->next;
		if (!strcmp(head->name, name)){
			if (!strcmp(head->pass, password)){
				printf("Welcome back %s\n", head->name);
				*permision = 1;
				return head;
			}
		}
	}
	printf("Username or password is incorrect\n");
	*permision = 0;
	*per = 0;
	return NULL;
}