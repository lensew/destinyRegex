/*******************************************************
 *	c_regex_engine.h
 *	author:��������
 *	copyright(c) 2015 - ~: ��鿴LICENSE�ļ�
 *	Description(����):������ʽ����
 ******************************************************/
#pragma once
/*regex�Զ���*/
#ifndef C_REGEX_AUTO_MACHINE
#define C_REGEX_AUTO_MACHINE
#include "c_defines.h"

static struct condition* current_condition;
static struct condition* temp_condition;

static struct single_condition* current_s_condition;
static struct single_condition* temp_s_condition;

static struct list_char* current_char_list;
static struct list_char* temp_list_char;

static int temp_index = 0;

static bool is_large_brace_cloes = true;
static bool is_mid_bracket_close = true;
static bool is_bracket_close = true;

static int temp_least_num = 0;
static int temp_max_num = 0;

/*���list_char*/
void char_list_add_char(char c) {
	if (!current_char_list) {
		current_char_list = construct_char(c);
		temp_list_char = current_char_list;
	}
	else {
		temp_list_char->next = construct_char(c);
		temp_list_char = temp_list_char->next;
	}
}

/*���Single_condition*/
void s_condition_add_s_condition(struct list_char* list) {
	if (!current_s_condition) {
		current_s_condition = construct_s_condition(list, temp_least_num, temp_max_num);
		temp_s_condition = current_s_condition;
	}
	else {
		temp_s_condition->next = construct_s_condition(list, temp_least_num, temp_max_num);
		temp_s_condition = temp_s_condition->next;
	}
}

/*���condition*/
void condition_add_condition(struct single_condition* s_con) {
	if (!current_condition) {
		current_condition = construct_condition(s_con);
		temp_condition = current_condition;
	}
	else {
		temp_condition->next = construct_condition(s_con);
		temp_condition = temp_condition->next;
	}
}

/*list_char��������ַ�*/
void char_list_add_many_char(char start, char end) {
	if (!current_char_list) {
		current_char_list = construct_char(start);
		temp_list_char = current_char_list;
	}
	else {
		temp_list_char->next = construct_char(start);
		temp_list_char = temp_list_char->next;
	}
	if (end >= 127) {
		end = 126;
	}
	for (char t = start + 1; t <= end; t++) {
		temp_list_char->next = construct_char(t);
		temp_list_char = temp_list_char->next;
	}
}

/*ת���ַ�����*/
bool change_letter(struct regex* reg, int begin, int end) {
	if (begin > end) {
		return false;
	}
	switch (reg->reg_str[begin]) {
		case CHANGE_LETTER:
			char_list_add_char(CHANGE_LETTER);
			return true;
		case TAB:
			char_list_add_char('\t');
			return true;
		case RETURN_:
			char_list_add_char('\r');
			return true;
		case NEW_LINE:
			char_list_add_char('\n');
			return true;
		case TAB_V:
			char_list_add_char('\v');
			return true;
		case NEW_PAGE:
			char_list_add_char('\f');
			return true;
		case LEFT_BRACKET:
			char_list_add_char(LEFT_BRACKET);
			return true;
		case RIGHT_BRACKET:
			char_list_add_char(RIGHT_BRACKET);
			return true;
		case LEFT_LARGE_BRACE:
			char_list_add_char(LEFT_LARGE_BRACE);
			return true;
		case RIGHT_LARGE_BRACE:
			char_list_add_char(RIGHT_LARGE_BRACE);
			return true;
		case LEFT_MID_BRACKET:
			char_list_add_char(LEFT_MID_BRACKET);
			return true;
		case RIGHT_MID_BRACKET:
			char_list_add_char(RIGHT_MID_BRACKET);
			return true;
		case BLANK:
			char_list_add_char(BLANK);
			return true;
		case COMMA:
			char_list_add_char(COMMA);
			return true;
		case DOT:
			char_list_add_char(DOT);
			return true;
		case MULTI_MATCH_LETTER:
			char_list_add_char(MULTI_MATCH_LETTER);
			return true;
		case QUES:
			char_list_add_char(QUES);
			return true;
		case PLUS:
			char_list_add_char(PLUS);
			return true;
		case DECIMAL:
			char_list_add_many_char('0', '9');
			return true;
		case LOWER_LETTER:
			char_list_add_many_char('a', 'z');
			return true;
		case SPACE:
			char_list_add_char(BLANK);
			char_list_add_char('\t');
			char_list_add_char('\r');
			char_list_add_char('\n');
			char_list_add_char('\v');
			char_list_add_char('\f');
			return true;
		case UPER_LETTER:
			char_list_add_many_char('A', 'Z');
			return true;
		case SIMPLE_LETTER:
			char_list_add_many_char('0', '9');
			char_list_add_many_char('a', 'z');
			char_list_add_many_char('A', 'Z');
			char_list_add_char('_');
			return true;
		case NOT_DECIMAL:
			char_list_add_many_char(-128, '0' - 1);
			char_list_add_many_char('9' + 1, 126);
			char_list_add_char(127);
			return true;
		case NOT_LOWER_LETTER:
			char_list_add_many_char(-128, 'a' - 1);
			char_list_add_many_char('z' + 1, 126);
			char_list_add_char(127);
			return true;
		case NOT_SPACE:
			char_list_add_many_char(-128, 8);
			char_list_add_many_char(14, 31);
			char_list_add_many_char(33, 126);
			char_list_add_char(127);
			return true;
		case NOT_UPER_LETTER:
			char_list_add_many_char(-128, 'A'-1);
			char_list_add_many_char('Z' + 1, 126);
			char_list_add_char(127);
			return true;
		case NOT_SIMPLE_LETTER:
			char_list_add_many_char(-128, '0' - 1);
			char_list_add_many_char('9' + 1, 'A' - 1);
			char_list_add_many_char('Z' + 1, '_' - 1);
			char_list_add_char(96);
			char_list_add_many_char('z' + 1, 126);
			char_list_add_char(127);
			return true;
		case RANGE_LETTER:
			char_list_add_char(RANGE_LETTER);
			return true;
		default:
			error_str = "�����ת���ַ�!";
			return false;
	}
}

