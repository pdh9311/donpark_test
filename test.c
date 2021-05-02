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

	printf("%%5.-5%%\t: |%5.-5%|\n");		// warning
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
	printf("%%0c\t: |%0c|\n", 'a');			// warning
	printf("%%.c\t: |%.c|\n", 'a');	
	printf("%%.0c\t: |%.0c|\n", 'a');		// warning
	printf("%%.5c\t: |%.5c|\n", 'a');		// warning
	printf("%%.*c\t: |%.*c|\n", 0, 'a');	// warning
	printf("%%.*c\t: |%.*c|\n", 3, 'a');	// warning

	printf("%%5c\t: |%5c|\n", 'a');
	printf("%%05c\t: |%05c|\n", 'a');		// warning
	printf("%%-5c\t: |%-5c|\n", 'a');
	printf("%%-05c\t: |%-05c|\n", 'a');		// warning
}

void	str_test()
{
	char *str = "test";
	char *null_value = 0;

	// str
	printf("[opt]\t  [print]\t[arg]\n---------------------------------\n");

	printf("%%s\t: |%s|\n", str);
	printf("%%s\t: |%s|\t(null)\n", null_value);
	printf("%%0s\t: |%0s|\n", str);					// warning
	printf("%%.-5s\t: |%.-5s|\n", str);				// warning
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
	printf("%%d\t: |%d|\t(0)\n\n", 0);
	printf("%%.-5d\t: |%.-5d|\t(10)\n", 10);		// warning

	// precision is 0 && variable arg is 0 
	printf("%%.d\t: |%.d|\t(0)\n", 0);
	printf("%%.0d\t: |%.0d|\t(0)\n", 0);
	printf("%%5.d\t: |%5.d|\t(0)\n", 0);
	printf("%%5.0d\t: |%5.0d|\t(0)\n", 0);

	printf("%%5.d\t: |%5.d|\t(1)\n", 1);
	printf("%%5.0d\t: |%5.0d|\t(1)\n\n", 1);

	// precision value > numlen
	printf("%%.5d\t: |%.5d|\n", 12);
	printf("%%.9d\t: |%.9d|\n\n", 12);
	// precision value <= numlen
	printf("%%.d\t: |%.d|\n", 12345);
	printf("%%.0d\t: |%.0d|\n", 12345);
	printf("%%.*d\t: |%.*d|\n", -5, 12345);
	printf("%%.3d\t: |%.3d|\n", 12345);
	printf("%%.5d\t: |%.5d|\n\n", 12345);

	printf("%%8.5d\t: |%8.5d|\n", 12);
	printf("%%08.5d\t: |%08.5d|\n", 12);
	printf("%%08d\t: |%08d|\n\n", 12);
	printf("%%8.5d\t: |%8.5d|\n", -12);
	printf("%%08.5d\t: |%08.5d|\n",-12);
	printf("%%08d\t: |%08d|\n", -12);


}

void	unint_test()
{
	// unint
	printf("[opt]\t  [print]\t[arg]\n---------------------------------\n");
	
	printf("%%u\t: |%u|\t(10)\n", 10);
	printf("%%.-5u\t: |%.-5u|\t(10)\n", 10);		// warning

	printf("%%.u\t: |%.u|\t(0)\n", 0);
	printf("%%.0u\t: |%.0u|\t(0)\n", 0);
	printf("%%5.u\t: |%5.u|\t(0)\n", 0);
	printf("%%5.0u\t: |%5.0u|\t(0)\n", 0);

}

void	flag0_test()
{
	printf("%%05%%\t: |%%|\n");
	printf("%%05d\t: |%05d|\n", 1);
	printf("%%05i\t: |%05i|\n", 2);
	printf("%%05u\t: |%05u|\n", 3);
	printf("%%05x\t: |%05x|\n", 123);
	printf("%%05X\t: |%05X|\n\n", 123);

	printf("%%05c\t: |%05c|\n", 'a');		// warning
	printf("%%05s\t: |%05s|\n", "test");	// warning
	printf("%%05p\t: |%05p|\n", "test");	// warning

}

void	pointer_test()
{
	void	*ptr = NULL;

	printf("%%p\t: |%p|\n", 17);		// wanring
	printf("%%p\t: |%p|\n", "test");
	printf("%%.p\t: |%.p|\n", "test");
	printf("%%.0p\t: |%.0p|\n", "test");			// warning
	printf("%%.5p\t: |%.5p|\n", "test");			// warning
	printf("%%.*p\t: |%.*p|\t(5)\n", 5, "test");	// warning
	printf("%%.*p\t: |%.*p|\t(-5)\n", -5, "test");	// warning
	printf("%%020p\t: |%020p|\n", "test");			// warning
	printf("%%20p\t: |%20p|\n\n", "test");			// warning
	
	printf("%%p\t: |%p|\n", ptr);
	printf("%%.p\t: |%.p|\n", ptr);
	printf("%%8.p\t: |%8.p|\n", ptr);

}

void	hex_test()
{
	printf("%%x\t: |%x|\n", 123);
	printf("%%x\t: |%x|\n", -123);
	printf("%%.-5x\t: |%.-5x|\n", 123);			// warning
	printf("%%.*x\t: |%.*x|\n\n", -5, 123);

	printf("%%.x\t: |%.x|\t(0)\n", 0);
	printf("%%.0x\t: |%.0x|\t(0)\n", 0);
	printf("%%5.x\t: |%5.x|\t(0)\n", 0);
	printf("%%5.0x\t: |%5.0x|\t(0)\n", 0);

	printf("%%5.x\t: |%5.x|\t(1)\n", 1);
	printf("%%5.0x\t: |%5.0x|\t(1)\n\n", 1);



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
		else if (!strcmp(argv[1], "flag0"))
		{
			printf("================flag0_test======================\n");
			flag0_test();
		}
		else if (!strcmp(argv[1], "pointer"))
		{
			printf("================pointer_test====================\n");
			pointer_test();
		}
		else if (!strcmp(argv[1], "hex"))
		{
			printf("================pointer_test====================\n");
			hex_test();
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
		printf("================flag0_test======================\n");
		flag0_test();
		printf("================pointer_test====================\n");
		pointer_test();
		printf("================pointer_test====================\n");
		hex_test();

	}
	return (0);
}
