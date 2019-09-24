#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

#include <cstdint>
using namespace std;


namespace caveofprogramming {

//#pragma pack(2)
#pragma pack(push, 2)
struct BitmapFileHeader {
/*    char header[2]{ 'B', 'M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset; */
    char header[2] { 'B', 'M' };
	int32_t fileSize;
	int32_t reserved { 0 };
	int32_t dataOffset;

};
#pragma pack(pop)

};


#endif // BITMAPFILEHEADER_H_INCLUDED
