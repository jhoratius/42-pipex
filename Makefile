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

MANDATORY_BUILT = .mandatory_built
BONUS_BUILT = .bonus_built

all: $(NAME)

$(NAME): $(OBJSMANDAT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJSMANDAT)
	touch $(MANDATORY_BUILT)
	rm -f $(BONUS_BUILT)

bonus: $(BONUS_BUILT) 


$(BONUS_BUILT) : $(OBJSBONUS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJSBONUS)
	touch $(BONUS_BUILT)
	rm -rf $(MANDATORY_BUILT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME) $(OBJSMANDAT) $(OBJSBONUS) $(MANDATORY_BUILT) $(BONUS_BUILT)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
