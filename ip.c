#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "utils.h"

int ip_validate(char *ip)
{
	char num_str[20];
	char *p_num;
	char *p;
	unsigned int num;
	int len;
	int dot;

	len = strlen(ip);
	if (len < 7 || len > 15) {
		return -1;
	}

	for (p = ip, p_num = num_str, dot = 0; *p != 0; p++) {
		if (*p == '.') {
			++dot;

			*p_num = 0;
			num = parse_uint(num_str);
			if (num == -1 || num > 255) {
				return -1;
			}

			p_num = num_str;
			continue;
		}
		*p_num++ = *p;
	}

	if (dot != 3) {
		return -2;
	}

	*p_num = 0;
	num = parse_uint(num_str);
	if (num == -1 || num > 255) {
		return -3;
	}

	return 0;
}

int parse_ip(char *ip, unsigned char *sections)
{
	char num_str[20];
	char *p_num;
	char *p;
	int index = 0;

	for (p = ip, p_num = num_str; *p != 0; p++) {
		if (*p == '.') {
			*p_num = 0;
			sections[index++] = parse_uint(num_str);

			p_num = num_str;
			continue;
		}
		*p_num++ = *p;
	}

	*p_num = 0;
	sections[index] = parse_uint(num_str);

	return 0;
}
