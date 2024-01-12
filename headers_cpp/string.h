/*******************************************************
 *	string.h
 *	author:��������
 *	copyright(c) 2015 - ~: ��鿴LICENSE�ļ�
 *	Description(����):�ַ���
 ******************************************************/
#pragma once
#ifndef STRING_H
#define STRING_H

#include "includes.h"
namespace RegularExpression {
	class string {
	public:
		char *str;
		int length;

		explicit string(int size) {
			this->length = size;
			this->str = new char[size + 1];
		}

	public:
		string() {
			this->length = 0;
			this->str = new char[1];
			this->str[0] = '\0';
		}

		string(const string &js) {
			this->length = js.length;
			this->str = new char[js.length + 1];
			for (int i = 0; i < js.length; i++) {
				this->str[i] = js.str[i];
			}
			this->str[length] = '\0';
		}

		string &operator=(const string &js) {
			if (this == &js) {
				return *this;
			}
			this->length = js.length;
			if (this->str) {
				delete[] this->str;
			}
			this->str = new char[js.length + 1];
			for (int i = 0; i < js.length; i++) {
				this->str[i] = js.str[i];
			}
			this->str[length] = '\0';
			return *this;
		}

		string(const std::string &js) {
		    this->length = (int) js.size();
		    this->str = new char[this->length + 1];
		    for (int i = 0; i < this->length; i++) {
		        this->str[i] = js[i];
		    }
		    this->str[length] = '\0';
		}

		string(const char *js) {
			int size = 0;
			while (js[size] != '\0') {
				size++;
			}
			this->length = size;
			this->str = new char[this->length + 1];
			for (int i = 0; i < this->length; i++) {
				this->str[i] = js[i];
			}
			this->str[length] = '\0';
		}

		string(const char *js, int size) {
			this->length = size;
			this->str = new char[this->length + 1];
			for (int i = 0; i < this->length; i++) {
				this->str[i] = js[i];
			}
			this->str[length] = '\0';
		}

		~string() {
			if (this->str) {
				delete[] this->str;
			}
		}

		inline char operator[](int index) const {
			return this->str[index];
		}

		inline char &operator[](int index) {
			return this->str[index];
		}

		/*���س���*/
		inline int size() const {
			return this->length;
		}

		/*���س���*/
		inline int get_length() const {
			return this->length;
		}

		/*�ַ�������*/
		string operator+(const string &j) const {
			string result(this->length + j.length);
			for (int i = 0; i < this->length; i++) {
				result.str[i] = this->str[i];
			}
			for (int k = 0; k < j.length; k++) {
				result.str[k + this->length] = j.str[k];
			}
			result.str[this->length + j.length] = '\0';
			return result;
		}

		/*�ַ�������*/
		string operator+(const std::string &j) const {
		    int size = (int) j.size();
		    string result(this->length + size);
		    for (int i = 0; i < this->length; i++) {
		        result.str[i] = this->str[i];
		    }
		    for (int k = 0; k < size; k++) {
		        result.str[k + this->length] = j[k];
		    }
		    result.str[this->length + size] = '\0';
		    return result;
		}

		/*��β��׷���ַ�*/
		string operator+(const char &c) const {
			string result(this->length + 1);
			for (int i = 0; i < this->length; i++) {
				result.str[i] = this->str[i];
			}
			result.str[this->length] = c;
			result.str[this->length + 1] = '\0';
			return result;
		}

		/*�Ƿ�����*/
		bool is_num()const {
			int dot_num = 0;
			for (int i = 0; i < this->length; i++) {
				if (str[i] < 48 || str[i] > 57) {
					if (str[i] == '.') {
						dot_num++;
					}
					else {
						return false;
					}
				}
			}
			return dot_num <= 1;
		}

		/*�ַ�������*/
		void appand(const string &j) {
			string temp = *this;
			if (this->str) {
				delete[] this->str;
			}
			this->str = new char[this->length + j.length + 1];
			for (int i = 0; i < this->length; i++) {
				this->str[i] = temp.str[i];
			}
			for (int k = 0; k < j.length; k++) {
				this->str[k + this->length] = j.str[k];
			}
			this->str[this->length + j.length] = '\0';
			this->length = this->length + j.length;
		}

