CC        := cc
CFLAGS    := 
SRC = src/main.c src/parse.c  src/checker.c gnl/get_next_line.c gnl/get_next_line_utils.c src/print_stack.c \
	src/max_min.c src/hash.c src/smart_rotate.c src/LIS.c src/pos.c src/back_to.c \
	src/smart_rotate_pr.c src/sort_instruction.c
B ?= 2 1 3 6 5 8
LIBRARY = libft/library/libft.a linked_list/library/liblink.a 

all: $(LIBRARY)
	@ $(CC) $(CFLAGS) -g $(SRC)  $(LIBRARY)  -o push_swap
	


$(LIBRARY) :
	@ make -C libft
	@ make -C linked_list

lik :
	@ make -C linked_list

clean:
	@ make clean -C libft/
	@ make clean -C linked_list
fclean :
	@ make fclean -C libft
	@ make fclean -C linked_list
	@ rm -rf push_swap

re : fclean all