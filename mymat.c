#include "mat.h"

/* Main & Supporting Functions */
int main()
{

	/* List and place the calculator commands */

	command cmd[] = {
		{"read_mat", readMat},
		{"print_mat", printMat},
		{"add_mat", addMat},
		{"sub_mat", subMat},
		{"mul_mat", mulMat},
		{"mul_scalar", mulScalar},
		{"trans_mat", transMat},
		{"stop", stop}
	};

	/* List and reset zero the matrix */

	matrix MAT_A = {{NUMBER_BEGINNING_MATRIX}}, MAT_B = {{NUMBER_BEGINNING_MATRIX}}, MAT_C = {{NUMBER_BEGINNING_MATRIX}}, MAT_D = {{NUMBER_BEGINNING_MATRIX}}, MAT_E = {{NUMBER_BEGINNING_MATRIX}}, MAT_F = {{NUMBER_BEGINNING_MATRIX}};

	mat mats[6];

        char *comma = " \t\n";
	char *cp;

	char commandInput[LENGTH_COMMAND], command[LENGTH_COMMAND];

	int j, loopRun, cpLength, cmdLength = sizeof(cmd) / sizeof(cmd[0]), matsLength;

	/* List and place the matrix in calculator */

	mats[0].name = "MAT_A";
	mats[0].mat = &MAT_A;
	mats[1].name = "MAT_B";
	mats[1].mat = &MAT_B;
	mats[2].name = "MAT_C";
	mats[2].mat = &MAT_C;
	mats[3].name = "MAT_D";
	mats[3].mat = &MAT_D;
	mats[4].name = "MAT_E";
	mats[4].mat = &MAT_E;
	mats[5].name = "MAT_F";
	mats[5].mat = &MAT_F;

	matsLength = sizeof(mats) / sizeof(mats[0]);

	loopRun = 1;

	printf("\n\033[1m\033[34mMatrix calculator \033[0m\n\n");

	printf("Performs computational operations on matrices \n\n");

	printf("\n\033[1m\033[37mExisting matrices in the calculator : \033[0m\n");
	printf("MAT_A, MAT_B, MAT_C, MAT_D, MAT_E, MAT_F \n");
	printf("* All matrices are %d X %d \n", N, N);
	printf("* All matrices contain float numbers values \n");
	printf("* All matrix values are reset to %d at the beginning \n", NUMBER_BEGINNING_MATRIX);

	printf("\n\033[1m\033[37mOperations in matrix calculator : \033[0m\n");
	printf("read_mat, print_mat, add_mat, sub_mat, mul_mat, mul_scalar, trans_mat, stop \n");

	printf("\n\033[1m\033[32mread_mat : \033[0m\n");
	printf("This assigns real numbers to the selected matrix \n");

	printf("\n\033[1m\033[32mprint_mat : \033[0m\n");
	printf("This performs a prints the matrix in a convenient way to read \n");

	printf("\n\033[1m\033[32madd_mat : \033[0m\n");
	printf("This performs a connection of two matrix and stores the result in a selected matrix \n");

	printf("\n\033[1m\033[32msub_mat : \033[0m\n");
	printf("This performs a subtraction of two matrix and stores the result in a selected matrix \n");

	printf("\n\033[1m\033[32mmul_mat : \033[0m\n");
	printf("This performs a multipliaction of two matrix and stores the result in a selected matrix \n");

	printf("\n\033[1m\033[32mmul_scalar : \033[0m\n");
	printf("This performs a multipliaction of a matrix by an float number and stores the result in a selected matrix \n");

	printf("\n\033[1m\033[32mtrans_mat : \033[0m\n");
	printf("This performs transpose the matrix and stores the result in a selected matrix \n");

	printf("\n\033[1m\033[32mstop : \033[0m\n");
	printf("This performs stops the progrm \n");

	printf("\n\033[1m\033[37mStructure of the program command : \033[0m\n");
	printf("[name of command] [list of matrix or variable] [list of variable] \n");	

	printf("\n\033[1m\033[36m[name of command] : \033[0m\n");
	printf("The name of the command \nfor example: add_mat | print_mat | mul_scaler \n");	

	printf("\n\033[1m\033[36m[list of matrix or variable] : \033[0m\n");
	printf("The list of the matrix or variable \nmin 1 matrix or variable, max 3 matrix or variable \nfor example: MAT_A | MAT_B, MAT_A, MAT_C | MAT_A, 4, MAT_F \n");

	printf("\n\033[1m\033[36m[list of variable] : \033[0m\n");
	printf("The list of the float number, if command request it, min 1 float number \nfor example: 1, 5, 5 | -4, 6.7, 3 \n");	

	printf("\n\033[1m\033[37mArrange full command line : \033[0m\n");
	printf("1) White characters (spaces or tabs) are allowed without any character or string restriction \n");
	printf("2) Each matrix or variable is separated by a single comma \n");
	printf("3) There should be no redundant text at the end of the full command line \n");

	printf("\n\033[1m\033[37mFull command line examples : \033[0m\n");
	printf("print_mat MAT_D\n");
	printf("add_mat MAT_A, MAT_B, MAT_C\n");
	printf("read_mat MAT_B, 2, 2, 2, 0, 2\n");
	printf("mul_scalar MAT_D, -3, MAT_E\n");

	printf("\n");

	while(loopRun) {

		printf("enter full commad : \n");

	  	if(fgets(command, LENGTH_COMMAND, stdin) != NULL)
		{
			copyString(commandInput, command);

			printf("The full command is : \n%s \n", commandInput);

			cp = strtok(command, comma);

			if(cp != NULL) {

				cpLength = strlen(cp);

				if(commasEqualsNumber(cp, 0, FALSE) && cp[cpLength-1] != ',') {

					for(j = 0; j < cmdLength && strcmp(cp, cmd[j].name) != 0; j++) {}

					if(j == cmdLength) {
						printf("Undefined commamd name \n\n");
					} else {
						loopRun = (*(cmd[j].func))(commandInput, cp, mats, matsLength);
					}

				} else {
			
					printf("Illegal comma \n\n");
				}

			}

		} else {

			printf("End of file \n");
		
			loopRun = 0;

		}

	}

	return 0;
}

