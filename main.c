#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>


#define EXIT_KEY 'Q'
#define INVALID_INPUT -1

int getValidatedFloat(float *fNum, float *sNum);
void clearInputBuffer();

int main() {

	float fNum = 0.0f;
	char op = '\0';
	float sNum = 0.0f;
	float output = 0.0f;
	bool isValidOperation = true;

	printf("\n*************** CALCULATOR ***************\n");

	while(1) {

		isValidOperation = true;

		// Step 1: Take operator input	
		printf("\nEnter operator (+, -, *, /) or press 'Q' to quit: ");

		if(scanf(" %c", &op) != 1) {
			printf("\nPlease enter a valid option!!\n");
			clearInputBuffer();
			continue;
		}

		op = toupper(op);

		if (op == EXIT_KEY) {
			printf("\nYou have successfully exited the program.\n");
			break;
		}

		// Step 2: Take two operands
		if (getValidatedFloat(&fNum, &sNum) == INVALID_INPUT){
			continue;
		}

		// Step 3: Perform operation
		switch(op) {
			case '+': output = fNum + sNum; break;
			case '-': output = fNum - sNum; break;
			case '*': output = fNum * sNum; break;
			case '/':
				if(sNum == 0) {
					printf("\nCannot divide by 0, Please enter a valid divisor\n");
					isValidOperation = false;
					break;
				}
				output = fNum / sNum;
				break;
			default:
				clearInputBuffer();
				printf("\nPlease enter a valid operator\n");
				isValidOperation = false;
				break;
		}
		if (isValidOperation) {
			printf("%.2f %c %.2f = %.2f\n", fNum, op,  sNum, output);
		}	
	}

	return 0;
}

int getValidatedFloat(float *fNum, float *sNum) {
	printf("\nPlease enter first number : ");

	if (scanf("%f", fNum) != 1){
		printf("\nPlease enter a valid number!!\n");
		clearInputBuffer();
		return INVALID_INPUT;
	}

	printf("\nPlease enter second number : ");

	if (scanf("%f", sNum) != 1){
		printf("\nPlease enter a valid number!!\n");
		clearInputBuffer();
		return INVALID_INPUT;
	}
	
	return 0;
}

void clearInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}