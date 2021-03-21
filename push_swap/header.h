#include <unistd.h>
#include <stdlib.h>

typedef struct s_deck{
	int value;
	int index;
	int keep;
	struct s_deck *next
}		t_deck;

void	push_back_init(t_deck *a, int val);
void	push_back(t_deck *a, t_deck *new);
void	push_fron(t_deck *a, t_deck *new);
int	checkarg(char *s);
