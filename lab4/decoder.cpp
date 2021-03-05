#ifndef DECODER_CPP
#define DECODER_CPP
/*
 * decoder.cpp
 */
#include "decoder.h"
std::string morseToChar(std::string morse)
{
	if(morse == ".-")		{return "a";}
	else if(morse == "-..."){return "b";}
	else if(morse == "-.-."){return "c";}
	else if(morse == "-..") {return "d";}
	else if(morse == ".")	{return "e";}
	else if(morse == "..-."){return "f";}
	else if(morse == "--.") {return "g";}
	else if(morse == "...."){return "h";}
	else if(morse == "..")  {return "i";}
	else if(morse == ".---"){return "j";}
	else if(morse == "-.-") {return "k";}
	else if(morse == ".-.."){return "l";}
	else if(morse == "--")  {return "m";}
	else if(morse == "-.")  {return "n";}
	else if(morse == "---") {return "o";}
	else if(morse == ".--."){return "p";}
	else if(morse == "--.-"){return "q";}
	else if(morse == ".-.") {return "r";}
	else if(morse == "...") {return "s";}
	else if(morse == "-")	{return "t";}
	else if(morse == "..-") {return "u";}
	else if(morse == "...-"){return "v";}
	else if(morse == ".--") {return "w";}
	else if(morse == "-..-"){return "x";}
	else if(morse == "-.--"){return "y";}
	else if(morse == "--.."){return "z";}
	else {return " ";}
}

std::string trim(const std::string &s)
{
    auto start = s.begin();
    while (start != s.end() && std::isspace(*start)) {
        start++;
    }
 
    auto end = s.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));
 
    return std::string(start, end + 1);
}

std::string decode(std::string input)
{
	int node = 0;
	std::string sub, output = "";
	for(std::size_t i = 0;i<=input.length();i++)
	{
		if(input[i]==' ')
		{
			sub = input.substr(node,i-node);
			output+=morseToChar(sub);
			node = i+1;
		}
		if(i==input.length()-1)
		{
			sub = input.substr(node,i+1-node);
			output+=morseToChar(sub);
			node = i+1;
		}
	}
	output = trim(output);
	return output;
}
#endif /* DECODER_CPP */