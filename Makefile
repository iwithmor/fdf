# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/20 18:36:08 by iwithmor          #+#    #+#              #
#    Updated: 2016/12/01 16:25:58 by iwithmor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# DIRECTORIES
LDIR = ./libft
MLXDIR = ./minilibx_macos
IDIR = .

# LIBRARIES
LIB = $(LDIR)/libft.a
MLX = $(MLXDIR)/mlx.a

# ADD LIBRARIES
FINDLIB = -L$(LDIR) -lft -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit

# INCLUDE FILES
INCLUDE = -I$(IDIR) -I$(LDIR) -I$(MLXDIR)

SRC = main.c fdf.c key_events.c calculate.c draw.c connect.c rotate.c move.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(FINDLIB)

$(OBJ): $(SRC)
	gcc $(FLAGS) -c $(SRC) $(INCLUDE)

$(SRC): $(LIB) $(MLX)

$(LIB):
	make -C $(LDIR)

$(MLX):
	make -C $(MLXDIR)

clean:
	make clean -C $(LDIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LDIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
