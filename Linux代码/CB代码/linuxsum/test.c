#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include "test.h"
#include <time.h>
#include <assert.h>
#include <malloc.h>
typedef struct MAZE
{
	char c;
	int Count;
	int backx;
	int backy;
	int flag;

}M;
typedef struct S
{
	char Stack_obj[Stack_size];
	int Stack_pos[Stack_size][2];
	int top;
}Seq_Stack;
int arr1[11] = { 0,2,87,39,49,34,62,53,6,44,98 };
int flag = 0;
int P[7] = { 0 };
// str
int strlen1(char* m)
{
	int i = 0;
	int len = 0;

	while (*(m + i) != '\0')
	{
		i++;
		len++;
	}
	return len;
}
void str1()
{
	getchar();
	char str[100];
	fgets(str,100,stdin);
	int t;
	t = strlen1(str);
	printf("%d\n", t);
}
void str2()
{
	getchar();
	char a[] = "guozhipengzhencongming";
	char b[30] = { 0 };
	int i;
	for (i = 0; *(a + i) != '\0'; i++)
		*(b + i) = *(a + i);
	*(b + i) = '\0';
	printf("output1:%s\n", a);
	printf("output2:");
	for (i = 0; b[i] != '\0'; i++)
		printf("%c", b[i]);
	printf("\n");
}
void str3() {
	getchar();
	int i, j;
	char str1[20], str2[20];
	printf("the first zfc: \n");
	fgets(str1, 20, stdin);
	printf("the second zfc: \n");
	fgets(str2, 20, stdin);
	printf("\n");
	printf("the origin zfc：\n%s \n%s", str1, str2);
	for (i = strlen(str1), j = 0; j <= strlen(str2); i++, j++) {

		str1[i] = str2[j];
	}
	printf("the next zfc：%s\n", str1);
}
void str4() {
	getchar();
	char s1[100], s2[100];
	printf("input s1[],s2[]:");
	fgets(s1, 100, stdin);
	fgets(s2, 100, stdin);
	if ((int)s1[0] > (int)s2[0])
	{
		printf("s1>s2");
	}
	else if ((int)s1[0] < (int)s2[0]) {
	printf("s1<s2");
	}
	else {
	printf("s1=s2");
	}
}
void str5() {
	getchar();
	char text[80];
	int len;
	printf("intput your string：\n");
	fgets(text, 80, stdin);
	len = strlen(text);
	for (int i = 0; i < len; i++)
	{
		if (text[i] >= 'a' && text[i] < 'z' || text[i] >= 'A' && text[i] < 'Z')
		{
			text[i]++;
		}
		else if (text[i] == 'z')
		{
			text[i] = 'a';
		}
		else if (text[i] == 'Z')
		{
			text[i] = ' ';
		}
	}
	printf("output：\n%s", text);


}
void str6() {
	getchar();
	char c = '0';
	while (c != '\n')
	{
		scanf("%c", &c);

		if (c >= 'A' && c <= 'Z') {

			c = c + 32;
			printf("%c", c);
		}
		else if (c >= 'a' && c <= 'z') {

			c = c - 32;
			printf("%c", c);

		}
	}
}
void str7() {
	getchar();
	char a[101];
	int len, i;
	while (fgets(a, 100, stdin)) {
		len = strlen(a);
		if (a[0] >= 'a' && a[0] <= 'z') {
			a[0] = toupper(a[0]);
		}
		for (i = 0; i < len; i++) {
			if (isspace(a[i]) && a[i + 1] >= 'a' && a[i + 1] <= 'z') {
				a[i + 1] = toupper(a[i + 1]);
			}
		}
		printf("%s", a);
		printf("\n");
	}
}
void str8() {
	getchar();
	char str[30] = { '\0' };
	int count = 0;
	printf("please input the string\n");
	fgets(str, 30, stdin);
	printf("%s", str);
	int length = strlen(str);
	for (int i = 0; i < length; i++)
	{
		if (str[i] != ' ')
		{
			count++;
			while (str[i] != ' ' && str[i] != '\0')
			{
				i++;
			}
		}
	}
	printf("%d\n", count);

}
void str9()
{
	getchar();
	char str[100];
	printf("Enter a string with extra spaces :");
	fgets(str, 100, stdin);
	char* p = str;
	while (*p == ' ') {
		p++;
	}
	int j = 0;
	while (*p != '\0')
	{
		str[j++] = *p++;
		while (str[j - 1] == ' ' && *p == ' ')
		{
			p++;
		}
	}
	if (str[j - 1] == ' ')
		str[j - 1] = '\0';
	else
		str[j] = '\0';
	printf("%s", str);
}
void str10() {
	char s1[100];
	char s2[100];
	int i = 0;
	int m = 0, n = 1;
	int j = 1;
	printf("enter a string\n");
	getchar();
	fgets(s1, 99, stdin);
	fgets(s1, 99, stdin);
	s2[0] = s1[0];
	for (i = 0; s1[i] != '\0'; i++, m++, n++)
	{
		if (s1[m] == 32 && s1[n] != 32) {
			s2[j] = s1[n]; j++;
		}
	}
	for (i = 0; i < j; i++) {
		printf("%c", s2[i]);
	}
	printf("\n");
}
void str11()
{
	getchar();
	char str11[100];
	char hstr11[100];
	int i;
	int j = 0, count = 0;
	printf("qingshuruzifuchuan:\n");
	fgets(str11, 100, stdin);
	for (i = strlen(str11) - 1; i >= 0; i--)
	{
		hstr11[j] = str11[i];
		j++;

	}
	for (j = 0; j < strlen(str11); j++)
	{
		if (str11[j] == hstr11[j])
		{
			count++;
		}
	}
	if (count == strlen(str11))
	{
		printf("It is hw\n");
	}
	else
	{
		printf("It is not hw\n");
	}
	printf("\n");
}
void str12()
{
	getchar();
	char str12[100];
	char hstr12[100];
	int i, j = 0;
	printf("qingshuruzifuchuan:\n");
	fgets(str12, 100, stdin);
	for (i = strlen(str12) - 1; i >= 0; i--)
	{
		hstr12[j] = str12[i];
		printf("%c", hstr12[j]);
		j++;
	}
	printf("\n");
}
void str13()
{
	getchar();
	char str13[100];
	char hstr13[100];
	char str[100];
	int i, j;
	printf("qingshuruzifuchuan:\n");
	fgets(str13, 100, stdin);
	fgets(hstr13, 100, stdin);
	for (i = 0; i < 100; i++)
	{
		str[i] = str13[i];
		str13[i] = hstr13[i];
		hstr13[i] = str[i];

	}
	printf("\n");
	printf("%s%s", str13, hstr13);
	printf("\n");

}
void str14()
{
	getchar();
	char str14[100];
	int i;
	int alphabet = 0;
	int space = 0;
	int number = 0;
	int others = 0;
	printf("qingshuruzifuchuan:\n");
	fgets(str14, 100, stdin);
	for (i = 0; i < strlen(str14) - 1; i++)
	{

		if ((str14[i] >= 'a' && 'z' >= str14[i]) || (str14[i] >= 'A' && 'Z' >= str14[i]))
		{
			alphabet++;
		}
		else if (str14[i] == ' ')
		{
			space++;
		}
		else if (str14[i] >= '0' && str14[i] <= '9')
		{
			number++;
		}

		else
		{
			others++;
		}
	}
	printf("the count of alphabet,apace,number,others is: %d, %d, %d ,%d\n ", alphabet, space, number, others);
	printf("\n");
}
void str15()
{
	getchar();
	char str15[100];
	char c;
	int delect = 0;
	int i, j;
	printf("qingshuruzifuchuan:\n");
	fgets(str15, 100, stdin);
	scanf("%c", &c);

	for (i = 0; i < strlen(str15); i++)
	{

		if (str15[i] == c)
		{
			for (j = i; j < strlen(str15) - 1; j++)
			{
				str15[j] = str15[j + 1];
			}
			str15[strlen(str15) - 1] = '\0';
			i--;//
		}

	}

	printf("%s", str15);
	printf("\n");

}
void str16()
{
	getchar();
	char str16[100];
	char hstr16[100];
	int pos, len;

	printf("qingshuruzifuchuan:\n");
	fgets(str16, 100, stdin);
	scanf("%d %d", &pos, &len);

	int i, j = 0;

	if (strlen(str16) < pos + len)
	{
		printf("Illegal input");
	}

	else
	{
		for (i = 0; i < pos - 1; i++)
		{
			hstr16[j] = str16[i];
			j++;
		}
		for (i = pos + len - 1; str16[i] != '\0'; i++)
		{
			hstr16[j] = str16[i];
			j++;
		}
		hstr16[j] = '\0';

	}
	printf("%s", hstr16);
	printf("\n");
}
void str17()
{
	getchar();
	char str17[100];
	char hstr17[100];
	int delect = 0;
	int i, j;
	printf("qingshuruzifuchuan:\n");
	fgets(str17, 100, stdin);
	fgets(hstr17, 100, stdin);

	for (i = 0; i < strlen(str17); i++)
	{
		for (j = 0; j < strlen(hstr17); j++)
		{
			if (str17[i] == hstr17[j])
			{
				for (j = i; j < strlen(str17) - 1; j++)
				{
					str17[j] = str17[j + 1];
				}
				str17[strlen(str17) - 1] = '\0';
				i--;//
			}


		}


	}

	printf("%s \n", str17);
	printf("\n");

}
void str18()
{
	getchar();
	char str18[30];
	char hstr18[30];
	printf("qingshuruzifuchuan:\n");
	fgets(str18, 30, stdin);
	fgets(hstr18, 30, stdin);
	printf("\n");
	int len1, len2, i = 0, j = 0;
	len1 = strlen(str18) - 1;
	len2 = strlen(hstr18) - 1;
	int len = len1 > len2 ? len1 : len2;
	int* num1 = (int*)malloc(len * sizeof(int));
	int* num2 = (int*)malloc(len * sizeof(int));
	for (i = 0; i < len; i++)
	{
		num1[i] = i < len1 ? str18[len1 - i - 1] - '0' : 0;
	}
	for (j = 0; j < len; j++)
	{
		num2[j] = j < len2 ? hstr18[len2 - j - 1] - '0' : 0;
	}
	int* sum = (int*)malloc(len * sizeof(int));
	int flag = 0;
	for (i = 0; i < len; i++)
	{
		sum[len - 1 - i] = (num1[i] + num2[i] + flag) % 10;
		flag = (num1[i] + num2[i] + flag) / 10;
	}
	if (flag == 1)
	{
		printf("1");
	}
	printf("jieguowei:");
	for (i = 0; i < len; i++)
	{
		printf("%d", sum[i]);
	}
	printf("\n");
	free(num1);
	free(num2);
	free(sum);
	num1 = NULL;
	num2 = NULL;
	sum = NULL;
	printf("\n");
}
void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
void arrange(int* arr, int size) {
	int i = 0, j = 1;
	while (1) {
		while (arr[i] & 1) i += 2;
		while ((arr[j] & 1) == 0) j += 2;
		swap(&arr[i], &arr[j]);
		i += 2;
		j += 2;
		if (i >= size || j >= size) break;
	}
}
void str19()
{
	printf("Please enter ten numbers\n ");
	int arr[11];
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &arr[i]);
	}
	arrange(arr, 10);
	for(int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
}
void str20()
{
	getchar();
	char str20[100];
	char asc[255] = { 0 };
	int i = 0;
	printf("qingshuruzifuchuan:\n");
	fgets(str20, 100, stdin);
	for (; str20[i] != '\0'; i++)
	{
		asc[str20[i]]++;

	}
	for (i = 0; str20[i] != '\0'; i++)
	{
		if (asc[str20[i]] == 1)

		{
			printf("%c", str20[i]);
			break;

		}

	}
	printf("\n");
}
void str21()
{
	char str[100], pat[10];
	getchar();
	printf("Please enter s1:");
	fgets(str, 100, stdin);
	printf("Please enter s2:");
	fgets(pat, 10, stdin);
	int n = strlen(str) - 1;
	int m = strlen(pat) - 1;
	for (int s = 0; s < n - m + 1; ++s)
	{
		int i = s, j = 0;
		for (; j < m - 1;)
		{
			if (str[i] == pat[j])++i, ++j;
			else break;
		}
		if (str[i] == pat[j])
			printf("%d\n", s);
	}
}
void str22()
{
	char str[30];
	getchar();
	printf("Please enter s:");
	fgets(str, 30, stdin);
	int i = 0;
	int x = 0, sum = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			x = str[i] - '0';
		}
		i++;
		sum += x;
	}
	printf("%d\n", sum);
}
void str23()
{
	char str[30];
	int strtoint[30];
	getchar();
	printf("Please enter str:");
	fgets(str, 100, stdin);
	int i = 0;
	while (str[i] != '\0')
	{
		strtoint[i] = str[i] - 48;
		i++;
	}
	for (int i = 0; i < strlen(str) - 1; i++)
	{
		printf("%d", strtoint[i]);
	}
}
void str24()
{
	char p[10];
	getchar();
	printf("Please enter s:");
	fgets(p, 10, stdin);
	int len = strlen(p);
	int i = 0;
	int flag = 0;
	if (p[0] == '-')
	{
		i = 1;
		flag = 1;
	}
	else if (p[0] == '+')
	{
		i = 1;
		flag = 0;
	}
	int sum = 0;
	for (; i < len; ++i)
	{
		if (p[i] >= '0' && p[i] <= '9')
		{
			sum += (int)(p[i] - '0') * pow(10, len - i - 1);
		}
	}
	printf("%d", flag > 0 ? sum * -1 : sum);
}
void str25()
{
	char l[100], s[100];
	getchar();
	int i, k = 0, j = 0, ssum = 0, sum = 0;
	printf("Please enter l:");
	fgets(l, 100, stdin);
	fflush(stdin);
	printf("Please enter s:");
	fflush(stdin);
	fgets(s,100,stdin);

	for (i = 0;; i++)
	{
		if (s[i] == '\0')
			break;
		ssum++;
	}
	for (j = 0;; j++)
	{
		if (l[j] == '\0')
		{
			break;
		}
		if (sum == ssum)
		{
			break;
		}
		if (l[j] == s[k])
		{
			sum++;
			k++;
			continue;
		}
		else
		{
			if (k == 0 || j == 0)
			{
				continue;
			}

			k = 0;
			j -= 1;
			sum = 0;
			continue;
		}
	}
	if (sum == ssum)
		printf("TRUE");
	else
		printf("FALSE");
}
void str26()
{
	int len, i;
	char str[100];
	getchar();
	printf("Please enter str:");
	fgets(str, 100, stdin);
	len = strlen(str);
	for (i = len - 1; i >= 0; i--)
		printf("%c", str[i]);
}
void str27()
{
	char str[100];
	int a[256] = { 0 };
	getchar();
	printf("");
	printf("Please enter str:");
	fgets(str, 100, stdin);
	for (int i = 0; i < strlen(str); i++)
	{
		if (++a[str[i]] == 2)
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
			{
				printf("%c", str[i]);
				break;
			}
		}
	}
}
void str28()
{
	char s[100];
	int i, j, n, k;
	getchar();
	printf("Please enter s:");
	fgets(s, 100, stdin);
	n = strlen(s);
	for (i = 0; i < n - 1; i++)
	{
		for (j = k = i + 1; j < n - 1; j++)
			if (s[j] != s[i])
				s[k++] = s[j];
		s[k] = '\0';
	}
	printf("new S1:\n%s", s);
}
void str29()
{
	char s[100], s1[100]; int i, j, m = 0, pri[100], max = 0, x = 0, y = 0, n;
	getchar();
	printf("Please enter s:");
	fgets(s, 100, stdin);
	n = strlen(s);
	for (i = 0; i < n; i++)
	{
		if (isalpha(s[i]))
		{
			pri[m] = i;
			s1[m++] = toupper(s[i]);
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j <= i && i + j < m; j++)
		{
			if (s1[i - j] != s1[i + j])break;//jishu
			if ((2 * j + 1) > max)
			{
				max = 2 * j + 1;
				x = pri[i - j];
				y = pri[i + j];
			}
		}
		for (j = 0; j <= i && i + j < m; j++)
		{
			if (s1[i - j] != s1[i + j + 1])break;//oushu
			if ((2 * j + 2) > max)
			{
				max = 2 * j + 2;
				x = pri[i - j];
				y = pri[i + j + 1];
			}
		}


	}
	for (i = x; i <= y; i++)
		printf("%c", s[i]);
}
void str30()
{
	//2 to 10
	getchar();
	char a[10], b[10];
	printf("Please enter a:");
	fgets(a, 9, stdin);
	printf("Please enter b:");
	fgets(b, 9, stdin);
	int len, i, sum1 = 0, sum2 = 0, sum = 0, m, j;
	len = strlen(a) - 1;
	if (len <= 9)
	{
		for (i = 0; i < len; i++)
		{
			m = 1;
			if (a[i] == '1')
			{
				for (j = 1; j <= len - i - 1; j++)
					m *= 2;
				sum1 += m;
			}
		}
	}
	len = strlen(b) - 1;
	if (len <= 9)
	{
		for (i = 0; i < len; i++)
		{
			m = 1;
			if (b[i] == '1')
			{
				for (j = 1; j <= len - i - 1; j++)
					m *= 2;
				sum2 += m;
			}
		}
	}
	sum = sum1 + sum2;
	i = 1;
	long long num = 0;
	int rem, step = 1;

	while (sum != 0)
	{
		rem = sum % 2;
		step++;
		sum / 2;
		sum /= 2;
		num += (long long)(rem * i);
		i *= 10;
	}
	printf("%lld", num);
}
// px
int binarySearch(int a[], int low, int high, int value)
{
	if (low > high)
		return -1;

	int mid = (low + high) / 2;

	if (value == a[mid])
		return mid;
	else if (value > a[mid])
		return binarySearch(a, mid + 1, high, value);
	else
		return binarySearch(a, low, mid - 1, value);
}
int Search(int a[], int low, int high, int value)
{
	int mid = (low + high) / 2;

	if (a[mid] > a[low])
	{
		if (a[low] <= value && value <= a[mid])
		{
			return binarySearch(a, low, mid, value);
		}

		else
		{
			return Search(a, mid + 1, high, value);
		}
	}
	else
	{
		if (a[mid] <= value && value <= a[high])
		{
			return binarySearch(a, mid, high, value);
		}
		else
		{
			return Search(a, low, mid - 1, value);
		}
	}
}
void getIndexofIncArray(int* a, int M, int N, int target, int* x, int* y) {
	int i = 0, j = M - 1, count;
	*x = *y = -1;
	for (count = 0; count < N + M; count++) {
		if (target == *(a + N * j + i)) {
			*x = j;
			*y = i;
			printf("true");
		}
		else	if (target > *(a + N * j + i)) {
			if ((i >= N) && (j < 0)) {
				break;
			}
			else {
				i++;
			}
		}
		else {
			if ((i >= N) && (j < 0)) {
				break;
			}
			else {
				j--;
			}
		}
	}
	printf("false");
}
void px1()
{
	int i, a[10];
	int max1, max2;
	printf("Enter ten numbers \n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d ", &a[i]);
	}
	max1 = max2 = a[0];
	for (i = 1; i < 10; i++)
	{
		if (max1 < a[i])
		{
			max2 = max1;
			max1 = a[i];
		}
		else if (max2 < a[i])
		{
			max2 = a[i];
		}
	}
	printf("%d", max2);
}
void px2()
{
	int a[] = { 3,4,5,6,7,8,9,0,1,2 };
	Search(a, 0, 9, 0);
}
void px3() {
	int i, j;
	int target;
	int* p1 = &i, * p2 = &j;
	int a[4][5] = {
		{1, 3, 7, 11, 19},
		{2, 7, 10, 29, 30},
		{13, 28, 54, 69, 90},
		{46, 57, 78, 98, 101}
	};
	printf("please enter target\n");
	scanf("%d", &target);
	getIndexofIncArray(&a[0][0], 4, 5, target, p1, p2);
	printf("%d, %d\n", i, j);
}
void initial(int R[], int low, int high)	//产生R[low..high中的随机数
{
	int i;
	srand((unsigned)time(NULL));
	for (i = low; i < high; i++)
	{
		R[i] = rand() % 100 + 1;
		printf("%4d ", R[i]);

	}
	printf("\n\n");
}
int test(KeyType R[], int low, int high)
{
	int i;
	for (i = low; i < high - 1; i++)
		if (R[i] > R[i + 1])
			return 0;
	return 1;
}
void BubbleSort(KeyType R[], int n)
{
	int i, j, temp;
	int exchange;
	for (i = 0; i < n - 1; i++)
	{
		exchange = 0;
		for (j = n - 1; j > i; j--)
			if (R[j] < R[j - 1])
			{
				temp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = temp;
				exchange = 1;
			}

		if (!exchange)
			break;


	}
	for (i = 1; i < n; i++)
	{
		printf("%4d", R[i]);
	}

}
void BubbleSortTime(KeyType R[], int n)
{
	clock_t t;
	printf("\n mppx\t\t");
	t = clock();
	BubbleSort(R, n);
	t = clock() - t;
	printf(" \t%lfsecond ", ((float)t) / CLOCKS_PER_SEC);
	if (test(R, 0, n - 1))
		printf(" \t\t right\n\n ");
	else
		printf(" \t\t false\n\n ");
}
void InsertSort(KeyType R[], int n)
{
	int i, j; KeyType tmp;
	for (i = 1; i < n; i++)
	{
		if (R[i] < R[i - 1])		//反序时
		{
			tmp = R[i];
			j = i - 1;
			do					//找R[i]的插入位置
			{
				R[j + 1] = R[j];   	//将关键字大于R[i]的记录后移
				j--;
			} while (j >= 0 && R[j] > tmp);
			R[j + 1] = tmp;      	//在j+1处插入R[i]
		}

	}
	for (i = 1; i < n; i++)
	{
		printf("%4d", R[i]);
	}
}
void InsertSortTime(KeyType R[], int n)
{
	clock_t t;
	printf("zjcrox\t\t");
	t = clock();
	InsertSort(R, n);
	t = clock() - t;
	printf(" \t%lfsecond ", ((float)t) / CLOCKS_PER_SEC);
	if (test(R, 0, n - 1))
		printf(" \t\t right\n\n ");
	else
		printf(" \t\t false\n\n ");
}
void ShellSort(KeyType R[], int n)
{
	int i, j, d;
	KeyType tmp;
	d = n / 2;
	while (d > 0)
	{
		for (i = d; i < n; i++)
		{
			tmp = R[i];
			j = i - d;
			while (j >= 0 && tmp < R[j])
			{
				R[j + d] = R[j];
				j = j - d;
			}
			R[j + d] = tmp;
		}
		d = d / 2;
	}
	for (i = 1; i < n; i++)
	{
		printf("%4d", R[i]);
	}
}
void ShellSortTime(KeyType R[], int n)
{
	clock_t t;
	printf("xrpx\t\t");
	t = clock();
	ShellSort(R, n);
	t = clock() - t;
	printf(" \t%lfsecond ", ((float)t) / CLOCKS_PER_SEC);
	if (test(R, 0, n - 1))
		printf(" \t\t right\n\n ");
	else
		printf(" \t\t false\n\n ");
}
void FGX(int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("-");

	}
	printf("\n");
}
void px456()
{
	KeyType R[11];
	int n = 11;
	printf("\n randon 10ge1-100 dezhengzhengshu:\n\n");
	initial(R, 0, n - 1);
	FGX(50);
	FGX(50);
	printf("\n\t\t\t\ttime of eachsorting result and results correct\n\n");
	FGX(112);
	printf(" \n sortmethod  \t\t\t sortresult    \t\t\t pxtime   \t\t\tresults correct\n\n");
	FGX(112);

	//mp
	BubbleSortTime(R, n);

	//zjcr
	InsertSortTime(R, n);

	//xr
	ShellSortTime(R, n);

	FGX(112);
	printf("\n");
}
void swapnum(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swapnum(&arr[i], &arr[j]);
		}
	}
	swapnum(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quick_sort(int arr[], int low, int high)
{
	if (low < high) {
		int q = partition(arr, low, high);

		quick_sort(arr, low, q - 1);
		quick_sort(arr, q + 1, high);
	}
}
void px7()
{
	int arr[] = { 10, 80, 30, 90, 40, 50, 70 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("After performing quick sort:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	quick_sort(arr, 0, n - 1);
	printf("\nAfter performing quick sort:\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}
void merge(int* a, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int* L = (int *)malloc(n1);
	int* R = (int *)malloc(n2);

	for (int i = 0; i < n1; i++)
	{
		L[i] = a[p + i];
	}
	for (int i = 0; i < n2; i++)
	{
		R[i] = a[q + i + 1];
	}
	int L_sum = 0;
	int R_sum = 0;
	for (int k = p; k <= r; k++)
	{
		if (L[L_sum] < R[R_sum] && L_sum < n1)
		{
			a[k] = L[L_sum];
			L_sum++;
		}
		else if (R_sum < n2)
		{
			a[k] = R[R_sum];
			R_sum++;
		}
		else {
			a[k] = L[L_sum];
			L_sum++;
		}
	}
}
void merge_sort(int* a, int p, int r) {
	fflush(stdin);
	if (p < r)
	{
		int q = floor((p + r) / 2);
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}
void px8()
{
	fflush(stdin);
	int n;
	printf("please input n shuzu：");
	scanf("%d",&n);
	int a[100];

	time_t t;
	srand((unsigned)time(&t));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand();
	}

	printf("paixu qian shuzu：");
	for (int i = 0; i < n; i++)
	{
		printf("%d",a[i]);
	}

	merge_sort(a, 0, n - 1);

	printf("paixu hou shuzu：");
	for (int i = 0; i < n; i++)
	{
		printf("%d",a[i]);
	}
}
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void PercDown(int  A[], int i, int N)
{
	int child;
	ElementType Tmp;

	for (Tmp = A[i]; 2 * i + 1 < N; i = child) {
		child = 2 * i + 1; i;
		if (child != N - 1 && A[child + 1] > A[child])
			++child;
		if (Tmp < A[child])
			A[i] = A[child];
		else
			break;
	}
	A[i] = Tmp;
}
void HeapSort(int A[], int N)
{
	int i;
	for (i = N / 2; i >= 0; --i)
		PercDown(A, i, N);
	for (i = N - 1; i > 0; --i)
	{
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}
void Print(int A[], int N)
{
	fflush(stdin);
	int i;
	for (i = 0; i < N; i++)
	{
		printf(" %d ", A[i]);
	}
}
void px9()
{
	fflush(stdin);
	int arr[10] = { 2,87,39,49,34,62,53,6,44,98 };
	Print(arr, 10);
	printf("\n");
	HeapSort(arr, 10);
	Print(arr, 10);
	printf("\n");
}
void px10() {
	int i, j;
	int min;
	printf("please input length:\n");
	int a[100], length;
	scanf("%d", &length);
	printf("please input number:\n");
	for (int i = 0; i < length; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 1; i < length - 1; i++) {
		min = i;
		for (j = i + 1; j < length; j++) {
			if (a[j] < a[min])
				min = j;
		}
		if (min != i) {
			int temp;
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
	for (int i = 0; i < length; i++)
	{
		printf("%d ", a[i]);
	}
}
// acm
void acm1()
{
	getchar();
	int integer, sum = 0;
	printf("input: ");
	scanf("%d", &integer);
	if (integer < 0)
		integer = -integer;
	while (integer > 0)
	{
		sum = sum + integer % 10;
		integer = integer / 10;
	}
	printf("%d", sum);
}
void acm2()
{
	getchar();
	int a[3][3];
	int i = 0, j = 0, b, k, h;
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			scanf("%d", &a[i][j]);
			printf("a[%d][%d]=%d\t",i, j, a[i][j]);
		}
		printf("\n");
	}
	{
		b = a[1][1];
		for (i = 0; i <= 2; i++)
		{
			for (j = 0; j <= 2; j++)
			{
				//b=a[1][1];
				if (a[i][j] >= b)
				{
					b = a[i][j];
					k = i, h = j;
				}
				else
					continue;
			}
		}
		printf("max=%d,a[%d][%d]", b, k, h);
	}
}
void acm3()
{
	getchar();
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	if (x < y)
	{
		x += y;
		y = x - y;
		x = x - y;
	}
	if (x < z)
	{
		x += z;
		z = x - z;
		x = x - z;
	}
	if (y < z)
	{
		y += z;
		z = y - z;
		y = y - z;
	}
	printf("%d %d %d", x, y, z);
}
void acm4()
{
	int m, n, j, sum = 0;
	scanf("%d%d", &m, &n);
	for (int a = m; a <= n; a++) {
		int flag = 1;
		if (a == 1)
			flag = 0;
		for (j = 2; j < a; j++)
		{
			if (a % j == 0)
				flag = 0;
		}
		if (flag)
			sum += a;
		printf("%d", sum);
	}
}
void acm5()
{
	int i, j, k;
	printf("\n");
	for (i = 1; i < 5; i++) {
		for (j = 1; j < 5; j++) {
			for (k = 1; k < 5; k++) {
				if (i != k && i != j && j != k) {
					printf("%d%d%d     ", i, j, k);
				}
			}
		}
	}
}
void acm6()
{
	fflush(stdin);
	int year = 0, month = 0, day = 0, i = 0, sum = 0;
	while (1)
	{
		printf("input the year：");
		scanf("%d", &year);
		printf("input the month：");
		scanf("%d", &month);
		printf("input the data：");
		scanf("%d", &day);
		i = 0;
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day > 0 && day <= 31)
			{
				i = 1;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 0 && day <= 30)
			{
				i = 1;
			}
			break;
		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			{
				if (day > 0 && day <= 29)
				{
					i = 1;
				}
			}
			else
			{
				if (day > 0 && day <= 28)
				{
					i = 1;
				}
			}
			break;
		default:
			i = 0;
			break;
		}
		if (i)
		{
			break;
		}
		else
		{
			printf("input the correct year month data!!!\n");
		}
	}
	i = 0;
	switch (month)
	{
	case 12:
		i = i + 30;
	case 11:
		i = i + 31;
	case 10:
		i = i + 30;
	case 9:
		i = i + 31;
	case 8:
		i = i + 31;
	case 7:
		i = i + 30;
	case 6:
		i = i + 31;
	case 5:
		i = i + 30;
	case 4:
		i = i + 31;
	case 3:
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			i = i + 29;
		}
		else
		{
			i = i + 28;
		}
	case 2:
		i = i + 31;
	case 1:
		;
	}
	sum = i + day;
	printf("%d year %d month %d data is %d year's %d day\n！", year, month, day, year, sum);
}
void acm7()
{
	fflush(stdin);
	int num = 0;
	int a[4];
	scanf_s("%d", &num);
	a[0] = num / 1000;
	a[1] = num / 100 % 10;
	a[2] = num / 10 % 10;
	a[3] = num % 10;
	for (int i = 0; i < 4; i++)
	{
		a[i] += 5;
		a[i] %= 10;
	}
	for (int i = 0; i <= 3 / 2; i++)
	{
		int tmp = a[i];
		a[i] = a[3 - i];
		a[3 - i] = tmp;
	}
	for (int i = 0; i < 4; i++)
	{
		printf("%d", a[i]);
	}
}
void BiAdd()
{
	fflush(stdin);
	int i;
	P[1]++;
	for (i = 1; i <= 6; i++)
	{
		if (P[i] > 1) {
			P[i] = 0;
			P[i + 1]++;
		}
	}
}
int CountPerson()
{
	int n = 0, i;
	for (i = 1; i <= 6; i++)
		if (P[i])    n++;
	return n;
}
void acm8()
{
	int a[7] = { 0 }, max = 0, t = 0, i, j;
	for (i = 1; i <= 64; i++)
	{
		t = 0;
		if (i != 1)    BiAdd();
		if ((P[1] + P[2] > 0) && (P[1] + P[4] < 2) && (P[1] + P[5] + P[6] == 2) && (P[2] == P[3]) && (P[3] != P[4])) {
			if (P[4] == 0)
				if (P[5] == 0)		t = CountPerson();
				else    t = CountPerson();
		}
		if (t > max) {
			max = t;
			for (j = 1; j <= 6; j++)   a[j] = P[j];
		}
	}
	for (i = 1; i <= 6; i++)
		if (a[i])    printf("%c,", 'A' + i - 1);
}
void acm9()
{
	int max = 0, temp = 0;
	int n;
	printf("Please enter number");
	scanf("%d", &n);
	int p[100];
	printf("Please enter array");
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (temp <= 0)
			temp = p[i];
		else
			temp += p[i];
		if (max < temp)
			max = temp;
	}
	printf("%d", max);
}
void acm10(){}
// acm11
void pr_arr_3_11(int arr[], int len)
{
	if (arr == NULL || len < 1) return;
	pr_arr_3_11(arr, len - 1);
	printf("%-4d ", arr[len - 1]);
}
int cmp_3_11(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
void findNum_3_11(int src[], int len)
{
	if (src == NULL || len < 1) return;
	int i = 0;
	int* buff = (int*)malloc(sizeof(int) * len);
	memcpy(buff, src, sizeof(int) * len);
	qsort(buff, len, sizeof(int), cmp_3_11);
	printf("\n");
	pr_arr_3_11(buff, len);
	printf("\n\n");
	printf("the result:\n\n");
	for (i = 0; i < len; i++)
	{
		if (src[i] == buff[i])
			printf(" %d: %d ", i, src[i]);
	}
	free(buff);
}
void acm11()
{
	getchar();
	int src[N_3_11], i;;
	printf("\n");
	printf("qingshurushuzi:\n");
	for (i = 0; i < N_3_11; i++)
	{
		scanf("%d", &src[i]);
	}
	//int src[]={21,34,34,45,45,56,565,67,67,768,32};
	findNum_3_11(src, sizeof(src) / sizeof(int));
	printf("\n");
}
// acm12
int find_half_3_12(int* arr, int len)
{
	int count = 0;

	int cur = 0;
	int i = 0;
	assert(arr != NULL);
	for (; i < len; ++i)
	{
		if (count == 0)
		{
			cur = arr[i];
			count = 1;
		}
		else if (arr[i] == cur)
			count++;
		else
			count--;
	}
	return cur;
}
void acm12()
{
	getchar();
	int arr[N_3_12], i;
	printf("\n");
	printf("qingshurushuzi:\n");
	for (i = 0; i < N_3_12; i++)
	{
		scanf("%d", &arr[i]);
	}
	//int arr[] = { 1, 2, 2, 2, 3, 2, 6, 2, 7, 2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("this number is %d\n", find_half_3_12(arr, len));
	printf("\n");
}
void find_num_3_13(int* arr, int size)
{
	int num1 = 0;
	int num2 = 0;
	int i;
	int end_num = 0;
	int flag = 0;
	for (i = 0; i < size; i++)
	{
		end_num ^= *(arr + i);
	}
	while (!(end_num & 1))
	{
		flag++;
		end_num >>= 1;
	}
	for (i = 0; i < size; i++)
	{
		int tmp = arr[i] >> flag;
		if (tmp & 1)
		{
			num1 ^= arr[i];
		}
		else
		{
			num2 ^= arr[i];
		}
	}
	printf("num1=%d \nnum2=%d\n\n", num1, num2);
}
void acm13()
{
	getchar();
	int arr[N_3_13], i;
	printf("\n");
	printf("qingshurushuzi:\n");
	for (i = 0; i < N_3_13; i++)
	{
		scanf("%d", &arr[i]);
	}
	//int arr[] = { 1, 1, 2, 5, 3, 3, 4,4, 5,6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	find_num_3_13(arr, size);

	printf("\n");
}
void acm14()
{
	getchar();
	int i, j, x, k;
	printf("qingshu 2*3 de juzhen:\n");
	while (scanf_s("%d", &x) != EOF) {
		int a[2][3] = { 0 }, b[3][2] = { 0 }, c[2][2] = { 0 };
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 3; j++) {
				if (i == 0 && j == 0)
				{
					a[0][0] = x;
				}
				else
				{
					scanf("%d", &a[i][j]);
				}
			}
		}
		printf("\n");
		printf("qingshu 3*2 dejzhen :\n");
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 2; j++)
			{

				scanf_s("%d", &b[i][j]);
			}
		}
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++) {
				for (k = 0; k < 3; k++)
					c[i][j] += a[i][k] * b[k][j];
			}
		}
		printf("\n");
		printf("2*2dejuzhenwei:\n");
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++)
			{

				printf("%d", c[i][j]);
				if (j < 2)	printf(" ");
			}
			printf("\n");
		}
	}
	printf("\n");
}
void acm15() {
	printf("continue！");
}

