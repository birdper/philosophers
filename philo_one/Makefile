NAME			:= philo_one

SOURCE_DIRS		:= . src bin

VPATH			:= $(SOURCE_DIRS)

C_FLAG			:=

HEADER			:= philo_one.h

SRCS			:= \
				main.c				\
				parse.c				\
				ft_isdigit.c		\
				ft_atoi.c			\
				ft_itoa.c			\
				ft_putnbr_fd.c		\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_strlen.c			\
				ft_strdup.c			\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				is_notnumber.c		\
				philo_one_utils.c	\
				start_dinner.c		\
				monitoring.c		\

OBJ				:= $(SRCS:c=o)




%.o:	%c -I$(INCLUDES)/$(HEADEARS)
	gcc $(C_FLAG) -c $< -o $@



all: $(NAME)


$(NAME):	$(OBJ)
	gcc $(C_FLAG) $^ -o $(NAME)
	#gcc $(C_FLAG) -ggdb -fsanitize=address -fno-omit-frame-pointer -g $^ -o $(NAME)



clean:
	rm -f $(OBJ)


fclean:		clean
	rm -f $(NAME)


re: fclean all


.PHONY:			clean fclean re