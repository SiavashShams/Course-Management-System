#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utility.h"
typedef struct student std;
typedef struct teacher teach;
int teacherlist(teach* head,std* scurr){
	int i = 0;
	if (head == NULL)
		return 0;
	while (head->next != NULL){
		head = head->next;
		std* point = head->stdptr;
		while (point->next != NULL){
			point = point->next;
			if (!strcmp(point->name, scurr->name)){
				i++;
				printf("----------\n");
				printf("%s\n", head->name);
				printf("----------\n");
				break;
			}
		}
	}
	if (i == 0)
		printf("Teacher list is empty\n");
	return i;
}