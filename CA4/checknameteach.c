#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utility.h"
typedef struct student std;
typedef struct teacher teach;
int checknameteach(teach*head, char* name){
	teach* ptr = head;
	while (ptr->next != NULL){
		ptr = ptr->next;
		if (!strcmp(ptr->name, name)){
			printf("This username is already taken\n");
			return 0;
		}
	}
	return 1;
}