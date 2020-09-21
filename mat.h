
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 4
#define TRUE 1
#define FALSE 0
#define LENGTH_COMMAND 120
#define NUMBER_BEGINNING_MATRIX 0

typedef float matrix[N][N];

typedef struct {
	char *name;
	matrix *mat;
} mat;

typedef struct {
	char *name;
	int (*func)(char commandInput[], char *cp, mat mats[], int matsLength);
} command;

typedef struct tnode {
	matrix *first_parm;
	matrix *second_parm;
	matrix *result;
} parms;

/* Function Prototypes */

int toNumber(char s[], float *number);
parms setMatrix(mat mats[], int matsLength, int count, char *s, char *cp);
int commasEqualsNumber(char s[], int amount, int showError);
int commandTextAfter(char *cp);

void copyString(char target[], char source[]);

int printMat(char commandInput[], char *cp, mat mats[], int matsLength);
int addMat(char commandInput[], char *cp, mat mats[], int matsLength);
int readMat(char commandInput[], char *cp, mat mats[], int matsLength);
int subMat(char commandInput[], char *cp, mat mats[], int matsLength);
int mulMat(char commandInput[], char *cp, mat mats[], int matsLength);
int mulScalar(char commandInput[], char *cp, mat mats[], int matsLength);
int transMat(char commandInput[], char *cp, mat mats[], int matsLength);
int stop(char commandInput[], char *cp, mat mats[], int matsLength);


