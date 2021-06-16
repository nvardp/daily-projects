#include "cube.h"

 Cubes::Cubes()
	{
		srand(time(0));
	}
	std::string  Cubes::encrypt(const std::string& str)
	{
		m_size = str.size() - 3;
		auto a = generate_cube(str);
		auto as = rotate_cubes();
		as += "\n";
		as += get_rotated();
		return as;
	}
	std::string  Cubes::decrypt(const std::string& str)
	{
		derotate(str);
		std::string a = get_rotated();
		a.erase(a.begin() + m_size, a.end());
		return a;
	}


	void  Cubes::derotate(const std::string& str)
	{
		auto it = str.cbegin();
		while (*it != '^')
		{
			unsigned int index = (*it - '0') - 1;
			while (*it != ',')
			{
				chose_direction(*it, index);
				it++;
			}
			it++; it++;
		}
	}
	Cubes::Data  Cubes::generate_cube(const std::string& s)
	{
		auto it = s.cbegin();
		int last = 0;
		while (it != s.cend() - 3)
		{
			for (int j = 0; j < CUBE_SIZE; j++)
			{
				if (last++ == s.size() - 3)
					break;
				cube[j] = *it;
				++it;
			}
			vec.push_back(cube);
		}
		return vec;
	}
	std::string  Cubes::rotate_cubes()
	{
		std::string result = "";
		for (unsigned int cube_number = 0; cube_number < vec.size(); cube_number++)
		{
			result += std::to_string(cube_number + 1);
			int rotation_time = rnd_number();
			for (int i = 0; i < rotation_time; i++)
			{
				int direction = rnd_number();
				result += get_script(direction);
				chose_direction(direction, cube_number);
			}
			result += ", ";
		}
		result += "^";
		return result;
	}
	std::string  Cubes::get_rotated() const
	{
		std::string str = "";
		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < CUBE_SIZE; j++)
			{
				str += vec[i][j];
			}
		}
		return str;
	}
	std::string  Cubes::get_script(int x) const noexcept
	{
		switch (x)
		{
		case 0:
			return ":L";
		case 1:
			return ":R";
		case 2:
			return ":U";
		case 3:
			return ":D";
		}
	}

	void  Cubes::chose_direction(char x, unsigned int index)
	{
		switch (x)
		{
		case 'R':
			to_left(index);
			break;
		case 'L':
			to_right(index);
			break;
		case 'D':
			up(index);
			break;
		case 'U':
			down(index);
			break;
		default:
			break;
		}
	}
	void  Cubes::chose_direction(int x, unsigned int index)
	{
		switch (x)
		{
		case 0:
			to_left(index);
			break;
		case 1:
			to_right(index);
			break;
		case 2:
			up(index);
			break;
		case 3:
			down(index);
			break;
		}
	}

	void  Cubes::to_left(unsigned int inedx)
	{
		std::swap(vec[inedx][4], vec[inedx][5]);
		std::swap(vec[inedx][5], vec[inedx][1]);
		std::swap(vec[inedx][1], vec[inedx][0]);
		std::swap(vec[inedx][6], vec[inedx][7]);
		std::swap(vec[inedx][7], vec[inedx][3]);
		std::swap(vec[inedx][3], vec[inedx][2]);
	}
	void  Cubes::to_right(unsigned int v)
	{
		std::swap(vec[v][5], vec[v][1]);
		std::swap(vec[v][5], vec[v][0]);
		std::swap(vec[v][4], vec[v][5]);

		std::swap(vec[v][7], vec[v][3]);
		std::swap(vec[v][7], vec[v][2]);
		std::swap(vec[v][6], vec[v][7]);
	}
	void  Cubes::up(unsigned int v)
	{
		std::swap(vec[v][0], vec[v][3]);
		std::swap(vec[v][3], vec[v][2]);
		std::swap(vec[v][2], vec[v][1]);

		std::swap(vec[v][4], vec[v][7]);
		std::swap(vec[v][7], vec[v][6]);
		std::swap(vec[v][6], vec[v][5]);
	}
	void  Cubes::down(unsigned int v)
	{
		for (int i = 0; i < CUBE_SIZE / 2 - 1; i++)
		{
			std::swap(vec[v][i], vec[v][i + 1]);
			std::swap(vec[v][i + 4], vec[v][i + 5]);
		}
	}

	int  Cubes::rnd_number()
	{
		return rand() % RANGE;
	}

