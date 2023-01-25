#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 10
#define MAX_INT_SIZE 10
#define FUNC_COUNT 9
#define EXIT 0

// Add your recursive functions declarations here
bool isEven(int num, int dig);
int howManyPaths(int x, int y);
int biggestLowPower(int x, int num);
int partSum(int num);
void intToStr(int num, char s[]);
void fillMaxPrefixesArray(int numbers[], int n, int maxPrefixesArray[]);
void getMinToStart(int numbers[], int n);
void combineArrays(int sortedArr1[], int size1, int sortedArr2[], int size2);
int countSmaller(int arr[], int start, int end, int num);

// Testing functions
int readArray(int data[], int maxSize);
void printArray(int data[], int size);
void bubbleSort(int arr[], int size);
void swap(int arr[], int i, int j);
void checkQ1();
void checkQ2();
void checkQ3();
void checkQ4();
void checkQ5();
void checkQ6();
void checkQ7();
void checkQ8();
void checkQ9();

/*********** main - don't make any changes here !!! ***************************/
void main()
{
	int funcNum;
	bool exit = false;

	while (!exit)
	{
		printf("Enter the number of function you want to check (1-%d) or %d to exit the program: ", FUNC_COUNT, EXIT);
		scanf("%d", &funcNum);

		switch (funcNum)
		{
		case 1:
			checkQ1();
			break;
		case 2:
			checkQ2();
			break;
		case 3:
			checkQ3();
			break;
		case 4:
			checkQ4();
			break;
		case 5:
			checkQ5();
			break;
		case 6:
			checkQ6();
			break;
		case 7:
			checkQ7();
			break;
		case 8:
			checkQ8();
			break;
		case 9:
			checkQ9();
			break;
		case EXIT:
			exit = true;
			break;
		default:
			printf("Invalid choice.\n");
		}
		printf("\n");
	}

}

/***************** Testing functions - don't make any changes here!!! ***************/
void checkQ1()
{
	int num, dig;

	printf("Enter a positive integer: ");
	scanf("%d", &num);
	printf("Enter a digit: ");
	scanf("%d", &dig);
	if (isEven(num, dig))
	{
		printf("%d appears even number of times in %d\n", dig, num);
	}
	else
	{
		printf("%d appears odd number of times in %d\n", dig, num);
	}
}

void checkQ2()
{
	int x, y;

	printf("Enter two non-negative integers: ");
	scanf("%d%d", &x, &y);
	printf("There are %d paths from (0,0) to (%d,%d)\n", howManyPaths(x, y), x, y);
}

void checkQ3()
{
	int x, num;

	printf("Enter two positive integers: ");
	scanf("%d%d", &x, &num);
	printf("The biggest power of %d which is smaller than %d is %d\n", x, num, biggestLowPower(x, num));
}

void checkQ4()
{
	int num;

	printf("Enter a positive integer: ");
	scanf("%d", &num);
	printf("The partial sum of %d digits is %d\n", num, partSum(num));
}

void checkQ5()
{
	int num;
	char string[MAX_INT_SIZE + 1];

	printf("Enter a positive integer: ");
	scanf("%d", &num);
	intToStr(num, string);
	printf("The string representing the integer %d is %s\n", num, string);
}

void checkQ6()
{
	int numbers[SIZE];
	int maxPrefixes[SIZE];
	int size;

	size = readArray(numbers, SIZE);
	fillMaxPrefixesArray(numbers, size, maxPrefixes);
	printf("Max prefixes array: ");
	printArray(maxPrefixes, size);
}

void checkQ7()
{
	int numbers[SIZE];
	int size;

	size = readArray(numbers, SIZE);
	getMinToStart(numbers, size);
	printf("The minimal number is: %d\n", numbers[0]);

	// check if all other numbers are still inb array
	bubbleSort(numbers, size);
	printf("The sorted array: ");
	printArray(numbers, size);
}

void checkQ8()
{
	int arr1[SIZE], arr2[2 * SIZE];
	int size1, size2;

	size1 = readArray(arr1, SIZE);
	size2 = readArray(arr2, 2 * SIZE - size1);

	// sort arrays
	bubbleSort(arr1, size1);
	bubbleSort(arr2, size2);

	combineArrays(arr1, size1, arr2, size2);
	printf("The combined sorted array: ");
	printArray(arr2, size1 + size2);
}

void checkQ9()
{
	int numbers[SIZE];
	int size, num;

	// read numbers from user (assumption: numbers are different from each other)
	size = readArray(numbers, SIZE);
	bubbleSort(numbers, size);

	printf("Please enter an integer: ");
	scanf("%d", &num);

	printf("There are %d numbers in array that are smaller than %d\n", countSmaller(numbers, 0, size - 1, num), num);
}

// This function reads a series of integers from user into data array. 
// The function will first ask the user to enter the number of integers he wishes
// to enter to array. If number is bigger than maxSize, then only the first masSize
// numbers will be read.
// The fucntion returns the arrays logical size (number of elements inserted into array).
int readArray(int data[], int maxSize)
{
	int count;
	int i;	// number of elements inserted into array

	printf("How many numbers would you like to enter to array ? (no more than %d) ", maxSize);
	scanf("%d", &count);
	if (count > maxSize)
	{
		count = maxSize;
	}
	printf("Please enter %d integers: ", count);

	for (i = 0; i < count; i++)
	{
		scanf("%d", &data[i]);	// read current input number		
	}

	return count;
}

