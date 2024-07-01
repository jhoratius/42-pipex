NAME = pipex

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g3
#  -Werror
RM 			= rm -f
EXTS 	= .c

MAINPRE 	= src/
GNLPRE		= get_next_line/

# SRCS 		= $(addsuffix ${EXTSRCS}, \
# 							$(addprefix ${PATHSRCS},
MAINFILES =		ft_close_fds \
				ft_handle_files \
				ft_here_docs \
				ft_split \
				ft_work_pid \
				parsing \
				pipex \
				utils \

GNLFILES =		get_next_line \
				get_next_line_utils \

SRCS = $(addsuffix ${EXTS}, \
			$(addprefix ${MAINPRE}, $(MAINFILES)) \
			$(addprefix ${GNLPRE}, $(GNLFILES)) \
		)

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