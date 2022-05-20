CC        := cc
CFLAGS    := -g

# ####################PUSH_SWAP######################

SRC = main.c parse.c  \
	max_min.c smart_rotate.c LIS.c pos.c back_to.c \
	smart_rotate_pr.c sort_instruction.c loops.c
OBJS=$(addprefix obj/,$(SRC:.c=.o))

# ################CHECKER############################

SRC_CHECKER= checker.c  gnl/get_next_line.c \
	gnl/get_next_line_utils.c   parse.c \
	max_min.c pos.c back_to.c \
	smart_rotate_pr.c sort_instruction.c loops.c
OBJS_CH=$(addprefix obj/,$(SRC_CHECKER:.c=.o))

# ################LIBRARY############################

LIBRARY = libft/library/libft.a \
	linked_list/library/liblink.a

# ################COLOR##############################

COLOR='\033[0;32m'
NC='\033[0m'
RE= '\033[0;34m'
RED='\033[0;31m'

# #######################BIN#########################

PUSH_SWAP = push_swap
CHECKER = checker

# ###################################################
all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP) : $(OBJS) 
	@ $(CC) $(CFLAGS) $(OBJS)  $(LIBRARY)  -o $(PUSH_SWAP)



bonus : $(CHECKER)

$(CHECKER) : $(OBJS_CH) 
	@ $(CC) $(CFLAGS) $(OBJS_CH) $(LIBRARY) -o $(CHECKER)
	
	
obj/%.o: src/%.c $(LIBRARY)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ echo ${RE}"Making the $(notdir $@)"${NC}

obj/gnl/%.o: gnl/%.c $(LIBRARY)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ echo ${RE}"Making the $(notdir $@)"${NC}

$(LIBRARY) :
	@ make -C libft
	@ make -C linked_list

lik :
	@ make -C linked_list

clean : 
	@ rm -rf $(OBJS) 
	@ rm -rf $(OBJS_CH) 
	@ make clean -C libft/
	@ make clean -C linked_list
fclean : clean
	@ rm -rf $(PUSH_SWAP)
	@ rm -rf $(CHECKER)
	@ make fclean -C libft
	@ make fclean -C linked_list

re : fclean all