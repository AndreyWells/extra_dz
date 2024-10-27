#include <iostream>
#include <fstream>
#include <cstdint>
using namespace std;
struct BMPHeader {
  uint16_t fileType;
  uint32_t fileSize;
  uint16_t reserved1;
  uint16_t reserved2;
  uint32_t offsetData;
};
int main()
{
 ifstream in_binary1("image.bmp",ios::binary);
    if (in_binary1.is_open()) {
        in_binary1.seekg(0, ios::end);
        size_t actFileSize = in_binary1.tellg();
        in_binary1.seekg(0, ios::beg);
        BMPHeader bmpHeader;
        in_binary1.read(reinterpret_cast<char*>(&bmpHeader), sizeof(bmpHeader));
        cout << bmpHeader.fileSize << endl;
}
}
