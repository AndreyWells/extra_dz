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

}
