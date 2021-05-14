#!/bin/bash
SRCS = $(wildcard *.c)
OBJS = $(SRCS:%.c=%.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror -g $^ -o $(NAME)
%.o: %.c
	gcc -Wall -Wextra -Werror -c -g $< -o $@
run: $(NAME)
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` && ./push_swap $$ARG | wc -l
test: $(NAME)
	res=0
	a=0 ; while [[ $$a -le 100 ]]; do \
	tmp=$$(ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` && ./push_swap $$ARG | wc -l) ;\
	res=$$(($$res+$$tmp)) ;\
	((a = a + 1)) ;\
	done ;\
	res=$$(($$res / $$a)) ;\
	echo $$res

check: $(NAME)
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` && ./push_swap $$ARG | ./checker_Mac $$ARG
vis: $(NAME)
	python3 pyviz.py `ruby -e "puts (0..100).to_a.shuffle.join(' ')"`
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
