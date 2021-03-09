#include "../includes/ft_printf.h"

int main()
{
	/*
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
	printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
	ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
	printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
	ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
	printf("---------------LE VRAI-------------\n\n");
	printf("| %*.5s %.5s |\n", 10, "123", "4567");
	printf("| %*.5s %*.5s |\n", 10, "123", 10, "4567");
	printf("| %*.5s %*.5s |\n", -10, "123", 10, "4567");
	printf("| %*.5s %*.5s |\n", 10, "123", -10, "4567");
	printf("| %*.5s %*.5s |\n", -10, "123", -10, "4567");
	printf("---------------LE MIEN-------------\n\n");
	ft_printf("| %*.5s %.5s |\n", 10, "123", "4567");
	ft_printf("| %*.5s %*.5s |\n", 10, "123", 10, "4567");
	ft_printf("| %*.5s %*.5s |\n", -10, "123", 10, "4567");
	ft_printf("| %*.5s %*.5s |\n", 10, "123", -10, "4567");
	ft_printf("| %*.5s %*.5s |\n", -10, "123", -10, "4567");
	*/
	printf("|%*s|\n", 601, "12345");
	ft_printf("|%*s|\n", 601, "12456");
}
