NAME = pipex

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
RM 			= rm -f
EXTSRCS 	= .c
PATHSRCS 	= src/

SRCS 		= $(addsuffix ${EXTSRCS}, \
							$(addprefix ${PATHSRCS}, \
							pipex \
				))

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(NAME) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re