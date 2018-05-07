#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

int SIZE = 10;

struct Point
{
	int x;
	int y;
};


int main()
{
	int MainMenu();
	void playGame();
	
	if(MainMenu())
	{
		playGame();
	}
	
    return 0;
}

int MainMenu()
{
	/*This is the Main Menu of the Game! This should allow them to play the game and change the size!*/
	char input = 'n';
	int answer = 1;
	
	while(input == 'n')
	{
		printf("********************************************************************************\n");
		printf("*Welcome to Minesweeper! Enter the following numbers to choose your difficulty!*\n");
		printf("********************************************************************************\n");
		printf("*\t1. Easy (5x5)\t\t\t\t\t*\n");
		printf("*\t2. Low Medium (7x7)\t\t\t\t*\n");
		printf("*\t3. Medium (10x10)\t\t\t\t*\n");
		printf("*\t4. High Medium (12x12)\t\t\t\t*\n");
		printf("*\t5. Hard (15x15)\t\t\t\t\t*\n");
		printf("*\t6. Tedious (20x20)\t\t\t\t*\n");
		printf("*\t7. Bored on a Saturday Afternoon (30x30)\t*\n");
		printf("*\t\t\t\t\t\t\t*\n");
		printf("*\t\t\t\t\t\t\t*\n");
		printf("*\t\t\t\t\t\t\t*\n");
		printf("*\t0. Exit Program\t\t\t\t\t*\n");
		printf("*********************************************************\n");
		printf("->");
		scanf("%c",&input);
		
		if(input == '1')
			SIZE = 5;
		
		else if(input == '2')
			SIZE = 7;
			
		else if(input == '3')
			SIZE = 10;
		
		else if(input == '4')
			SIZE = 12;
			
		else if(input == '5')
			SIZE = 15;
		
		else if(input == '6')
			SIZE = 20;
			
		else if(input == '7')
			SIZE = 30;
			
		else if(input == '0')
			answer = 0;
		else
		{
			input = 'n';
			system("cls");
		}
	}
		
	return answer;
}


void playGame()
{
	void printMap(const char map[SIZE][SIZE]);
	void placeBombs(char map[SIZE][SIZE]);
	
	void initArray(char array[SIZE][SIZE], char c);
	
	void Cursor(char array[SIZE][SIZE], int x, int y);
	void PROXIMITYBOMB(char KnownMap[SIZE][SIZE], char MineMap[SIZE][SIZE], struct Point p);
	int input();
	
	char KnownMap[SIZE][SIZE];
	char ActualMap[SIZE][SIZE];
	
	int isGameDone = 0;
	
	int x = 0;
	int y = 0;
	int UserInput = 0;
	
	srand(time(NULL));
	
	initArray(KnownMap, '-');
	initArray(ActualMap, '-');
	placeBombs(ActualMap);
	
	while(isGameDone == 0)
	{
		printf("Pos(%i,%i)\n",x,y);
		//printMap(ActualMap);
		Cursor(KnownMap,x,y);
		printf("Enter 4/6 to go Left/Down\n");
		printf("Enter 8/2 to go Up/Down\n");
		printf("Enter 5 to check the tile!\n");
		printf("Press 0 to Mark the Tile\n");
		printf("->");
		UserInput = input();
		
		if(UserInput == 4)
		{
			if(x <= 0)
				;
			else
				x--;
		}
		if(UserInput == 6)
		{
			if(x >= SIZE - 1)
				;
			else
				x++;
		}
		if(UserInput == 8)
		{
			if(y <= 0)
				;
			else
				y--;
		}
		if(UserInput == 2)
		{
			if(y >= SIZE - 1)
				;
			else
				y++;
		}
		
		if(UserInput == 5)
		{
			if(ActualMap[x][y] == '*')
			{
				KnownMap[x][y] = '*';
				isGameDone = 1;
			}
			
			else if(ActualMap[x][y] == '0')
			{
				struct Point p;
				p.x = x;
				p.y = y;
				PROXIMITYBOMB(KnownMap,ActualMap,p);
			}
				KnownMap[x][y] = ActualMap[x][y];
			
		}
		
		system("cls");
	}
	printf("Game Over! You stepped on a mine!\n");
	Cursor(ActualMap,x,y);
	system("PAUSE");
	
}

