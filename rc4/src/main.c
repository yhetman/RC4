/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: yhetman <yhetman@student.unit.ua>                                    */
/*                                                                            */
/*   Created: 2021/10/15 12:56:03 by yhetman                                  */
/*   Updated: 2021/10/15 12:56:04 by yhetman                                  */
/*                                                                            */
/* ************************************************************************** */

#include "rc4.h"

static void
usage()
{
	printf("Usage:\n ./rc4 -i /path/input -o /path/output -k /path/key -e | -d\n");
}


static int
get_flags(int argc, char **argv, char **input, char **key, char **output, bool *encrypt)
{
	int flag;

	while ((flag = getopt(argc, argv, "i:o:k:edh")) != -1)
	{
		switch (flag)
		{
			case 'i':
				*input = optarg;
				break ;
			case 'o':
				*output = optarg;
				break ;
			case 'k':
				*key = optarg;
				break;
			case 'd':
				*encrypt = false;
				break ;

			case 'e':
				*encrypt = true;
				break ;
			
			case 'h':
				usage();
				return -1;
		}
	}
	return 0;
}


int
main(int argc, char **argv)
{
	bool 		encrypt = true;
	char		*input,
				*key,
				*output;

	if (argc < 5)
		usage();
	
	if ((get_flags(argc, argv, &input, &key, &output, &encrypt)) < 0)
		return 1;

	if (encrypt)
		encryption(input, key, output);
	else
		decryption(input, key, output);
	

	return 0;
}


