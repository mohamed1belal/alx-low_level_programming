#include "main.h"

#define USAGE "Usage: cp file_from file_to\n"
#define ERR_NOREAD "Error: Can't read from file %s\n"
#define ERR_NOWRITE "Error: Can't write to %s\n"
#define ERR_NOCLOSE "Error: Can't close fd %d\n"
#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)

/**
  * copy_file - copies the contents of one file to another
  * @src_filename: source file name
  * @dest_filename: destination file name
  *
  * Return: 1 on success, 0 on failure
  */
int copy_file(const char *src_filename, const char *dest_filename)
{
	int src_fd = 0, dest_fd = 0;
	ssize_t bytes_read;
	char buffer[READ_BUF_SIZE];

	src_fd = open(src_filename, O_RDONLY);
	if (src_fd == -1)
	{
		dprintf(STDERR_FILENO, ERR_NOREAD, src_filename);
		return (0);
	}

	dest_fd = open(dest_filename, O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, ERR_NOWRITE, dest_filename);
		close(src_fd);
		return (0);
	}

	while ((bytes_read = read(src_fd, buffer, READ_BUF_SIZE)) > 0)
	{
		if (write(dest_fd, buffer, bytes_read) != bytes_read)
		{
			dprintf(STDERR_FILENO, ERR_NOWRITE, dest_filename);
			close(src_fd);
			close(dest_fd);
			return (0);
		}
	}

	close(src_fd);
	close(dest_fd);

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, ERR_NOREAD, src_filename);
		return (0);
	}

	return (1);
}

/**
  * main - check the code
  * @ac: argumnet count
  * @av: argument vector
  *
  * Return: Always 0.
 */
int main(int ac, char **av)
{
	if (ac != 3)
	{
		dprintf(STDERR_FILENO, USAGE);
		return (97);
	}

	if (copy_file(av[1], av[2]))
	{
		return (EXIT_SUCCESS);
	}
	else
	{
		return (98);
	}
}