		/*�ַ�������*/
		void appand(const std::string &j) {
			string temp = *this;
			if (this->str) {
				delete[] this->str;
			}
			this->str = new char[this->length + j.size() + 1];
			for (int i = 0; i < this->length; i++) {
				this->str[i] = temp.str[i];
			}
			for (unsigned int k = 0; k < j.size(); k++) {
				this->str[k + this->length] = j[k];
			}
			this->str[this->length + j.size()] = '\0';
			this->length = this->length + j.size();
		}

		/*��β������ַ�*/
		void appand(const char &c) {
			string temp = *this;
			if (this->str) {
				delete[] this->str;
			}
			this->str = new char[this->length + 2];
			for (int i = 0; i < this->length; i++) {
				this->str[i] = temp.str[i];
			}
			this->str[this->length] = c;
			this->str[this->length + 1] = '\0';
			this->length = this->length + 1;
		}

		/*��β������ַ�*/
		void operator+=(const char &c) {
			string temp = *this;
			if (this->str) {
				delete[] this->str;
			}
			this->str = new char[this->length + 2];
			for (int i = 0; i < this->length; i++) {
				this->str[i] = temp.str[i];
			}
			this->str[this->length] = c;
			this->str[this->length + 1] = '\0';
			this->length = this->length + 1;
		}

		/*�ַ�������*/
		void operator+=(const string &j) {
			string temp = *this;
			if (this->str) {
				delete[] this->str;
			}
			this->str = new char[this->length + j.length + 1];
			for (int i = 0; i < this->length; i++) {
				this->str[i] = temp.str[i];
			}
			for (int k = 0; k < j.length; k++) {
				this->str[k + this->length] = j.str[k];
			}
			this->str[this->length + j.length] = '\0';
			this->length = this->length + j.length;
		}

		/*�ַ�������*/
		void operator+=(const std::string &j) {
		    int size = (int) j.size();
		    string temp = *this;
		    if (this->str) {
		        delete[] this->str;
		    }
		    this->str = new char[this->length + size + 1];
		    for (int i = 0; i < this->length; i++) {
		        this->str[i] = temp.str[i];
		    }
		    for (int k = 0; k < size; k++) {
		        this->str[k + this->length] = j[k];
		    }
		    this->str[this->length + size] = '\0';
		    this->length = this->length + size;
		}

		/*�ַ�����ȱȽ�*/
		bool operator==(const string &j) const {
			if (this->length != j.length) {
				return false;
			}
			for (int i = 0; i < this->length; i++) {
				if (this->str[i] != j.str[i]) {
					return false;
				}
			}
			return true;
		}

		/*�ַ������ȱȽ�*/
		inline bool operator!=(const string &j) const {
			return !this->operator==(j);
		}

		bool operator>(const string &str2) const {
			if (this->is_num() && str2.is_num()) {
				return atof(this->str) > atof(str2.str);
			}
			for (int i = 0; i < this->length; i++) {
				if (i < str2.length) {
					if (this->str[i] > str2.str[i]) {
						return true;
					}
					else if (this->str[i] < str2.str[i]) {
						return false;
					}
				}
				else {
					return true;
				}
			}
			return false;
		}

		inline bool operator>=(const string &str2) const {
			return this->operator==(str2) || this->operator>(str2);
		}

		inline bool operator<=(const string &str2) const {
			return !this->operator>(str2);
		}

		inline bool operator<(const string &str2) const {
			return !this->operator>=(str2);
		}

		/*������(��0����)pos����ȡ����Ϊlen���Ӵ�(����pos)*/
		string sub_str(int pos, int len) const {
			if (pos < 0 || pos + len > this->length || len < 0) {
				string result(0);
				result.str[0] = '\0';
				return result;
			}
			else {
				string result(len);
				for (int i = 0; i < len; i++) {
					result.str[i] = this->str[pos + i];
				}
				result.str[len] = '\0';
				return result;
			}
		}

