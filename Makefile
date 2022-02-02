CC        := cc
CFLAGS    := -Wall -Wextra -Werror
SRC = src/main.c src/parse.c  src/checker.c gnl/get_next_line.c gnl/get_next_line_utils.c
B ?= 2 1 3 6 5 8
LIBRARY = libft/library/libft.a linked_list/library/liblink.a 

all: $(LIBRARY)
	@ $(CC) $(CFLAGS) -g $(SRC)  $(LIBRARY)  -o push_swap
	


$(LIBRARY) :
	@ make -C libft
	@ make -C linked_list
clean:
	@ make clean -C libft/
	@ make clean -C linked_list
fclean :
	@ make fclean -C libft
	@ make fclean -C linked_list
	@ rm -rf push_swap

re : fclean all