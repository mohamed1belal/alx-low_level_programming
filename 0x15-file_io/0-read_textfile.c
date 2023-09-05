#include "main.h"

/**
  * read_textfile - reads text from a file and prints it
  * @filename: name of file to read
  * @letters: number of bytes to read
  *
  * Return: number bytes read/printed
  */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read = 0;
	char buffer[READ_BUF_SIZE];

	if (!filename || !letters)
		return (0);

	fd = open(filename, O_RDONLY); /* Corrected the file open flag */
	if (fd == -1)
		return (0);

	while (letters > 0)
	{
		ssize_t bytes = read(fd, buffer, READ_BUF_SIZE);
		ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes);

		if (bytes == -1)
		{
			close(fd);
			return (0);
		}

		if (bytes_written == -1)
		{
			close(fd);
			return (0);
		}

		bytes_read += bytes_written;
		letters -= bytes_written;

		if (bytes < READ_BUF_SIZE)
			break;
	}

	close(fd);
	return (bytes_read);
}
