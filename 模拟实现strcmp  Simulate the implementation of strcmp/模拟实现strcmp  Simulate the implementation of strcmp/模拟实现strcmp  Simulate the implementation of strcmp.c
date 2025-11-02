#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int my_strcmp(char arr1[], char arr2[])

{

	int i = 0;

	for (i; arr1[i] != '\0' || arr2[i] != '\0'; i++)

	{

		if (arr1[i] != arr2[i])

			return 0;

	}

	return 1;

}

int main()

{

	char arr1[100];

	char arr2[100];

	scanf("%s", &arr1);

	scanf("%s", &arr2);

	int result = my_strcmp(arr1, arr2);

	if (result)

		printf("yes");

	else

		printf("no");

	return 0;

}