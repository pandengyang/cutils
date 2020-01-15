#include <stdio.h>
#include <string.h>

#include "utils.h"

int hexlify(char *bytes, int bytes_len, char *buf, int buf_len)
{
	if (bytes_len * 2 > buf_len) {
		return -1;
	}

	for (int i = 0; i < bytes_len; i++) {
		snprintf(buf + i * 2, buf_len - i * 2, "%02x", bytes[i]);
	}

	return 0;
}

int unhexlify(char *str, char *buf, int buf_len)
{
	size_t len;
	int h, l;

	len = strlen(str);

	if (len % 2 != 0) {
		return -1;
	}

	if (len > buf_len / 2) {
		return -2;
	}

	for (int i = 0, j = 0; i < len; i += 2, j++) {
		h = c2i(str[i]);
		l = c2i(str[i + 1]);

		if (h < 0 || l < 0) {
			return -3;
		}

		buf[j] = (h << 4) + l;
	}

	return 0;
}
