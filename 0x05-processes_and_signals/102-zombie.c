#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

/**
 * infinite_while - an infinite loop
 * Return: 0
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - Entry point
 *
 * Return: int
*/
int main(void)
{
	int i = 0, pid = 0;

	while (i < 5)
	{
		pid = fork();
		if (pid == -1)
			perror("an error occured");
		if (pid == 0)
			infinite_while();
		else if (pid != 0)
		{
			printf("%d\nZombie process created, PID:", getpid());
		}
		i++;
	}
	return (0);
}