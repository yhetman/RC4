/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rc4.c                                                                    */
/*                                                                            */
/*   By: yhetman <yhetman@student.unit.ua>                                    */
/*                                                                            */
/*   Created: 2021/10/15 14:51:10 by yhetman                                  */
/*   Updated: 2021/10/15 14:51:13 by yhetman                                  */
/*                                                                            */
/* ************************************************************************** */


#include "rc4.h"


static void
ft_swap(unsigned char a, unsigned char b)
{
	unsigned char  tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void
rc4(unsigned char *input, long ilength, unsigned char *key, \
	long klength, unsigned char *output)
{
	unsigned char 	T[256],
    			 	S[256];
    int 			j = 0,
    				t = 0,
    				i = 0,
    				x = 0;
   
    
    for(i = 0 ; i < 256 ; i++)
    {
        S[i] = i;
        T[i] = key[i % klength];
    }
    for(i = 0 ; i < 256; i++)
    {
        j = ( j + S[i] + T[i] ) % 256;
        ft_swap(S[j], S[i]);
    }
    j = 0;
    for(x = 0 ; x < ilength ; x++)
    {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
    	ft_swap(S[j], S[i]);
        t = (S[i] + S[j]) % 256;
        output[x]= input[x]^S[t];
    }
}
