#include "main.h"

/**
  * _strlen - returns the length of a string
  * @s: the string whose length to check
  *
  * Return: integer length of string
  */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
  * append_text_to_file - appends text to file
  * @filename: name of file to create
  * @text_content: text to write
  *
  * Return: 1 on success, 0 on failure
  */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes = 0, len = _strlen(text_content);

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (len > 0)
	{
		bytes = write(fd, text_content, len);
		if (bytes == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
