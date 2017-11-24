# Project file
NAME 		= gnl.out

# Project builds
SRCSDIR 	= ./
SRCSFILES 	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRCS 		= $(addprefix $(SRCDIR), $(SRCSFILES))
HDIR 		= ./
BUILDDIR 	= ./build/
OBJS 		= $(addprefix $(BUILDDIR), $(SRCS:.c=.o))

# Libft builds and dirs
LIBDIR 		= ./libft/
LIBFT 		= ./libft/libft.a
LIBHDIR		= ./libft/includes/

# Compiler flags
CC		= gcc
CFLAGS 		= -Wall -Werror -Wextra

# Main rule
all		: $(BUILDDIR) $(LIBFT) $(NAME)

# Object dir rule
$(BUILDDIR)	:
	@mkdir -p $(BUILDDIR)
	@echo -e "\033[1;34mGNL\t\t\033[1;33mCreation [builddir]\t\033[0;32m[OK]\033[0m"

$(LIBFT):
	@echo -n -e "\033[1;34mLibft\t\t\033[1;33mMaking [libft.a]"
	@make -s -C $(LIBDIR)

# Project file rule
$(NAME)		: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@ -L$(LIBDIR) -lft
	@echo -e "\033[1;34mGNL\t\t\033[1;33mCompilation [gnl]\t\033[0;32m[OK]\033[0m"
	@echo
	@echo -e "\033[1;34m------>\t\t\033[1;33m./gnl.out\t\t\033[0;32m[NOW]\033[0m"

# Objects rule
$(BUILDDIR)%.o	: $(SRCSDIR)%.c
	@$(CC) $(CFLAGS) -iquote $(LIBHDIR) -iquote $(HDIR) -c $< -o $@

# Cleaning up the build files
clean	:
	@rm -Rf $(BUILDDIR)
	@echo -e "\033[1;34mGNL\t\t\033[1;33mCleaning [builddir]\t\033[0;32m[OK]\033[0m"
	@make -s -C $(LIBDIR) clean

# Getting rid of the project file
fclean	: clean
	@rm -Rf $(NAME)
	@echo -e "\033[1;34mGNL\t\t\033[1;33mCleaning [gnl]\t\t\033[0;32m[OK]\033[0m"
	@make -s -C $(LIBDIR) fclean

# Do both of the above
re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re
