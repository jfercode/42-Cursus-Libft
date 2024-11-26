#include "../include/libft.h"

// Prototipos de funciones

void check_ft_isalpha() 
{
	int	i;
	i = 'A';

	printf("isalpha: %d || ", isalpha(i));
	printf("ft_isalpha: %d\n", ft_isalpha(i));
	
}

void check_ft_isdigit()
{
	int	i; 
	i = '2';

	printf("isdigit: %d || " , isdigit(i));
	printf("ft_isdigit: %d\n", ft_isdigit(i));
}

void check_ft_isalnum()
{
	int	i;
	i = '9';

	printf("isalnum: %d\n", isalnum(i));
	printf("ft_isalnum: %d\n", ft_isalnum(i));
}

void check_ft_isascii()
{
	int	i;
	i = 58;

	printf("isascii: %d ||", isascii(i));
	printf("ft_isascii: %d\n", ft_isascii(i));
	
}

void check_ft_isprint()
{
	int	i;
	i = 11;

	printf("isprint: %d ||", isascii(i));
	printf("ft_isprint: %d\n", ft_isascii(i));
	
}

void check_ft_toupper()
{
	int	c;

	c = 'c';
	printf("toupper - %d is %d || ", c, toupper(c));
	printf("ft_toupper - %d is %d\n", c, ft_toupper(c));
}

void check_ft_tolower()
{
	int c;

	c = 'I';

	printf("tolower: %d s %d ||", c, tolower(c));
	printf("ft_tolower: %d is %d\n", c, ft_tolower(c));
}

void check_ft_strncmp()
{
	const char *s1 = "Hello";
	const char *s2 = "Hella";

	printf("comparation %s & %s is %d\n", s1, s2, ft_strncmp(s1, s2, 5));
}

void check_ft_memcmp()
{
	const char *s1;
	const char *s2;
	size_t n;

	s1 = "-1";
	s2 = "+1";
	n = 30;
	if (ft_memcmp(s1, s2, n))
		printf("%s and %s are not equals\n", s1, s2);
	else 
		printf("%s and %s are equals\n", s1, s2);
}

void check_ft_atoi()
{
	const char* n;

	n = "   -12345*6";
	printf("%s -> atoi: %d || ", n, atoi(n));
	printf("ft_atoi: %d\n", ft_atoi(n));  
}

void check_ft_strlen()
{
	const char *str;
	str = "Sol";
	printf("%s-> strlen: %lu || ",str, strlen(str));
	printf("ft_strlen: %lu\n", ft_strlen(str));	
}

void check_ft_strlcpy()
{
	const char *src = "Hello World!";
	char dst[50];
	size_t sol;

	printf("dst: %s && src: %s || ", dst, src);
	sol = ft_strlcpy(dst, src, sizeof(dst));	
	if(sol)
		printf("dst after ft_srtlcpy: %s || ft_strlcpy result: %zu\n", dst,sol);
	else
		printf("dst error");
}

void check_ft_strlcat()
{
	const char *src = "World!";
    char dst[15] = "Hello, ";

    printf("dst before ft_strlcat: '%s' || ", dst);
    size_t sol = ft_strlcat(dst, src, sizeof(dst));
    printf("dst after ft_strlcat: '%s'\n", dst);
    printf("needed length: %zu\n", sol);
}
void check_ft_memset()
{
	char str[20] = "ABCDE";
	printf("Str: %s || ", str);
	memset(str, 'X', 5);
	printf("Str memset  X: %s || ", str);
	ft_memset(str, 'Y', 5);
	printf("Str ft_memset Y: %s\n", str);

}

void check_ft_memcpy()
{
	char *src;
	char dest[50];

	src = "Hello World!";
	printf("dest bfr memcpy: %s || ", dest);
	memcpy(dest, src, 5);
	printf("dest aftr memcpy: %s || ", dest);
	bzero(dest, 50);
	printf("dest bfr ft_memcpy: %s || ", dest);
	ft_memcpy(dest, src, 5);
	printf("dest aftr ft_memcpy: %s\n", dest);
}

void check_ft_memmove()
{
   char src1[] = "Hello, World!";
    char dest1[50];

    printf("Before ft_memmove: dest1 = '%s' || ", dest1);
    ft_memmove(dest1, src1, strlen(src1) + 1);
    printf("After ft_memmove: dest1 = '%s'\n", dest1);

    // Test case 2: Overlapping regions (src before dest)
    char overlap1[] = "1234567890";
    printf("Before ft_memmove (overlap): %s || ", overlap1);
    ft_memmove(overlap1 + 2, overlap1, 5);
    printf("After ft_memmove (overlap): %s\n", overlap1); // Should be "1212345670"

    // Test case 3: Overlapping regions (dest before src)
    char overlap2[] = "abcdefghij";
    printf("Before ft_memmove (overlap): %s || ", overlap2);
    ft_memmove(overlap2, overlap2 + 2, 8);
    printf("After ft_memmove (overlap): %s\n", overlap2);	
}

