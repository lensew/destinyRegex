/*******************************************************
 *	test.cpp
 *	author:��������
 *	copyright(c) 2015 - ~: ��鿴LICENSE�ļ�
 *	Description(����):����
 ******************************************************/
#include "header.h"
using std::string;

//����������ʽ�ָ��ַ���
void test_token_cpp() {
	RegularExpression::string str = "abcdabcdacbd";
	try {
		regex reg("[ab]{1,2}");
		sregex_token_iterator it(str.begin(), str.end(), reg, -1);
		sregex_token_iterator end;
		while (it != end) {
			cout << *it << endl;
			it++;
		}
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

//����������ʽƥ��
void test_match_cpp() {
	string str = "abcdabcdacbd";
	try {
		regex reg("abcd");
		if (regex_match(str, reg)) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

//����������ʽ����
void test_search_cpp() {
	string str = "abcdabcdacbd";
	try {
		regex reg("abcd");
		if (regex_search(str, reg)) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

int main() {
	test_token_cpp();
	test_match_cpp();
	test_search_cpp();
#ifdef _WIN32
	system("pause");
#endif
	return 0;
}
