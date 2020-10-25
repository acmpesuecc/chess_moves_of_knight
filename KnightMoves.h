/*			KnightMoves.h			*/

/*Structure Position defines the position of the knight on the chessboard*/
typedef struct Position
{
	int num_pos;		//Position given by the user converted into integer form
	int num_of_knight_next; //Number of next knight positions
	int knight_next[8]; //Integer array consisting of next knight moves
} Position;

/*Struct to define the hash table*/
typedef struct Hash
{
	int arr_strings[80][8]; //Hash table with hash index as the position. 
	int inserted[80]; //To indicate whether the position has been inserted. Value is number of next positions.
}Hash;

//Utility functions
int checkPos(char,int);			//To check for valid input. And convert lowercase to uppercase for operations
Position *createPos(char,int);		//Initialise position elements
Hash *createHash(void);			//Initialise hash table attributes
Position *givePos(Position *);		//Give next knight moves
int hashIndex(Position *);		//Give hash index 
void hashInsert(Position *,Hash *);	//Insert into hash table
int ispresent(Position *,Hash *);	//Check if position has been stored in hash table
void printPos(Hash *,Position *);	//Print positions on the console
void userinput(char,int,Hash *);	//Driver function
