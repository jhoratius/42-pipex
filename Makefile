NAME = pipex

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
RM 			= rm -f
EXTS 	=	.c

MAINBONUS 	= bonus/
MAINMANDAT	= mandatory/

GNLPRE		= get_next_line/

MANDATFILES	= 	ft_close_fds 		\
				ft_handle_errors 	\
				ft_handle_files 	\
				ft_split 			\
				ft_work_pid 		\
				parsing 			\
				pipex 				\
				utils 				\

BONUSFILES	=	ft_close_fds 		\
				ft_handle_errors 	\
				ft_handle_files 	\
				ft_here_docs 		\
				ft_split 			\
				ft_work_pid 		\
				parsing 			\
				pipex 				\
				utils 				\

GNLFILES	=	get_next_line 		\
				get_next_line_utils \

SRCSMANDAT	= $(addsuffix ${EXTS}, \
			$(addprefix ${MAINMANDAT}, $(MANDATFILES)) \
			)

SRCSBONUS	= $(addsuffix ${EXTS}, \
			$(addprefix ${MAINBONUS}, $(BONUSFILES)) \
			$(addprefix ${GNLPRE}, $(GNLFILES)) \
			)

OBJSBONUS	= $(SRCSBONUS:.c=.o)
OBJSMANDAT	= $(SRCSMANDAT:.c=.o)

all: $(NAME)

$(NAME): $(OBJSMANDAT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJSMANDAT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJSBONUS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJSBONUS)

clean:
	$(RM) $(NAME) $(OBJSMANDAT) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
