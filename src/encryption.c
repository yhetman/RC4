/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   encryption.c                                                             */
/*                                                                            */
/*   By: yhetman <yhetman@student.unit.ua>                                    */
/*                                                                            */
/*   Created: 2021/10/15 13:48:13 by yhetman                                  */
/*   Updated: 2021/10/15 13:48:14 by yhetman                                  */
/*                                                                            */
/* ************************************************************************** */

#include "rc4.h"

unsigned char
*reading(FILE *file, long *filesize)
{
	unsigned char	*info;
	long 			i;

	fseek(file, 0, 2);
	i = ftell(file);
	*filesize = i;
	fseek(file, 0, 0);
	info = (unsigned char *) calloc(*filesize + 10, sizeof(unsigned char));
    memset(info, 0 ,*filesize + 10);
    fread(info, 1 ,*filesize , file);
    fclose (file);
    return info;
}

void
encryption(const char *input, const char  *fkey, const char *output)
{
    unsigned char 	*plain_data,
    				*cyphered,
    				*key;
    long 			fsize,
    				klength;
	FILE 			*f;

    f = fopen (input,"rb");
    plain_data = reading(f, &fsize);
    cyphered = (unsigned char *) calloc(fsize + 10,sizeof(unsigned char));
    memset (cyphered,0,fsize + 10);
    f = fopen (fkey,"rb");
    key = reading(f, &klength);
    
    if(klength > 256)
    {
        printf("Key length must be shorter 256 bytes.");
        exit(1);
    }
    
    rc4(plain_data, fsize - 1, key, klength, cyphered);
    
    f = fopen(output, "w");
    fwrite(cyphered, 1, fsize, f);
    fclose(f);
    free (plain_data);
    free (cyphered);
    free (key);
}