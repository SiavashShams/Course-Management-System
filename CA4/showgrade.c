#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utility.h"
typedef struct student std;
typedef struct teacher teach;
void showgrade(std* head , teach* thead){
	char* name = malloc(sizeof(char));
	scanf("%s", name);
	int ID;
	while (thead->next != NULL){
		thead = thead->next;
		if (!strcmp(thead->name, name)){
			if (head->grade[thead->ID] < 0){
				printf("Not graded yet\n");
				return;
			}
			printf("Your grade is: %f\n", head->grade[thead->ID]);
			return;
		}
	}
	printf("Not graded yet\n");
}