void acm16(){}
// acm17
//Status is the type of function whose value is the function result status code
typedef int Status;
typedef struct {
	int* data;
	int length;
}List;


Status ListLength(List* L) {
	return L->length;
}//ListLength
Status InitList(List* L) {
	L->data = (int*)malloc(30 * sizeof(int));
	if (!L) exit(OVERFLOW);
	L->length = 0;
	return OK;
}//InitList
Status DestroyList(List* L) {
	free(L);
	return OK;
}//DestroyList
Status ClearList(List* L) {
	int i;
	for (i = 0; i <= ListLength(L); i++) {
		if (L->data[i] != 0)
			L->data[i] = 0;
		L->length--;
	}
	L->length--;
	return OK;
}//ClearList
Status ListEmpty(List* L) {
	if (L->length != 0)
		return FALSE;
	else
		return TRUE;
}//ListEmpty
Status GetElem(List* L, int i, int* e) {
	int j;
	for (j = 0; j < ListLength(L); j++)
		if (j == i - 1) {
			e = &L->data[j];
			break;
		}
	return *e;
}//GetElem
Status compare(List* a, int b) {
	int i, judge;
	for (i = 0, judge = 0; i < ListLength(a); i++) {
		if (a->data[i] == b) {
			judge = 1;
			return TRUE;
			break;
		}
	}
	if (judge == 0)
		return FALSE;
}//compare
Status LocateElem(List* L, int e, Status(*pfun)(List* ce, int num)) {
	int i;
	for (i = 0; i < ListLength(L); i++) {
		if (L->data[i] == e) {
			return i + 1;
			break;
		}
	}
	if (!pfun(L, e))
		return 0;
}//LocateElem
Status PriorElem(List* L, int cur_e, int* pre_e) {
	int i, judge;
	for (i = 0, judge = 0; i < ListLength(L); i++) {
		if (i != 0 && cur_e == L->data[i]) {
			judge = 1;
			pre_e = &L->data[i - 1];
			break;
		}
	}
	if (i == 0 || judge == 0)
		return ERROR;
	else
		return *pre_e;
}//PriorElem
Status NextElem(List* L, int cur_e, int* next_e) {
	int i, judge;
	for (i = 0, judge = 0; i < ListLength(L); i++)
		if (i != ListLength(L) - 1 && cur_e == L->data[i]) {
			judge = 1;
			next_e = &L->data[i + 1];
			break;
		}
	if (i == ListLength(L) - 1 || judge == 0)
		return ERROR;
	else
		return *next_e;
}//NextElem
Status ListInsert(List* L, int i, int e) {
	int j;
	if (i<1 || (i - 1)>ListLength(L)) return ERROR;
	else {
		for (j = ListLength(L); j >= i; j--)
			L->data[j] = L->data[j - 1];
		L->length++;
		L->data[j] = e;
		return OK;
	}
}
Status ListDelete(List* L, int i, int* e) {
	int j, temp;
	if (i<0 || i>ListLength(L)) return ERROR;
	temp = L->data[i];
	for (j = i; j < ListLength(L) - 1; j++)
		L->data[j] = L->data[j + 1];
	L->length--;
	e = &temp;
	return *e;
}//ListDelete
Status visit(List* L) {
	int i, judge;
	for (i = 0, judge = 0; i < ListLength(L); i++) {
		if (L->data[i] != NULL)
			judge = 1;
		else {
			judge = 0;
			break;
		}
	}
	if (judge == 0)
		return ERROR;
	else
		return OK;
}//visit
Status ListTraverse(List* L, Status(*pfun)(List* ce)) {
	if (pfun(L))
		return TRUE;
	else
		return FALSE;
}//ListTraverse
void UnionList(List* La, List* Lb) {
	La->length = ListLength(La);
	Lb->length = ListLength(Lb);
	int i, re, * el = NULL;
	Status(*pfun)(List * ce, int num);
	for (i = 0; i < Lb->length; i++) {
		re = GetElem(Lb, i + 1, el);
		if (!LocateElem(La, re, compare))
			printf("ListInsert Status: %d\n", ListInsert(La, La->length + 1, re));
	}
}//UnionList
void MergeList(List* La, List* Lb, List* Lc) {
	//La and LB are arranged in non decreasing order
	InitList(Lc);
	int i = 0, j = 0, k = 0;
	La->length = ListLength(La);
	Lb->length = ListLength(Lb);
	int* ai = NULL, * bj = NULL, a, b;
	while ((i < La->length) && (j < Lb->length)) {
		GetElem(La, i + 1, ai);
		a = GetElem(La, i + 1, ai);
		GetElem(Lb, j + 1, bj);
		b = GetElem(Lb, j + 1, bj);
		Lc->length;
		if (a <= b) {
			k++;
			ListInsert(Lc, k, a);
			i++;
		}
		else {
			k++;
			ListInsert(Lc, k, b);
			j++;
		}
	}
	while (i < La->length) {
		GetElem(La, i + 1, ai);
		a = GetElem(La, i + 1, ai);
		i++;
		k++;
		ListInsert(Lc, k, a);
	}
	while (j < Lb->length) {
		GetElem(Lb, j + 1, bj);
		b = GetElem(Lb, j + 1, bj);
		j++;
		k++;
		ListInsert(Lc, k, b);
	}
}//MergeList

