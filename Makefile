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

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ./$(NAME)

re: fclean all
