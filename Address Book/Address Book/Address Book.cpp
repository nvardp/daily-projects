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
	bool Add_to_contact()
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
	
	bool Remove_from_book()
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
	
	void See_All()
	{
		for (int i = 0; i < vec.size(); i++)
		{
			std::cout << vec[i].id << " " << vec[i].name << " " << vec[i].phone << " " << vec[i].address << std::endl;
		}
	}
private:
	AddressBook person;
	std::vector<AddressBook> vec;
	static int id;  //i wanted it to be static
	void Add_name()
	{
		std::string name = "";
		std::cout << "enter name" << std::endl;
		std::cin >> name;
		person.name= name;
		person.id = ++id;
	}
	void Add_phone()
	{
		std::string phone = "";
		std::cout << "enter phone" << std::endl;
		std::cin >> phone;
		person.phone = phone;
	}
	void Add_address()
	{
		std::string address = "";
		std::cout << "enter address" << std::endl;
		std::cin >> address;
		person.address = address;
	}
};
int _AddressBook::id = 0;
void help()
{
	std::cout << "For adding new contact press add" << std::endl;;
	std::cout << "For removing existing contact press rm" << std::endl;;
	std::cout << "To see all existing contact press ls" << std::endl;;
	std::cout << "For help  press help" << std::endl;
}


void parse(const std::string& q, _AddressBook& ob)
{
	
	if (q == "help" || q == "HELP")
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



//template <typename T, std::size_t N>
//constexpr void myarr(T(&)[N]) noexcept {
//	for (size_t i = 0; i < N; i++)
//	{
//		std::cout << i << std::endl;
//	}
//	//return N;
//
//}




int main()
{


	/*int arr[] = { 1, 2, 3, 4, 5 };
	 myarr(arr);


	 int x = 4;
	 auto y = x;
	 auto z = &x;
	std:: cout << typeid(z).name();*/
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
