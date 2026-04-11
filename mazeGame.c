//Works for Linux Machines...

#include <stdio.h>
#include <stdlib.h>

#define BOX_LEN 10
#define BOX_HEI 10

typedef struct{
	int x,
	    y;
} Player;

char maze[BOX_HEI][BOX_LEN];

void fillWhiteSpaceInBoxes(){
	for(int i=0; i<BOX_HEI; i++)
		for(int j=0; j<BOX_LEN; j++)
			maze[i][j] = ' ';
}

void createMap(){
	for(int i=0; i<BOX_HEI; i++){
		if(i==1){
			maze[i][0] = '#';
			for(int j = 2; j<BOX_LEN; j++)
				maze[i][j] = '#';
		} else if(i==2){
			maze[i][0] = maze[i][3] = '#';
			for(int j = 7; j<BOX_LEN; j++)
				maze[i][j] = '#';
		} else if(i==3){
			maze[i][0] = maze[i][1] = maze[i][5] = '#';
			for(int j = 8; j<BOX_LEN; j++)
				maze[i][j] = '#';
		} else if(i==4){
			maze[i][9] = '#';
			for(int j = 0; j<=6; j++)
				maze[i][j] = '#';
		} else if(i==5){
			maze[i][0] = maze[i][6] = '#';
			for(int j = 8; j<BOX_LEN; j++)
				maze[i][j] = '#';
		} else if(i==6)
			maze[i][0] = maze[i][2] = maze[i][3] = maze[i][4] = maze[i][6] = maze[i][9] = '#';
		
		else if(i==7)
			maze[i][0] = maze[i][4] = maze[i][6] = maze[i][7] = maze[i][9] = '#';

		else if(i==8){
			maze[i][4] = maze[i][9] = '#';
			for(int j = 0; j<=2; j++)
				maze[i][j] = '#';
		} else if(i==9)
			for(int j = 5; j<BOX_LEN; j++)
				maze[i][j] = '#';
	}	
}

void displayMaze(){
	for(int i=0; i<BOX_HEI; i++){
		for(int j=0; j<BOX_LEN; j++)
			printf("[%c]",maze[i][j]);
		printf("\n");
	}
}

void movePlayer(Player *player, char movement){
	if(movement == 'w'){
		if(maze[player->y-1][player->x] != '#')
			player->y--;
	} else if(movement == 's'){
		if(maze[player->y+1][player->x] != '#' && player->y <9)
			player->y++;
	} else if(movement == 'a'){
		if(maze[player->y][player->x-1] != '#' && player->x >0)
			player->x--;
	} else if(movement == 'd')
		if(maze[player->y][player->x+1] != '#'  && player->x<9)
			player->x++;
}

void placePlayer(Player *player){
	maze[player->y][player->x] = '*';
}

void gameLoop(Player *player){
	int condition = 1;
	while(condition){
		fillWhiteSpaceInBoxes();
		createMap();
		placePlayer(player);
		system("clear");	
		printf("%20s\n","MAZE GAME");
		displayMaze();
		system("/bin/stty raw");
		char input = getchar();
		system("/bin/stty cooked");
		if(input == 'q'){
			printf("%23s\n","YOU LEFT THE GAME");
			condition = 0;
		}
		movePlayer(player,input);
		if(player->y == 0){
			printf("%20s\n","YOU WON!!!\n");
			condition = 0;
		}
	}
}

int main(void){
	Player player = {0,9};
	gameLoop(&player);
	return 0;
}
