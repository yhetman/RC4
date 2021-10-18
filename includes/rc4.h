/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rc4.h                                                                    */
/*                                                                            */
/*   By: yhetman <yhetman@student.unit.ua>                                    */
/*                                                                            */
/*   Created: 2021/10/15 12:56:15 by yhetman                                  */
/*   Updated: 2021/10/15 12:56:19 by yhetman                                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef RC4_H
# define RC4_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>


void			encryption(const char *input, const char  *fkey, const char *output);
void			decryption(const char *input, const char  *fkey, const char *output);
void			rc4(unsigned char *input, long ilength, unsigned char *key, \
				long klength, unsigned char* output);
unsigned char 	*reading(FILE *file, long *filesize);

#endif
