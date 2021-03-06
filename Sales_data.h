/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
 */

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data
{
	friend Sales_data add(const Sales_data &, const Sales_data &);
	friend std::ostream &print(std::ostream &, const Sales_data &);
	friend std::istream &read(std::istream &, Sales_data &);

public:
	// constructors
	explicit Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {std::cout<<"受委托构造函数"<<std::endl;}
	explicit Sales_data() : Sales_data("", 0, 0) {std::cout<<"默认构造函数"<<std::endl;}
	explicit Sales_data(std::string s) : Sales_data(s, 0, 0) {std::cout<<"只接受string作为实参的构造函数"<<std::endl;}
	explicit Sales_data(std::istream &is) : Sales_data() { read(is, *this); std::cout<<"接受输入流作为实参的构造函数"<<std::endl; }

	// operations on Sales_data objects
	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &);
	double avg_price() const{
		if(units_sold)
			return revenue/units_sold;
		return 0.;
	}

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// nonmember Sales_data interface functions
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

std::istream &read(std::istream &is, Sales_data &s)
{
	double price;
	is>>s.bookNo>>s.units_sold>>price;
	if(is)
		s.revenue = s.units_sold*price;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os<<item.bookNo<<" "<<item.units_sold<<" "
	  <<item.revenue<<" "<<item.avg_price();
	return os;
}

Sales_data &Sales_data::combine(const Sales_data &item)
{
	units_sold += item.units_sold;
	revenue += item.revenue;

	return *this;
}

// used in future chapters
inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}
#endif
