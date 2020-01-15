#include <time.h>
#include <sys/time.h>
#include <stdio.h>

/* 获取时间，格式为时:分:秒.毫秒
 * 例如：20:56:51.888
 */
void get_time(struct timeval tv, char *buf, int buf_len)
{
	struct tm *ptm;

	ptm = localtime((time_t *) & tv.tv_sec);
	snprintf(buf, buf_len, "%02d:%02d:%02d.%03d", ptm->tm_hour, ptm->tm_min,
		 ptm->tm_sec, tv.tv_usec / 1000);

	return;
}

/* 获取两个时间之间的间隔，格式为秒 毫秒
 * 例如：0s 100ms
 */
void get_elapsed(struct timeval before, struct timeval after, char *buf,
		 int buf_len)
{
	snprintf(buf, buf_len, "%ds %dms", after.tv_sec - before.tv_sec,
		 (after.tv_usec - before.tv_usec) / 1000);

	return;
}
