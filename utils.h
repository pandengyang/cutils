#ifndef __UTILS_H__
#define __UTILS_H__

#define sizeofmember(type, member) sizeof (((type*)0)->member)

#define SEQ_BITS 3
#define SEQ_MAX (~(-1l << SEQ_BITS))
#define SEQ_MAX2 ((1 << SEQ_BITS) - 1)
#define SEQ_MASK SEQ_MAX

#define WORKER_ID_SHIFT SEQ_BITS
#define WORKER_ID_BITS 5
#define WORKER_ID_MAX (~(-1l << WORKER_ID_BITS))
#define WORKER_ID_MASK (WORKER_ID_MAX << WORKER_ID_SHIFT)

/* bcd.c */
unsigned bcd2bin(unsigned char val)
unsigned char bin2bcd(unsigned val)

/* time.c */
void get_time(struct timeval tv, char *buf, int buf_len);
void get_elapsed(struct timeval before, struct timeval after, char *buf, int buf_len);

/* hex.c */
int hexlify(char *bytes, int bytes_len, char *buf, int buf_len);
int unhexlify(char *str, char *buf, int buf_len);

/* str.c */
char *trim(char *str);
int c2i(char ch);
unsigned int parse_uint(char *num_str);

/* ip.c */
int ip_validate(char *ip);
int parse_ip(char *ip, unsigned char * sections);


#endif