int checkPoints(struct Point Array[100], struct Point cPoint)
{
	int i;
	struct Point iPoint;
	for(i = 0; i < 100; i++)
	{
		iPoint = Array[i];
		if(iPoint.x == cPoint.x)
			if(iPoint.y == cPoint.y)
				return 0;
	}
	
	return 1;
}

void initPointArray(struct Point Array[100])
{
	int i;
	struct Point Template;
	Template.x = -1;
	Template.y = -1;
	for(i = 0; i < 100; i++)
	{
		Array[i] = Template;
	}
}

void PROXIMITYBOMB(char KnownMap[SIZE][SIZE], char MineMap[SIZE][SIZE], struct Point p)
{
	void initPointArray(struct Point Array[100]);
	int checkPoints(struct Point Array[100], struct Point cPoint);
	
	
	struct Point points[100];
	initPointArray(points);
	int index = 0;
	points[0] = p;
	int i;
	
	for(i = 0; i < 100; i++)
	{
		struct Point current = points[i];
		struct Point checkPoint;
		if(current.x == -1 && current.y == -1)
			continue;
			
		//check to see if theres a bomb on the left
		if(current.x != 0 && MineMap[current.x - 1][current.y] == '0')
		{
			
			checkPoint.x = current.x - 1;
			checkPoint.y = current.y;
			if(checkPoints(points,checkPoint) == 1)
				points[++index] = checkPoint;
		}
		if (current.x != 0)
		{
			KnownMap[current.x - 1][current.y] = MineMap[current.x - 1][ current.y];
		}
		
		//check upper-left
		if(current.y != 0 && current.x != 0 && MineMap[current.x - 1][current.y - 1] == '0')
		{
			checkPoint.x = current.x - 1;
			checkPoint.y = current.y - 1;
			if(checkPoints(points,checkPoint) == 1)
				points[++index] = checkPoint;
		}
		if (current.y != 0 && current.x != 0)
		{
			KnownMap[current.x - 1][current.y - 1] = MineMap[current.x - 1][ current.y - 1];
		}
		//check up
		if(current.y != 0 && MineMap[current.x][current.y - 1] == '0')
		{
			checkPoint.x = current.x - 0;
			checkPoint.y = current.y - 1;
			if(checkPoints(points,checkPoint) == 1)
				points[++index] = checkPoint;
		}
		if (current.y != 0)
		{
			KnownMap[current.x - 0][current.y - 1] = MineMap[current.x - 0][ current.y - 1];
		}
		//check upper-right
		if(current.y != 0 && current.x != SIZE - 1 && MineMap[current.x + 1][current.y - 1] == '0')
		{
			checkPoint.x = current.x + 1;
			checkPoint.y = current.y - 1;
			if(checkPoints(points,checkPoint) == 1)
				points[++index] = checkPoint;
		}
		if (current.y != 0 && current.x != SIZE - 1)
		{
			KnownMap[current.x + 1][current.y - 1] = MineMap[current.x + 1][ current.y - 1];
		}
		//check right
		if(current.x != SIZE - 1&& MineMap[current.x + 1][current.y - 0] == '0')
		{
			checkPoint.x = current.x + 1;
			checkPoint.y = current.y - 0;
			if(checkPoints(points,checkPoint) == 1)
				points[++index] = checkPoint;
		}
		if (current.x != SIZE - 1)
		{
			KnownMap[current.x + 1][current.y - 0] = MineMap[current.x + 1][ current.y - 0];
		}
		//check bottom-right
		if(current.y != SIZE - 1 && current.x != SIZE - 1 && MineMap[current.x + 1][current.y + 1] == '0')
		{
			checkPoint.x = current.x + 1;
			checkPoint.y = current.y + 1;
			if(checkPoints(points,checkPoint) == 1)
				points[++index] = checkPoint;
		}
		if (current.y != SIZE - 1 && current.x != SIZE - 1)
		{
			KnownMap[current.x + 1][current.y + 1] = MineMap[current.x + 1][ current.y + 1];
		}
		//check down
		if(current.y != SIZE - 1 && MineMap[current.x + 0][current.y + 1] == '0')
		{
			checkPoint.x = current.x + 0;
			checkPoint.y = current.y + 1;
			if(checkPoints(points,checkPoint) == 1)
				points[++index] = checkPoint;
		}
		if (current.y != SIZE - 1)
		{
			KnownMap[current.x + 0][current.y + 1] = MineMap[current.x + 0][ current.y + 1];
		}
		//check bottom-left
		if(current.y != SIZE - 1 && current.x != 0 && MineMap[current.x - 1][current.y + 1] == '0')
		{
			checkPoint.x = current.x - 1;
			checkPoint.y = current.y + 1;
			if(checkPoints(points,checkPoint) == 1)
				points[++index] = checkPoint;
		}
		if (current.y != SIZE - 1 && current.x != 0)
		{
			KnownMap[current.x - 1][current.y + 1] = MineMap[current.x - 1][ current.y + 1];
		}
	}
}

