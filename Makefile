# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 11:40:51 by tdharmar          #+#    #+#              #
#    Updated: 2025/11/19 19:17:13 by tdharmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	push_swap
BONUS_NAME		:=	checker

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror

INC_DIR			:=	includes/	
SRC_DIR			:=	srcs/

SRCS_FILES		:=	stack/stack_behav.c 		stack/stack_utils.c \
					sort/push_swap_main.c		sort/push_swap_operation.c \
					sort/sort_utils.c   		sort/sort_case.c \
					sort/sort_general_utils.c 	sort/sort_general_calc_fst.c  sort/sort_general_calc_snd.c \
					other/ft_utilities.c \
					main.c

SRCS			:=	$(SRCS_FILES:%.c=$(SRC_DIR)%.c)
OBJS			:=	$(SRCS:%.c=%.o)

UTILS_OBJS		:=	$(filter-out $(SRCS_DIR)main.o, $(OBJS))

BONUS_DIR		:=	bonus/
BONUS_FILES		:=	main.c

BONUS			:=	$(BONUS_FILES:%.c=$(BONUS_DIR)%.c)
BONUS_OBJS		:=	$(BONUS:%.c=%.o)

all: $(NAME) Makefile

$(NAME): $(OBJS) Makefile
	@make -C libft
	@cp libft/libft.a .
	${CC} ${CFLAGS} -I${INC_DIR} ${OBJS} libft.a -o $@

$(OBJS): %.o:%.c
	${CC} ${CFLAGS} -I${INC_DIR} -c $< -o $@

clean:
	rm -rf ${OBJS}
	rm -rf ${BONUS_OBJS}
	rm -rf ${UTILS_OBJS}
	@make -C libft clean

fclean: clean
	rm -f ${NAME}
	rm -rf libft.a
	rm -rf ${BONUS_NAME}
	@make -C libft fclean

re: fclean all

bonus:	$(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(UTILS_OBJS) Makefile
	@make -C libft
	@cp libft/libft.a .
	${CC} ${CFLAGS} -I${INC_DIR} $(BONUS_OBJS) $(UTILS_OBJS) libft.a -o $@

$(BONUS_OBJS): %.o : %.c
	$(CC) $(CFLAG) -I$(INC_DIR) -c $< -o $@

.PHONY: all clean fclean re