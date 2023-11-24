#include "main.h"

#define USAGE "Usage: cp file_from file_to\n"
#define ERR_NOREAD "Error: Can't read from file %s\n"
#define ERR_NOWRITE "Error: Can't write to file %s\n"
#define ERR_NOCLOSE "Error: Can't close fd %d\n"
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
#define READ_BUF_SIZE 1024

/**
  * main - program
  * @ac: arg count
  * @av: arg vector
  *
  * Return: 1 on success 0 on failure
  */

int main(int ac, char **av)
{
	ssize_t bytes_read, bytes_written;

	int copy_file(const char *src_filename, const char *dest_filename);

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, USAGE);
		return (97);
	}

	if (copy_file(av[1], av[2]))
	{
		return (1);
	}
	else
	{
		return (98);
	}
}

int copy_file(const char *src_filename, const char *dest_filename)
{
	int from_fd = open(src_filename, O_RDONLY);

	if (from_fd == -1)
	{
		dprintf(STDERR_FILENO, ERR_NOREAD, src_filename);
		return (0);
	}

	int to_fd = open(dest_filename, O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);

	if (to_fd == -1)
	{
		dprintf(STDERR_FILENO, ERR_NOWRITE, dest_filename);
		close(from_fd);
		return (0);
	}

	char buffer[READ_BUF_SIZE];

	while ((bytes_read = read(from_fd, buffer, READ_BUF_SIZE)) > 0)
	{
		bytes_written = write(to_fd, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, ERR_NOWRITE, dest_filename);
			close(from_fd);
			close(to_fd);
			return (0);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, ERR_NOREAD, src_filename);
		close(from_fd);
		close(to_fd);
		return (0);
	}

	if (close(from_fd) == -1 || close(to_fd) == -1)
	{
		dprintf(STDERR_FILENO, ERR_NOCLOSE,
				(close(from_fd) == -1) ? from_fd : to_fd);
		return (0);
	}

	return (1);
}
