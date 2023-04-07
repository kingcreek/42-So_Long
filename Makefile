# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 15:53:22 by imurugar          #+#    #+#              #
#    Updated: 2023/02/27 15:53:22 by imurugar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = ./src/

SRCS	=	ft_map_validate.c ft_map.c ft_utils.c ft_setup.c \
			../getnextline/get_next_line.c ft_game_utils.c \
			ft_pathval.c ft_pathval2.c

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

# /* ~~~~~~~ INCLUDING LIBFT ~~~~~~~ */
LIBFT_DIR = libft
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_DIR}/libft.a

# /* ~~~~~~~ INCLUDING MINILIBX ~~~~~~~ */
MLX_DIR = minilibx
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
GCC = gcc
CFLAGS = -Wall -Werror -Wextra
MFLAGS = -ldl -lmlx -L${MLX_DIR} -framework OpenGL -framework AppKit -lz
IFLAGS:= -I ./inc
LFLAGS:= -L $(LIBFT_DIR) -lft

# /* ~~~~~~~ OTHER ~~~~~~~ */
NAME = so_long
RM = rm -f

# /* ~~~~~~~ BONUS ~~~~~~~ */
 BONUS = so_long_bonus
 BONUS_DIR = ./bonus/

 BONUS_SRCS	=	ft_map_validate_bonus.c ft_map_bonus.c ft_utils_bonus.c ft_setup_bonus.c \
			ft_anim_bonus.c ../getnextline/get_next_line.c ft_game_utils_bonus.c \
			ft_enemies_bonus.c ft_pathval_bonus.c ft_pathval2_bonus.c


 B_OBJS = ${addprefix ${BONUS_DIR}, ${BONUS_SRCS:.c=.o}}

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all:	${NAME}		

$(NAME): $(OBJS)
	@echo $(CYAN) " - Compiling minilibx" $(RED)
	@make -C ${MLX_DIR}
	@echo $(CYAN) " - Compiling libft" $(RED)
	@cd $(LIBFT_DIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(GCC) $(CFLAGS) $(OBJS) $(SRCS_DIR)main.c $(IFLAGS) $(LFLAGS) -o $(NAME) $(MFLAGS)
	@echo $(GREEN) "[FINISHED OK]" $(EOC)

bonus:	${BONUS}	

$(BONUS): $(B_OBJS)
	@make -C ${MLX_DIR}
	@cd $(LIBFT_DIR) && $(MAKE)
	@echo $(PURPLE) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(B_OBJS) $(BONUS_DIR)main_bonus.c $(IFLAGS) $(LFLAGS) -o $(BONUS) $(MFLAGS) 
	@echo $(GREEN) "[OK COMPILED]" $(EOC)

clean:
	@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
	@${RM} ${OBJS}
	@${RM} ${B_OBJS}
	@${RM} -r ${OBJ_DIR}
	@make -C ${LIBFT_DIR} -f ${LIBFT_MAKE} fclean
	@make -C ${MLX_DIR} -f ${MLX_MAKE} clean

fclean: clean
	@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
	@${RM} ${OBJS} ${NAME}
	@${RM} ${B_OBJS} ${BONUS} 

re: 	fclean all

.PHONY: all clean fclean re
