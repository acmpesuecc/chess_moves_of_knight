/*			KnightMain.c			*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "KnightMoves.h"

int main()
{
	Hash *table=createHash();

	printf("The position in a chess board is given as A1,A2,A3...B1,B2,B3...H6,H7,H8 where the alphabet represents the row number and the number represents the column number.\nThe values returned on entering the position when prompted is the next possible positions that a knight can move on a chess board.\n");

	while(1)
	{
		char x[10];
		printf("\n");
		printf("Enter position on chess board. Enter 0 to exit:");
		// gets(x);
		scanf("%s", x);
		if(*x=='0')
			break;
		else if(strlen(x)!=2)
		{
			printf("Invalid input\n");
			continue;
		}
		int y = (int)(x[1])-48;
		userinput(x[0],y,table);
		fflush(stdin);
	}

	free(table);

	return 0;
}
