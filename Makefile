# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanghyki <kanghyki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 15:23:01 by kanghyki          #+#    #+#              #
#    Updated: 2022/12/01 15:58:19 by kanghyki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------[ COLOR ]-----------------
COMPILE_COLOR	=	"\033[1;34m"
BUILD_COLOR		=	"\033[1;32m"
MODE_COLOR		=	"\033[1;35m"
DEL_COLOR		=	"\033[1;31m"
END				=	"\033[0;0m"
CLEAR			=	"\x1b[1A\x1b[M"
#---------------[ LIBFT ]-----------------
LIB_DIR			=	lib
LIBFT			=	$(LIBFT_DIR)/libft.a
LIBFT_DIR		=	$(LIB_DIR)/libft
LIBFT_INC		=	$(LIBFT_DIR)/inc
#---------------[ CUB3D ]-----------------
NAME			=	cub3D
SRC_INC			=	src
SRC_DIR			=	src
SRC				=	main.c

OBJ_DIR			=	obj
OBJ				=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
#----------------[ CMD ]------------------
CC				=	gcc
CPPFLAGS		=	-I $(SRC_INC)\
					-I $(LIBFT_DIR)
ifndef DEBUG
	CFLAGS	=	-Wall -Wextra -Werror
else
	CFLAGS	=	-g -Wall -Wextra -Werror
endif
LDLIBS			=	-l ft -L $(LIBFT_DIR)
RM				=	rm -rf

vpath %.c $(SRC_DIR)

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@echo $(COMPILE_COLOR) "💾 [$<] Compiling..." $(END)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	@echo $(COMPILE_COLOR) "✨ [$@] was created" $(END)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@echo $(BUILD_COLOR) "🔨 [$@] Building..." $(END)
	@$(CC) $(LDLIBS) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo $(BUILD_COLOR) "🎉 [$@] was created" $(END)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ) $(OBJ_DIR)
	@echo $(DEL_COLOR) "🧹 [Object files] were removed" $(END)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo $(DEL_COLOR) "🧹 [$(NAME)] were removed" $(END)

re:
	@make fclean
	@make all

debug: fclean
	@make DEBUG=1 all

.PHONY: all clean fclean re debug
