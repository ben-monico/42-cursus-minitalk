NAME = server

NAME2 = client

SRCS_SV =	server.c\
			base_to_base.c

SRCS_CL =	client.c\
			utils.c

OBJS_SV = $(SRCS_SV:.c=.o)

OBJS_CL = $(SRCS_CL:.c=.o)

CC = gcc 

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I . -I ft_printf -I libft

LINKERS = -Lft_printf -lftprintf  -Llibft -lft

.c.o:
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS_SV) $(NAME2)
		$(CC) $(FLAGS) $(LINKERS) $(OBJS_SV) -o $(NAME)

$(NAME2): $(OBJS_CL)
		$(CC) $(FLAGS) $(LINKERS) $(OBJS_CL) -o $(NAME2)

all: $(NAME)

re: fclean all

clean:
	rm -f $(OBJS_SV) $(OBJS_CL)

fclean: clean
	rm -f $(NAME1) $(NAME2)

.PHONY: all re clean fclean