/*�ַ���Χ��-�Ĵ���*/
bool range(struct regex* reg, int begin, int end) {
	if (begin > end) {
		return false;
	}
	char end_char = reg->reg_str[begin];
	if (current_char_list) {
		if (temp_list_char->value < end_char) {
			if (end_char == 127) {
				char_list_add_many_char(temp_list_char->value + 1, 126);
				char_list_add_char(127);
			}
			else {
				char_list_add_many_char(temp_list_char->value + 1, end_char);
			}
		}
		else {
			error_str = "�Ƿ��ķ�Χ(-���ַ�����С��-�Ҳ��ַ�)!";
			return false;
		}
	}
	else {
		char_list_add_char(RANGE_LETTER);
	}
	return true;
}

/*�����������е�����*/
bool left_mid_bracket(struct regex* reg, int begin, int end) {
	for (int i = begin; i <= end; i++) {
		switch (reg->reg_str[i]) {
			case LEFT_BRACKET:
			case RIGHT_BRACKET:
				error_str = "������[]�в�����Ƕ��С����()!";
				return false;
			case LEFT_LARGE_BRACE:
			case RIGHT_LARGE_BRACE:
				error_str = "������[]�в�����Ƕ�״�����{}!";
				return false;
			case LEFT_MID_BRACKET:
				error_str = "������[]������Ƕ��!";
				return false;
			case RIGHT_MID_BRACKET:
				if (current_char_list) {
					is_mid_bracket_close = true;
					temp_index = i;
					return true;
				}
				else {
					error_str = "������[]�в���Ϊ��!";
					return false;
				}
				//break;
			case CHANGE_LETTER:
				if (!change_letter(reg, i + 1, end)) {
					return false;
				}
				else {
					i++;
				}
				break;
			case RANGE_LETTER:
				if (!range(reg, i + 1, end)) {
					return false;
				}
				break;
			default:
				char_list_add_char(reg->reg_str[i]);
				break;
		}
	}
	error_str = "��������[δ�ҵ�ƥ�����������]!";
	return false;
}

/*�õ�ƥ������*/
bool get_match_num(struct regex* reg, int begin, int end) {
	if (begin > end || reg->reg_str[begin] != LEFT_LARGE_BRACE) {
		if (reg->reg_str[begin] == PLUS) {
			temp_index = begin;
			temp_least_num = 1;
			temp_max_num = MAX_INT_VAL;
			return true;
		}
		if (reg->reg_str[begin] == MULTI_MATCH_LETTER) {
			temp_index = begin;
			temp_least_num = 0;
			temp_max_num = MAX_INT_VAL;
			return true;
		}
		temp_least_num = 1;
		temp_max_num = 1;
		temp_index = begin - 1;
		return true;
	}
	char* buffer = (char*)malloc(sizeof(char) * 11);
	int temp_num = 0;
	int comma_num = 0;
	for (int i = begin + 1; i <= end; i++) {
		if (reg->reg_str[i] == BLANK || reg->reg_str[i] >= '0'&&reg->reg_str[i] <= '9') {
			if (temp_num > 9) {
				error_str = "ƥ�����������̫��!";
				free(buffer);
				return false;
			}
			buffer[temp_num] = reg->reg_str[i];
			temp_num++;
		}
		else if (reg->reg_str[i] == COMMA) {
			if (comma_num > 0) {
				error_str = "ƥ������﷨����!";
				free(buffer);
				return false;
			}
			buffer[temp_num] = '\0';
			comma_num++;
			if (is_num(buffer)) {
				temp_least_num = atoi(buffer);
				temp_num = 0;
			}
			else {
				error_str = "ƥ������﷨����!";
				free(buffer);
				return false;
			}
		}
		else if (reg->reg_str[i] == RIGHT_LARGE_BRACE) {
			if (comma_num > 0) {
				buffer[temp_num] = '\0';
				if (is_num(buffer)) {
					temp_max_num = atoi(buffer);
					if (temp_least_num > temp_max_num) {
						error_str = "��Сƥ��������ܴ������ƥ�����!";
						free(buffer);
						return false;
					}
				}
				else {
					if (has_num(buffer)) {
						error_str = "ƥ������﷨����!";
						free(buffer);
						return false;
					}
					else {
						temp_max_num = MAX_INT_VAL;
					}
				}
			}
			else {
				buffer[temp_num] = '\0';
				if (is_num(buffer)) {
					temp_least_num = atoi(buffer);
					temp_max_num = temp_least_num;
				}
				else {
					error_str = "ƥ������﷨����!";
					free(buffer);
					return false;
				}
			}
			temp_index = i;
			free(buffer);
			return true;
		}
		else {
			error_str = "����ƥ�����ʱ������������ַ�";
			free(buffer);
			return false;
		}
	}
	error_str = "�������{���Ҵ�����}��ƥ��!";
	free(buffer);
	return false;
}

