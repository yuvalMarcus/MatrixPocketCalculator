#include "mat.h"

/* This assigns real numbers to the selected matrix  */
int readMat(char commandInput[], char *cp, mat mats[], int matsLength)
{
        char *comma = " ,\t\n";
	float numbers[N*N] = {0};
	float number;
	int i, j, c, length, isNumber, commasValid, textAfter;

	parms temp_parm;

	i = j = 0;
	length = N * N;

	temp_parm = setMatrix(mats, matsLength, 1, commandInput, cp);

	if(temp_parm.first_parm == NULL)
		return 1;

	while((cp = strtok(NULL, comma)) != NULL && i < length) {

		isNumber = toNumber(cp, &number);

		if(!isNumber) {
			
			printf("Parameter not a real number \n\n");

			return 1;
		}

		numbers[i] = number;
		
		i++;
	}

	if(i == 0) {

		printf("Missing parameter \n\n");
		
		return 1;
	}

	commasValid = commasEqualsNumber(commandInput, i, TRUE);

	if(!commasValid)
		return 1;

	textAfter = commandTextAfter(cp);

	if(textAfter)
		return 1;

	i = 0;
	c = 0;

	while(i != N) {

		(*temp_parm.first_parm)[i][j] = numbers[c];
		
		j++;

		if(j == N) {

			j = 0;
			i++;
		}	
		
		c++;
	}

	return 1;
}

/* This performs a prints the matrix in a convenient way to read */
int printMat(char commandInput[], char *cp, mat mats[], int matsLength)
{
	int i, j, textAfter, commasValid;

	parms temp_parm;

	commasValid = commasEqualsNumber(commandInput, 0, TRUE);

	if(!commasValid)
		return 1;

	temp_parm = setMatrix(mats, matsLength, 1, commandInput, cp);

	if(temp_parm.first_parm == NULL)
		return 1;

	textAfter = commandTextAfter(cp);

	if(textAfter)
		return 1;

	for(i = 0; i < N; i++) {

		for(j = 0; j < N; j++) {

			printf(" %8.2f ", (*temp_parm.first_parm)[i][j]); 

		}

		printf("\n");

	}

	printf("\n");

	return 1;
}

/* This performs a connection of two matrix and stores the result in a selected matrix */
int addMat(char commandInput[], char *cp, mat mats[], int matsLength)
{
	int i, j, textAfter, commasValid;

	parms temp_parm;

	commasValid = commasEqualsNumber(commandInput, 2, TRUE);

	if(!commasValid)
		return 1;

	temp_parm = setMatrix(mats, matsLength, 3, commandInput, cp);

	if(temp_parm.first_parm == NULL || temp_parm.second_parm == NULL || temp_parm.result == NULL)
		return 1;

	textAfter = commandTextAfter(cp);

	if(textAfter)
		return 1;
	
	for(i = 0; i < N; i++) {

		for(j = 0; j < N; j++) {

			(*temp_parm.result)[i][j] = (*temp_parm.first_parm)[i][j] + (*temp_parm.second_parm)[i][j];

		}
	}

	return 1;

}

/* his performs a subtraction of two matrix and stores the result in a selected matrix */
int subMat(char commandInput[], char *cp, mat mats[], int matsLength)
{
	int i, j, textAfter, commasValid;

	parms temp_parm;

	commasValid = commasEqualsNumber(commandInput, 2, TRUE);

	if(!commasValid)
		return 1;

	temp_parm = setMatrix(mats, matsLength, 3, commandInput, cp);

	if(temp_parm.first_parm == NULL || temp_parm.second_parm == NULL || temp_parm.result == NULL)
		return 1;

	textAfter = commandTextAfter(cp);

	if(textAfter)
		return 1;

	for(i = 0; i < N; i++) {

		for(j = 0; j < N; j++) {

			(*temp_parm.result)[i][j] = (*temp_parm.first_parm)[i][j] - (*temp_parm.second_parm)[i][j];

		}
	}

	return 1;

}

/* This performs a multipliaction of two matrix and stores the result in a selected matrix */
int mulMat(char commandInput[], char *cp, mat mats[], int matsLength)
{
	int i, j, textAfter, commasValid;
	float colSum;

	parms temp_parm;

	commasValid = commasEqualsNumber(commandInput, 2, TRUE);

	if(!commasValid)
		return 1;

	temp_parm = setMatrix(mats, matsLength, 3, commandInput, cp);

	if(temp_parm.first_parm == NULL || temp_parm.second_parm == NULL || temp_parm.result == NULL)
		return 1;

	textAfter = commandTextAfter(cp);

	if(textAfter)
		return 1;	


	for(i = 0; i < N; i++) {

		colSum = 0;

		for(j = 0; j < N; j++) {

			colSum = colSum + (*temp_parm.second_parm)[j][i];
		}

		for(j = 0; j < N; j++) {

			(*temp_parm.result)[j][i] = colSum * (*temp_parm.first_parm)[j][i];

		}
	}

	return 1;
}

/* This performs a multipliaction of a matrix by an float number and stores the result in a selected matrix */
int mulScalar(char commandInput[], char *cp, mat mats[], int matsLength)
{
	char *comma = " ,\t\n";
	int i, j, textAfter, commasValid, isNumber;
	float scalar, number;
	matrix *temp;

	parms temp_parm;

	commasValid = commasEqualsNumber(commandInput, 2, TRUE);

	if(!commasValid)
		return 1;

	temp_parm = setMatrix(mats, matsLength, 1, commandInput, cp);

	if(temp_parm.first_parm == NULL)
		return 1;

	temp = temp_parm.first_parm;

	cp = strtok(NULL, comma);

	isNumber = toNumber(cp, &scalar);

	if(!isNumber) {
		printf("Parameter not a scalar \n");
		return 1;
	}

	temp_parm = setMatrix(mats, matsLength, 1, commandInput, cp);

	if(temp_parm.first_parm == NULL)
		return 1;

	textAfter = commandTextAfter(cp);

	if(textAfter)
		return 1;

	for(i = 0; i < N; i++) {

		for(j = 0; j < N; j++) {

			number = (*temp)[i][j] * scalar;

			if(number == 0)
				number = 0;

			(*temp_parm.first_parm)[i][j] = number;

		}
	}

	return 1;
}

/* This performs transpose the matrix and stores the result in a selected matrix */
int transMat(char commandInput[], char *cp, mat mats[], int matsLength)
{
	int i, j, textAfter, commasValid;

	parms temp_parm;

	matrix mat;

	commasValid = commasEqualsNumber(commandInput, 1, TRUE);

	if(!commasValid)
		return 1;

	temp_parm = setMatrix(mats, matsLength, 2, commandInput, cp);

	if(temp_parm.first_parm == NULL || temp_parm.second_parm == NULL)
		return 1;

	textAfter = commandTextAfter(cp);

	if(textAfter)
		return 1;

	for(i = 0; i < N; i++) {

		for(j = 0; j < N; j++) {

			mat[i][j] = (*temp_parm.first_parm)[j][i];

		}
	}

	for(i = 0; i < N; i++) {

		for(j = 0; j < N; j++) {

			(*temp_parm.second_parm)[i][j] = mat[i][j];

		}
	}

	return 1;

}

/* This performs stops the progrm */
int stop(char commandInput[], char *cp, mat mats[], int matsLength)
{
	char *comma = " \n\t";

	cp = strtok(NULL, comma);

	if(cp != NULL) {

		printf("Extraneous text after end of command \n\n");

		return 1;
	}

	return 0;
}


