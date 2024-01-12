/*******************************************************
 *	test.c
 *	author:��������
 *	copyright(c) 2015 - ~: ��鿴LICENSE�ļ�
 *	Description(����):����
 ******************************************************/
#include "header.h"

/*������ʽ�ָ�ʾ��*/
void test_splite_c() {
	printf("splite------\n");
	struct regex* reg = construct_regex("a{2}[ab]{2,3}");
	char* str = "aaabtaaabbbtaabaa";
	if (!regex_splite(str, reg)) {
		printf("%s\n", error_str);
	}
	else {
		//ƥ����ַ���
		struct regex_match_iterator* m_it = reg->match_strs;
		while (m_it) {
			printf("%s\n", m_it->value);
			m_it = m_it->next;
		}
		printf("\n");
		//���ָ���ַ���
		struct regex_token_iterator* t_it = reg->token_strs;
		while (t_it) {
			printf("%s\n", t_it->value);
			t_it = t_it->next;
		}
		printf("\n");
	}
	free_regex(reg);
	free(reg);
	printf("splite------\n");
}

/*������ʽ����ʾ��*/
void test_search_c() {
	printf("search------\n");
	struct regex reg;
	reg.reg_str = "shja\\U{2,4}";
	char* str = "shjabbbahsytHeywew";
	if (regex_search(str, &reg)) {
		printf("%s\n", reg.match_strs->value);
	}
	else {
		printf("%s not found!\n", reg.reg_str);
	}
	free_regex(&reg);
	printf("search------\n");
}

/*������ʽƥ��ʾ��*/
void test_match_c() {
	printf("match------\n");
	struct regex reg;
	reg.reg_str = "shja\\u{2,4}[\\.\\(]{0,4}[jkl]{3,}m{3}";
	char* str = "shjaEWR.(.jkkljkljlkmmm";
	if (regex_match(str, &reg)) {
		printf("match!\n");
	}
	else {
		printf("not match!\n");
	}
	char* str1 = "shjaEWR.(...jkkljkljlkmmm";
	if (regex_match(str1, &reg)) {
		printf("match!\n");
	}
	else {
		printf("not match!\n");
	}
	free_regex(&reg);
	printf("match------\n");
}

int main() {
	test_splite_c();
	printf("\n");
	test_search_c();
	printf("\n");
	test_match_c();
	printf("\n");
#ifdef _WIN32
	system("pause");
#endif
	return 0;
}