void check_ft_memchr()
{
	char arr[] = "Hello, world!";
    char ch = 'o';
    size_t num_bytes = sizeof(arr);
    char *result = ft_memchr(arr, ch, num_bytes);
   	
	printf("str: %s || ", arr);
    if (result != NULL) 
        printf("Character '%c' found at position: %ld\n", ch, result - arr);
    else
        printf("Character '%c' not found in the array.\n", ch);

}
void check_ft_calloc()
{
	int *array_ft;
    int *array_std;
    int num_elements = 5;

    // Using ft_calloc to allocate memory for 5 integers
    array_ft = (int *)ft_calloc(num_elements, sizeof(int));

    if (array_ft == NULL) {
        printf("Memory allocation failed for ft_calloc.\n");
    }

    // Using calloc from standard library to allocate memory for 5 integers
    array_std = (int *)calloc(num_elements, sizeof(int));

    if (array_std == NULL) {
        printf("Memory allocation failed for calloc.\n");
        free(array_ft);
    }

    // Printing the values of the allocated arrays
    printf("Values in array (allocated using ft_calloc):\n");
    for (int i = 0; i < num_elements; i++) {
        printf("array_ft[%d] = %d\n", i, array_ft[i]);
    }

    printf("Values in array (allocated using calloc):\n");
    for (int i = 0; i < num_elements; i++) {
        printf("array_std[%d] = %d\n", i, array_std[i]);
    }

    // Comparing the memory content of both arrays
    if (memcmp(array_ft, array_std, num_elements * sizeof(int)) == 0) {
        printf("Both arrays have identical memory content.\n");
    } else {
        printf("The memory content of both arrays differs.\n");
    }

    // Freeing the allocated memory
    free(array_ft);
    free(array_std);
}

void check_ft_bzero()
{
	char str01[50] = "Hello World!";
	char str02[50] = "Hello World!";

    printf("Original string: %s\n", str01);
	bzero(str01, 5);
    printf("String01 after bzero: %s\n", str01);
	printf("Original string02: %s\n", str02);
	ft_bzero(str02, 5);
	printf("String02 after ft_bzero: %s\n", str02);
}

void check_ft_strchr()
{
	char *w;

	w = "Hello World!";
	printf("character to find o in %s : %s\n", w, ft_strchr(w, 'o'));
}

void check_ft_strrchr()
{
	char *w;

	w = "Hello World!";
	printf("character to find o in %s: %s\n", w, ft_strrchr(w, 'o'));
}

void check_ft_strnstr()
{
	const char *b;
	const char *l;
	size_t		len;

	b = "Hello World!";
	l = "el";
	len = 50;
	printf("chain %s in %s is %s\n", l, b, ft_strnstr(b, l, len));
}

void check_ft_strdup()
{
	const char *c;
	char *n;

	c = "Hello World!";
	n = "";
	printf("%s bfr ft_strdup || ", n);
	n = ft_strdup(c);
	printf("aftr ft_strdup: %s\n", n);
	free(n);
}

void check_ft_substr()
{
	const char *c;
	unsigned int st;
	size_t l;
	char *result;

	c = "Hello World";
	st = 8;
	l = 9;
	result = ft_substr(c,st,l);
	printf("ft_substr(%s,%u, %zu): %s\n", c, st, l, result); 
	free(result);
}

void check_ft_strjoin()
{
	const char *s1 = "Hello";
	const char *s2 = " World!";
	char *result = ft_strjoin(s1, s2);
	printf("ft_strjoin(%s, %s): %s\n", s1, s2, result);
	free(result);
}

void check_ft_strtrim()
{
	char const *s1 = "*****Hello World!*****";
	char const *set = "!H*";
	char *result;
	result = ft_strtrim(s1, set);
	printf("ft_strtrim(%s, %s): %s\n", s1, set, result);
	free(result);
}

void check_ft_split()
{
	char	*s ="lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	char	c = ' ';
	char	**ar = ft_split(s, c);
	int		i = 0;
	printf("ft_split(%s, %c): \n", s, c);
	while (ar[i])
	{
		printf("%s\n", ar[i]);
		i++;
	}
}

void check_ft_itoa()
{
	printf("ft_itoa(%d): %s\n", -42, ft_itoa(-42));
}

char to_upper(unsigned int index, char c)
{
	(void) index;
     return ft_toupper(c);
}
void check_ft_strmapi()
{
	char *str = "+lOrEm IpSuM";
	char *rs = ft_strmapi(str, to_upper);
	if (rs)
	{
		printf("ft_strmapi(%s, %s): %s\n",str, "ft_toupper", rs);
		free(rs);
	}
}

void	change_to_lower(unsigned int index, char *c)
{
	(void) index;
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

void check_ft_striteri()
{
	char str[] = "HELLO WORLD!";
	printf("/* striteri test */\n");
	printf("Original string: %s || ", str);
	ft_striteri(str, change_to_lower);
	printf("Modified string: %s\n", str);
}

void check_ft_putchar_fd()
{
	char c;

	c = 'c';
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void check_ft_putstr_fd()
{
	char *str;

	str = "Hello World!\n";
	ft_putstr_fd(str, 1);
}

void check_ft_putendl_fd()
{
	char *str;

	str = "Hello World!";
	ft_putendl_fd(str, 1);
}

void check_ft_putnbr_fd()
{
	int	n;

	n = -42;
	ft_putnbr_fd(n, 1);
	write (1, "\n", 1);
}

int main() 
{
    check_ft_isalpha();
	check_ft_isdigit();
	check_ft_isalnum();
	check_ft_isascii();
	check_ft_isprint();
	check_ft_toupper();
	check_ft_tolower();
	check_ft_strncmp();
	check_ft_memcmp();
	check_ft_atoi();
	check_ft_strlen();
	check_ft_strlcpy();
	check_ft_strlcat();
	check_ft_memset();
	check_ft_memcpy();
	check_ft_memmove();
	check_ft_memchr();
	check_ft_calloc();
	check_ft_bzero();
	check_ft_strchr();
	check_ft_strrchr();
	check_ft_strnstr();
	check_ft_strdup();
	check_ft_substr();
	check_ft_strjoin();
	check_ft_strtrim();
	check_ft_split();
	check_ft_itoa();
	check_ft_strmapi();
	check_ft_striteri();
	check_ft_putchar_fd();
	check_ft_putstr_fd();
	check_ft_putendl_fd();
	check_ft_putnbr_fd();

	return 0;
}
