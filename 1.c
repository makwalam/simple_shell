#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
	printf("#cisfun$ ");
	fflush(stdout);
}

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		pid_t child_pid = fork();

		if (child_pid < 0)
		{
			perror("fork");
		}
		else if (child_pid == 0)
		{
			if (execlp(command, command, NULL) == -1)
			{
				perror("execlp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;
			waitpid(child_pid, &status, 0);

			if (WIFEXITED(status))
			{
				if (WEXITSTATUS(status) != 0)
				{
					printf("Command returned non-zero exit status\n");
				}
			}
			else
			{
				printf("Command terminated abnormally\n");
			}
		}
	}

	return 0;
}

