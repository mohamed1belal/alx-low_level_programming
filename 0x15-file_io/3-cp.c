#include "main.h"
<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

/**
 * create_buffer - allocats for buffer buttes
 * @file: the name of the file buff
 * Description: task number 3
 * Return: pointer to the buff allocat.
 */

char *create_buffer(char *file);
void close_file(int fd);

char *create_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
=======

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
>>>>>>> eacde93 (test)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
 * close_file - closes file descriptors
 * @fd: file descriptor
 */

void close_file(int fd)
{
	int m;

	m = close(fd);

	if (m == -1)
	{
<<<<<<< HEAD
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: The num of atgs in the program
 * @argv: array of pointers to the args
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buff, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		w = write(to, buff, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		r = read(from, buff, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buff);
	close_file(from);
	close_file(to);

	return (0);
=======
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
>>>>>>> eacde93 (test)
}