/*�ͷſռ�*/
void free_current() {
	if (current_char_list) {
		free_char_list(current_char_list);
	}
	if (current_s_condition) {
		free_single_conditions(current_s_condition);
	}
	if (current_condition) {
		free_conditions(current_condition);
	}
}

/*��ʼ״̬*/
/*NOTICE:��ʹ��type����*/
bool init(struct regex* reg, int begin, int end, int type/*��ʹ�ô˲���*/) {
	//�ǵ��ڷ���falseǰfree�����е���Դ
	current_condition = NULL;
	temp_condition = NULL;
	current_s_condition = NULL;
	temp_s_condition = NULL;
	current_char_list = NULL;
	temp_list_char = NULL;
	for (int i = begin; i <= end; i++) {
		switch (reg->reg_str[i]) {
			case LEFT_LARGE_BRACE:
				error_str = "�������{����ֱ�ӳ���!";
				free_current();
				return false;
			case RIGHT_LARGE_BRACE:
				error_str = "�Ҵ�����}�Ҳ���ƥ����������!";
				free_current();
				return false;
			case LEFT_BRACKET:
			case RIGHT_BRACKET:
				//NOTICE
				error_str = "��ʱ��֧��ʹ��С����()�ֶ�ƥ��";
				free_current();
				return false;
			case OR_CHAR:
				if (!current_s_condition) {
					error_str = "|��ʹ�ò���ȷ!";
					free_current();
					return false;
				}
				condition_add_condition(current_s_condition);
				current_s_condition = NULL;
				temp_s_condition = NULL;
				break;
			case PLUS:
				error_str = "�Ӻ�+���ܵ�������!";
				free_current();
				return false;
			case MULTI_MATCH_LETTER:
				error_str = "�Ǻ�*���ܵ�������!";
				free_current();
				return false;
			case LEFT_MID_BRACKET:
				if (is_mid_bracket_close) {
					if (!left_mid_bracket(reg, i + 1, end)) {
						free_current();
						return false;
					}
					else {
						i = temp_index;
						if (get_match_num(reg, i + 1, end)) {
							s_condition_add_s_condition(current_char_list);
							i = temp_index;
							current_char_list = NULL;
							temp_list_char = NULL;
						}
						else {
							free_current();
							return false;
						}
					}
				}
				else {
					error_str = "������[]������Ƕ��!";
					free_current();
					return false;
				}
				break;
			case RIGHT_MID_BRACKET:
				error_str = "���������Ҳ���ƥ�����������!";
				free_current();
				return false;
			case CHANGE_LETTER:
				if (!change_letter(reg, i + 1, end)) {
					free_current();
					return false;
				}
				else {
					i++;
					if (get_match_num(reg, i + 1, end)) {
						s_condition_add_s_condition(current_char_list);
						i = temp_index;
						current_char_list = NULL;
						temp_list_char = NULL;
					}
					else {
						free_current();
						return false;
					}
				}
				break;
			case QUES:
				char_list_add_many_char(-128, 126);
				char_list_add_char(127);
				temp_least_num = 1;
				temp_max_num = 1;
				s_condition_add_s_condition(current_char_list);
				current_char_list = NULL;
				temp_list_char = NULL;
				break;
			case DOT:
				char_list_add_many_char(-128, 126);
				char_list_add_char(127);
				if (get_match_num(reg, i + 1, end)) {
					s_condition_add_s_condition(current_char_list);
					i = temp_index;
					current_char_list = NULL;
					temp_list_char = NULL;
				}
				else {
					free_current();
					return false;
				}
				break;
			default:
				char_list_add_char(reg->reg_str[i]);
				if (get_match_num(reg, i + 1, end)) {
					s_condition_add_s_condition(current_char_list);
					i = temp_index;
					current_char_list = NULL;
					temp_list_char = NULL;
				}
				else {
					free_current();
					return false;
				}
				break;
		}
	}
	if (current_s_condition) {
		condition_add_condition(current_s_condition);
		current_s_condition = NULL;
		temp_s_condition = NULL;
	}
	if (!current_condition) {
		error_str = "������ʽ����Ϊ��!";
		free_current();
		return false;
	}
	reg->conditions = current_condition;
	current_condition = NULL;
	return true;
}

#endif