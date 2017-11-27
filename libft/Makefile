# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tparand <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 16:46:58 by tparand           #+#    #+#              #
#    Updated: 2017/11/24 11:34:20 by tparand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=	ft_atoi.c		\
		ft_bzero.c		\
		ft_factorial.c		\
		ft_isalnum.c		\
		ft_isalpha.c		\
		ft_isascii.c		\
		ft_isdigit.c		\
		ft_islower.c		\
		ft_isprint.c		\
		ft_isupper.c		\
		ft_itoa.c		\
		ft_lstadd.c		\
		ft_lstaddend.c		\
		ft_lstdel.c		\
		ft_lstdelone.c		\
		ft_lstgetlast.c		\
		ft_lstislast.c		\
		ft_lstiter.c		\
		ft_lstmap.c		\
		ft_lstnew.c		\
		ft_memalloc.c		\
		ft_memccpy.c		\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memdel.c		\
		ft_memmove.c		\
		ft_memset.c		\
		ft_putchar.c		\
		ft_putchar_fd.c		\
		ft_putendl.c		\
		ft_putendl_fd.c		\
		ft_putnbr.c		\
		ft_putnbr_fd.c		\
		ft_putstr.c		\
		ft_putstr_fd.c		\
		ft_strcat.c		\
		ft_strchr.c		\
		ft_strclen.c		\
		ft_strclr.c		\
		ft_strcmp.c		\
		ft_strcpy.c		\
		ft_strdel.c		\
		ft_strdup.c		\
		ft_strequ.c		\
		ft_striter.c		\
		ft_striteri.c		\
		ft_strjoin.c		\
		ft_strlcat.c		\
		ft_strlen.c		\
		ft_strmap.c		\
		ft_strmapi.c		\
		ft_strncat.c		\
		ft_strncmp.c		\
		ft_strncpy.c		\
		ft_strndup.c		\
		ft_strnequ.c		\
		ft_strnew.c		\
		ft_strnstr.c		\
		ft_strrchr.c		\
		ft_strsplit.c		\
		ft_strstr.c		\
		ft_strsub.c		\
		ft_strtrim.c		\
		ft_strwcount.c		\
		ft_swap.c		\
		ft_tolower.c		\
		ft_toupper.c

OBJS	=	$(SRCS:.c=.o)
H	=	./includes
CC	=	gcc
CFLAGS	=	-c -Wall -Werror -Wextra

all	: $(NAME)

$(NAME)	: $(OBJS)
	@ar rc $@ $(OBJS)
	@echo -e "\t\033[0;32m[OK]\033[0m"
	@ranlib $@
	@echo -e "\033[1;34mLibft\t\t\033[1;33mIndexing [libft.a]\t\033[0;32m[OK]\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) $< -o $@ -iquote $(H)

clean:
	@rm -Rf $(OBJS)
	@echo -e "\033[1;34mLibft\t\t\033[1;33mCleaning [objs]\t\t\033[0;32m[OK]\033[0m"

fclean	: clean
	@rm -Rf $(NAME)
	@echo -e "\033[1;34mLibft\t\t\033[1;33mCleaning [libft.a]\t\033[0;32m[OK]\033[0m"

re: fclean all

.PHONY: clean fclean
