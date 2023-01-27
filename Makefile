# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 14:13:55 by dbraga-b          #+#    #+#              #
#    Updated: 2023/01/20 14:13:59 by dbraga-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
LIBFT = ./libft.a
CFLAGS = -Wall -Wextra -Werror

PUSH = push_swap
SRC_PUSH = src/push_swap.c src/instructions.c src/operations/oppush.c src/operations/oprevrotate.c src/operations/oprotate.c src/operations/opswap.c src/main.c
OBJ_PUSH = $(SRC_PUSH:.c=.o)


all: $(PUSH)

$(LIBFT):
		$(MAKE) -C ./libft

$(PUSH): $(OBJ_PUSH) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ_PUSH) $(LIBFT) -o push_swap

clean:
		$(MAKE) clean -C ./libft
		$(RM) $(OBJ_PUSH)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(PUSH)

re: fclean all

