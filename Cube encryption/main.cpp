#include "cube.h"

int main()
{
	std::string tmp = "";
	std::string str = "";

	while (tmp != "end")
	{
		std::getline(std::cin, tmp);
		str += tmp;
	}
	Cubes ob;
	auto encoded = ob.encrypt(str);
	std::cout << "Encrypred text is: \n" << encoded << std::endl;
	std::cout << "\n Decrypted text is: \n" << ob.decrypt(encoded) << std::endl;
}