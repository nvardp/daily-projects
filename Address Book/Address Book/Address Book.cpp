#include "address_book.h"

	_AddressBook::_AddressBook() {  };
	bool _AddressBook::Add_to_contact()
	{
		try
		{
			Add_name();
			Add_phone();
			Add_address();
			vec.push_back(person);
			return true;
		}
		catch(bool a)
		{
			return false;
		}
	}
	bool _AddressBook::Remove_from_book()
	{
		int target = 0;
		std::cout << "press id of contact you want to delete" << std::endl;
		std::cin >> target;
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i].id == target)
				vec.erase(vec.begin()+i);
		}
		return true;
	}
	void _AddressBook::See_All()
	{
		for (int i = 0; i < vec.size(); i++)
		{
			std::cout << vec[i].id << " " << vec[i].name << " " << vec[i].phone << " " << vec[i].address << std::endl;
		}
	}
	void _AddressBook::Add_name()
	{
		std::string name = "";
		std::cout << "enter name" << std::endl;
		std::cin >> name;
		person.name= name;
		person.id = ++id;
	}
	void _AddressBook::Add_phone()
	{
		std::string phone = "";
		std::cout << "enter phone" << std::endl;
		std::cin >> phone;
		person.phone = phone;
	}
	void _AddressBook::Add_address()
	{
		std::string address = "";
		std::cout << "enter address" << std::endl;
		std::cin >> address;
		person.address = address;
	}

int _AddressBook::id = 0;
