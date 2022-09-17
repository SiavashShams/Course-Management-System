#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utility.h"
typedef struct student std;
typedef struct teacher teach;
void grade(teach*head){
	char* name = malloc(sizeof(char));
	float grade;
	scanf("%s", name);
	scanf("%f", &grade);
	std* point = head->stdptr;
	while (point->next != NULL){
		point = point->next;
		if (!strcmp(point->name, name)){
			//point->grade = malloc(sizeof(float));
			point->grade[head->ID] = grade;
			printf("%s graded\n", point->name);
			return;
		}
	}
	printf("Student not found\n");

}