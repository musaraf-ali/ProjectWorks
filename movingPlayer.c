#include <stdio.h>
#include <stdlib.h>

typedef struct {
	short xCoordinate;
	short yCoordinate;
} Player;

void displayGrid(Player *player){
	for(int i = -10; i<=10; i++){
		for(int j = -10; j<=10; j++)
			if(player->xCoordinate == j && player->yCoordinate == i)
				printf("*");
			else 
				printf("-");
		printf("\n");
	}
}

void takeMovementInput(Player *player){
	char input = ' ';
	while(input != 'q'){
		system("clear");
		displayGrid(player);
		system("/bin/stty raw"); //(Searched Online!!) Don't know how it actually works!!
		input = getchar(); //Because of the previous statement I don't need to press Enter Key.
		system("/bin/stty cooked"); //(Searched Online!!) to return to normal settings.
		if(input == 'w'){
			if (player->yCoordinate>-10)
				player->yCoordinate--;
		} else if(input == 's'){
			if(player->yCoordinate<10)
				player->yCoordinate++;
		} else if(input == 'a'){
			if(player->xCoordinate>-10)
				player->xCoordinate--;
		} else if(input == 'd'){
			if(player->xCoordinate<10)
				player->xCoordinate++;
		}
	}
	printf("\n");
}

int main(void){
	Player player = {0,0};
	takeMovementInput(&player);
	return 0;
}
