#* ************************************************************************** *#
#*                                                                            *#
#*                                                                            *#
#*   Makefile                                                                 *#
#*                                                                            *#
#*   By: yhetman <yhetman@student.unit.ua>                                    *#
#*                                                                            *#
#*   Created: 2021/10/15 12:51:52 by yhetman                                  *#
#*   Updated: 2021/10/15 12:51:54 by yhetman                                  *#
#*                                                                            *#
#* ************************************************************************** *#


SRCS = main.c encryption.c rc4.c decryption.c

SRCS_DIR = src/

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

OBJ_DIR = obj/

LIB_NAME = librc4.a

RC = rc4

FLAGS = -I includes -Wall -Wextra -Werror

DEBUG_FLAGS = -g3 -fsanitize=address

RC_MAIN = src/main.c

all: make_obj_dir $(RC)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	gcc $(FLAGS) -c $< -o $@

$(LIB_NAME): $(OBJ)
	ar -rv $(LIB_NAME) $^
	ranlib $(LIB_NAME)

$(RC): $(LIB_NAME) $(RC_MAIN)
	gcc $(FLAGS) $(RC_MAIN) $(LIB_NAME) -o $(RC)

make_obj_dir:
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(RC)
	rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean flcean re debug