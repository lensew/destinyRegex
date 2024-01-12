/*******************************************************
 *	c_defines.h
 *	author:��������
 *	copyright(c) 2015 - ~: ��鿴LICENSE�ļ�
 *	Description(����):һЩ����
 ******************************************************/
#pragma once
 /*���ݽṹ����*/
#ifndef C_DESTINY_REGEX
#define C_DESTINY_REGEX

#define NULL 0
#define MAX_INT_VAL 0x3FFFFFFF

#define true 1
#define false 0
#define bool char

#include <stdlib.h>
#include <string.h>

#define OR_CHAR '|'
#define LEFT_LARGE_BRACE '{'
#define RIGHT_LARGE_BRACE '}'
#define LEFT_MID_BRACKET '['
#define RIGHT_MID_BRACKET ']'
#define LEFT_BRACKET '('
#define RIGHT_BRACKET ')'
#define CHANGE_LETTER '\\' //˫б��ת��
#define TAB 't' //��Ҫת��
#define RETURN_ 'r' //��Ҫת��
#define NEW_LINE 'n' //��Ҫת��
#define NEW_PAGE 'f' //��Ҫת��
#define TAB_V 'v' //��Ҫת��
#define BLANK ' ' //�ո�
#define COMMA ',' //����
#define DOT '.' //ͨ���
#define MULTI_MATCH_LETTER '*' //���ƥ���
#define QUES '?' //0��1��
#define PLUS '+' //һ������
#define DECIMAL 'd' //һ��ʮ��������,��Ҫת��
#define LOWER_LETTER 'l' //һ��Сд��ĸ,��Ҫת��
#define SPACE 's' //һ���հ׷����ո�����Ʊ���ȣ�,��Ҫת��
#define UPER_LETTER 'u'//һ����д��ĸ,��Ҫת��
#define SIMPLE_LETTER 'w' //һ����ĸ��a��z��A��Z�������֣�0��9�����»��ߣ�_��,��Ҫת��
#define NOT_DECIMAL 'D' //����\d֮����ַ�,��Ҫת��
#define NOT_LOWER_LETTER 'L' //����\l֮����ַ�,��Ҫת��
#define NOT_SPACE 'S' //����\s֮����ַ�,��Ҫת��
#define NOT_UPER_LETTER 'U' //����\u֮����ַ�,��Ҫת��
#define NOT_SIMPLE_LETTER 'W' //����\w֮����ַ�,��Ҫת��
#define RANGE_LETTER '-' //��Χ��ʾ��

char* error_str = "";//������Ϣ

/*ƥ���ַ���ѡ�б�*/
struct list_char {
	char value;
	struct list_char *next;
};

/*����list_char*/
struct list_char* construct_char(char c) {
	struct list_char* list = (struct list_char*)malloc(sizeof(struct list_char));
	list->value = c;
	list->next = NULL;
	return list;
}

/*������ʽ��һƥ�䵥Ԫ*/
struct single_condition {
	struct list_char* match_letters;
	struct single_condition* next;
	unsigned int least_match_time;//����ƥ�����
	unsigned int max_match_time;//���ƥ�����
};

/*����single_condition*/
struct single_condition* construct_s_condition(struct list_char* list, int l_m_time, int m_m_time) {
	struct single_condition* con = (struct single_condition*)malloc(sizeof(struct single_condition));
	con->match_letters = list;
	con->least_match_time = l_m_time;
	con->max_match_time = m_m_time;
	con->next = NULL;
	return con;
}

/*������ʽƥ�䵥Ԫ*/
struct condition {
	struct single_condition* single_conditions;
	struct condition* next;
};

/*����condition*/
struct condition* construct_condition(struct single_condition* s_con) {
	struct condition* con = (struct condition*)malloc(sizeof(struct condition));
	con->single_conditions = s_con;
	con->next = NULL;
	return con;
}

/*ƥ���ַ���*/
struct regex_match_iterator {
	struct regex_match_iterator* next;
	char* value;
};

/*����regex_match_iterator*/
struct regex_match_iterator* construct_match_iterator(char* val) {
	struct regex_match_iterator* it = (struct regex_match_iterator*)malloc(sizeof(struct regex_match_iterator));
	it->next = NULL;
	it->value = val;
	return it;
}

/*δƥ���ַ���������ַ���*/
struct regex_token_iterator {
	struct regex_token_iterator* next;
	char* value;
};

