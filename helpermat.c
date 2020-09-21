#include "mat.h"

/* The function translates a number in string to float number and returns whether or not it succeeds */
int toNumber(char s[], float *number)
{	
	int c, sign, offset;
	float n, posDecimal;
	char type;

	posDecimal = 10.0;

	type = 'b';

	if(s[0] == '-')
		sign = -1;
	
	if(sign == -1)
		offset = 1;
	else
		offset = 0;

	n = 0;

	for(c = offset; s[c] != '\0'; c++) {

		if(!isdigit(s[c]) && s[c] != '.') {		

			return 0;
		}

		if(s[c] == '.') {

			type = 'a';
		} else {
			
			if(type == 'b')
				n = n * 10 + ( s[c] - '0' );

			if(type == 'a') {
				n = n + ( (s[c] - '0') / posDecimal );
				posDecimal = posDecimal * 10;
			}	

		}
	}

	if(sign == -1)
		n = -n;

	*number = n;

	return 1;
}

/* The function assigns matrices to a temporary parms variable */
parms setMatrix(mat mats[], int matsLength, int count, char *s, char *cp) {

	char *comma = " ,\t\n";
	int i, amount = 0;

	parms temp_parm;

	temp_parm.first_parm = NULL;
	temp_parm.second_parm = NULL;
	temp_parm.result = NULL;

	if(cp == NULL)
		cp = strtok(s, comma);
	else
		cp = strtok(NULL, comma);

	if(cp == NULL) {

		printf("Missing matrix name \n\n");

		return temp_parm;
	}

	if(count == 0)
		return temp_parm;

	for(i = 0; i < matsLength && strcmp(cp, mats[i].name) != 0; i++) {}

	if(i < matsLength) {
			
		temp_parm.first_parm = mats[i].mat;

		amount++;
	}

	while(amount < count && (cp = strtok(NULL, comma)) != NULL) {

		for(i = 0; i < matsLength && strcmp(cp, mats[i].name) != 0; i++) {}

		if(i < matsLength) {

			if(temp_parm.second_parm == NULL)
				temp_parm.second_parm = mats[i].mat;
			else
				temp_parm.result = mats[i].mat;

			amount++;
		}

	}

	if(amount < count) {
		
		printf("Undefined matrix name \n\n");
	}

	return temp_parm;

}

/* The function copies of string */
void copyString(char target[], char source[])
{
	int i = 0;

	for(i = 0; source[i] != '\0'; i++) {

		target[i] = source[i];
	}

	target[i] = '\0';
}

/* The function performs a valid comma check in the full command */
int commasEqualsNumber(char s[], int amount, int showError)
{

	int i, length, count, isComma, FirstWord, moveToEndFirstWord, isNotFirstComma;

	if(s[0] == ',') {

		if(showError)
			printf("Commas not valid \n\n");

		return 0;
	}

	length = strlen(s);

	count = 0;
	FirstWord = FALSE;
	moveToEndFirstWord = FALSE;
	isComma = FALSE;
	isNotFirstComma = TRUE;

	for(i = 0; !moveToEndFirstWord && i < length; i++) {

		if(!FirstWord && s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {

			FirstWord = TRUE;
		}

		if(FirstWord && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')) {

			moveToEndFirstWord = TRUE;
		}
		
	}

	for(; i < length; i++) {

		if((isNotFirstComma && isComma) || (s[i] == ',' && isComma)) {

			if(showError)
				printf("Commas not valid \n\n");

			return 0;
		}

		if(s[i] == ',') {

			isComma = TRUE;

		} else if (s[i] != ',' && s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {

			isNotFirstComma = FALSE;
			isComma = FALSE;
		}

		if(s[i] == 44) {

			count++;
		}
	}

	if(amount > count) {
		
		if(showError)
			printf("Missing comma \n\n");
	
		return 0;
	}


	if(amount < count) {
		
		if(showError)
			printf("Multiple consecutive commas \n\n");
	
		return 0;
	}

	return 1;
}

/* This function checks for text at the end of the full command */
int commandTextAfter(char *cp)
{

	char *comma = " \t";
	int length;

	cp = strtok(NULL, comma);

	if(cp == NULL) {

		return 0;
	}

	length = strlen(cp);

	if(length <= 1) {

		return 0;
	}

	printf("Extraneous text after end of command \n\n");

	return 1;
}

