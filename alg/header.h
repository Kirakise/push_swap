#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define RAZD 4294967299

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void pa(long long **from, long long **to);
void ss(long long **a, long long **b);
void sa(long long **a);
void ra(long long **a);
void rr(long long **a, long long **b);
void rra(long long **a);
void rrr(long long **a, long long **b);
int getmed(long long *a);
int getmax(long long *a);
int countitems(long long *a);
void printmas(long long *a);
char			**ft_split(char const *str, char c);
int isnum(char *s);
void parse(long long **a, int argc, char **argv);
char    *ft_substr(char const *s, unsigned int start, size_t len);
size_t  ft_strlen(const char *s);
int     checknums(long long *a, int zeroflag);
int getmedof(long long **a, int i, int j);
void sortmas(long long **a, long long **b, int sorted);
#endif