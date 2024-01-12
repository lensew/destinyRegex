/*******************************************************
 *	exception.h
 *	author:��������
 *	copyright(c) 2015 - ~: ��鿴LICENSE�ļ�
 *	Description(����):�ַ���
 ******************************************************/
#pragma once
#ifndef DESTINY_EXCEPTION_H
#define DESTINY_EXCEPTION_H

namespace RegularExpression {
	class exception {
	private:
		const char* str;
	public:
		explicit exception(const char* s) :str(s) {}
		virtual ~exception(){}
		inline const char* what() {
			return this->str;
		}
	};
}

#endif