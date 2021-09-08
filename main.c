/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:04:53 by msanjuan          #+#    #+#             */
/*   Updated: 2021/09/08 14:35:59 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define MAG "\e[0;35m"
#define RESET "\e[0m"

void check(int a, int b)
{
	a == b ? printf(GRN "OK.\e[0m (%d | Vrai: %d)\n\n", a, b) : printf(RED "KO.\e[0m(%d |Vrai: %d)\n\n", a, b);
}
void checkLeaks(void)
{
	system("leaks a.out");
}

int main(void)
{

	printf(YEL "---------------------------------\n");
	printf("        Tests with \e[0;35mno\e[0;33m flags      \n");
	printf("---------------------------------\e[0m\n");
	int ct_printf = (ft_printf("Bonjour ceci est un test sans flag\n"));
	int v_printf = (printf("Bonjour ceci est un test sans flag\n"));
	check(ct_printf, v_printf);


	printf(YEL "---------------------------------\n");
	printf("      Tests for \e[0;35mevery\e[0;33m  flags     \n");
	printf("---------------------------------\e[0m\n");
	char *phrase;
	phrase = "phrase";
	int count_printf = ft_printf("Tests d'une longue %s (adresse : %p) de %c lignes pour \ntester les %d flags %% (ou est-ce %i?), sachant que 42 fait %x (%X)\n\n", phrase, &phrase, 'x', 9, 10, 42, 42);
	ft_printf("Compteur de la fausse : %d\n\n", count_printf);
	int vrai_printf = printf("Tests d'une longue %s (adresse : %p) de %c lignes pour \ntester les %d flags %% (ou est-ce %i?), sachant que 42 fait %x (%X)\n\n", phrase, &phrase, 'x', 9, 10, 42, 42);
	printf("Compteur de la vraie : %d\n", vrai_printf);
	check(count_printf, vrai_printf);


	printf(YEL "---------------------------------\n");
	printf("          Tests for \e[0;35m%%c\e[0;33m          \n");
	printf("---------------------------------\e[0m\n");
	int c1 = ft_printf("Test |%c|\n", 'j');
	int c1_true = printf("Test |%c|\n", 'j');
	check(c1, c1_true);

	int c2 = ft_printf("Test |%c| |%c| |%s|\n", '1', 'w', "c");
	int c2_true = printf("Test |%c| |%c| |%s|\n", '1', 'w', "c");
	check(c2, c2_true);


	printf(YEL "---------------------------------\n");
	printf("          Tests for \e[0;35m%%%%\e[0;33m         \n");
	printf("---------------------------------\e[0m\n");
	int percent_count = ft_printf("Test |%%|\n");
	int true_percent_count = printf("Test |%%|\n");
	check(percent_count, true_percent_count);

	printf(YEL "---------------------------------\n");
	printf("          Tests for \e[0;35m%%s\e[0;33m         \n");
	printf("---------------------------------\e[0m\n");
	char *null_test = NULL;
	int s1 = ft_printf("Test |%s|\n", null_test);
	int s1_true = printf("Test |%s|\n", null_test);
	check(s1, s1_true);

	char *str_test = "réussi";
	int s2 = ft_printf("Test |%s|\n", str_test);
	int s2_true = printf("Test |%s|\n", str_test);
	check(s2, s2_true);

	int s3 = ft_printf("Test |%s|\n", "Ceci est un test");
	int s3_true = printf("Test |%s|\n", "Ceci est un test");
	check(s3, s3_true);

	int s4 = ft_printf("Test str vide |%s|\n", "");
	int s4_true = printf("Test str vide |%s|\n", "");
	check(s4, s4_true);

	int s5 = ft_printf("Test |%s|\n", "The red glint of paint sparkled under the sun. He had dreamed of owning this car since he was ten, and that dream had become a reality less than a year ago. It was his baby and he spent hours caring for it, pampering it, and fondling over it. She knew this all too well, and that's exactly why she had taken a sludge hammer to it.");
	int s5_true = printf("Test |%s|\n", "The red glint of paint sparkled under the sun. He had dreamed of owning this car since he was ten, and that dream had become a reality less than a year ago. It was his baby and he spent hours caring for it, pampering it, and fondling over it. She knew this all too well, and that's exactly why she had taken a sludge hammer to it.");
	check(s5, s5_true);


	printf(YEL "---------------------------------\n");
	printf("          Tests for \e[0;35m%%d\e[0;33m         \n");
	printf("---------------------------------\e[0m\n");
	int int_test = 0;
	int d1 = ft_printf("Test %d\n", int_test);
	int d1_true = printf("Test %d\n", int_test);
	check(d1, d1_true);

	int int_test2 = 42;
	int d2 = ft_printf("Test %d\n", int_test2);
	int d2_true = printf("Test %d\n", int_test2);
	check(d2, d2_true);

	int int_test0 = -4212242;
	int d3 = ft_printf("Test %d\n", int_test0);
	int d3_true = printf("Test %d\n", int_test0);
	check(d3, d3_true);

	int int_test3 = INT_MIN;
	int d4 = ft_printf("Test %d\n", int_test3);
	int d4_true = printf("Test %d\n", int_test3);
	check(d4, d4_true);

	int int_test4 = INT_MAX;
	int d5 = ft_printf("Test %d\n", int_test4);
	int d5_true = printf("Test %d\n", int_test4);
	check(d5, d5_true);

	printf(YEL "---------------------------------\n");
	printf("         Tests for \e[0;35m%%i\e[0;33m         \n");
	printf("---------------------------------\e[0m\n");
	int int_test5 = 0;
	int i1 = ft_printf("Test %i\n", int_test5);
	int i1_true = printf("Test %i\n", int_test5);
	check(i1, i1_true);

	int int_test6 = 57789;
	int i2 = ft_printf("Test %i\n", int_test6);
	int i2_true = printf("Test %i\n", int_test6);
	check(i2, i2_true);

	int int_test7 = -1;
	int i3 = ft_printf("Test %i\n", int_test7);
	int i3_true = printf("Test %i\n", int_test7);
	check(i3, i3_true);

	int int_test8 = INT_MAX;
	int i4 = ft_printf("Test %i\n", int_test8);
	int i4_true = printf("Test %i\n", int_test8);
	check(i4, i4_true);


	printf(YEL "---------------------------------\n");
	printf("          Tests for \e[0;35m%%u\e[0;33m         \n");
	printf("---------------------------------\e[0m\n");
	unsigned int int_test9 = 0;
	int u1 = ft_printf("Test %u\n", int_test9);
	int u1_true = printf("Test %u\n", int_test9);
	check(u1, u1_true);

	unsigned int int_test10 = 4278;
	int u2 = ft_printf("Test %u\n", int_test10);
	int u2_true = printf("Test %u\n", int_test10);
	check(u2, u2_true);

	unsigned int int_test12 = UINT_MAX;
	int u3 = ft_printf("Test %u\n", int_test12);
	int u3_true = printf("Test %u\n", int_test12);
	check(u3, u3_true);


	printf(YEL "---------------------------------\n");
	printf("          Tests for \e[0;35m%%x\e[0;33m         \n");
	printf("---------------------------------\e[0m\n");
	int int_test13 = 0;
	int x1 = ft_printf("Test %x\n", int_test13);
	int x1_true = printf("Test %x\n", int_test13);
	check(x1, x1_true);

	int int_test14 = 42;
	int x2 = ft_printf("Test %x\n", int_test14);
	int x2_true = printf("Test %x\n", int_test14);
	check(x2, x2_true);

	int int_test17 = -1;
	int x3 = ft_printf("Test %x\n", int_test17);
	int x3_true = printf("Test %x\n", int_test17);
	check(x3, x3_true);

	int int_test18 = 13;
	int x4 = ft_printf("Test %x\n", int_test18);
	int x4_true = printf("Test %x\n", int_test18);
	check(x4, x4_true);

	int int_test19 = 5;
	int x5 = ft_printf("Test %x\n", int_test19);
	int x5_true = printf("Test %x\n", int_test19);
	check(x5, x5_true);

	int int_test15 = INT_MIN;
	int x6 = ft_printf("Test %x\n", int_test15);
	int x6_true = printf("Test %x\n", int_test15);
	check(x6, x6_true);

	int int_test16 = INT_MAX;
	int x7 = ft_printf("Test %x\n", int_test16);
	int x7_true = printf("Test %x\n", int_test16);
	check(x7, x7_true);

	int int_test20 = 501;
	int x8 = ft_printf("Test %x\n", int_test20);
	int x8_true = printf("Test %x\n", int_test20);
	check(x8, x8_true);

	int int_test21 = -178;
	int x9 = ft_printf("Test %x\n", int_test21);
	int x9_true = printf("Test %x\n", int_test21);
	check(x9, x9_true);

	int int_test22 = 111111;
	int x10 = ft_printf("Test %x\n", int_test22);
	int x10_true = printf("Test %x\n", int_test22);
	check(x10, x10_true);


	printf(YEL "---------------------------------\n");
	printf("          Tests for \e[0;35m%%X\e[0;33m         \n");
	printf("---------------------------------\e[0m\n");
	int int_test23 = 0;
	int upp_x1 = ft_printf("Test %X\n", int_test23);
	int upp_x1_true = printf("Test %X\n", int_test23);
	check(upp_x1, upp_x1_true);

	int int_test24 = 42;
	int upp_x2 = ft_printf("Test %X\n", int_test24);
	int upp_x2_true = printf("Test %X\n", int_test24);
	check(upp_x2, upp_x2_true);

	int int_test25 = -1;
	int upp_x3 = ft_printf("Test %X\n", int_test25);
	int upp_x3_true = printf("Test %X\n", int_test25);
	check(upp_x3, upp_x3_true);

	int int_test26 = 13;
	int upp_x4 = ft_printf("Test %X\n", int_test26);
	int upp_x4_true = printf("Test %X\n", int_test26);
	check(upp_x4, upp_x4_true);

	int int_test27 = 5;
	int upp_x5 = ft_printf("Test %X\n", int_test27);
	int upp_x5_true = printf("Test %X\n", int_test27);
	check(upp_x5, upp_x5_true);

	int int_test28 = INT_MIN;
	int upp_x6 = ft_printf("Test %X\n", int_test28);
	int upp_x6_true = printf("Test %X\n", int_test28);
	check(upp_x6, upp_x6_true);

	int int_test29 = INT_MAX;
	int upp_x7 = ft_printf("Test %X\n", int_test29);
	int upp_x7_true = printf("Test %X\n", int_test29);
	check(upp_x7, upp_x7_true);

	int int_test30 = 501;
	int upp_x8 = ft_printf("Test %X\n", int_test30);
	int upp_x8_true = printf("Test %X\n", int_test30);
	check(upp_x8, upp_x8_true);

	int int_test31 = -178;
	int upp_x9 = ft_printf("Test %X\n", int_test31);
	int upp_x9_true = printf("Test %X\n", int_test31);
	check(upp_x9, upp_x9_true);

	int int_test32 = 111111;
	int upp_x10 = ft_printf("Test %X\n", int_test32);
	int upp_x10_true = printf("Test %X\n", int_test32);
	check(upp_x10, upp_x10_true);



	printf(YEL "---------------------------------\n");
	printf("          Tests for \e[0;35m%%p\e[0;33m         \n");
	printf("---------------------------------\e[0m\n");
	char *ptr_test = NULL;
	int p1 = ft_printf("Test NULL address |%p|\n", ptr_test);
	int p1_true = printf("Test NULL address |%p|\n", ptr_test);
	check(p1, p1_true);

	char *test2 = "Test123*";
	char *ptr_test2 = test2;
	int p2 = ft_printf("Test str address |%p|\n", ptr_test2);
	int p2_true = printf("Test str address |%p|\n", ptr_test2);
	check(p2, p2_true);

	int test3 = 1;
	int *ptr_test3 = &test3;
	int p3 = ft_printf("Test int address |%p|\n", ptr_test3);
	int p3_true = printf("Test int address |%p|\n", ptr_test3);
	check(p3, p3_true);

	char test4 = 'a';
	char *ptr_test4 = &test4;
	int p4 = ft_printf("Test char address |%p|\n", ptr_test4);
	int p4_true = printf("Test char address |%p|\n", ptr_test4);
	check(p4, p4_true);

	int test5 = -1;
	int* ptr_test5 = &test5;
	int p5 = ft_printf("Test neg int address |%p|\n", ptr_test5);
	int p5_true = printf("Test neg int address |%p|\n", ptr_test5);
	check(p5, p5_true);

	long int ptr_test6 = LONG_MIN;
	int p6 = ft_printf("Test long min address |%p|\n", &ptr_test6);
	int p6_true = printf("Test long min address |%p|\n", &ptr_test6);
	check(p6, p6_true);

	long int ptr_test7 = LONG_MAX;
	int p7 = ft_printf("Test long max address |%p|\n", &ptr_test7);
	int p7_true = printf("Test long max address |%p|\n", &ptr_test7);
	check(p7, p7_true);

	unsigned long int ptr_test8 = -ULONG_MAX;
	int p8 = ft_printf("Test ulong min address |%p|\n", &ptr_test8);
	int p8_true = printf("Test ulong min address |%p|\n", &ptr_test8);
	check(p8, p8_true);

	unsigned long int ptr_test9 = ULONG_MAX;
	int p9 = ft_printf("Test ulong max address |%p|\n", &ptr_test9);
	int p9_true = printf("Test ulong max address |%p|\n", &ptr_test9);
	check(p9, p9_true);

	ft_printf("This %p is even stranger\n", (void *)-1);
	printf("This %p is even stranger\n\n", (void *)-1);
	
	atexit(checkLeaks);
	return (0);
}
