# ###################COMMAND#############################
CC=cc
CFLAGS=-Wall -Wextra -Werror -g
RM = rm -f
AR    := ar rcs
# ###################PATH#############################
SRC_DIR = src
INCLUDE_DIR = include
SRC = ft_abs.c      ft_memcpy.c      ft_strlcat.c \
	ft_atoi.c     ft_memmove.c     ft_strlcpy.c \
	ft_bzero.c    ft_memset.c      ft_strlen.c \
	ft_calloc.c   ft_putchar_fd.c  ft_strmapi.c \
	ft_in_tab.c   ft_putendl_fd.c  ft_strncmp.c \
	ft_isalnum.c  ft_putnbr_fd.c   ft_strnstr.c \
	ft_isalpha.c  ft_putstr_fd.c   ft_strrchr.c \
	ft_isascii.c  ft_split.c       ft_strtrim.c \
	ft_isdigit.c  ft_strchr.c      ft_substr.c \
	ft_isprint.c  ft_strcmp.c      ft_tolower.c \
	ft_itoa.c     ft_strdup.c      ft_toupper.c \
	ft_memchr.c   ft_striteri.c \
	ft_memcmp.c   ft_strjoin.c 
SRCS = $(addprefix src/, $(SRC))
OBJS = $(SRCS:.c=.o)
INCLUDES = $(wildcard $(INCLUDE_DIR)/*)
OBJ_DIR = $(addprefix obj/, $(notdir $(OBJS)))
NAME = libft.a
MAIN = main.c
EXEC = main
# ################COLOR##############################
COLOR='\033[0;32m'
NC='\033[0m' # No Color
RE= '\033[0;34m'
# ###################################################
all: $(NAME) 
	
	

obj/%.o: src/%.c $(INCLUDES)
	@ printf $(COLOR)"#"$(NC)
	@ $(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o obj/$(notdir $@)
	
WAITING : 
	@ echo ${COLOR}"LIBRARY OF LIBFT IS CREATING ..."${NC}

$(NAME): WAITING $(OBJ_DIR) $(INCLUDES) 
	@ $(AR) library/$(NAME) $(OBJ_DIR)
	@ echo ${COLOR}"\nLIBFT LIBRARY CREATED"${NC}

TEST :
	@ $(CC) $(CFLAGS) $(MAIN)  -I $(INCLUDE_DIR) -o $(EXEC) library/$(NAME)
	@ echo ${COLOR}"EXECUTBLE DONE"${NC}
	@ printf  ${RE}"RESULT = "${NC} && ./$(EXEC)
	@ printf "\n"
clean:
	@ $(RM) $(OBJ_DIR) main

fclean: clean
	@ $(RM) library/$(NAME)
	@ echo ${COLOR}"Libft Library and objs CLEAN DONE"${NC}

re: fclean all

.PHONY: all clean fclean re