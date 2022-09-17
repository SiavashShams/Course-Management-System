#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utility.h"
typedef struct student std;
typedef struct teacher teach;
int studentslist(teach* head){
	int count = 0;
	std* point = head->stdptr;
	if (point == NULL || point->next == NULL)
		return 0;
	while (point->next != NULL){
		point = point->next;
		count++;
	}
	return count;
}