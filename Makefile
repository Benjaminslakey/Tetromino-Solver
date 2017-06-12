NAME= fillit
SRCS= tet_main.c \
	  tet_file_read.c \
	  tet_lst_add.c \
	  tet_map_piece.c \
	  tet_place.c \
	  tet_valid_chk.c \
	  tet_error.c \
	  tet_solver.c \

OBJ		= $(SRCS:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFT	= libft.a
LIBLINK	= -L./libft

all: $(NAME)

$(LIBFT):
	make -C ./libft
	mv libft/$(LIBFT) .

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(LIBLINK) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	rm -rf $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -rf ./$(NAME)

re: fclean all
