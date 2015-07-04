#ifndef _BASE64_H_
#define _BASE64_H_

#pragma once

#include <string>

class CBase64
{
public:
	std::string Mask(const char* Data, int DataByte);
	std::string Unmask(const char* Data, int DataByte);
    std::string Encode(const char* Data, int DataByte);
    std::string Decode(const char* Data, int DataByte, int& OutByte);
};

#endif // _BASE64_H_
