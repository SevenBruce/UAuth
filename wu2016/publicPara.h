#ifndef PUBLICPARA_H
#define PUBLICPARA_H

/* the length of a random string */
static int RANDOM_STRING_LENGTH = 8;

/* the length of a random number */
static int RANDOM_NUMBER_LENGTH = 20;


/* the length of a hash 256 string */
static int HASH_MESSAGE_LENGH = 32;


/* NIST p192 bit elliptic curve prime 2#192-2#64-1 */
static char *ecp_user_define = (char *)"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFFFFFFFFFF";

/* elliptic curve parameter B */
static char *ecb_user_define = (char *)"64210519E59C80E70FA7E9AB72243049FEB8DEECC146B9B1";

/* elliptic curve - point of prime order (x,y) */
static char *ecx_user_define = (char *)"188DA80EB03090F67CBF20EB43A18800F4FF0AFD82FF1012";
static char *ecy_user_define = (char *)"07192B95FFC8DA78631011ED6B24CDD573F977A11E794811";

#endif
