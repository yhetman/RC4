/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   decryption.c                                                             */
/*                                                                            */
/*   By: yhetman <yhetman@student.unit.ua>                                    */
/*                                                                            */
/*   Created: 2021/10/15 13:48:25 by yhetman                                  */
/*   Updated: 2021/10/15 13:48:27 by yhetman                                  */
/*                                                                            */
/* ************************************************************************** */


#include "rc4.h"

void
decryption(const char *input, const char  *fkey, const char *output)
{
    unsigned char   *plain_data,
                    *cyphered,
                    *key;
    long            fsize,
                    klength;
    FILE            *f;

    
    f = fopen (input,"rb");
    cyphered = reading(f,&fsize);

    plain_data = (unsigned char *) calloc(fsize + 10,sizeof(unsigned char));
    memset (plain_data, 0, fsize + 10);
    f = fopen (fkey,"rb");
    key = reading(f, &klength);

    if(klength > 256)
    {
        printf("Key length must be shorter 256 bytes.");
        exit(1);
    }

    rc4(cyphered, fsize - 1, key, klength, plain_data);
  
    f = fopen(output, "w");
    fwrite(plain_data, 1, fsize, f);
    fclose(f);
    free (plain_data);
    free (cyphered);
    free(key);

}