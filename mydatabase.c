#include "mydatabase.h"
#include <malloc.h>
#include <string.h>

MYDB *initmydb(const char *dbfile)
{
	MYDB *tdb = malloc(sizeof(MYDB));
	strcpy(tdb->dbfilename, dbfile);
	tdb->list = create_userlist();

	load_userlist(tdb->list, tdb->dbfilename);

	return tdb;
}
static void changestyle(char *argv[], char buf[100])
{
	buf++;
	while(*buf)
	{
		if(' '==*(buf-1) && ' '!=*buf)
		{
			*argv++ = buf;
			*(buf-1) = '\0';
		}

		buf++;
	}
}
int processmydb(MYDB *mydb, char *cmdline)
{
	char *argv[100] = {NULL};
	changestyle(argv, cmdline+6);
	if(0 == strncmp("insert", cmdline, 6) )//insert
	{
		add_userlist(mydb->list, argv[0], argv[1]);
		return 0;
	}
	else
	if(0 == strncmp("delete", cmdline, 6) )//delete
	{
		del_userlist(mydb->list, argv[0], argv[1]);
		return 0;
	}
	else
	if(0 == strncmp("update", cmdline, 6) )//update
	{
		return update_userlist(mydb->list, argv[0], argv[1], argv[2]);
	}
	else
	if(0 == strncmp("select", cmdline, 6) )//update
		return select_userlist(mydb->list, argv[0], argv[1]);
	else
		return -1;
}

int closemydb(MYDB *mydb)
{
	//save list to file
	save_userlist(mydb->list, mydb->dbfilename);
	//distroy list
}

