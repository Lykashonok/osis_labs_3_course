#ifndef DECODER_H
#define DECODER_H
/*
 * decoder.h
 */
#include <iostream>
#include <string>
#include <algorithm>
std::string trim(const std::string &s);
std::string morseToChar(std::string morse);
std::string decode(std::string);
#endif /* DECODER_H */