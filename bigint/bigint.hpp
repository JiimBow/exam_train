/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbow <jimbow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 10:38:04 by jimbow            #+#    #+#             */
/*   Updated: 2026/05/28 12:10:36 by jimbow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <string>
#include <iostream>

class bigint
{
private:
	std::string _number;
public:
	bigint();
	bigint(std::string str);
	bigint(unsigned int n);
	bigint(const bigint& copy);
	bigint& operator=(const bigint& copy);
	~bigint();

	bigint operator+(const bigint& b) const;
	bigint& operator+=(const bigint& b);

	bigint& operator++();
	bigint operator++(int);

	bool operator<(const bigint& b) const;
	bool operator<=(const bigint& b) const;
	bool operator>(const bigint& b) const;
	bool operator>=(const bigint& b) const;
	bool operator==(const bigint& b) const;
	bool operator!=(const bigint& b) const;

	bigint operator<<(const bigint& b) const;
	bigint operator>>(const bigint& b) const;
	bigint& operator<<=(const bigint& b);
	bigint& operator>>=(const bigint& b);

	bigint operator<<(unsigned int n) const;
	bigint operator>>(unsigned int n) const;
	bigint& operator<<=(unsigned int n);
	bigint& operator>>=(unsigned int n);

	std::string getNumber() const;
	std::string addStrings(const std::string& a, const std::string& b) const;
};

std::ostream& operator<<(std::ostream& os, const bigint& obj);

#endif