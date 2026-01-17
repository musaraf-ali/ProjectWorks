#include <stdio.h>

void displayWeeksName(void){
	char weeks[7][4] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
	printf("\n");
	for(int i=0; i<7; i++)
		printf("%s\t",weeks[i]);
	printf("\n");
}

void displayMonth(int space, int endDate, char nameMonth[]){
	printf("Month: %s of the year 2026\n",nameMonth);
	displayWeeksName();
	for(int i=-1*space, count = 1; i<=endDate; i++, count++){
		if(i>0)
			printf("%d\t",i);
		else
			printf("\t");
		if(count%7==0)
			printf("\n");
	}
	printf("\n");
}

int main(void){
	printf("Enter the numerical value for the month :");
	int month;
	scanf("%d",&month);
	switch(month){
		case 1: displayMonth(3,31,"January");break;
		case 2: displayMonth(-1,28,"February");break;
		case 3: displayMonth(-1,31,"March");break;
		case 4: displayMonth(2,30,"April");break;
		case 5: displayMonth(4,31,"May");break;
		case 6: displayMonth(0,30,"June");break;
		case 7: displayMonth(2,31,"July");break;
		case 8: displayMonth(5,31,"August");break;
		case 9: displayMonth(1,30,"September");break;
		case 10: displayMonth(3,31,"October");break;
		case 11: displayMonth(-1,30,"November");break;
		case 12: displayMonth(1,31,"December");break;
		default : printf("Invalid Input, should in the range (1-12)\n");
	}
	return 0;
}
