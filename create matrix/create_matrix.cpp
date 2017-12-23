#include <iostream>
#include <string>
#include <cstdio>
#include<Windows.h>
#include <fstream>
#include <time.h>

int main()
{
	std::string str_in;
	std::cout << "Matrix Height: ";
	std::getline(std::cin, str_in);
	unsigned int matrix_height = abs(atoi(str_in.c_str()));
	std::cout << "Matrix Width: ";
	std::getline(std::cin, str_in);
	unsigned int matrix_width = abs(atoi(str_in.c_str()));
	std::cout << "Lower Cell Range (positive): ";
	std::getline(std::cin, str_in);
	unsigned int lower_bound = abs(atoi(str_in.c_str()));
	std::cout << "Upper Cell Range (positive): ";
	std::getline(std::cin, str_in);
	unsigned int upper_bound = abs(atoi(str_in.c_str()));
	//last one, I promise
	std::cout << "File Name: ";
	std::string file_name;
	std::getline(std::cin, file_name);

	//ok, we can finally do the codes
	srand(0);

	std::ofstream out_file(file_name, std::ofstream::out);

	//line 1 of the file (or 0 if you want to be annoying about it)
	out_file << std::to_string(matrix_height) << " " << std::to_string(matrix_width) << std::endl;
	//loop for all of the rows
	for (unsigned int h = 0; h < matrix_height; h++)
	{

		//loop for all of the columns in the row
		for (unsigned int w = 0; w < matrix_width; w++)
		{
			unsigned int random_number = lower_bound + (rand() % (upper_bound + lower_bound - 1));
			//write a random number in our range to the file.
			out_file << std::to_string(random_number) << " ";
		}


		//at the end of each row we want to add a '\n' so that we move down to a new line.
		//this will make it easier to parse the file. (by like 3 lines lol)
		out_file << '\n';
	}

	//close our file becase we are done writing to it
	out_file.close();
}