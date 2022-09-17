typedef struct student std;
typedef struct teacher teach;
struct student{
	float* grade;
	char* name;
	char* pass;
	std* next;
};
struct teacher {
	char* name;
	char* pass;
	int ID;
	std reqhead;
	std* stdptr;
	teach* next;
};
int checknamestd(std*, char*);
std* insert_std(std*,int*,int*);
teach* insert_teacher(teach*,int*,int*);
int checknameteach(teach*, char*);
int request(teach*, std*);
int deletenode(std*, char*);
int accept(teach*);
int showreqs(teach*);
std* loginstd(std*, int*, int*);
teach* loginteach(teach*, int*, int*);
void grade(teach*);
void showgrade(std*, teach*);
int teacherlist(teach*, std*);
int studentslist(teach*);
void savestudents(teach*, std*);
void saveteachers(teach*);
std* readstudents(char* , std*);
teach* readteachers(char* , teach*);