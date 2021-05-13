#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void pa(int **from, int **to);
void ss(int **a, int **b);
void sa(int **a);
void ra(int **a);
void rr(int **a, int **b);
void rra(int **a);
void rrr(int **a, int **b);
int getmed(int *a);
int getmax(int *a, int regime);
int countitems(int *a);
void printmas(int *a);
void	*ft_memmove(void *to, void *from, size_t len);
#endif