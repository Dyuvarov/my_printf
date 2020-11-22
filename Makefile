
NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = src

DIR_BS = src_bonus

INCLUDES = -I includes/ -I libft/

B_INCLUDES = -I includes_bonus/ -I libft/

SOURCES = ft_printf.c \
		  tools.c \
		  tools2.c \
		  parse.c \
          parse_flags.c \
          parse_width.c \
          parse_accuracy.c\
          parse_type.c\
          handler.c\
          handle_char.c\
          handle_string.c\
          handle_hex.c\
          handle_upper_hex.c\
          handle_pointer.c\
          handle_percent.c\
          handle_int.c\
          handle_uint.c

BONUS_SOURCES = ft_printf_bonus.c \
                tools_bonus.c \
                tools2_bonus.c \
                parse_bonus.c \
                parse_flags_bonus.c \
                parse_width_bonus.c \
                parse_accuracy_bonus.c\
                parse_type_bonus.c\
                handler_bonus.c\
                handle_char_bonus.c\
                handle_string_bonus.c\
                handle_hex_bonus.c\
                handle_upper_hex_bonus.c\
                handle_pointer_bonus.c\
                handle_percent_bonus.c\
                handle_int_bonus.c\
                handle_uint_bonus.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

B_SRCS = $(addprefix $(DIR_BS)/,$(BONUS_SOURCES))

OBJS = $(SOURCES:.c=.o)

B_OBJS = $(BONUS_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

bonus: $(B_OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(B_OBJS)
	@ranlib $(NAME)


%.o: $(DIR_S)/%.c
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

%.o: $(DIR_BS)/%.c
	gcc $(FLAGS) $(B_INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -f $(B_OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY:	all clean fclean re bonus