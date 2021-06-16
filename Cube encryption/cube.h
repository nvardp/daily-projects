#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>
#include<vector>
#include<array>

const int CUBE_SIZE = 8;
const int RANGE = 4;

class Cubes
{
public:
	Cubes();
	using Data = std::vector<std::array<char, CUBE_SIZE> >;
	std::string encrypt(const std::string& str);
	std::string decrypt(const std::string& str);

private:
	void derotate(const std::string& str);
	Data generate_cube(const std::string& s);
	std::string  rotate_cubes();
	std::string get_rotated() const;
	std::string get_script(int x) const noexcept;

	void chose_direction(char x, unsigned int index);
	void chose_direction(int x, unsigned int index);

	void to_left(unsigned int inedx);
	void to_right(unsigned int v);
	void up(unsigned int v);
	void down(unsigned int v);

	int rnd_number();
private:
	std::array<char, CUBE_SIZE> cube{ '0' };
	std::vector<std::array<char, CUBE_SIZE> > vec;
	int m_size; 
};