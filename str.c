#include <string.h>
#include <ctype.h>
#include <stdio.h>

int c2i(char ch)
{
	if (isdigit(ch))
		return ch - 48;

	if (ch < 'A' || (ch > 'F' && ch < 'a') || ch > 'f')
		return -1;

	if (isalpha(ch))
		return isupper(ch) ? ch - 55 : ch - 87;

	return -1;
}

char *trim(char *str)
{
	char *p = str;
	char *p1;

	if (p) {
		p1 = p + strlen(str) - 1;

		while (*p && isspace(*p)) {
			p++;
		}

		while (p1 > p && isspace(*p1)) {
			*p1-- = '\0';
		}
	}

	return p;
}

unsigned int parse_uint(char *num_str)
{
	char *p;

	if (strlen(num_str) == 0) {
		return -1;
	}

	for (p = num_str; *p != 0; p++) {
		if (!isdigit(*p)) {
			return -2;
		}
	}

	return atoi(num_str);
}
