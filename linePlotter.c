#include <stdio.h>

typedef struct{
	float slope;
	float yIntercept;
} Line;

void displayGrid(Line *line){
	for(int y=25; y>=-25; y--){
		for(int x=-50; x<=50; x++){
			float yValue = x*line->slope + line->yIntercept;
			if(yValue >= y-0.5 && yValue <= y+0.5)
				printf("*");
			else if(y == 0 || x == 0)
				printf("-");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("Equation of the line: y = %.3fx + %.3f\n",line->slope,line->yIntercept);
}

void takingData(Line *line){
	printf("Enter the value of the slope: ");
	scanf("%f",&line->slope);
	printf("Enter the value of y-intercept: ");
	scanf("%f",&line->yIntercept);
}
int main(void){
	Line line;
	takingData(&line);
	displayGrid(&line);
	return 0;
}
