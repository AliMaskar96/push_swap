# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-mas <aait-mas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 11:22:17 by aait-mas          #+#    #+#              #
#    Updated: 2022/06/28 00:50:30 by aait-mas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CHECKER		= 	checker

CC 			=	gcc

FLAGS 		=	-Wall -Wextra -Werror

SRC_M			=	Mandatory/push_swap.c \
				Mandatory/check_args.c \
				Mandatory/linked_list_utils.c \
				Mandatory/s_p_r_rr.c \
				Mandatory/ss_rr_rrr.c \
				Mandatory/small_sort.c \
				Mandatory/big_sort1.c \
				Mandatory/big_sort2.c \
				Mandatory/big_sort_utils.c \
				Mandatory/push_swap_utils.c \
				Mandatory/small_big_index.c \

SRC_B		=	Bonus/get_next_line/get_next_line_utils.c \
				Bonus/get_next_line/get_next_line.c \
				Bonus/checker.c \
				Bonus/check_arg_bonus.c \
				Bonus/linked_list_utils.c\
				Bonus/sort_stack.c \
				Bonus/s_p_r_rr_bonus.c \
				Bonus/ss_rr_rrr_bonus.c \
				Bonus/push_swap_utils_bonus.c \
				
				
OBJS_M		=	$(SRC_M:.c=.o)

OBJS_B		=	$(SRC_B:.c=.o)

all			:	$(NAME)

bonus		:	$(CHECKER)

$(NAME)		:	$(OBJS_M)
				$(CC) $(FLAGS) $(OBJS_M) -o $(NAME)

$(CHECKER)	:	$(OBJS_B)
				$(CC) $(FLAGS) $(OBJS_B) -o $(CHECKER)
clean		:
				rm -f $(OBJS_M)
				rm -f $(OBJS_B)

fclean		:	clean
				rm -f $(NAME)
				rm -f $(CHECKER)

re			:	fclean all
