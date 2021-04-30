// mac unix experience printf test
#include <stdio.h>
#include <string.h>

void	percent_test()
{
	// %
	printf("[opt]\t  [print]\t[arg]\n---------------------------------\n");
	
	printf("%%\t: |%%|\n");
	printf("%%5%%\t: |%5%|\n");
	printf("%%05%%\t: |%05%|\n");
	printf("%%-5%%\t: |%-5%|\n");
	printf("%%-05%%\t: |%-05%|\n\n");

	printf("%%1%%\t: |%1%|\n");
	printf("%%0%%\t: |%0%|\n\n");

//	printf("%%5.-5%%\t: |%5.-5%|\n");		// warning
	printf("%%5.*%%\t: |%5.*%|\t(-5)\n", -5);
	printf("%%5.%%\t: |%5.%|\n");
	printf("%%5.0%%\t: |%5.0%|\n");
	printf("%%05.3%%\t: |%05.3%|\n");
	printf("%%05.8%%\t: |%05.8%|\n");

}

void	char_test()
{
	// char
	printf("[opt]\t  [print]\t[arg]\n---------------------------------\n");

	printf("%%c\t: |%c|\n", 'a');
//	printf("%%0c\t: |%0c|\n", 'a');			// warning
	printf("%%.c\t: |%.c|\n", 'a');	
//	printf("%%.0c\t: |%.0c|\n", 'a');		// warning
//	printf("%%.5c\t: |%.5c|\n", 'a');		// warning
//	printf("%%.*c\t: |%.*c|\n", 0, 'a');	// warning
//	printf("%%.*c\t: |%.*c|\n", 3, 'a');	// warning

	printf("%%5c\t: |%5c|\n", 'a');
//	printf("%%05c\t: |%05c|\n", 'a');		// warning
	printf("%%-5c\t: |%-5c|\n", 'a');
//	printf("%%-05c\t: |%-05c|\n", 'a');		// warning
}

void	str_test()
{
	char *str = "test";
	char *null_value = 0;

	// str
	printf("[opt]\t  [print]\t[arg]\n---------------------------------\n");

	printf("%%s\t: |%s|\n", str);
	printf("%%s\t: |%s|\t(null)\n", null_value);
//	printf("%%0s\t: |%0s|\n", str);					// warning
//	printf("%%.-5s\t: |%.-5s|\n", str);				// warning
	printf("%%.*s\t: |%.*s|\t(-5)\n\n", -5, str);

	printf("%%.s\t: |%.s|\n", str);
	printf("%%.0s\t: |%.0s|\n", str);
	printf("%%5.s\t: |%5.s|\n", str);
	printf("%%5.0s\t: |%5.0s|\n\n", str);

	printf("%%.3s\t: |%.3s|\n", str);
	printf("%%.5s\t: |%.5s|\n", str);
	printf("%%.*s\t: |%.*s|\t\t(2)\n", 2, str);
}

void	int_test()
{
	// int
	printf("[opt]\t  [print]\t[arg]\n---------------------------------\n");

	printf("%%d\t: |%d|\t(10)\n", 10);
	printf("%%d\t: |%d|\t(0)\n", 0);
//	printf("%%.-5d\t: |%.-5d|\t(10)\n", 10);		// warning

	printf("%%.d\t: |%.d|\t(0)\n", 0);
	printf("%%.0d\t: |%.0d|\t(0)\n", 0);
	printf("%%5.d\t: |%5.d|\t(0)\n", 0);
	printf("%%5.0d\t: |%5.0d|\t(0)\n", 0);

	printf("%%5.d\t: |%5.d|\t(1)\n", 1);
	printf("%%5.0d\t: |%5.0d|\t(1)\n", 1);


}

void	unint_test()
{
	// unint
	printf("[opt]\t  [print]\t[arg]\n---------------------------------\n");
	
	printf("%%u\t: |%u|\t(10)\n", 10);
//	printf("%%.-5u\t: |%.-5u|\t(10)\n", 10);		// warning

	printf("%%.u\t: |%.u|\t(0)\n", 0);
	printf("%%.0u\t: |%.0u|\t(0)\n", 0);
	printf("%%5.u\t: |%5.u|\t(0)\n", 0);
	printf("%%5.0u\t: |%5.0u|\t(0)\n", 0);


}
int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (!strcmp(argv[1], "percent"))
		{
			printf("==================percent_test==================\n");
			percent_test();
		}
		else if (!strcmp(argv[1], "char"))
		{
			printf("==================char_test=====================\n");
			char_test();
		}
		else if (!strcmp(argv[1], "str"))
		{
			printf("==================str_test======================\n");
			str_test();
		}
		else if (!strcmp(argv[1], "int"))
		{
			printf("==================int_test======================\n");
			int_test();
		}
		else if (!strcmp(argv[1], "unint"))
		{
			printf("================unint_test======================\n");
			unint_test();
		}
	}
	else
	{
		printf("==================percent_test==================\n");
		percent_test();
		printf("==================char_test=====================\n");
		char_test();
		printf("==================str_test======================\n");
		str_test();
		printf("==================int_test======================\n");
		int_test();
		printf("================unint_test======================\n");
		unint_test();

	}
	return (0);
}
