#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utility.h"
typedef struct student std;
typedef struct teacher teach;
void savestudents(teach* thead, std* head){
	FILE* fptr = fopen("students.txt", "w+");
	int i = 0;
	if (head->next == NULL)
		return;
	while (head->next != NULL){
		head = head->next;
		fprintf(fptr, "%s ", head->name);
		fprintf(fptr, "%s ", head->pass);
		i = teacherlist(thead, head);
		fprintf(fptr, "%d ", i);
		for (int j = 0; j < i; j++){
			if (head->grade[j] >= 0)
				fprintf(fptr, "%f ", head->grade[j]);
			else
				fprintf(fptr, "0 ");
		}
		fprintf(fptr, "\n");
	}
	fclose(fptr);
}
void saveteachers(teach* thead){
	FILE* fptr = fopen("teachers.txt", "w+");
	int i = 0;
	std* point = &thead->reqhead;
	std* sptr = thead->stdptr;
	if (thead->next == NULL)
		return;
	while (thead->next != NULL){
		thead = thead->next;
		sptr = thead->stdptr;
		point = &thead->reqhead;
		fprintf(fptr, "%s ", thead->name);
		fprintf(fptr, "%s ", thead->pass);
		i = showreqs(thead);
		fprintf(fptr, "%d ", i);
		for (int j = 0; j < i; j++){
			point = point->next;
			fprintf(fptr, "%s ", point->name);
		}
		int k = studentslist(thead);
		fprintf(fptr, "%d ", k);
		for (int z = 0; z < k; z++){
			sptr = sptr->next;
			fprintf(fptr, "%s ", sptr->name);
		}
		fprintf(fptr, "\n");
	}
}