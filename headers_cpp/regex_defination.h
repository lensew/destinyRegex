/*******************************************************
 *	regex_defination.h
 *	author:��������
 *	copyright(c) 2015 - ~: ��鿴LICENSE�ļ�
 *	Description(����):������ʽ����
 ******************************************************/
#ifndef REGEX_ENGINE_H
#define REGEX_ENGINE_H

#define MAX_INT_VAL 0x3FFFFFFF

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


#endif
