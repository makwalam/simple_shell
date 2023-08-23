/**
 * struct kid - Represents information about a kid.
 * @name: The name of the kid.
 * @age: The age of the kid.
 * @hobby: The hobby of the kid.
 * @height: The height of the kid.
 */

#include <stdio.h>

struct kid {
	char *name;
	int age;
	char *hobby;
	float height;
};

/**
 * print_kid - Prints information about a kid.
 * @k: Pointer to the kid structure to be printed.
 */
void print_kid(const struct kid *k)
{
	if (k)
	{
		printf("Name: %s\n", k->name);
		printf("Age: %d\n", k->age);
		printf("Hobby: %s\n", k->hobby);
		printf("Height: %.2f\n", k->height);
	}
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	struct kid my_kid = {"Alice", 8, "Drawing", 1.30};

	print_kid(&my_kid);

	return (0);
}
