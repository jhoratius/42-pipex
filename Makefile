NAME = pipex

CC 			= cc
CFLAGS 		= -Wall -Wextra -g3
#  -Werror
RM 			= rm -f
EXTSRCS 	= .c
PATHSRCS 	= src/

SRCS 		= $(addsuffix ${EXTSRCS}, \
							$(addprefix ${PATHSRCS}, \
							ft_close_fds \
							ft_handle_files \
							ft_split \
							ft_work_pid \
							parsing \
							pipex \
							utils \
				))

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re