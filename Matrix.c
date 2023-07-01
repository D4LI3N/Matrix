#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 


/*###############################################################################*\
  #   ASSIGNMENT:  Final Project - Matrix Operations/Transformations            #
  #    PROFESSOR:  Benedict Redson                                              #
  #     DUE DATE:  25.12.2019                                                   #
  #                                                                             # 
  #       AUTHOR:  Danijel Petrovic                                             #
  #        EMAIL:  danielthe@cyberdude.com                                      #
  #         DATE:  24.12.2019                                                   #
  # INDEX NUMBER:  2019/230364                                                  #
  #                                                                             #
  #  DESCRIPTION: Simple program that demonstrates couple of different          #
  #               operations and transformations with matrices.                 #
  #  NOTE:        Program is initially designed as an interpreter.              #
\*###############################################################################*/


/* ++++++++++ GLOBAL VARIABLES ++++++++++ */
const char menuBanner[] = "\n\
                                 Final Project     \n\
Student: Daniel Petrovich                            Professor: Benedict Redson\n\
\n\
\n\
		Wake up Neo...The\n\
 		\033[92m /$$      /$$             /$$               /$$          		\n\
		| $$$    /$$$            | $$              |__/          		\n\
		| $$$$  /$$$$  /$$$$$$  /$$$$$$    /$$$$$$  /$$ /$$   /$$		\n\
		| $$ $$/$$ $$ |____  $$|_  $$_/   /$$__  $$| $$|  $$ /$$/		\n\
		| $$  $$$| $$  /$$$$$$$  | $$    | $$  \\__/| $$ \\  $$$$/ 		\n\
		| $$\\  $ | $$ /$$__  $$  | $$ /$$| $$      | $$   $$  $$ 		\n\
		| $$ \\/  | $$|  $$$$$$$  |  $$$$/| $$      | $$ /$$/\\  $$		\n\
		|__/     |__/ \\_______/   \\___/  |__/      |__/|__/  \\__/\033[0m	\n\
		                                               has You...\n\
\n\
Matrix Operations:		\n\
		0 = Exit				4 = Multiplication	\n\
		1 = Addition				5 = Transposition	\n\
		2 = Substraction			6 = Zig-zag			\n\
		3 = Scalar Multiplication		7 = Even Neighbor	\n\
\n\
Choice (0 default): ";
/* ---------- GLOBAL VARIABLES ---------- */


/* ++++++++++ FUNCTION PROTOTYPES ++++++++++ */
//User_input-related functions
char menuScreen();
void userInput(int zeroFlag);
void get_dimensions(int *x, int *y);
void get_k(int *k);
void get_column(int *c, int r);
int **get_matrix(int x,int y);
void print_matrix(int **matrix, int x, int y);

//Operational functions
int **matrix_addition(int **matrix1, int **matrix2, int r1,int c1,int r2,int c2);
int **matrix_substraction(int **matrix1, int **matrix2, int r1,int c1,int r2,int c2);
int **matrix_scalar(int **matrix1, int k, int r1,int c1);
int **matrix_multiplication(int **matrix1, int **matrix2, int r1,int c1,int r2,int c2);
void **matrix_transposition(int **matrix1, int r1, int c1);
void **matrix_zigzag(int **matrix1,int r1, int c1);
void **matrix_eveN(int **matrix1,int r1, int c1);

//Neighbor functions
int elementHasLeftNeighbour(int j);
int elementHasUpperNeighbour(int i);
int elementHasRightNeighbour(int j, int numOfColumns);
int elementHasBottomHeighbour(int i, int numOfRows);
int elementHasUpperLeftNeighbour(int i, int j);
int elemenHasBottomLeftNeighbour(int i, int j, int numOfRows);
int elemenHasUpperRightNeighbour(int i, int j, int numOfColumns);
int elementHasBottomRightNeighbour(int i, int j, int m1NumOfRows, int m1NumOfColumns);
int getLeftNeihgbour(int **matrix, int i, int j);
int getUpperNeihgbour(int **matrix, int i, int j);
int getRightNeighbour(int **matrix, int i, int j);
int getBottomNeighbour(int **matrix, int i, int j);
int getUpperLeftNeighbour(int **matrix, int i, int j);
int getBottomLeftNeighbour(int **matrix, int i, int j);
int getUpperRightNeighbour(int **matrix, int i, int j);
int getBottomRightNeighbour(int **matrix, int i, int j);
int sumOfIntBits(int value);
/* ---------- FUNCTION PROTOTYPES ---------- */


