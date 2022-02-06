# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/26 01:40:57 by otaishi           #+#    #+#              #
#    Updated: 2020/12/28 12:51:19 by otaishi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC    = gcc

CFLAGS    = -Wall    -Wextra    -Werror

RM        =    rm -f

INCDIR    =    ./

SRCDIR    =    ./

SRC = ft_printf.c\
 printf_utils.c\
 libft_1.c\
 all_utils.c\
 int_utils_1.c\
 int_utils_2.c\
 uint_utils1.c\
 uint_utils2.c\
 uint_utils3.c\
 char_utils.c\
 string_utils.c\
 pointer_utils.c\
 pointer_utils_2.c\

SRCS    =    $(addprefix $(SRCDIR), $(SRC))

OBJS    =    $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS)    -I $(INCDIR) -c $< -o $(<:.c=.o)

$(NAME):    $(OBJS)
	ar    rcs    $(NAME)    $(OBJS)

all:        $(NAME)

clean:
	$(RM) $(OBJS)

fclean:        clean
	$(RM) $(NAME)

re:            fclean all

.PHONY:    all clean fclean re