void acm17()
{
	List* Li = (List*)malloc(sizeof(List));
	InitList(Li);
	int i, n, * r = NULL;
	printf("Enter List Li Length: ");
	scanf_s("%d", &n);
	printf("Enter %d numbers: ", n);
	for (i = 0; i < n; i++) {
		scanf_s("%d", &Li->data[i]);
		Li->length++;
	}
	ListLength(Li);
	ListEmpty(Li);
	GetElem(Li, 3, r);
	LocateElem(Li, 13, compare);
	PriorElem(Li, 16, r);
	NextElem(Li, 2, r);
	ListInsert(Li, 1, 1);
	ListDelete(Li, 2, r);
	ListTraverse(Li, visit);
	List* Lb = (List*)malloc(sizeof(List));
	InitList(Lb);
	int m;
	printf("Enter List Lb length: ");
	scanf_s("%d", &m);
	printf("Enter %d numbers: ", m);
	for (i = 0; i < m; i++) {
		scanf("%d", &Lb->data[i]);
		Lb->length++;
	}
	List* Lc = (List*)malloc(sizeof(List));
	MergeList(Li, Lb, Lc);
	ClearList(Li);
	ListEmpty(Li);
	DestroyList(Li);
	system("pause");
}
void acm18() {
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= i; j++) {
			printf("%2d x%2d = %-2d ", j, i, i * j);

		}
		printf("\n");
	}
}
void acm19() {
	int n;
	scanf("%d", &n);
	float t;
	for (int i = 1; i <= 10000000; i++) {
		t = i;
		for (int j = 1; j < n; j++) {
			t -= t / 2.0 + 1;
		}
		if (t == 1) {
			printf("%d", i);
			break;
		}
	}
}
// acm20
void InitStack(Seq_Stack* s)
{
	s->top = -1;
}
int Push(Seq_Stack* s, char c, int m, int n)
{
	if (s->top == Stack_size - 1)
		return 0;
	(s->top)++;
	s->Stack_obj[s->top] = c;
	s->Stack_pos[s->top][0] = m;
	s->Stack_pos[s->top][1] = n;
	return 1;
}
int Pop(Seq_Stack* s)
{
	if (s->top == -1)
		return 0;
	(s->top)--;
	return s->top;
}
int GetTop(Seq_Stack s)
{
	if (s.top == -1)
		return 0;
	else
		return s.Stack_obj[s.top];
}
void ClearStack(Seq_Stack* s)
{
	s->top == -1;
}
int IsEmpty(Seq_Stack s)
{
	if (s.top == -1)
		return 1;
	else
		return 0;
}
int IsFull(Seq_Stack s)
{
	if (s.top == Stack_size - 1)
		return 1;
	else
		return 0;
}
void Show(char maze[][11])
{
	for (int i = 0; i < 10; i++)
	{
		printf("%s", maze[i]);
	}
}
void recursion_Go(char maze[][11], int m, int n)
{
	if (maze[m][n] == 'E')
	{
		flag = Finish;
		maze[m][n] = '*';
		return;
	}
	//cout<<"flag:   "<<flag<<endl;;
	if ((maze[m][n + 1] == ' ' || maze[m][n + 1] == 'E'))
	{
		maze[m][n] = '*';
		recursion_Go(maze, m, n + 1);
		if (flag == Finish)
			return;
	}
	if ((maze[m + 1][n] == ' ' || maze[m + 1][n] == 'E'))
	{
		maze[m][n] = '*';
		recursion_Go(maze, m + 1, n);
		if (flag == Finish)
			return;
	}
	if ((maze[m][n - 1] == ' ' || maze[m][n - 1] == 'E'))
	{
		maze[m][n] = '*';
		recursion_Go(maze, m, n - 1);
		if (flag == Finish)
			return;
	}
	if ((maze[m - 1][n] == ' ' || maze[m - 1][n] == 'E'))
	{
		maze[m][n] = '*';
		recursion_Go(maze, m - 1, n);
		if (flag == Finish)
			return;
	}
	maze[m][n] = '!';
}
void non_recursion_Go(char maze[][11], int m, int n)
{
	int p = 0;
	Seq_Stack s;
	InitStack(&s);
	M Maze[10][11];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			Maze[i][j].c = maze[i][j];
			Maze[i][j].Count = 0;
			Maze[i][j].backx = 0;
			Maze[i][j].backy = 0;
			Maze[i][j].flag = No_in_Stack;
		}
	}
	char c;
	int top;
	int a, b;
	Push(&s, Maze[m][n].c, m, n);
	Maze[m][n].flag = In_Stack;
	while (!IsEmpty(s))
	{
		top = Pop(&s);
		c = s.Stack_obj[top + 1];
		a = s.Stack_pos[top + 1][0];
		b = s.Stack_pos[top + 1][1];
		Maze[a][b].c = '*';

		if (c == ' ' || c == 'S')
		{
			Maze[a][b].c = '*';
			if (Maze[a - 1][b].c == ' ' || Maze[a - 1][b].c == 'E')
			{
				if (Maze[a - 1][b].flag == No_in_Stack)
				{
					Push(&s, Maze[a - 1][b].c, a - 1, b);
					Maze[a][b].Count++;
					Maze[a - 1][b].backx = a;
					Maze[a - 1][b].backy = b;
					Maze[a - 1][b].flag = In_Stack;
				}
			}
			if (Maze[a][b - 1].c == ' ' || Maze[a][b - 1].c == 'E')
			{
				if (Maze[a][b - 1].flag == No_in_Stack)
				{
					Push(&s, Maze[a][b - 1].c, a, b - 1);
					Maze[a][b].Count++;
					Maze[a][b - 1].backx = a;
					Maze[a][b - 1].backy = b;
					Maze[a][b - 1].flag = In_Stack;
				}
			}
			if (Maze[a + 1][b].c == ' ' || Maze[a + 1][b].c == 'E')
			{
				if (Maze[a + 1][b].flag == No_in_Stack)
				{
					Push(&s, Maze[a + 1][b].c, a + 1, b);
					Maze[a][b].Count++;
					Maze[a + 1][b].backx = a;
					Maze[a + 1][b].backy = b;
					Maze[a + 1][b].flag = In_Stack;
				}
			}
			if (Maze[a][b + 1].c == ' ' || Maze[a][b + 1].c == 'E')
			{
				if (Maze[a][b + 1].flag == No_in_Stack)
				{
					Push(&s, Maze[a][b + 1].c, a, b + 1);
					Maze[a][b].Count++;
					Maze[a][b + 1].backx = a;
					Maze[a][b + 1].backy = b;
					Maze[a][b + 1].flag = In_Stack;
				}
			}
		}
		if (c == 'E')
		{
			Maze[a][b].c = '*';
			break;
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Maze[i][j].c == '*' && Maze[i][j].Count == 0)
				{
					Maze[Maze[i][j].backx][Maze[i][j].backy].Count--;
					Maze[i][j].c = '!';
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Maze[i][j].Count == 0 && Maze[i][j].c == '*')
				{
					Maze[i][j].c = '!';
				}
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			maze[i][j] = Maze[i][j].c;
		}
	}
}
void acm20()
{
	char maze[10][11];
	getchar();
	for (int i = 0; i < 10; i++)
	{
		fgets(maze[i], 10, stdin);
	}
	int a, b;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (maze[i][j] == 'S')
			{
				a = i;
				b = j;
			}
		}
	}
	non_recursion_Go(maze, a, b);
	Show(maze);
}

