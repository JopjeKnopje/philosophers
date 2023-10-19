# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                          :+:    :+:              #
#                                                      +:+                     #
#    By: jboeve <jboeve@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/17 12:05:02 by jboeve        #+#    #+#                  #
#    Updated: 2023/10/19 16:12:10 by jboeve        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 	:= app
INCLUDE := -Iinclude 


RUN_CMD := ./$(NAME)

ifdef DEBUGM
	CFLAGS += -g -fsanitize=address
endif
ifdef DEBUGT
	CFLAGS += -g -fsanitize=thread
endif

# CFLAGS += -Wall -Wextra -Werror
# CFLAGS += -Wall -Wextra
# CFLAGS += -g 
# CFLAGS += -g -fsanitize=thread
# CFLAGS += -g -fsanitize=address

SRC_DIR = src
SRCS = main.c \
	   free.c \
	   parse.c \
	   philo.c \
	   forks.c \
	   libf2.c \
	   utils.c \
	   logger.c \
	   monitor.c \
	   philo_action.c \
	   meuk.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

HEADER_DIR = include
HEADERS = meta.h

HEADERS := $(addprefix $(HEADER_DIR)/, $(HEADERS))

OBJ_DIR = obj
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))



all: $(NAME)

debugt:
	make fclean
	make DEBUGT=1

debugm:
	make fclean
	make DEBUGM=1

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDE) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) Makefile 
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $< 

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	$(RUN_CMD) 5 190 60 60

runt: debugt
	$(RUN_CMD) 

runm: debugm
	$(RUN_CMD)

compile_commands: fclean
	$(MAKE) | compiledb

norm:
	norminette include src