/* ++++++++++ MAIN FUNCTION ++++++++++ */
int main() {
	int r1=0, c1=0, r2=0, c2=0, k=0; //dimensions
	int **matrix1, **matrix2, **matrix3; //matrices
	int exitFlag = 0;
	char choice = '0';

	while(!exitFlag){
		switch(menuScreen()){
			case '0':
				exitFlag++;
				break;
			case '1':
				get_dimensions(&r1,&c1);
				printf("\nEnter First matrix:\n");
				matrix1 = get_matrix(r1,c1);
				printf("\nEnter second matrix:\n");
				matrix2 = get_matrix(r1,c1);
				matrix3 = matrix_addition(matrix1,matrix2,r1,c1,r1,c1);
				print_matrix(matrix3,r1,c1);
				break;
			case '2':
				get_dimensions(&r1,&c1);
				printf("\nEnter First matrix:\n");
				matrix1 = get_matrix(r1,c1);
				printf("\nEnter second matrix:\n");
				matrix2 = get_matrix(r1,c1);
				matrix3 = matrix_substraction(matrix1,matrix2,r1,c1,r1,c1);
				print_matrix(matrix3,r1,c1);
				break;
			case '3':
				get_k(&k);
				get_dimensions(&r1,&c1);
				printf("\nEnter matrix:\n");
				matrix1 = get_matrix(r1,c1);
				matrix3 = matrix_scalar(matrix1,k,r1,c1);
				print_matrix(matrix3,r1,c1);
				break;
			case '4':
				get_dimensions(&r1,&c1);
				printf("\nEnter first matrix:\n");
				matrix1 = get_matrix(r1,c1);
				get_column(&c2,c1);
				printf("\nEnter second matrix:\n");
				matrix2 = get_matrix(c1,c2);
				matrix3 = matrix_multiplication(matrix1,matrix2,r1,c1,c1,c2);
				print_matrix(matrix3,r1,c2);
				break;
			case '5':
				get_dimensions(&r1,&c1);
				printf("\nEnter matrix:\n");
				matrix1 = get_matrix(r1,c1);
				matrix_transposition(matrix1,r1,c1);
				//print_matrix(matrix3,r1,c1);
				break;
			case '6':
				get_dimensions(&r1,&c1);
				printf("\nEnter matrix:\n");
				matrix1 = get_matrix(r1,c1);
				matrix_zigzag(matrix1,r1,c1);
				break;
			case '7':
				get_dimensions(&r1,&c1);
				printf("\nEnter matrix:\n");
				matrix1 = get_matrix(r1,c1);
				matrix_eveN(matrix1,r1,c1);
				break;

			default:
				printf("\n<Invalid option!>");
				break;
		}
		printf("\n(Press any key to continue!)");
		getch();
	}
	printf("\nGoodbye!");
	return 0;
}
/* ---------- MAIN FUNCTION ---------- */


/* ++++++++++ FUNCTION DEFINITIONS ++++++++++ */
char menuScreen(){
	/*
	* Function:  Shows main banner, and lets user to choose next operation
	*---------------------------------------------------------------------
	* Arguments: None
	* Returns:   char
 	*/
	char choice;
	system("cls");
	printf(menuBanner);
	choice = getche();
	return choice;
}


void get_dimensions(int *x, int *y){
	/*
	* Function:  Stores x and y axis of matrix
	*-----------------------------------------
	* Arguments:
	*	-*x = Location of x axis
	*	-*y = Location of y axis
	* Returns:    None
 	*/
	*x = 0; *y = 0;
	printf("\nEnter matrix dimensions(<ROWS> <COLUMNS>): ");
	scanf(" %d %d",x,y);
	while(*x == 0 || *y == 0){
		printf("\n[!] Please enter two numbers (<ROWS> <COLUMNS>): ");
		scanf("%*s");
		scanf("%*s");
		scanf("%d %d",x,y);
	}
}

