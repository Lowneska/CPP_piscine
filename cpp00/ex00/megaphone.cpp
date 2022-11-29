#include <iostream>
#include <string.h>

void    strCapitalize(char *str)
{
    int i = 0;
    int length = strlen(str);

    while (i < length)
    {
        std::cout << (char)toupper(str[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i = 1;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (i < argc)
		{
			strCapitalize(argv[i]);
			i++;
		}
		std::cout << std::endl;
    }
    return (0);
}