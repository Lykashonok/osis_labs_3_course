/*
 * main.cpp
 */
#include "coder.h"
#include "decoder.h"
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstring>
int main(int argc, char *argv[])
{
	bool is_encoding = false;
	std::string mod = argv[1], file_from_file = argv[2], file_to_file = argv[3];
	// printf("%d, %s\n%s\n%s\n\n\n", argc, mod.c_str(), file_from_file.c_str(), file_to_file.c_str());
	if ((mod.compare("-e") == 0 || mod.compare("-d") == 0) && argc == 4) {
		if (mod.compare("-e") == 0)
			is_encoding = true;
	} else {
		printf("Usage: -e|-d file_from file_to");
	}

	std::ifstream file_from(file_from_file);
	file_from.seekg(0, std::ios::end);
	size_t size = file_from.tellg();
	std::string file_contents(size, ' ');
	file_from.seekg(0);
	file_from.read(&file_contents[0], size);

	std::string result;

	if (is_encoding) {
		result = encode(file_contents);
	} else {
		result = decode(file_contents);
	}

	// printf("%s\n", result.c_str());
	std::ofstream file(file_to_file);
	file << result;

	return 0;
}

// to run - clear && make clean && make && ./test.sh