void get_k(int *k){
	/*
	* Function:  Stores multiplicator from user input
	*------------------------------------------------
	* Arguments:
	*	-*k = Location of multiplicator
	* Returns:    None
 	*/
	*k = 0;
	printf("\nEnter multiplicator k: ");
	scanf(" %d",k);
	while(*k == 0){
		printf("\n[!] Please enter one number (<k>): ");
		scanf("%*s");
		scanf("%d",k);
	}
}

void get_column(int *c, int r){
	/*
	* Function:  Returns column (only for matrix multiplication)
	*-----------------------------------------------------------
	* Arguments:
	*	-*c = Location used to store column
	*	-r  = First row (only to display with print)
	* Returns:    None
 	*/
	*c = 0;
	printf("\nEnter column for second matrix: ROW=%d COLUMN=",r);
	scanf(" %d",c);
	while(*c == 0){
		printf("\n[!] Please enter one number (<COLUMN>): ");
		scanf("%*s");
		scanf("%d",c);
	}
}

int **get_matrix(int x,int y){
	/*
	* Function:  Returns matrix elements from user input
	*------------------------------------------------------
	* Arguments:
	*	-x = Dimension of x axis
	*	-y = Dimension of y axis
	* Returns:    Matrix
 	*/
	int **matrix, a, b;
	matrix = malloc(sizeof(int*)*x);
	for(a=0;a<x;a++){
		matrix[a] = malloc(sizeof(int)*y);
		for(b=0;b<y;b++){
			scanf("%d", &matrix[a][b]);
		}
	}
	//printf("%p\n", matrix); //location
	return matrix;
}


void print_matrix(int **matrix, int x, int y){
	/*
	* Function:  Prints matrix on a screen
	*------------------------------------------------------
	* Arguments:
	*	-matrix = Matrix (double-pointer)
	*	-x = Dimension of x axis
	*	-y = Dimension of y axis
	* Returns:    None
 	*/
	int a, b;
	printf("\nResulted matrix:\n");
	for(a=0;a<x;a++){
		for(b=0;b<y;b++){
			printf(" %d", matrix[a][b]);
		}
	printf("\n");
	}
}

int **matrix_addition(int **matrix1, int **matrix2, int r1,int c1,int r2,int c2){//matrices must have same dimension
	/*
	* Function:  Adds two matrices and returns their result
	*------------------------------------------------------
	* Arguments:
	*	-matrix1 = First matrix (double-pointer)
	*	-matrix2 = Second matrix (double-pointer)
	*	-r1 = Row size of the first matrix
	*	-r2 = Row size of the second matrix
	*	-c1 = Column size of the first matrix
	*	-c2 = Column size of the second matrix
	* Returns:    Resulted matrix
 	*/
	if(r1 == r2 && c1 == c2){
		int **matrix3,i,j;
		for(i=0;i<r2;i++){
			for(j=0;j<c2;j++){
				matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
			}
		}
		return matrix3;
	}else{
		printf("\nERROR_SUM");
	}
}

int **matrix_substraction(int **matrix1, int **matrix2, int r1,int c1,int r2,int c2){//matrices must have same dimension
	/*
	* Function:  Substracts two matrices and returns their result
	*------------------------------------------------------------
	* Arguments:
	*	-matrix1 = First matrix (double-pointer)
	*	-matrix2 = Second matrix (double-pointer)
	*	-r1 = Row size of the first matrix
	*	-r2 = Row size of the second matrix
	*	-c1 = Column size of the first matrix
	*	-c2 = Column size of the second matrix
	* Returns:    Resulted matrix
 	*/
	if(r1 == r2 && c1 == c2){
		int **matrix3,i,j;
		for(i=0;i<r2;i++){
			for(j=0;j<c2;j++){
				matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
			}
		}
		return matrix3;
	}else{
		printf("\nERROR_SUB");
	}
}

int **matrix_scalar(int **matrix1, int k, int r1,int c1){
	/*
	* Function:  Multiplies every matrix element with 'k', and returns resulted matrix
	*---------------------------------------------------------------------------------
	* Arguments:
	*	-matrix1 = First matrix (double-pointer)
	*	-r1 = Row size of the matrix
	*	-c1 = Column size of the matrix
	*	-k  = Multiplicator
	* Returns:    Resulted matrix
 	*/
	int **matrix3,i,j,**g;
	printf("\nOperation:");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			matrix3[i][j] = (int)k * (int)matrix1[i][j];
			printf("%d",matrix3[i][j]);
			//++i;--i;++j;--j;
		}
	}
	return matrix3;
}

