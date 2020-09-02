#ifndef BITMAP_H
#define BITMAP_H

#include <fstream>
#include <vector>
#include <QColor>

typedef struct tagBITMAPFILEHEADER {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
    unsigned int biSize;
    long biWidth;
    long biHeight;
    unsigned short biPlanes;
    unsigned  short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    long biXPelsPerMeter;
    long biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BITMAPINFOHEADER;

BITMAPFILEHEADER* readBitmapFileHeader(std::ifstream& is);
BITMAPINFOHEADER* readBitmapInfoHeader(std::ifstream& is);
std::vector<QColor> readBitmapColorTable(std::ifstream& is, int colorTableEntries);
std::vector<unsigned char> readBitmapPixelIndices(std::ifstream& is, BITMAPINFOHEADER* bitmapInfoHeader);

bool verifyBitmapFileHeader(BITMAPFILEHEADER *bitmapFileHeader, int fileLength);
bool verifyBitmapInfoHeader(BITMAPINFOHEADER *bitmapInfoHeader);
int getColorTableEntries(BITMAPINFOHEADER *bitmapInfoHeader);

#endif // BITMAP_H