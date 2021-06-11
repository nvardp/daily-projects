#include <iostream>
#include <stdlib.h>
#include <time.h>
#include<string>
#include<vector>
#include<array>
using namespace std;
const int CUBE_SIZE = 8;

class Cubes
{
public:
	Cubes()
	{
		srand(time(0));
	}
	using Data = vector<array<char, 8> >;
	string encrypt(const string& str)
	{
		size = str.size() - 3;
		auto a = generate_cube(str);
		auto as = rotate_cubes();
		as += "\n";
		as += get_rotated();
		return as;
	}
	string decrypt(const string& str)
	{
		derotate(str);
		string a = get_rotated();
		a.erase(a.begin() + size, a.end());
		return a;
	}

private:
	void derotate(const string& str)
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
	Data generate_cube(const string& s)
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
	string  rotate_cubes()
	{
		string result = "";
		for (unsigned int cube_number = 0; cube_number < vec.size(); cube_number++)
		{
			result += to_string(cube_number + 1);
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
	string get_rotated() const
	{
		string str = "";
		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < CUBE_SIZE; j++)
			{
				str += vec[i][j];
			}
		}
		return str;
	}
	string get_script(int x) const noexcept
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

	void chose_direction(char x, unsigned int index)
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
	void chose_direction(int x, unsigned int index)
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

	void to_left(unsigned int inedx)
	{
		swap(vec[inedx][4], vec[inedx][5]);
		swap(vec[inedx][5], vec[inedx][1]);
		swap(vec[inedx][1], vec[inedx][0]);
		swap(vec[inedx][6], vec[inedx][7]);
		swap(vec[inedx][7], vec[inedx][3]);
		swap(vec[inedx][3], vec[inedx][2]);
	}
	void to_right(unsigned int v)
	{
		swap(vec[v][5], vec[v][1]);
		swap(vec[v][5], vec[v][0]);
		swap(vec[v][4], vec[v][5]);

		swap(vec[v][7], vec[v][3]);
		swap(vec[v][7], vec[v][2]);
		swap(vec[v][6], vec[v][7]);
	}
	void up(unsigned int v)
	{
		swap(vec[v][0], vec[v][3]);
		swap(vec[v][3], vec[v][2]);
		swap(vec[v][2], vec[v][1]);

		swap(vec[v][4], vec[v][7]);
		swap(vec[v][7], vec[v][6]);
		swap(vec[v][6], vec[v][5]);
	}
	void down(unsigned int v)
	{
		for (int i = 0; i < CUBE_SIZE / 2 - 1; i++)
		{
			swap(vec[v][i], vec[v][i + 1]);
			swap(vec[v][i + 4], vec[v][i + 5]);
		}
	}

	int rnd_number()
	{
		return rand() % 4;
	}
private:
	array<char, CUBE_SIZE> cube{ '0' };
	vector<array<char, CUBE_SIZE> > vec;
	int size; // bug fix helper 
};

int main()
{
	
	string tmp = "";
	string str = "";
	while (tmp != "end")
	{
		cin >> tmp;
		str += tmp;
	}
	Cubes ob;
	auto encoded = ob.encrypt(str);
	cout << "Encrypred text is: \n" << encoded << endl;
	cout << "\n Decrypted text is: \n" << ob.decrypt(encoded) << endl;
}

