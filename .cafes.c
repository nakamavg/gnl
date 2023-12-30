
#include <stdio.h>

void	prueba(void)
{
	int		cafes0 = 100;
	static int	cafes1 = 100;

	printf("QUEDAN cafes0 = %d, cafes1 = %d\n", cafes0, cafes1);
	cafes0--;
	cafes1--;
}
int main(void)
{
	prueba();
	prueba();
	prueba();
}