CC = gcc
NAME = foundation.a
FUNCS = f_absval\
		f_array_append\
		f_array_cmp\
		f_array_len\
		f_array_resize\
		f_bzero\
		f_dtoc\
		f_isalnum\
		f_isalpha\
		f_isascii\
		f_isdigit\
		f_isprint\
		f_iswhitespace\
		f_memalloc\
		f_memcpy\
		f_memset\
		f_putchar\
		f_putchar_fd\
		f_putendl\
		f_putnbr\
		f_putnbr_fd\
		f_putstr\
		f_stralloc\
		f_strcat\
		f_strncat\
		f_strchr\
		f_strcmp\
		f_strncmp\
		f_strcount\
		f_strcpy\
		f_strncpy\
		f_strnew\
		f_strnstr\
		f_strlen\
		f_strsplit

TEST := tests
SRCS := $(patsubst %, %.c, $(FUNCS))
OBJS := $(patsubst %.c, %.o, $(SRCS))
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(TEST): $(OBJS)
	gcc -o $(OBJS) tests.c -L. $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all