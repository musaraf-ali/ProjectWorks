#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 50
#define MAX_STR_LEN 100

typedef struct{
	char taskList[MAX_TASKS][MAX_STR_LEN];
	int isDone[MAX_TASKS];
	int givenTasks;
} Tasks;

void displayTasks(Tasks tasks){
	printf("%40s\n\n","----( To Do list )----");
	if(tasks.givenTasks == 0)
		printf("%30s\n%35s\n","The list is EMPTY!!","Press A or a to add Tasks!!");
	for(int i=0; i<tasks.givenTasks; i++){
		printf(" [%d] ", i+1);
		if(tasks.isDone[i]==1){
			printf("(Done)");
			for(int j=0; tasks.taskList[i][j]!='\0'; j++)
				printf("%c-",tasks.taskList[i][j]);
		} else 
			printf("%s",tasks.taskList[i]);
		printf("\n");
	}
	printf("\n%40s\n","----( End of list )----");
}

void readString(char *string){
	int index = 0;
	char letter = ' ';
	while(letter != '\n'){
		letter = getchar();
		string[index++] = letter;
	}
	index--;
	string[index] = '\0';
}
void addTasks(Tasks *tasks){
	if(tasks->givenTasks == MAX_TASKS){
		printf("No More Task can be added!!");
		return;
	}
	printf("Enter the task.\n");
	printf("> ");
	readString(tasks->taskList[tasks->givenTasks]);
	tasks->isDone[tasks->givenTasks] = 0;
	tasks->givenTasks++;
}

void taskDone(Tasks *tasks, int index){
	tasks->isDone[index-1] = 1;
}

void manageDisplay(Tasks *tasks){
	while(1){	
		system("clear");
		displayTasks(*tasks);
		printf("\n\n (A/a) -> Add Task\t(D/d) -> Mark as Done\t(Q/q) -> Quit \n");
		system("/bin/stty raw");
		char input = getchar();
		system("/bin/stty cooked");
		system("clear");
		displayTasks(*tasks);
		if(input == 'Q' || input == 'q')
			break;
		if(input == 'A' || input == 'a')
			addTasks(tasks);
		else if(input == 'D' || input == 'd'){
			int index;
			printf("Enter the index of the task you wish to mark as done: ");
			scanf("%d",&index);
			taskDone(tasks, index);
		}
	}
}

int main(void){

	Tasks tasks = {{" "},{0},0 };
	manageDisplay(&tasks);	
	return 0;
}
