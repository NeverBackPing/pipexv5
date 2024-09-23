####################### 🛠️ ##############################

CC =  cc
CFLAGS = -Wall -Werror -Wextra

####################### 🛠️ ##############################

RM = rm -rf

####################### 🤖 ##############################

NAME = pipex

######################## 📁 #############################

LIBFT = libft.a

LIBFT_DIR = libft

LIBC = libc/ft_isalpha.c libc/ft_isdigit.c libc/ft_isalnum.c libc/ft_isascii.c libc/ft_isprint.c libc/ft_strlen.c\
	libc/ft_memset.c libc/ft_bzero.c libc/ft_memcpy.c libc/ft_memmove.c libc/ft_strlcat.c libc/ft_strlcpy.c\
	libc/ft_strchr.c libc/ft_strrchr.c libc/ft_strncmp.c libc/ft_memchr.c libc/ft_strnstr.c libc/ft_toupper.c\
	libc/ft_memcmp.c libc/ft_tolower.c libc/ft_atoi.c libc/ft_calloc.c libc/ft_strdup.c\
	libc/ft_substr.c libc/ft_strjoin.c libc/ft_strtrim.c libc/ft_itoa.c libc/ft_strmapi.c libc/ft_striteri.c\
	libc/ft_putchar_fd.c libc/ft_putstr_fd.c libc/ft_putendl_fd.c libc/ft_putnbr_fd.c libc/ft_split.c\
	libc/ft_lstnew_bonus.c libc/ft_lstadd_front_bonus.c libc/ft_lstsize_bonus.c libc/ft_lstlast_bonus.c\
	libc/ft_lstadd_back_bonus.c libc/ft_lstdelone_bonus.c libc/ft_lstclear_bonus.c libc/ft_isspace.c\
	libc/ft_lstiter_bonus.c libc/ft_lstmap_bonus.c libc/ft_atol.c libc/ft_signe.c libc/ft_isdigitsigne.c\
	libc/ft_strtok.c libc/ft_strcat.c libc/ft_strcmp.c

LIBFT_OBJS = $(LIBC:.c=.o)

######################## 📁 #############################

PRINTF = libftprintf.a

PRINTF_DIR = printf

PRINTF_SRC =  printf/ft_converse_base.c printf/ft_hexa_base.c printf/size_hexa.c\
	printf/ft_hexa_lower.c  printf/ft_putchar.c printf/ft_putnbr.c printf/ft_printf.c\
	printf/ft_print_usigned.c printf/ft_putstr.c printf/ft_swap.c

PRINTF_OBJS = $(PRINTF_SRC:.c=.o)

######################## 📁 #############################

GNL = get_next_line.a

GNL_DIR = gnl

GNL_SRC = gnl/get_next_line_utils.c gnl/get_next_line.c

GNL_OBJS = $(GNL_SRC:.c=.o)

######################## 📁 #############################

SRC = srcs/main.c srcs/cmd.c srcs/cmd_utils.c srcs/error_system.c srcs/exec.c\
	srcs/exit.c srcs/fd.c srcs/fd_utils.c srcs/file_error.c srcs/fork.c srcs/pipe_utils.c\
	srcs/cmd_tool.c

SRCS = ${SRC} ${LIBC} ${PRINTF_SRC} ${GNL_SRC}

OBJS = $(SRCS:.c=.o)

######################## 📁 #############################

BONUS_SRC = bonus/pipex_bonus.c bonus/return_bonus.c bonus/heredoc_bonus.c bonus/fd_bonus.c\
	bonus/cmd_bonus.c bonus/exec_bonus.c bonus/pipex_bonus_utils.c bonus/error_bonus.c

BONUS_SRCS = ${BONUS_SRC} ${LIBC} ${PRINTF_SRC} ${GNL_SRC}

#patsubst
OBJS_B = $(BONUS_SRCS:.c=.o)

######################## 🧠 #############################

INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR)

######################## 🎨 #############################

BLUE	=	\033[0;34m
GREEN	=	\033[0;32m
RED		=	\033[31m
RESET	=	\033[0m
YELLOW	=	\033[0;33m

define HEADER

██████╗ ██╗██████╗ ███████╗██╗  ██╗
██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝
██████╔╝██║██████╔╝█████╗   ╚███╔╝
██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗
██║     ██║██║     ███████╗██╔╝ ██╗
╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝
endef
export HEADER

define HEADER_BONUS

██████╗ ██╗██████╗ ███████╗██╗  ██╗    ██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗
██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝    ██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝
██████╔╝██║██████╔╝█████╗   ╚███╔╝     ██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗
██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗     ██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║
██║     ██║██║     ███████╗██╔╝ ██╗    ██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║
╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝

endef
export HEADER_BONUS

######################## 🗃️ #############################

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

######################## 🎶🎹 ############################

all:  $(LIBFT) $(PRINTF) $(GNL) $(NAME) header

bonus: $(LIBFT) $(PRINTF) $(GNL) $(OBJS_B) header_bonus
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_B) $(LIBFT) $(PRINTF) $(GNL) -L. -lft -lftprintf -o $(NAME)
	@echo "$(RED)$$HEADER_BONUS$(RESET)"

$(LIBFT): $(LIBFT_OBJS)
		ar rcs $(LIBFT) $(LIBFT_OBJS)

$(PRINTF): $(PRINTF_OBJS)
		ar rcs $(PRINTF) $(PRINTF_OBJS)

$(GNL): $(GNL_OBJS)
		ar rcs $(GNL) $(GNL_OBJS)

header:
	@echo "$(RED)$$HEADER$(RESET)"

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL)
	 $(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(PRINTF) $(GNL) -L. -lft -lftprintf -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B) $(LIBFT_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

fclean: clean
	$(RM) $(LIBFT) $(PRINTF) $(GNL) $(NAME)

re: fclean all

.PHONY: all  clean fclean bonus header header_bonus re