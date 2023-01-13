NAME	:= cub3D
CC		:= gcc
CFLAGS	:= -Wall -Werror -Wextra -g -Lmlx -lmlx -L/usr/lib -framework OpenGL -framework AppKit
INCLUDE	:= -I./include
OBJ_DIR	:= obj
SRCS_DIR:= src/cub3D
GNL_DIR	:= src/get_next_line
SRCS	:= $(wildcard $(SRCS_DIR)/*.c)
GNL_SRC	:= $(wildcard $(GNL_DIR)/*.c)
OBJ		:= $(patsubst %, $(OBJ_DIR)/%, $(notdir $(SRCS:.c=.o)))
GNL_OBJ	:= $(patsubst %, $(OBJ_DIR)/%, $(notdir $(GNL_SRC:.c=.o)))
ALL_OBJ	:= $(OBJ) $(GNL_OBJ) src/libft/libft.a

all: make-diff $(NAME)

make-diff:
	make -C src/libft/
	make -C mlx/

$(NAME): $(OBJ_DIR) $(OBJ) $(GNL_OBJ)
	$(CC) $(INCLUDE) $(ALL_OBJ) $(CFLAGS) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(INCLUDE) -Wall -Wextra -Werror -c $? -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	@$(CC) $(INCLUDE) -Wall -Werror -Wextra -c $< -o $@

re:	fclean all

clean:
	@rm -rf $(OBJ_DIR)
	make -C src/libft/ clean
	make -C mlx/ clean

fclean: clean
	@rm -rf $(NAME)
	make -C src/libft/ fclean
	make -C mlx/ clean

norm:
	@norminette $(shell find src -name "*.c") include

#for debug
print:
	@echo "----------OBJ_DIR----------"
	echo $(OBJ_DIR)/*.o
	@echo "----------SRCS_DIR----------"
	echo $(SRCS_DIR)/*.c
	@echo "----------OBJ----------"
	echo $(OBJ)
	@echo "----------SRCS----------"
	echo $(SRCS)

.PHONY: all make-diff clean fclean norm