/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbow <jimbow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 10:59:16 by jimbow            #+#    #+#             */
/*   Updated: 2026/05/28 12:13:15 by jimbow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"
#include <iostream>

bigint::bigint() : _number("0")
{

}

bigint::bigint(std::string str) : _number(str)
{
}

bigint::bigint(unsigned int n)
{
	if (n == 0)
	{
		_number = "0";
		return ;
	}

	while (n > 0)
	{
		int element = n % 10;
		char c = element + '0';

		_number = c + _number;

		n /= 10;
	}
}

bigint::bigint(const bigint& copy)
{
	*this = copy;
}

bigint& bigint::operator=(const bigint& copy)
{
	if (this != &copy)
		_number = copy._number;
	return *this;
}

bigint::~bigint()
{
}

bigint bigint::operator+(const bigint& b) const
{
	bigint c;

	c._number = addStrings(_number, b._number);
	return c;
}

bigint& bigint::operator+=(const bigint& b)
{
	_number = addStrings(_number, b._number);
	return *this;
}

bigint& bigint::operator++()
{
	_number = addStrings(_number, "1");
	return *this;
}

bigint bigint::operator++(int)
{
	bigint tmp(*this);
	_number = addStrings(_number, "1");
	return tmp;
}

bool bigint::operator<(const bigint& b) const
{
	if (_number.size() != b._number.size())
		return _number.size() < b._number.size();
	return _number < b._number;
}

bool bigint::operator<=(const bigint& b) const
{
	return !(*this > b);
}

bool bigint::operator>(const bigint& b) const
{
	return (b < *this);
}

bool bigint::operator>=(const bigint& b) const
{
	return !(*this < b);
}

bool bigint::operator==(const bigint& b) const
{
	return _number == b._number;
}

bool bigint::operator!=(const bigint& b) const
{
	return _number != b._number;
}

bigint bigint::operator<<(const bigint& b) const
{
	bigint tmp(*this);
	int i = b._number[0] - '0';
	tmp._number.append(i, '0');
	return tmp;
}

bigint bigint::operator>>(const bigint& b) const
{
	bigint tmp(*this);
	int i = b._number[0] - '0';

	if (i >= b._number.size())
	{
		tmp._number = "0";
		return tmp;
	}
	tmp._number.erase(_number.size() - i, i);
	return tmp;
}

bigint& bigint::operator<<=(const bigint& b)
{
	int i = b._number[0] - '0';
	_number.append(i, '0');
	return *this;
}

bigint& bigint::operator>>=(const bigint& b)
{
	int i = b._number[0] - '0';

	if (i >= _number.size())
	{
		_number = "0";
		return *this;
	}
	_number.erase(_number.size() - i, i);
	return *this;
}

bigint bigint::operator<<(unsigned int n) const
{
	bigint tmp(*this);

	if (_number == "0")
		return tmp;

	tmp._number.append(n, '0');
	return tmp;
}

bigint& bigint::operator<<=(unsigned int n)
{
	if (_number == "0")
		return *this;
	_number.append(n, '0');
	return *this;
}

bigint bigint::operator>>(unsigned int n) const
{
	bigint tmp(*this);
	if (n >= _number.size())
	{
		tmp._number = "0";
		return tmp;
	}
	tmp._number.erase(_number.size() - n, n);
	return tmp;
}

bigint& bigint::operator>>=(unsigned int n)
{
	if (n >= _number.size())
	{
		_number = "0";
		return *this;
	}
	_number.erase(_number.size() - n, n);
	return *this;
}

std::string bigint::addStrings(const std::string& a, const std::string& b) const
{
	int i = a.size() - 1;
	int j = b.size() - 1;
	int carry = 0;

	std::string result;

	while (i >= 0 || j >= 0 || carry)
	{
		int sum = carry;

		if (i >= 0)
			sum += a[i--] - '0';

		if (j >= 0)
			sum += b[j--] - '0';
		
		carry = sum / 10;
		char digit = char('0' + (sum % 10));

		result.insert(0, 1, digit);
	}

	return result;
}

std::string bigint::getNumber() const
{
	return _number;
}

std::ostream& operator<<(std::ostream& os, const bigint& obj)
{
	os << obj.getNumber();
	return os;
}
