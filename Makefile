# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                          :+:    :+:              #
#                                                      +:+                     #
#    By: jboeve <jboeve@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/17 12:05:02 by jboeve        #+#    #+#                  #
#    Updated: 2023/07/23 00:51:54 by joppe         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 	:= app
INCLUDE := -Iinclude 


RUN_CMD := ./$(NAME)

# CFLAGS += -Wall -Wextra -Werror
CFLAGS += -g -fsanitize=thread
# CFLAGS += -g -fsanitize=address
# CFLAGS = -g 

SRC_DIR = src
SRCS = main.c \
	   philo.c \
	   philo_action.c \
	   forks.c \
	   utils.c \
	   monitor.c \
	   free.c \
	   timer.c \
	   thread.c \
	   meuk.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

HEADER_DIR = include
HEADERS = meta.h \
		  timer.h

HEADERS := $(addprefix $(HEADER_DIR)/, $(HEADERS))

OBJ_DIR = obj
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))



all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDE) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $< 

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	$(RUN_CMD)

compile_commands: fclean
	$(MAKE) | compiledb

norm:
	norminette include src 
