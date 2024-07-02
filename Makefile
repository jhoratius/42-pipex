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










# ------------------------------------------------------------------------------------------------------------- >
# 
# 				████████╗███████╗░██████╗████████╗███████╗██╗░░░██╗██████╗░
# 				╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝██║░░░██║██╔══██╗
# 				░░░██║░░░█████╗░░╚█████╗░░░░██║░░░█████╗░░██║░░░██║██████╔╝
# 				░░░██║░░░██╔══╝░░░╚═══██╗░░░██║░░░██╔══╝░░██║░░░██║██╔══██╗
# 				░░░██║░░░███████╗██████╔╝░░░██║░░░███████╗╚██████╔╝██║░░██║
# 				░░░╚═╝░░░╚══════╝╚═════╝░░░░╚═╝░░░╚══════╝░╚═════╝░╚═╝░░╚═╝

# 	COPY PASTE ALL OF THIS SOMEWHERE IN YOUR MAKEFILE

# 	MAKE SURE THE NAME OF THE PROJECT IS: pipex
# 	IF YOUR BONUS ISNT: pipex_bonus, change that below
#

# 	AVAILABLE: (see desccription below)
# 	make m
# 	make b

NAMEE = pipex
NAMEE_BONUS = pipex_bonus

files:
	@rm -f $(INFILE) $(OUTFILE) $(OUTFILE_OK) bad_outfile bad_outfile_2
	@rm -f
	@touch $(INFILE)


# 	TESTING bonus with heredoc
#
b: $(NAMEE_BONUS)
	@$(call random_shmol_cat, teshting ... $(word 1, $^)! (stops with END), "repeat several times to see if it append correctly", $(CLS)\n, )
	-$(VALGRIND) ./$(word 1, $^) here_doc END $(ARGS3) $(OUTFILE)
	@echo "\n\tOutfile content:"
	@cat $(OUTFILE)


# 	TESTING several BAD cases scenario, and others break tests, with valgrind (most of the time)
# 		replace the first dependency $(NAMEE) with your $(NAME_BONUS) to test bonus (without heredoc)
# 
m: $(NAMEE) files
	$(call mandatory,  "wc -c" "wc -c" "wc -c" "wc -c", wc -c | wc -c | wc -c | wc -c, $(VALGRIND), $(CLS))
	$(call mandatory,  "wc -c" "wc -c", wc -c | wc -c, $(VALGRIND), $(CLS))
	$(call mandatory,  "ls -la" "/path/to/abc -a", ls -la | /path/to/abc -a, , $(CLS))
	$(call mandatory,  "ls -la" "path_to_troll -la", ls -la | path_to_troll -a, , $(CLS))
	$(call mandatory,  "ls -la", ls -la, , $(CLS))
	@$(call random_shmol_cat, "teshting with bad_infile、chmod..", "$(word 1, $^):", $(CLS), )
	-$(VALGRIND) ./$(word 1, $^) bad_infile $(ARGS2) bad_outfile
	@echo
	< bad_infile $(BASH2) > bad_outfile_2
	@echo "\n\t\033[5m~ Press Enter to continue...\033[0m"; \
 	read -p "" key
	@echo "$(CLS)\033[0m\033[38;5;1m"
	chmod 000 $(INFILE)
	@echo "\033[0m"
	$(call mandatory,  "ls -la" "wc -l", ls -la | wc -l, , );
	chmod 777 $(INFILE)
	$(call mandatory,  "ls -la" "cat", ls -la | cat, , );
	@$(call random_shmol_cat, "teshting without environement variables..", "$(word 1, $^):", $(CLS), )
	-env -i /bin/$(VALGRIND) ./$(word 1, $^) $(INFILE) $(ARGS2) $(OUTFILE);


# $(ARGS2) $(BASH2) $(VALGRIIND) $(CLS)
define mandatory
	@$(call random_shmol_cat, teshting ... $(word 1, $^): !, "$(1)", $(4), )
	-$(3) ./$(word 1, $^) $(INFILE) $(1) $(OUTFILE)
	@$(call random_shmol_cat, teshting: $(2), cat outputs should be identical:, , )
	-< $(INFILE) $(2) > $(OUTFILE_OK)
	@echo "\n\t\033[4mYour Outfile content\033[24m:"
	@cat $(OUTFILE)
	@echo "\n\t\033[4mBASH Outfile content\033[24m:"
	@cat $(OUTFILE_OK)
	@echo "\n\t\033[5m~ Press Enter to continue...\033[0m"; \
 	read -p "" key
endef
# ---------------------------------------------------------------------- >
INFILE = in_file
OUTFILE = out_file
OUTFILE_OK = out_file_ok

ARGS2 = "ls -la" "wc -l"
BASH2 = ls -la | wc -l

ARGS3 = "cat" "cat"
# ---------------------------------------------------------------------- >
# ------------------------------------------------------------------------------------------------------------- >
# @$(call random_shmol_cat, text 1, text 2, $(CLS), $(RESET));
# $(1)= $(CLEAR); $(2)= text1; $(3)= text2; $(4)= $(RESET)
define random_shmol_cat
	COLOR=$$(printf "\033[38;5;%dm" $$(shuf -i 1-255 -n 1)); \
	COLOR2=$$(printf "\033[38;5;%dm" $$(shuf -i 0-255 -n 1)); \
	echo "$(3)$${COLOR2}\
	\tにゃ~$${COLOR}\t⠀╱|、\n\
	\t\t(˚ˎ。7⠀⠀⠀$${COLOR2}~ $(1) ~$${COLOR}\n\
	\t\t⠀|、˜\\\\\t\t$${COLOR2}~ $(2)$${COLOR}\n\
	\t\t⠀じしˍ)ノ\n$(4)"
endef

CLS = \033[2J\033[H
RESET = \033[0m
# - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - -  - VALGRIIND
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --trace-children=yes --track-fds=yes
# ------------------------------------------------------------------------------------------------------------- >