		/*�����ַ�����*/
		const char* c_str() const {
			return this->str;
		}

		/*���*/
		inline friend ostream& operator<<(ostream& os, const string& js) {
			return os << js.str;
		}

		inline char* begin() const {
			return &(this->str[0]);
		}

		inline char* end() const {
			return &(this->str[this->length - 1]);
		}

		/*�ַ�������*/
		inline friend string operator+(const std::string &s, const string &js) {
		    return string(s) + js;
		}

		/*�����ַ�����λ��*/
		int index_of(const char &c) const {
			for (int i = 0; i < this->length; i++) {
				if (this->str[i] == c) {
					return i;
				}
			}
			return -1;
		}

		/*�Ƿ�����ַ�*/
		inline bool contains(const char &c) const {
			return this->index_of(c) > -1;
		}

		/*�Ƿ�����ַ���*/
		inline bool contains(const string &s) const {
			return this->index_of_KMP(s) > -1;
		}

		/*�Ƿ�����ַ���*/
		inline bool contains(const std::string &s) const {
		    return this->index_of_KMP(s) > -1;
		}

		/*����ָ�����ַ����ڴ��ַ����е�һ�γ��ִ�������(��0��ʼ����)*/
		int index_of(const string &s) const {
			return this->index_of_KMP(s);
		}

		/*����ָ�����ַ����ڴ��ַ����е�һ�γ��ִ�������(��0��ʼ����)*/
		int index_of(const std::string &s) const {
			return this->index_of_KMP(s);
		}

	protected:
		/*KMPʧ�ܺ���*/
		void function_fail_KMP(int *&next) const {
			int j = 0;
			int k = -1;
			next[0] = -1;
			while (j < this->length - 1) {
				if (k == -1 || this->str[k] == this->str[j]) {
					j++;
					k++;
					next[j] = k;
				}
				else {
					k = next[k];
				}
			}
		}

	public:
		/*�ַ���ƥ��KMP�㷨*/
		/*���������pos����ַ������� p,�򷵻�p��һ���ַ��ڴ��ַ����е�λ��*/
		int index_of_KMP(const string &p, const int pos = 0) const {
			if (p.length == 0 && pos < this->length) {
				return 0;
			}
			int *next = new int[p.length];
			p.function_fail_KMP(next);
			int i, j;
			for (i = pos, j = 0; i < this->length && j < p.length;) {
				if (this->str[i] == p.str[j]) {
					i++, j++;
				}
				else {
					if (next[j] == -1) {
						i++, j = 0;
					}
					else {
						j = next[j];
					}
				}
			}
			delete[] next;
			return p.str[j] == '\0' ? i - j : -1;
		}

		/*�ַ������滻*/
		void replace(char c, char new_char) {
			for (int i = 0; i < this->length; i++) {
				if (this->str[i] == c) {
					this->str[i] = new_char;
				}
			}
		}

		/*��ָ��λ��(index(��0��ʼ����))�Ƴ�ָ������(off)���ַ�*/
		string &remove_at(int index, int off = 1) {
			if (index < 0 || off < 0 || index + off > length) {
				return *this;
			}
			string temp(*this);
			if (this->str) {
				delete[] this->str;
			}
			this->str = new char[this->length - off + 1];
			for (int i = 0; i < index; i++) {
				this->str[i] = temp.str[i];
			}
			for (int j = index + off; j < length; j++) {
				this->str[j - off] = temp.str[j];
			}
			this->str[this->length - off] = '\0';
			this->length = this->length - off;
			return *this;
		}

		/*�Ƴ�ָ���ַ�*/
		string &remove(const char &c) {
			int index = this->index_of(c);
			if (index < 0) {
				return *this;
			}
			string temp(*this);
			if (this->str) {
				delete[] this->str;
			}
			this->str = new char[this->length];
			this->length--;
			for (int i = 0, j = 0; i <= this->length; i++) {
				if (i != index) {
					this->str[j++] = temp.str[i];
				}
			}
			this->str[this->length] = '\0';
			return *this;
		}
	};
}
#endif