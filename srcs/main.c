#include <stdio.h>
#include "../includes/ft_printf.h"
#include <limits.h>


int		main(void)
{
	char c = 'm';
	char *str = "Hello World !";
	char	*test = NULL;
	/*ft_printf("\n-------------- %% --------------\n\n");
	printf("test vrai printf %% avec width de 15 : %15%\n");
	ft_printf("test %% avec width de 15 : %15%\n");
	printf("test vrai printf %% avec width de 15 et 0 : %015%\n");
	ft_printf("test %% avec width de 15 et 0 : %015%\n");
	ft_printf("Test ft_printf\n");
	printf("------------------ %%c -----------------\n\n");
	
	printf("Vrai : |%c|\n", c);
	ft_printf("%c", c);
	printf("\nVrai : |%c|\n", c);
	ft_printf("Faux : |%c|\n", c);
	printf("|%-----5c|\n", -2147483648);
	ft_printf("|%-----5c|\n", -2147483648);
	printf("Vrai : |%15c|\n", c);
	ft_printf("|%15c|\n", c);
	printf("Vrai : |%-15c|\n", c);
	ft_printf("|%-15c|\n", c);
	printf("Vrai : |%015c|\n", c); //undefined
	ft_printf("undefined : |%015c|\n", c);
	printf("Vrai : |%0-15c|\n", c); //undefined
	ft_printf("undefined : |%0-15c|\n", c);
	printf("Vrai : |%-*c|\n", 15, c);
	ft_printf("|%-*c|\n", 15, c);
	printf(" Ici Vrai : |%-*c|\n", -15, c);
	ft_printf("|%-*c|\n", -15, c);
	printf("Vrai : |%0*c|\n", 15, c); //undefined
	ft_printf("undefined : |%0*c|\n", 15, c);
	printf("Vrai : |%15.3c|\n", c); //undefined
	ft_printf("undefined : |%15.3c|\n", c);
	printf("Vrai : |%-2.5c|\n", c); //undefined
	ft_printf("undefined : |%-2.5c|\n", c);
	printf("Vrai : |%*.*c|\n", 10, 4, c); //undefined
	ft_printf("undefined : |%*.*c|\n", 10, 4, c);
	printf("Vrai : |%.4c|\n", c); //undefined
	ft_printf("undefined : |%.4c|\n", c);
	printf("Vrai : |%4.c|\n", c);
	ft_printf("|%4.c|\n", c);
	printf("Vrai : |%.c|\n", c);
	ft_printf("|%.c|\n", c);
	printf("Vrai : |%12c| |%4c|\n", c, c);
	ft_printf("|%12c| |%4c|\n", c, c);
	printf("Vrai |%-15c|\n", 0);
	ft_printf("|%-15c|\n", 0);
	printf("|%0*c|\n", -15, -2147483648);
	ft_printf("|%0*c|\n", -15, -2147483648);
	*/
	printf("\n---------------- %%s -----------------\n\n");
	/*printf("test vrai printf sans flags : |%s|\n", str);
	ft_printf("Test  sans flags : |%s|\n", str);
	printf("Test vrai printf  avec width de 1 : |%1s|\n", str);
	ft_printf("Test avec width de 1 : |%1s|\n", str);
	printf("Test vrai printf  avec width de 14 : |%14s|\n", str);
	ft_printf("Test  avec width de 14 : |%14s|\n", str);
	printf("Test vrai printf  avec width de 0 : |%0s|\n", str);
	ft_printf("Test  avec width de 0 : |%0s|\n", str);
	printf("Test vrai printf  avec - et width de 18 : |%-18s|\n", str);
	ft_printf("test  avec - et width de 18 : |%-18s|\n", str);
	printf("test avec width de 15, precision de 0: |%15.0s|\n", str);
	ft_printf("test avec width de 15, precision de 0: |%15.0s|\n", str);
	printf("test avec width de 15, precision de 6, str NULL : |%15.6s|\n", test);
	ft_printf("test avec width de 15, precision de 6, str NULL : |%15.6s|\n", test);
	printf("test int de base juste pour voir l'itoa : |%d\n", 2147483647);
	ft_printf("test int de base juste pour voir l'itoa : |%d\n", 2147483647);
*/
	printf("precision de 0, no args le vrai : |%.d|\n", 0);
	ft_printf("precision de 0, no args le mien: |%.d|\n", 0);
	/*
	ft_printf("width de 15, precision de -6, int min le vrai : |%0*.*d|\n", 15, -6, INT_MIN);
		printf("Test vrai printf %%s avec 0 * et width de 18 : |%0*s|\n", 18, str);
	ft_printf("test %%s avec 0 * et width de 18 : |%0*s|\n", 18, str);
	printf("Test vrai printf %%s avec 0 * et width de 4 : |%0*s|\n", 4, str);
	ft_printf("test %%s avec 0 * et width de 4 : |%0*s|\n", 4, str);
	printf("test vrai printf %%s avec precision : |%.s|\n", str);
	ft_printf("test %%s avec precision : |%.s|\n", str);
	printf("Test vrai printf %%s avec 0 * : |%0*s|\n", -15, str);
	ft_printf("Test %%s avec 0 * : |%0*s|\n", -15, str);
//	printf("Test %%s avec - et 2 * et precision : |%0-*.*s|\n", 0, 0, (null));
	printf("Test vrai printf : |%0*s|\n", -15, str);
	printf("Test vrai printf : |%-.*s|\n", 0, str);
	ft_printf("Test %%s : |%-.*s|\n", 0, str);// Warning does NOT WORKING
	printf("Test avec vrai printf : |%-*.*s|\n", 15, 0, test);
	ft_printf("Test %%s avec width de 1 : %1s\n", str);
	ft_printf("Test %%s avec width de 14 : %14s\n", str);
	ft_printf("Test %%s avec width de 0 : %0s\n", str);
	ft_printf("test %%s avec - et width de 18 : %-18s\n", str);
	ft_printf("test %%s avec 0 * et width de 18 : %0*s\n", 18, str);
	ft_printf("test %%s avec 0* et width de 4 : %0*s\n", 4, str);
	printf("test vrai printf %%s avec precision 22.4 : %22.4s\n", str);
	ft_printf("test %%s avec precision de 22.4 : %22.4s\n", str);
	printf("test vrai printf %%s avec precision de 22.4 et 0 : %022.4s\n", str);
	ft_printf("test %%s avec precision de 22.4 et 0 : %022.4s\n", str);
	printf("Vrai : |%s|\n", "Coco Toto");
	ft_printf("|%s|\n", "Coco Toto");
	/*
	ft_printf("\n-------------- %%p ------------\n\n");
	ft_printf("test %%p : %p\n", &str);
	printf("test vrai printf %%p : %p\n", &str);
	ft_printf("test %%p avec width de 16 : %16p\n", &str);
	printf("test vrai printf %%p avec width de 16 : %16p\n", &str);
	ft_printf("Faux test %%p avec width de 8 : %8p\n", &str);
	printf("test vrai printf %%p avec width de 8 : %8p\n", &str);
	ft_printf("Faux test %%p avec * et width de 22 : %*p\n", 22, &str);
	printf("test vrai printf %%p avec * et width de 22 : %*p\n", 22, &str);
	printf("Vrai precision 22.4: |%22.4p|\n", &str);
	ft_printf("Faux precision 22.4: |%22.4p|\n", &str);
	printf("Vrai precision 22.0: |%22.0p|\n", &str);
	ft_printf("Faux precision 22.0: |%22.0p|\n", &str);
	printf("Vrai precision 22.20: |%22.20p|\n", &str);
	ft_printf("Faux precision 22.20: |%22.20p|\n", &str);
	printf("Vrai : |%020.15p|\n", &str);
	ft_printf("Faux : |%020.15p|\n", &str);
	//printf("test vrai printf %%p |%*.*p|\n", &str);
	printf("Vrai : |%015p|\n", &str);
	ft_printf("Faux : |%015p|\n", &str);
	printf("Vrai : |%.20p|\n", &str);
	ft_printf("Faux : |%.20p|\n", &str);
	printf("Vrai : |%15.20p|\n", &str);
	ft_printf("Faux : |%15.20p|\n", &str);
	printf("Vrai : |%.p|\n", '\0');
	ft_printf("Faux : |%.p|\n", '\0');
	printf("\n----------------- %%i-d -----------\n\n");
	printf("test vrai printf %%d : |%15d|\n", 2147483647);
	ft_printf("test %%d : |%15d|\n", 2147483647);
	printf("test vrai printf %%d : |%.20d|\n", 2147483647);
	ft_printf("test %%d : |%.20d|\n", 2147483647);
	printf("test vrai printf %%i : %i\n", -123476);
	ft_printf("test %%i : %i\n", -123476);
	printf("test vrai printf %%d avec width de 22 : %22d\n", 12345678);
	ft_printf("test %%d avec width de 22 : %22d\n", 12345678);
	printf("test vrai printf %%d avec precision 22.4 : %22.4d\n", 12345678);
	ft_printf("test %%d avec precision 22.4 : %22.4d\n", 12345678);
	printf("test vrai printf %%i avec precision |%22.12d|\n", 2147483647);
	ft_printf("test %%i avec precision |%22.12d|\n", 2147483647);
	printf("test vrai printf %%d avec precision 15.20 |%15.20d|\n", 2147483647);
	ft_printf("test %%d avec precision 15.20 |%15.20d|\n", 2147483647);
	printf("test vrai printf %%i : |%*d|\n", -15, 2147483647);
	ft_printf("test %%d : |%*d|\n", -15, 2147483647);
	printf("test vrai printf %%d : |%.0d|\n", 0);
	ft_printf("test %%d : |%.0d|\n", 0);
	printf("Test vrai printf %%d : |%.d|\n", 2147483647);
	ft_printf("Test %%d : |%.d|\n", 2147483647);
	printf("test vrai printf %%d precision 15.0 : |%15.0d|\n", 2147483647);
	ft_printf("test %%d precision 15.0 : |%15.0d|\n", 2147483647);
	printf("Vrai : |%d|\n", -2147483648);
	ft_printf("Faux : |%d|\n", -2147483648);
	printf("Vrai : |%-0*.*i|\n", 0, -6, 0);
	ft_printf("Faux : |%-0*.*i|\n", 0, -6, 0);
	printf("Vrai : |%.3i|\n", 0);
	ft_printf("|%.3i|\n", 0);
	printf("Vrai : |%.20d|\n", -2147483648);
	ft_printf("Faux : |%.20d|\n", -2147483648);
	printf("Vrai : |%.6i|\n", -3);
	ft_printf("Faux : |%.6i|\n", -3);
	ft_printf("\n------------------ %%u ---------------------\n\n");
	printf("Vrai : |%015u|\n", 2147483647);
	ft_printf("Faux : |%015u|\n", 2147483647);
	printf("Vrai : |%0*.*u|\n", 15, 0, 2147483647);
	ft_printf("Faux : |%0*.*u|\n", 15, 0, 2147483647);
	printf("Vrai : |%0*.*u|\n", 15, 6, 0);
	ft_printf("Faux : |%0*.*u|\n", 15, 6, 0);
	ft_printf("\n----------------- %%xX -----------------------\n");
	printf("vrai : |%*.22x|\n", 15, 2147483647);
	ft_printf("Faux : |%*.22x|\n", 15, 2147483647);
	ft_printf("%");
	ft_printf("\n%d", ft_printf("%"));
	printf("|%c|\n", 0);
	ft_printf("|%c|\n", 0);

	ft_printf("\n\n--------------- Cas qui ne marchent pas encore... ---------------------------\n\n");
	printf("Vrai flags %%9.2: |%9.2d|\n", UINT_MAX);
	ft_printf("Faux flags %%9.2: |%9.2d|\n", UINT_MAX);
	printf("Vrai : %%09.1: |%09.1d|\n", UINT_MAX + 1);
	ft_printf("Faux %%09.1: |%09.1d|\n", UINT_MAX + 1);
	ft_printf("\n\n------------------- Bonus ------------------------------------\n\n");
	printf("Vrai %% u : |% u|\n", 12);
	ft_printf("Faux %% u : |% u|\n", 12);
	printf("Vrai %%+u : |%+u|\n", 4765);
	ft_printf("Faux %%+u : |%+u|\n", 4765);
	printf("Vrai %% d : |% d|\n", 4765);
	ft_printf("Faux %% d : |% d|\n", 4765);
	printf("Vrai : %%+020d |%+020d|\n", 2147483647);
	ft_printf("Faux : %%+020d : |%+020d|\n", 2147483647);
	printf("Vrai : %%+20d : |%+20d|\n", -765);
	ft_printf("Faux : %%+20d : |%+20d|\n", -765);
	printf("Vrai %%-0+*.*d 0 0 :|%-0+*.*d|\n", 0, 0, 0);
	ft_printf("Faux %%-0+*.*d 0 0 : |%-0+*.*d|\n", 0, 0, 0);
	printf("Vrai %%0 -15.6d : |%0 -15.6d|\n", 0);
	ft_printf("Faux : %%0 -15.6d : |%0 -15.6d|\n", 0);
	printf("Vrai %%-0+15.d : |%-0+15.d|\n", 0);
	ft_printf("Faux %%-0+15.d : |%-0+15.d|\n", 0);
	*/
	return 0;
}