// This function prints the first size elements of data array (integers).
void printArray(int data[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
}

// This functions sorts arr in increasing order using bubble sort algorithm
void bubbleSort(int arr[], int size)
{
	int i, j;

	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
}

void swap(int arr[], int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

/******************************* Recursive functions **************************/
// Add recursive functions implementation here


//This function gets a natural number and a digit.
//Checks if the digit appears an even amount of times in the number.
bool isEven(int num, int dig) {
	int dig1, dig2;
	if (num < 10) {
		if (num == dig)
			return false;
		if (num != dig)
			return true;
	}
	dig1 = num % 10;
	num /= 10;
	dig2 = num % 10;
	num /= 10;
	if (dig1 == dig2 && dig == dig1)
		return isEven(num, dig);
	else {
		if (dig1 == dig) {
			num *= 10;
			num += dig1;
			return isEven(num, dig);
		}
		if (dig2 == dig) {
			num *= 10;
			num += dig2;
			return isEven(num, dig);
		}
		else {
			return isEven(num, dig);
		}
	}
}

//This function calculates an x,y net with a given starting point.
int howManyPaths(int x, int y) {
	int count = 0;
	if (x == 0 && y == 0) {
		return 1;
	}

	if (y > 0) {
		count += howManyPaths(x, y - 1);
	}

	if (x > 0) {
		count += howManyPaths(x - 1, y);
	}
	return count;
}

//This function gets parameters 'x' and 'num' and returns the maximal power of x.
//The power is <= num.
//x, num > 0, y >= 0, x >= 2.
int biggestLowPower(int x, int num) {
	if (x > num)
		return 1;
	return x * biggestLowPower(x, num / x);
}

//This function gets a parameter 'num' and retunrs the sum of num's digits, apart from the right digit.
//num > 0, if num is a 1 digit number, num = 0.
int partSum(int num) {
	int temp1, temp2;
	temp1 = num % 10;
	num /= 10;
	if (num == 0)
		return 0;
	temp2 = num % 10;
	num /= 10;
	num *= 10;
	num += temp1;
	return temp2 + partSum(num);
}

//This function gets a paramter 'num' and returns num as a char array.
//Array is large enough.
void intToStr(int num, char s[]) {
	int temp, size;
	temp = num % 10;
	if (num < 10) {
		s[0] = 48 + temp;
		s[1] = '\0';
		return;
	}
	num /= 10;
	intToStr(num, s);
	size = strlen(s);
	s[size] = 48 + temp;
	s[size + 1] = '\0';
}

//This unction gets an array and its size ('n').
//Fills array 'maxPrefixesArray' with the maximum value from the previuos element(s).
//n > 0, maxPrefixesArray is large enough.
void fillMaxPrefixesArray(int numbers[], int n, int maxPrefixesArray[]) {
	if (n == 1) {

		maxPrefixesArray[0] = numbers[0];
		return;
	}
	fillMaxPrefixesArray(numbers, n - 1, maxPrefixesArray);
	if (numbers[n - 1] > maxPrefixesArray[n - 2]) {
		maxPrefixesArray[n - 1] = numbers[n - 1];
	}
	else {
		maxPrefixesArray[n - 1] = maxPrefixesArray[n - 2];
	}
}

//This function gets an array and it's size ('n').
//Function reorders array so array[0] is the smallest number.
//n > 0.
void getMinToStart(int numbers[], int n) {
	int temp;
	if (n == 1) {
		return;
	}

	if (numbers[n - 1] < numbers[n - 2]) {
		temp = numbers[n - 1];
		numbers[n - 1] = numbers[n - 2];
		numbers[n - 2] = temp;
		getMinToStart(numbers, n - 1);
	}
	else {
		getMinToStart(numbers, n - 1);
	}
}

//This function gets two sorted arrays and their sizes.
//Returnes elements of both arrays as a single array.
//Sizes are >= 0, new array is large enough.
void combineArrays(int sortedArr1[], int size1, int sortedArr2[], int size2) {
	int i;
	if (size1 == 0) {
		return;
	}
	if (size2 == 0) {
		for (i = 0; i < size1; i++) {
			sortedArr2[i] = sortedArr1[i];
		}
		return;
	}

	if (sortedArr1[size1 - 1] > sortedArr2[size2 - 1]) {
		sortedArr2[size1 + size2 - 1] = sortedArr1[size1 - 1];
		combineArrays(sortedArr1, size1 - 1, sortedArr2, size2);
	}
	else {
		sortedArr2[size1 + size2 - 1] = sortedArr2[size2 - 1];
		combineArrays(sortedArr1, size1, sortedArr2, size2 - 1);
	}
}

//Function gets an array, parameters 'start', 'end', and 'num'.
//Returns number of elements between 'start and 'end' smaller than 'num'.
//All of array's parameters are different.
int countSmaller(int arr[], int start, int end, int num) {
	if (start == end) {
		if (arr[end] < num)
			return 1;
		else
			return 0;
	}
	if (end < start)
		return 0;
	if (arr[end] < num)
		return 1 + countSmaller(arr, start, end - 1, num);
	else
		return countSmaller(arr, start, end - 1, num);
}
