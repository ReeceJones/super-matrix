#include <iostream>
#include <cstdio>
#include <string>
#include <time.h>
#include <fstream>
#include <vector>

/*
fmt:
	line 1: matrix height, matrix width
	line 2-whatever: matrix data
*/

/*
data:
	each index is a positve integer
	idk cool stuffz to do with it yet
*/

std::vector<std::string> get_words(std::string str_base)
{
	//yes I know you can use getline to use the same purpose. But I mean like its cool cuz it looks like normal c 
	std::vector<std::string> ret_vec;
	/*std::stringstream ssBase(strBase);
	std::string strBuf;

	while (ssBase >> strBuf)
	vRet.push_back(strBuf);*/

	char* cstr = new char[str_base.size() + 1];
	strcpy(cstr, str_base.c_str());
	char* cstrWord = strtok(cstr, " ");
	while (cstrWord != 0)
	{
		ret_vec.push_back(cstrWord);
		cstrWord = strtok(0, " ");
	}

	delete[] cstr;

	return ret_vec;
}

int get_smallest(std::vector<int> vec_sort)
{
	//something really large
	int prev_smallest = 44594353450;
	for (int i : vec_sort)
	{
		if (i < prev_smallest)
			prev_smallest = i;
	}
	return prev_smallest;
}

int get_largest(std::vector<int> vec_sort)
{
	int prev_largest = -44594353450;
	for (int i : vec_sort)
	{
		if (i > prev_largest)
			prev_largest = i;
	}
	return prev_largest;
}

std::vector<int> sort_matrix(std::vector<int> vec_sort)
{
	std::cout << get_smallest(vec_sort) << std::endl;
}

int main()
{
	//get the file we are going to read the matrix from
	std::string str_in;
	std::cout << "Input file: ";
	std::getline(std::cin, str_in);
	clock_t start_time = clock();

	std::ifstream in_file(str_in, std::ifstream::in);

	//base line
	std::getline(in_file, str_in);
	std::vector<std::string> words = get_words(str_in);

	unsigned int height, width;

	//process the first line containing matrix size info
	for (unsigned int i = 0; i < 2; i++)
	{
		if (i == 0)
			height = atoi(words[i].c_str());
		else if (i == 1)
			width = atoi(words[i].c_str());
		//pls just work
	}
	std::cout << "Matrix Height: " << height << "; Matrix Width: " << width << std::endl;

	std::vector<std::string> vec_file;
	while (std::getline(in_file, str_in))
	{
		vec_file.push_back(str_in);
		std::cout << str_in << std::endl;
	}

	std::cout << "Sorted matrix: " << std::endl;

	for (std::string str : vec_file)
	{
		std::vector<std::string> vec_words = get_words(str);
		std::vector<int> vec_numbers;
		for (std::string str_num : vec_words)
		{
			//atoi because stoi is unstable (i always try to use atoi when possible b/c stoi will not want to work sometimes)
			vec_numbers.push_back(atoi(str_num.c_str()));
		}

		std::cout << "smallest: " << get_smallest(vec_numbers) << "; largest: " << get_largest(vec_numbers) << std::endl;

		vec_words.clear();
		vec_numbers.clear();
	}



	system("pause");
}