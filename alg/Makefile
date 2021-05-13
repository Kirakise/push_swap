SRCS = $(wildcard *.c)
OBJS = $(SRCS:%.c=%.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror -g $^ -o $(NAME)
%.o: %.c
	gcc -Wall -Wextra -Werror -c -g $< -o $@

test: $(NAME)
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` && ./push_swap $$ARG | wc -l
check:
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` && ./push_swap $$ARG | ./checker_Mac $$ARG
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