void linux1(){}
void linux2(){}
void linux3(){}
void linux4(){}
void linux5(){}
void linux6(){}
void linux7(){}
void linux8(){}
void linux9(){}
void linux10(){}

void str_opt()
{
	printf("1:String length               16:Delete substring \n");
	printf("2:String copy                 17:Delete specified word \n");
	printf("3:String cat                  18:Sum of large numbers \n");
	printf("4:String cmp                  19:Parity sort \n");
	printf("5:Non-space characters plus 1 20:Characters that appear only once \n");
	printf("6:String case conversion1     21:Find substring \n");
	printf("7:String case conversion2     22:String, output the sum of all numbers \n");
	printf("8:Word count                  23:Convert string to integer1 \n");
	printf("9:Remove extra spaces         24:Convert string to integer2 \n");
	printf("10:Hidden Headwords           25:Judge whether the letter has appeared \n");
	printf("11:Palindrome string          26:String inversion2 \n");
	printf("12:String inversion1          27:Characters that appear 2 times \n");
	printf("13:String exchange            28:Remove duplicate characters \n");
	printf("14:Statistics string          29:Find the longest symmetric string \n");
	printf("15:Delete specified characters30:Binary addition \n");
	printf("\nPlease enter options\n");
	int a;
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		str1();
		break;
	case 2:
		str2();
		break;
	case 3:
		str3();
		break;
	case 4:
		str4();
		break;
	case 5:
		str5();
		break;
	case 6:
		str6();
		break;
	case 7:
		str7();
		break;
	case 8:
		str8();
		break;
	case 9:
		str9();
		break;
	case 10:
		str10();
		break;
	case 11:
		str11();
		break;
	case 12:
		str12();
		break;
	case 13:
		str13();
		break;
	case 14:
		str14();
		break;
	case 15:
		str15();
		break;
	case 16:
		str16();
		break;
	case 17:
		str17();
		break;
	case 18:
		str18();
		break;
	case 19:
		str19();
		break;
	case 20:
		str20();
		break;
	case 21:
		str21();
		break;
	case 22:
		str22();
		break;
	case 23:
		str23();
		break;
	case 24:
		str24();
		break;
	case 25:
		str25();
		break;
	case 26:
		str26();
		break;
	case 27:
		str27();
		break;
	case 28:
		str28();
		break;
	case 29:
		str29();
		break;
	case 30:
		str30();
		break;
	default:
		break;
	}
}
void sort_opt()
{
	printf("1:Out the second largest number\n");
	printf("2:Binary search\n");
	printf("3:Ordered matrix\n");
	printf("4:Bubble Sort\n");
	printf("5:Direct insertion sort\n");
	printf("6:Hill sort\n");
	printf("7:Quick sort\n");
	printf("8:Merge sort\n");
	printf("9:Heap sort\n");
	printf("10:Simple selection sort\n");
	printf("\nPlease enter options\n");
	int a;
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		px1();
		break;
	case 2:
		px2();
		break;
	case 3:
		px3();
		break;
	case 4:
	case 5:
	case 6:
		px456();
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		px10();
		break;
	default:
		break;
	}
}
void acm_opt() {
	printf("1:The sum of the individual digits of an integer number \n");
	printf("2:3x3 matrix \n");
	printf("3:Sorting of three numbers \n");
	printf("4:Prime sum \n");
	printf("5:No repeated three digits \n");
	printf("6:The day of the year \n");
	printf("7:4-digit encryption n");
	printf("8:Urgent task\n");
	printf("9:And the maximum value subarray\n");
	printf("10:Kth node from the bottom\n");
	printf("11:int array sort\n");
	printf("12:There is a number in the array\n");
	printf("13:Two numbers that only appear once\n");
	printf("14:Product of two matrices \n");
	printf("15:Is there a ring in the singly linked list\n");
	printf("16:Invert a singly linked list\n");
	printf("17:Merge new linear table\n");
	printf("18:Print the multiplication formula table\n");
	printf("19:Monkey eating peach problem\n");
	printf("20:Maze problem\n");
	printf("\nPlease enter options\n");
	int a;
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		acm1();
		break;
	case 2:
		acm2();
		break;
	case 3:
		acm3();
		break;
	case 4:
		acm4();
		break;
	case 5:
		acm5();
		break;
	case 6:
		acm6();
		break;
	case 7:
		acm7();
		break;
	case 8:
		acm8();
		break;
	case 9:
		acm9();
		break;
	case 10:
		acm10();
		break;
	case 11:
		acm11();
		break;
	case 12:
		acm12();
		break;
	case 13:
		acm13();
		break;
	case 14:
		acm14();
		break;
	case 15:
		acm15();
		break;
	case 16:
		acm16();
		break;
	case 17:
		acm17();
		break;
	case 18:
		acm18();
		break;
	case 19:
		acm19();
		break;
	case 20:
		acm20();
		break;
	default:
		break;
	}
}
void linux_opt() {
	printf("1.The letters 'a-z' Of the loop.\n");
	printf("2.Read a linux file.\n");
	printf("3.Use file IO function to complete cp \n");
	printf("4.Child process and parent process \n");
	printf("5.Zombie process and orphan process \n");
	printf("6.Anonymous pipe \n");
	printf("7.message queue \n");
	printf("8.Output a string in seconds \n");
	printf("9.Capture SIGINT signal and SIGQUIT signal \n");
	printf("10.Four threads \n");
	int a;
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		linux1();
		break;
	case 2:
		linux2();
		break;
	case 3:
		linux3();
		break;
	case 4:
		linux4();
		break;
	case 5:
		linux5();
		break;
	case 6:
		linux6();
		break;
	case 7:
		linux7();
		break;
	case 8:
		linux8();
		break;
	case 9:
		linux9();
		break;
	case 10:
		linux10();
		break;
	default:
		break;
	}

}
