#include <iostream>
#include<map>
#include <cmath>
using namespace std;

map<char, int> key = { {'0',0}, {'1',1}, {'2',2}, {'3',3}, {'4',4}, {'5',5}, {'6',6}, {'7',7}, {'8',8}, {'9',9}, {':',10}, {'v',11}, {'a',12} };


bool chars[13][7][7] = { { {1,1,1,1,1,1,1}
						,{1,0,0,0,0,1,1}
						,{1,0,0,0,1,0,1}
						,{1,0,0,1,0,0,1}
						,{1,0,1,0,0,0,1}
						,{1,1,0,0,0,0,1}
						,{1,1,1,1,1,1,1} },
						{ {0,0,0,1,0,0,0}
						,{0,0,0,1,0,0,0}
						,{0,0,0,1,0,0,0}
						,{0,0,0,1,0,0,0}
						,{0,0,0,1,0,0,0}
						,{0,0,0,1,0,0,0}
						,{0,0,0,1,0,0,0}},
						{ {1,1,1,1,1,1,1}
						,{0,0,0,0,0,0,1}
						,{0,0,0,0,0,0,1}
						,{1,1,1,1,1,1,1}
						,{1,0,0,0,0,0,0}
						,{1,0,0,0,0,0,0}
						,{1,1,1,1,1,1,1}},
						{ {1,1,1,1,1,1,1}
						,{0,0,0,0,0,0,1}
						,{0,0,0,0,0,0,1}
						,{0,1,1,1,1,1,1}
						,{0,0,0,0,0,0,1}
						,{0,0,0,0,0,0,1}
						,{1,1,1,1,1,1,1}},
						{ {1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}
						,{1,1,1,1,1,1,1}
						,{0,0,0,0,0,0,1}
						,{0,0,0,0,0,0,1}
						,{0,0,0,0,0,0,1}},
						{ {1,1,1,1,1,1,1}
						,{1,0,0,0,0,0,0}
						,{1,0,0,0,0,0,0}
						,{1,1,1,1,1,1,1}
						,{0,0,0,0,0,0,1}
						,{0,0,0,0,0,0,1}
						,{1,1,1,1,1,1,1}},
						{ {1,1,1,1,1,1,1}
						,{1,0,0,0,0,0,0}
						,{1,0,0,0,0,0,0}
						,{1,1,1,1,1,1,1}
						,{1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}},
						{ {1,1,1,1,1,1,1}
						,{0,0,0,0,0,1,0}
						,{0,0,0,0,1,0,0}
						,{0,1,1,1,1,1,0}
						,{0,0,1,0,0,0,0}
						,{0,1,0,0,0,0,0}
						,{1,0,0,0,0,0,0} },
						{ {1,1,1,1,1,1,1}
						,{1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}
						,{1,1,1,1,1,1,1}
						,{1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}},
						{ {1,1,1,1,1,1,1}
						,{1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}
						,{1,1,1,1,1,1,1}
						,{0,0,0,0,0,0,1}
						,{0,0,0,0,0,0,1}
						,{0,0,0,0,0,0,1}},
						{ {0,0,0,0,0,0,0}
						,{0,0,0,0,0,0,0}
						,{0,0,0,1,0,0,0}
						,{0,0,0,0,0,0,0}
						,{0,0,0,1,0,0,0}
						,{0,0,0,0,0,0,0}
						,{0,0,0,0,0,0,0}},
						{ {1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}
						,{1,1,1,1,1,1,1}},
						{ {1,1,1,1,1,1,1}
						,{1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}
						,{1,1,1,1,1,1,1}
						,{1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}
						,{1,0,0,0,0,0,1}} };



bool surface[64][64] = { 0 };

bool in_bounds(int X, int Y)
{
	return X > -1 && X < 64 && Y > -1 && Y < 64;
}

void type(bool surf[64][64], bool txt[7][7],int xy[2])
{

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			int x = xy[0] + i;
			int y = xy[1] + j;

			if (in_bounds(x, y))
			{
				surf[x][y] = txt[i][j];
			}

		}
	}
}



void blit(bool surf[64][64], string str, int xy[2])
{
	for (int i = 0; i < str.size(); i++)
	{
		int xy_[2] = { xy[0],xy[1] + i * 8 };
		char a = str[i];
		type(surf, chars[key[a]], xy_);
	}
}

float project(int X, float scale)
{
	return (float)X / 64.0 * scale;
}

int aproject(float x, float scale)
{
	return int(x * 64.0 / scale);
}

void graph(bool surf[64][64], float a, float v, float (*f)(float,float,float))
{
	float scale = 1;
	for (int X = 0; X < 64; X++)
	{
		float x = project(X, scale);
		int Y = aproject((*f)(x, a, v), scale);
		if (in_bounds(X, Y))
		{
			surf[64 - Y - 1][X] = 1;
		}

	}
}

float f(float t, float a, float v)
{
	return (asinh(a * t + sinh(v)) - v) / a;
}




void disp(bool surf[64][64])
{
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			surf[i][j] ? cout << "*" : cout << " ";

		}
		cout << endl;
	}
}



int main()
{
	int xy[2] = { 0,0 };
	float a = 0.01, v = 0;
	string str = "12:37a";
	blit(surface, str, xy);
	graph(surface, a, v, &f);
	disp(surface);


	return 0;
}



