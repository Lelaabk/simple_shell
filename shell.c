#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 100
#define MAX_ARG 10
int execute_command(char *cmd);
void signize_command(char *cmd, char **arg);

/**
 * signize_command - introduced to signize command into indv arg
 * @cmd: command to execute
 * @arg: command argument
 */
void signize_command(char *cmd; char **arg)
{
	int arg_i = 0;
	char *sign;

	sign = strtok(cmd, " ");

	while (sign != NULL && arg_i < MAX_ARG - 1)
	{
		arg[arg_i++] = sign;
		sign = strtok(NULL, " ");
	}
	arg[arg_i] = NULL;
}
/**
 * execute_command - introduces to handle execution of cmd
 * @cmd: command to execute
 *
 * Return: returns statut of cmd execution
 */
int execute_command(char *cmd)
{
	char *arg[MAX_ARG];
	int status;

	signize_command(cmd, arg);

	/*Create new process*/
	pid_t pidt = fork();

	if (pidt == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pidt == 0)
	{
		/*Child process*/
		execvp(arg[0], arg);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		/*Parent process*/
		waitpid(pidt, &status, 0);
	}
	return (status);
}

int main(void)
{
	char cmd[MAX_CMD_LEN];

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		/* Remove trailing new line.*/
		cmd[strcspn(cmd, "\n")] = '\0';
		if (execute_command(cmd) == -1)
			printf("%s: No such file or directory\n", cmd);
	}
	return (0);
}