/*����regex_token_iterator*/
struct regex_token_iterator* construct_token_iterator(char* val) {
	struct regex_token_iterator* it = (struct regex_token_iterator*)malloc(sizeof(struct regex_token_iterator));
	it->next = NULL;
	it->value = val;
	return it;
}

/*������ʽ*/
/*ƥ��֮ǰ����compiler*/
struct regex {
	const char* reg_str;
	int str_len;
	struct condition* conditions;
	struct regex_match_iterator* match_strs;
	struct regex_token_iterator* token_strs;
};

/*����regex*/
struct regex* construct_regex(const char* str) {
	struct regex* reg = (struct regex*)malloc(sizeof(struct regex));
	reg->conditions = NULL;
	reg->reg_str = str;
	reg->str_len = 0;
	reg->match_strs = NULL;
	reg->token_strs = NULL;
	return reg;
}


/*�ͷ�list_char�ռ�*/
void free_char_list(struct list_char* list) {
	struct list_char* next;
	while (list) {
		next = list->next;
		free(list);
		list = next;
	}
}

/*�ͷ�single_condition�ռ�*/
void free_single_conditions(struct single_condition* s_con) {
	struct single_condition* next;
	while (s_con) {
		next = s_con->next;
		free_char_list(s_con->match_letters);
		free(s_con);
		s_con = next;
	}
}

/*�ͷ�condition�ռ�*/
void free_conditions(struct condition *con) {
	struct condition* next;
	while (con) {
		next = con->next;
		free_single_conditions(con->single_conditions);
		free(con);
		con = next;
	}
}

/*�ͷ�regex_match_iterator�ռ�*/
void free_match_iterator(struct regex_match_iterator* it) {
	struct regex_match_iterator* next;
	while (it) {
		next = it->next;
		free(it->value);
		free(it);
		it = next;
	}
}

/*�ͷ�regex_token_iterator�ռ�*/
void free_regex_token_iterator(struct regex_token_iterator* it) {
	struct regex_token_iterator* next;
	while (it) {
		next = it->next;
		free(it->value);
		free(it);
		it = next;
	}
}

/*�ͷ�regex�ռ�*/
void free_regex(struct regex* reg) {
	free_conditions(reg->conditions);
	free_match_iterator(reg->match_strs);
	free_regex_token_iterator(reg->token_strs);
}

/*�Ƿ���������ַ�*/
bool has_num(const char* str) {
	int index = 0;
	while (str[index] != '\0') {
		if (str[index] >= '0'&&str[index] <= '9') {
			return true;
		}
		index++;
	}
	return false;
}

/*�Ƿ���һ������*/
bool is_num(const char* str) {
	bool has_num_char = false;
	bool has_num = false;
	int index = 0;
	while (str[index] != '\0') {
		if (str[index] >= '0'&&str[index] <= '9') {
			if (has_num) {
				return false;
			}
			has_num_char = true;
		}
		else if (str[index] == ' ') {
			if (has_num_char) {
				has_num = true;
			}
		}
		else {
			return false;
		}
		index++;
	}
	return has_num_char;
}


/*�õ�������ʽ���ƥ�䳤��*/
int get_regex_least_length(struct regex* reg) {
	int least_len = MAX_INT_VAL;
	int len;
	struct condition* con = reg->conditions;
	while (con) {
		len = 0;
		struct single_condition* s_con = con->single_conditions;
		while (s_con) {
			len += s_con->least_match_time;
			s_con = s_con->next;
		}
		if (len < least_len) {
			least_len = len;
		}
		con = con->next;
	}
	return least_len;
}

/*�õ�������ʽ�ƥ�䳤��*/
int get_regex_max_length(struct regex* reg) {
	int max_len = 0;
	int len;
	struct condition* con = reg->conditions;
	while (con) {
		len = 0;
		struct single_condition* s_con = con->single_conditions;
		while (s_con) {
			if (len < MAX_INT_VAL) {
				len += s_con->max_match_time;
			}
			s_con = s_con->next;
		}
		if (len > max_len) {
			max_len = len;
		}
		con = con->next;
	}
	return max_len;
}

/*�����ַ���*/
char* generate_str(const char* str, int start, int end) {
	char* s = (char*)malloc((end - start + 2)*sizeof(char));
	int j = 0;
	for (int i = start; i <= end; i++) {
		s[j] = str[i];
		j++;
	}
	s[j] = '\0';
	return s;
}
#endif
