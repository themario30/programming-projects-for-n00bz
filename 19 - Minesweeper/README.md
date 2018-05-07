# Challenge 19 : Minesweeper
*MineSweeper* is the Game where you are tasked to find all the mines in a specific square grid. This is found by using the proximity numbers, which gives you an indication on how many mines are adjacent to that tile. Getting a number which gives you a zero is actually beneficial, as it explodes and shows you more proximity numbers.

## What's the catch?
I'm going to have to write it in ``C`` *Pure*, **unadulterated**, __***C***__.

## How will it work? How did you do it?
    1. One of the first things I did was to make sure I made an array of ``'-'``, to represent an empty grid. 
   
    2. After the matrix print has been done, I grabbed the rand function from ``stdlib.h`` to perform the randomness. I didn't use ``srand(time(NULL)))`` as it would make different results, and if I did something static, it should affect them all. Basically, dealing with the same field of mines to do test cases.
    
    3. After the mines have been placed, I had to place down the numbers showing how many bombs are next to it. This is where the code becomes ~~***BEAUTIFUL***~~ gross and unreadible. It had to check it's neighbor. It had to not only check it's neighbor up/down/left/right, but so it's corners. So I made two loops (cause we're dealing with a matrix here), and looped through each index to check each neighbor to see if there were any bombs.
    
    4. After that was done, I generated two arrays. One shows the current view of the player, and the other shows all the proximity numbers, as well as the locations of the mines. After that, I've implemented a ``cursor()`` function which adds a small cursor to show where the player is currently at.
    
    5. Movement. I had to go and place movement so that the cursor could move. Possibly the Easiest Implementation of the Program
    
    6. Now, here comes the ~~***BEAUTIFUL***~~ *difficult* part of the code. If the player checks the tile and gets a number, it returns a number. If it's a bomb, then it dies. However, what happens when a player steps on a proximity number that is zero? If this was C++, then I would've used a *Queue* object, and use that to queue as many 0's as I can to reveal the map as much as I can. However, this is *Pure*, **unadulterated**, __***C***__.
    
    6.5 I created a struct to create a structure which keeps track of every 0's it comes in contact with. In addition, I've also created an functions which looks through every strucutre in an array to see if that's the same one. I'm using brute force here, but since it's a small array of 100, it shouldn't matter as much.
    
    6.75 I created a function which loops through every struct in an array to reveal the neighbor. It also checks to see if the neighbor was also a 0's. This is where the genius part of the code comes in. When it finds a 0's, it first check to see if it exist in the Array, and if it doesn't, places that point into an array. I have a seperate index variable keeping track of the tail of the array. I've abritarily placed the array size to 100, but I figured that should be enough space. (__inb4 someone finds a bug with the code__)
    
    7. Added a main menu, and that's about it.
    
## Conclusion and After-Thoughts
When my friend told me to write this code in *Pure*, **unadulterated**, __***C***__, I thought that it would be slightly annoying to write it up without using objects, etc. I sort of chickened-out and used structs, but hey, if there a rocket launcher in the game, it's part of the game. Developing the ``PROXIMITY MINE`` function was probably the most annoying, as I had to check every detail to see that it didn't have any syntax or human errors. I can probably highly optimize this script, seeing how 'crude and primitive' it all is.

It was a fun challenge to do. I am liking this coding challenge and the various spins me and my friends put on there. Now that I am do these challenges like that, maybe the next challenge shall be difficult. Before I sign off though, I shall show you dreaded function which I had to design, as well as it's other function prototypes.

```c

struct Point
{
	int x;
	int y;
};

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

```
###May 7th, 2018


