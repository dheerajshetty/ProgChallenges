/**
PC 1.6.1 A C program for 3n+1 problem.
Have an array of size(j) to save the cycle counts.
Initialize the array with minus one.
Have a list to store the current trace - keep adding one to improve count memory.
Once a number is hit, its count is stored.
*/

#include<stdio.h>

//To store the list of the current trace.
typedef struct Node {
	int value;
	Node next;
} Node;

//To store the input records.
typedef struct Rec {
	int i;
	int j;
	Rec next;
} Rec;

void countMaxCycles(Rec input);
void readInputFromFile(Rec *userInput);
void writeToFile(Rec cyclesOutput, int maxCount);

int main() {

	//Head of the input record list.
	Rec head = NULL;

	//To store the current record member whose cycles is to be counted.
	Rec current = NULL;

	readInputFromFile(&head);
        current = head;

	while(NULL != current) {
		countMaxCyles(current);
		current = current.next;	
	}
}

void countMaxCycles(Rec input) {
	int currI = input.i;
	int currJ = input.j;
	int maxCylcesCount = 0;
	int currentTrace[currJ - currI + 1] = {-1};
	int currentInput = currI;
        int index = 0;
	int count = 0;

	while(currentInput <= currJ) {

		while(1 != currentInput) {
			//This is the 3n+1 algo step.
			//Even ? divide by two.
			//Odd ? Multiply by 3 and add 1.
			currentInput = ((currentInput % 2) == 0)?(currentInput/2):(3 * currentInput + 1);

			if(currentInput > currI && currentInput <= currJ) {
				if(currentTrace[currentInput-currI] != -1)
				{
					count += currentTrace[currentInput-currI];
					break;
				}
			}
			count += 1;
		}
		if (count > maxCyclesCount) {
			maxCyclesCount = count;
		}
		currentInput += 1;
	}
	writeToFile(input, maxCyclesCount);
}