int **matrix_multiplication(int **matrix1, int **matrix2, int r1,int c1,int r2,int c2){//c1=r2
	/*
	* Function:  Multiplicates 2 matrices, and returns their result
	*--------------------------------------------------------------
	* Arguments:
	*	-matrix1 = First matrix (double-pointer)
	*	-matrix2 = Second matrix (double-pointer)
	*	-r1 = Row size of the first matrix
	*	-r2 = Row size of the second matrix
	*	-c1 = Column size of the first matrix
	*	-c2 = Column size of the second matrix
	* Returns:    Resulted matrix
 	*/
	printf("%d %d\n",c1,r2);
	int **matrix3,i,j,k,sum=0;
	matrix3 = malloc(sizeof(int) * c1);
	for(i=0;i<r1;i++){
		matrix3[j] = malloc(sizeof(int) * r1);
		for(j=0;j<c2;j++){
			matrix3[i][j] = 0;
			for(k=0;k<c1;k++){
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return matrix3;
}

void **matrix_transposition(int **matrix, int r1, int c1){
	/*
	* Function:  Does transposition of matrix, and prints the result
	*---------------------------------------------------------------
	* Arguments:
	*	-matrix = First matrix (double-pointer)
	*	-r1 = Row size of the matrix
	*	-c1 = Column size of the matrix
	* Returns:    None
 	*/
	int **matrix3, c, d, transpose[10][10];
	int m = r1;
	int n = c1;
	
	for (c = 0; c < m; c++)
	for (d = 0; d < n; d++)
	  transpose[d][c] = matrix[c][d];
	
	printf("Transpose of the matrix:\n");
	
	for (c = 0; c < n; c++) {
	for (d = 0; d < m; d++)
	  printf("%d\t", transpose[c][d]);
	printf("\n");
	}
}

void **matrix_zigzag(int **matrix1,int r1, int c1){
	/*
	* Function:  Prints the matrix in zig-zag form
	*---------------------------------------------
	* Arguments:
	*	-matrix = First matrix (double-pointer)
	*	-r1 = Row size of the matrix
	*	-c1 = Column size of the matrix
	* Returns:    None
 	*/
	int i,j,flag=1;
	for(i=0;i<r1;i++){
		if(flag){
			for(j=0;j<c1;j++)
			printf("%d ", matrix1[i][j]);
			flag = 0;
		}else{
			for(int j=c1-1;j>=0;j--){
				printf("%d ",matrix1[i][j]);
				flag = 1;
			}
		
		}
	}
}

void **matrix_eveN(int **matrix1,int r1, int c1){
	/*
	* Function:  Prints matrix elements whose neighbors in bit representation are even
	*---------------------------------------------------------------------------------
	* Arguments:
	*	-matrix = First matrix (double-pointer)
	*	-r1 = Row size of the matrix
	*	-c1 = Column size of the matrix
	* Returns:    None
 	*/
	int *cells;
	int sum = 0;
	int howManyCells = 0;
	int num = 0;
	int m1NumOfRows = r1;
	int m1NumOfColumns = c1;
	
	for (int i = 0; i < m1NumOfRows; ++i)
	{
	    for (int j = 0; j < m1NumOfColumns; ++j)
	    {
	        if (elementHasLeftNeighbour(j)) {
	            num = getLeftNeihgbour(matrix1, i, j);
	            sum += sumOfIntBits(num);
	        }
	
	        if (elementHasUpperNeighbour(i)) {
	            num = getUpperNeihgbour(matrix1, i, j);
	            sum += sumOfIntBits(num);
	        }
	
	        if (elementHasRightNeighbour(j, m1NumOfColumns)) {
	            num = getRightNeighbour(matrix1, i, j);
	            sum += sumOfIntBits(num);
	        }
	
	        if (elementHasBottomHeighbour(i, m1NumOfRows)) {
	            num = getBottomNeighbour(matrix1, i, j);
	            sum += sumOfIntBits(num);
	        }
	
	        if (elementHasUpperLeftNeighbour(i, j)) {
	            num = getUpperLeftNeighbour(matrix1, i, j);
	            sum += sumOfIntBits(num);
	        }
	
	        if (elemenHasBottomLeftNeighbour(i, j, m1NumOfRows)) {
	            num = getBottomLeftNeighbour(matrix1, i, j);
	            sum += sumOfIntBits(num);
	        }
	
	        if (elemenHasUpperRightNeighbour(i, j, m1NumOfColumns)) {
	            num = getUpperRightNeighbour(matrix1, i, j);
	            sum += sumOfIntBits(num);
	        }
	
	        if (elementHasBottomRightNeighbour(i, j, m1NumOfRows, m1NumOfColumns)) {
	            num = getBottomRightNeighbour(matrix1, i, j);
	            sum += sumOfIntBits(num);
	        }
	        
	        
	        if (sum % 2 == 0) 
	        {
	            ++howManyCells;
	
	            if (howManyCells == 1) 
	            {
	                cells = (int*) malloc (1 * sizeof(int));
	                *cells = matrix1[i][j];
	            } 
	            else 
	            {
	                cells = (int*) realloc(cells, howManyCells *sizeof(int));
	                cells[howManyCells-1] = matrix1[i][j];
	            }
	        }
	    }
	}
	
	
	printf("Elements with even neighbors: ");
	for (int i = 0; i < howManyCells; ++i)
	{
	    printf("%d", cells[i]);
	    if(i < howManyCells-1) {
	        printf(", ");
	    }
	}
	
}

int sumOfIntBits(int value){
	/*
	* Function:  Sums ones in bit representation of argument value, and returns result
	*---------------------------------------------------------------------------------
	* Arguments: value = Number for operation
	* Returns:    Sum of bit representation of int (value)
 	*/
    int sum = 0;
    
    unsigned int c; // counter

     // define displayMask and left shift 31 bits
    unsigned int displayMask = 1 << 31;
    
     // loop through bits
     for ( c = 1; c <= 32; ++c ) 
     {
        sum += value & displayMask ? 1 : 0;
        value <<= 1; // shift value left by 1
     } // end if
     
     return sum;
}


//Neighbor functions
int elementHasLeftNeighbour(int j)
{
    return j > 0;
}
int elementHasUpperNeighbour(int i)
{
    return i > 0;
}
int elementHasRightNeighbour(int j, int numOfColumns)
{
    return j < (numOfColumns - 1);
}
int elementHasBottomHeighbour(int i, int numOfRows)
{
    return i < (numOfRows - 1);
}
int elementHasUpperLeftNeighbour(int i, int j)
{
    return (i > 0 && j > 0);
}
int elemenHasBottomLeftNeighbour(int i, int j, int numOfRows)
{
    return (j > 0) && (i < (numOfRows - 1));
}
int elemenHasUpperRightNeighbour(int i, int j, int numOfColumns)
{
    return (i > 0) && (j < (numOfColumns - 1));
}
int elementHasBottomRightNeighbour(int i, int j, int m1NumOfRows, int m1NumOfColumns)
{
    return (j < (m1NumOfColumns - 1)) && (i < (m1NumOfRows - 1));
}
// Get neighbour
int getLeftNeihgbour(int **matrix, int i, int j)
{
    return  matrix[i][j-1];
}
int getUpperNeihgbour(int **matrix, int i, int j)
{
    return matrix[i-1][j];
}
int getRightNeighbour(int **matrix, int i, int j)
{
    return matrix[i][j+1];
}
int getBottomNeighbour(int **matrix, int i, int j)
{
    return matrix[i+1][j];
}
int getUpperLeftNeighbour(int **matrix, int i, int j)
{
    return matrix[i-1][j-1];
}
int getBottomLeftNeighbour(int **matrix, int i, int j)
{
    return matrix[i+1][j-1];
}
int getUpperRightNeighbour(int **matrix, int i, int j)
{
    return matrix[i-1][j+1];
}
int getBottomRightNeighbour(int **matrix, int i, int j)
{
    return matrix[i+1][j+1];
}
/* ---------- FUNCTION DEFINITIONS ---------- */
