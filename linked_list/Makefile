# ###################COMMAND#############################
CC=cc
CFLAGS=-Wall -Wextra -Werror -g
RM = rm -f
AR    := ar rcs
# ###################PATH#############################
SRC_DIR = src
INCLUDE_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)
INCLUDES = src/ft_free.c src/ft_isin.c src/ft_lstadd_back_bonus.c \
	src/ft_lstlast_bonus.c src/ft_lstnew_bonus.c src/ft_lstsize_bonus.c \
	src/ft_pa.c src/ft_pb.c src/ft_pop.c src/ft_push.c src/ft_ra.c \
	src/ft_rb.c src/ft_rra.c src/ft_rrb.c src/ft_rr.c src/ft_rrr.c \
	src/ft_sa.c src/ft_sb.c src/ft_ss.c
OBJ_DIR = $(addprefix obj/, $(notdir $(OBJS)))
NAME = liblink.a
MAIN = main.c
EXEC = push_swap
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
	@ echo ${COLOR}"LIBRARY OF LINKED_LIST IS CREATING ..."${NC}

$(NAME): WAITING $(OBJ_DIR) $(INCLUDES) 
	@ $(AR) library/$(NAME) $(OBJ_DIR)
	@ echo ${COLOR}"\nLINKED_LIST LIBRARY CREATED"${NC}

TEST :
	@ $(CC) $(CFLAGS) $(MAIN)  -I $(INCLUDE_DIR) -o $(EXEC) library/$(NAME)
	@ echo ${COLOR}"EXECUTBLE DONE"${NC}
	@ printf  ${RE}"RESULT = "${NC} && ./$(EXEC)
	@ printf "\n"
clean:
	@ $(RM) $(OBJ_DIR) push_swap

fclean: clean
	@ $(RM) library/$(NAME)
	@ echo ${COLOR}"Linked_List library and obj CLEAN DONE"${NC}

re: fclean all

.PHONY: all clean fclean re