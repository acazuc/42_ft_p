#include "server.h"

void command_ls(t_client *client)
{
	DIR *dir;
	struct dirent *dirent;

	if (!(dir = opendir(client->path)))
	{
		write_long(client, -1);
		return;
	}
	write_long(client, 0);
	while ((dirent = readdir(dir)))
	{
		write_str(client, dirent->d_name);
	}
	write_str(client, "");
}
