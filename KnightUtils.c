/*			KnightUtils.c			*/

#include <stdio.h>
#include <stdlib.h>
#include "KnightMoves.h"

//Check for valid user input
int checkPos(char x,int y)
{
	if(x>64 && y>0 && x<73 && y<9)
		return 1;
	else
		return 0;
}

//Create position element
Position *createPos(char x,int y)
{
	Position *pos=(Position *)malloc(sizeof(Position));
	if(x>=97 && x<=123)
	{
		x=x-32;
	}
	if(checkPos(x,y))
		pos->num_pos=(x-65)*10+(y-1);
	else
		return NULL;
	pos->num_of_knight_next=0;
	int i;
	for(i=0;i<8;i++)
		pos->knight_next[i]=0;
	return pos;
}

//To create hash element
Hash *createHash()
{
	Hash *table=(Hash *)malloc(sizeof(Hash));
	int i,j;
	for(i=0;i<80;i++)
	{
		table->inserted[i]=0;
		for(j=0;j<8;j++)
			table->arr_strings[i][j]=0;
	}
	return table;
}

//Positions of knight in a chess board
Position *givePos(Position *pos)
{
	//These are the possible moves in one direction
	int Y[8] = { -1, 1, -2, 2, -2, 2, -1, 1 }; 
    	int X[8] = { -2, -2, -1, -1, 1, 1, 2, 2 }; 
	int i,x=pos->num_pos/10,y=pos->num_pos%10;
	for(i=0;i<8;i++)
	{
		//printf("(%d,%d)\n",x+X[i],y+Y[i]);
		if(x+X[i]>7 || y+Y[i]>7 || x+X[i]<0 || y+Y[i]<0);
		else
		{
			pos->knight_next[pos->num_of_knight_next]=(x+X[i])*10+(y+Y[i]);
			pos->num_of_knight_next++;
		}	
	}
	return pos;
}

//To get hash index
int hashindex(Position *pos)
{
	return pos->num_pos;	
}

//Insert into hashtable
void hashInsert(Position *pos, Hash *table)
{
	int i;
	for(i=0;i<pos->num_of_knight_next;i++)
		table->arr_strings[hashindex(pos)][i]=pos->knight_next[i];
	table->inserted[hashindex(pos)]=pos->num_of_knight_next;
	//printf("Inserted into hash table.\n");
}

//To check if the position the user asks is present in the hash table
int ispresent(Position *pos,Hash *table)
{
	if(table->inserted[pos->num_pos])
		return 1;
	else
		return 0;
}

//Print output
void printPos(Hash *table, Position *pos)
{
	int i,j,y;
	char x;
	printf("Valid positions are:\n");
	for(i=0;i<table->inserted[hashindex(pos)];i++)
	{
		x=(table->arr_strings[hashindex(pos)][i]/10)+65;
		y=(table->arr_strings[hashindex(pos)][i]%10)+1;
		printf("\t%c%d\n",x,y);
	}
	//printf("Values given from hash table.\n");
}

//To deal with user input
void userinput(char x,int y,Hash *table)
{
	Position *pos=createPos(x,y);
	if(pos==NULL)
	{
		printf("Invalid input\n");
		return;
	}
	else if(!ispresent(pos,table))
	{
		pos=givePos(pos);
		hashInsert(pos,table);	
	}
	printPos(table,pos);
	free(pos);
}
