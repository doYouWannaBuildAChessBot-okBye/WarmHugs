#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static char
	*get_line(
FILE *stream
)
{
	size_t	capacity = 1024;
	size_t	size = 0;
	char	*string = malloc(capacity);

	while (fgets(string + size, capacity - size, stream)) {
		size += strlen(string + size);

		if (string[size - 1] == '\n') 
			return (string);
		capacity *= 2;
		string = realloc(string, capacity);
	}
	free (string);
	return (NULL);
}

static char
	*get_token(
char *string,
char *store
)
{
	string += strlen(string);
	*string = *store;
	while (isspace(*string))
		string++;
	if (*string) {
		char *token = string;

		while (*string && !isspace(*string))
			string++;
		*store = *string;
		*string = 0;
		return (token);
	}
	return (NULL);
}

// im way too cooked to do this at home on my own while sick, ill continue with
// it tomorrow when im not as cooked
