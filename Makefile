# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 23:11:43 by raica-ba          #+#    #+#              #
#    Updated: 2025/03/16 22:24:45 by raica-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myscanf.a

CC = cc

INCLUDES = .

FLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src
OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

SRC_FILES = my_scanf.c my_scanf_storagefuncs.c my_scanf_utils.c my_scanf_auxiliaryfuncs\

EXEC = my_scanf

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
				@ar rcs $@ $(OBJ)
				@ranlib $@

$(EXEC): $(OBJ)
				$(CC) $(FLAGS) -o $(EXEC) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
				$(CC) $(FLAGS) -c $< -o $@
$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

clean:
				echo "Removing $(OBJ_DIR)"
				rm -rf $(OBJ_DIR)
fclean: clean
				echo "Removing $(NAME)"
				rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
