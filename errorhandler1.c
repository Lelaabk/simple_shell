#include "main.h"

/**
	* errhandler - print error msg.
	* @location: input location.
	* @cmd: input command.
	* Return: none.
*/

void errhandler(char *cmd, char *location)
{
_puts(location);
_puts(": 1: ");
_puts(cmd);
_puts(": not found");
_puts("\n");
/*_free(location);*/
}