int input()
{
	int i;
	scanf("%i",&i);
	
	return i;		
}

void Cursor(char array[SIZE][SIZE], int x, int y)
{
	int i, j;
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			if(j == x && i == y)
				printf(">%c<",array[j][i]);
			else
				printf(" %c ",array[j][i]);	
		}
		printf("\n");	
	}
}

void initArray(char array[SIZE][SIZE], char c)
{
	int i, j;
	
	for(i = 0; i < SIZE; i++)
		for(j = 0; j < SIZE; j++)
			array[j][i] = c;	
}

void placeBombs(char map[SIZE][SIZE])
{
	int i, j;
	int bombs = 0;
	const int MAXBOMBS = SIZE*SIZE / 5;
	
	while(bombs < MAXBOMBS)
	{
		
	for(i = 0; bombs < MAXBOMBS && i < SIZE; i++)
		for(j = 0; bombs < MAXBOMBS && j < SIZE; j++)
			{
				if(rand() % 100 < 5)
				{
					map[j][i] = '*';
					bombs++;
				}
			}
	}
	
	//adds the proximity of bombs
	for(i = 0;i < SIZE; i++)
		for(j = 0;j < SIZE; j++)
		{
			if(map[j][i] == '*')
				continue;
			int n = 0;
			
			//check to see if theres a bomb on the left
			if(j != 0 && map[j - 1][i] == '*')
			{
				n++;
			}
			//check upper-left
			if(i != 0 && j != 0 && map[j - 1][i - 1] == '*')
			{
				n++;
			}
			//check up
			if(i != 0 && map[j][i - 1] == '*')
			{
				n++;
			}
			//check upper-right
			if(i != 0 && j != SIZE - 1 && map[j + 1][i - 1] == '*')
			{
				n++;
			}
			//check right
			if(j != SIZE - 1&& map[j + 1][i - 0] == '*')
			{
				n++;
			}		
			//check bottom-right
			if(i != SIZE - 1 && j != SIZE - 1 && map[j + 1][i + 1] == '*')
			{
				n++;
			}
			//check down
			if(i != SIZE - 1 && map[j + 0][i + 1] == '*')
			{
				n++;
			}
			//check bottom-left
			if(i != SIZE - 1 && j != 0 && map[j - 1][i + 1] == '*')
			{
				n++;
			}
			
			map[j][i] = '0' + n;
			
		}
	
}

void printMap(const char map[SIZE][SIZE])
{
	int i,j;
	
	
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
			printf("%3c",map[j][i]);
		printf("\n");	
	}

}
