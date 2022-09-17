#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utility.h"
typedef struct student std;
typedef struct teacher teach;
std* readstudents(char* adress, std*head){
	FILE* fptr = fopen(adress, "r");
	int numofcourses;
	if (fptr == NULL)
		return head;
	while (!feof(fptr)){
		head->next = malloc(sizeof(std));
		head = head->next;
		head->name = malloc(sizeof(char));
		head->pass = malloc(sizeof(char));
		head->grade = malloc(sizeof(float));
		fscanf(fptr, "%s", head->name);
		fscanf(fptr, "%s", head->pass);
		fscanf(fptr, "%d", &numofcourses);
		for (int i = 0; i < numofcourses; i++){
			fscanf(fptr, "%f", &head->grade[i]);
		}
		head->next = NULL;
	}
}
teach* readteachers(char* adress, teach* head){
	FILE* fptr = fopen(adress, "r");
	std* sreqptr = &head->reqhead;
	int numofreqs;
	int numofstudents;
	if (fptr == NULL)
		return head;
	while (!feof(fptr)){
		head->next = malloc(sizeof(teach));
		head = head->next;
		head->stdptr = malloc(sizeof(std));
		std* sptr = head->stdptr;
		sptr->next = NULL;
		sreqptr = &head->reqhead;
		head->name = malloc(sizeof(char));
		head->pass = malloc(sizeof(char));
		fscanf(fptr, "%s", head->name);
		fscanf(fptr, "%s", head->pass);
		fscanf(fptr, "%d", &head->ID);
		fscanf(fptr, "%d", &numofreqs);
		for (int i = 0; i < numofreqs; i++){
			sreqptr->next = malloc(sizeof(std));
			sreqptr = sreqptr->next;
			sreqptr->name = malloc(sizeof(char));
			fscanf(fptr, "%s", sreqptr->name);
			sreqptr->next = NULL;
		}
		fscanf(fptr, "%d", &numofstudents);
		for (int i = 0; i < numofstudents; i++){
			sptr->next = malloc(sizeof(std));
			sptr = sptr->next;
			sptr->name = malloc(sizeof(char));
			fscanf(fptr, "%s", sptr->name);
			sptr->next = NULL;
		}
		head->next = NULL;
	}
}