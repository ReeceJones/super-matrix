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
	}

	system("pause");
}