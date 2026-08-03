/*
 * Exercise 19 from Chapter 17 of King: Write a function that, when given a
 * string as its argument, searches the following array of structures for a
 * matching command name, then calls the function associated with that name.
 */

#include <string.h>

#define NCMDS 9

struct {
	char *cmd_name;
	void (*cmd_pointer) (void);
} file_cmd[] =
	{{"new",       new_cmd},
	 {"open",      open_cmd},
	 {"close",     close_cmd},
	 {"close all", close_all_cmd},
	 {"save",      save_cmd},
	 {"save as",   save_as_cmd},
	 {"save all",  save_all_cmd},
	 {"print",     print_cmd},
	 {"exit",      exit_cmd},
	};

void call_cmd(const char *cmd)
{
	int i;

	for (i = 0; i < NCMDS; i++)
		if (strcmp(file_cmd[i].cmd_name, cmd) == 0) {
			(*file_cmd[i].cmd_pointer)();
			return;
		}
}
