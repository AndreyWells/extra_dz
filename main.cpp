#include <iostream>
#include <fstream>
#include <cstdint>
#pragma pack(1, push)
using namespace std;
struct BMPHeader {
  uint16_t fileType;
  uint32_t fileSize;
  uint16_t reserved1;
  uint16_t reserved2;
  uint32_t offsetData;
};
#pragma pack(pop)
int main()
{
 ifstream in_binary1("test1.bmp",ios::binary);
    if (in_binary1.is_open()) {
        in_binary1.seekg(0, ios::end);
        size_t actFileSize = in_binary1.tellg();
        in_binary1.seekg(0, ios::beg);
        BMPHeader bmpHeader;
        in_binary1.read(reinterpret_cast<char*>(&bmpHeader), sizeof(bmpHeader));
    if (bmpHeader.fileType != 0x4D42) {
        cout << "It's not BMP-FILE" << endl;
        in_binary1.close();
        return 1;
    }
    if (actFileSize == bmpHeader.fileSize) {
        cout << "The actual and nominal file sizes are equal " <<actFileSize<<" bytes"<< endl;
    }
    else {
        cout << "The actual and nominal file sizes are not equal"<< endl;
        cout <<"The actual file size is " << actFileSize << " bytes"<< endl;
        cout <<"The nominal file size is " << bmpHeader.fileSize << " bytes" << endl;
    }

}
}
