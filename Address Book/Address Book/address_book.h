#pragma once
#include <iostream>
#include <vector>

struct AddressBook
{
	int id;
	std::string name;
	std::string address;
	std::string phone;
};

class _AddressBook
{
public:
	_AddressBook() {  };
public:
	bool Add_to_contact();
	bool Remove_from_book();
	void See_All();

private:
	AddressBook person;
	std::vector<AddressBook> vec;
	static int id;  

	void Add_name();
	void Add_phone();
	void Add_address();
};
