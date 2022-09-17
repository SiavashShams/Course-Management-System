#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct student std;
typedef struct teacher teach;
struct student{
	float* grade;
	char* name;
	char* pass;
	std* next;
}std1;
struct teacher {
	char* name;
	char* pass;
	int ID;
	std reqhead;
	std* stdptr;
	teach* next;
};

       
int main(){
		int p = 1;		//permision
		int p2 = 1;
		char* command;
		std Shead;
		teach Thead;
		Shead.next = NULL;
		std* stdptr = &Shead;
		readstudents("students.txt", &Shead);
		Thead.next = NULL;
		readteachers("teachers.txt", &Thead,&Shead);
		command = malloc(sizeof(char));
		while (1){
			p2 = 1;
			scanf("%s", command);
			if (!strcmp(command, "signup_student")){
				std* Stemp = insert_std(&Shead,&p,&p2);
				if (p){
					while (1){
						scanf("%s", command);
						if (!strcmp(command, "request_course")){
							request(&Thead, Stemp);
						}
						else if (!strcmp(command, "logout")){
							printf("You logged out successfully\n");
							p2 = 0;
							break;
						}
						else if (!strcmp(command, "teacher_list")){
							teacherlist(&Thead,Stemp);
						}
						else if (!strcmp(command, "show_grade"))
							showgrade(Stemp, &Thead);

						else
							printf("Wrong input\n");
					}
				}
			}
			if (!strcmp(command, "login_student")){
				std* Stemp = loginstd(&Shead,&p,&p2);
				if (p){
					while (1){
						scanf("%s", command);
						if (!strcmp(command, "request_course")){
							request(&Thead, Stemp);
						}
						else if (!strcmp(command, "logout")){
							printf("You logged out successfully\n");
							p2 = 0;
							break;
						}
						else if (!strcmp(command, "teacher_list"))
							teacherlist(&Thead, Stemp);
						else if (!strcmp(command, "show_grade")){
							showgrade(Stemp, &Thead);
						}

						else
							printf("Wrong input\n");
					}
				}
			}
			if (!strcmp(command, "login_teacher")){
				teach* Ttemp = loginteach(&Thead, &p, &p2);
				if (p){
					while (1){
						scanf("%s", command);
						if (!strcmp(command, "accept")){
							accept(Ttemp);
						}
						else if (!strcmp(command, "requests_list"))
							showreqs(Ttemp);
						else if (!strcmp(command, "grade"))
							grade(Ttemp);
						else if (!strcmp(command, "logout")){
							printf("You logged out successfully\n");
							p2 = 0;
							break;
						}
						else
							printf("Wrong input\n");
					}
				}
			}
			else if (!strcmp(command, "signup_teacher")){
				teach* Ttemp = insert_teacher(&Thead, &p,&p2);
				if (p){
					while (1){
						scanf("%s", command);
						if (!strcmp(command, "accept")){
							accept(Ttemp);
						}
						else if (!strcmp(command, "requests_list"))
							showreqs(Ttemp);
						else if (!strcmp(command, "grade"))
							grade(Ttemp);
						else if (!strcmp(command, "logout")){
							printf("You logged out successfully\n");
							p2 = 0;
							break;
						}
						else
							printf("Wrong input\n");
					}
				}
			}
			else if (!strcmp(command, "exit")){
				savestudents(&Thead,&Shead);
				saveteachers(&Thead);
				exit(1);
			}
			else if (p2)
				printf("Wrong input\n");
		}
	}

