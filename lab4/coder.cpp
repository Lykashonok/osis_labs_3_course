#ifndef CODER_CPP
#define CODER_CPP
/*
 * coder.cpp
 */
#include "coder.h"
std::string charToMorse(char16_t letter)
{
    switch(letter) {
        case 'a': case 'A': return ".-";   break;
        case 'b': case 'B': return "-..."; break;
        case 'c': case 'C': return "-.-."; break;
		case 'd': case 'D': return "-..";  break;
        case 'e': case 'E': return ".";    break;
        case 'f': case 'F': return "..-."; break;
        case 'g': case 'G': return "--.";  break;
        case 'h': case 'H': return "...."; break;
        case 'i': case 'I': return "..";   break;
        case 'j': case 'J': return ".---"; break;
        case 'k': case 'K': return "-.-";  break;
        case 'l': case 'L': return ".-.."; break;
        case 'm': case 'M': return "--";   break;
        case 'n': case 'N': return "-.";   break;
        case 'o': case 'O': return "---";  break;
        case 'p': case 'P': return ".--."; break;
        case 'q': case 'Q': return "--.-"; break;
        case 'r': case 'R': return ".-.";  break;
        case 's': case 'S': return "...";  break;
        case 't': case 'T': return "-";    break;
        case 'u': case 'U': return "..-";  break;
        case 'v': case 'V': return "...-"; break;
        case 'w': case 'W': return ".--";  break;
        case 'x': case 'X': return "-..-"; break;
        case 'y': case 'Y': return "-.--"; break;
        case 'z': case 'Z': return "--.."; break;
		default: return " "; break;	
    }
}
std::string encode(std::string input)
{
	std::string output = "";
	for(std::size_t i=0;i<input.length();i++)
	{
		if(i!=0)
		{
			output+=" ";
		}
		output = output + charToMorse(input[i]);
	}
	return output;
}

#endif /* CODER_CPP */