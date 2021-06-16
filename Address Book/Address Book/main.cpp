#include "address_book.h"

void help()
{
	std::cout << "For adding new contact press add" << std::endl;;
	std::cout << "For removing existing contact press rm" << std::endl;;
	std::cout << "To see all existing contact press ls" << std::endl;;
	std::cout << "For help  press help" << std::endl;
}

void parse(const std::string& q, _AddressBook& ob)
{
	if (q == "help")
	{
		help();
	}
	else if (q == "add")
	{
		if (ob.Add_to_contact())
			std::cout << "new contact was succesfully added\n";
	}
	else if (q == "rm")
	{
		if (ob.Remove_from_book())
		{
			std::cout << "contact was succesfully deleted\n";
		}
	}
	else if (q == "ls")
	{
		ob.See_All();
	}
	else if (q == "exit")
	{
		return;
	}
	else
	{
		std::cout << "no such command, press help to see all commands\n";
	}
}

int main()
{
	help();
	_AddressBook ob;
	while (true)
	{
		std::string query = "";
		std::cin >> query;
		parse(query, ob);
		if (query == "exit")
			break;
	}
}