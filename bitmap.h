#ifndef BITMAP_H
#define BITMAP_H

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
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

typedef struct tagBITMAP {
    BITMAPFILEHEADER *bitmapFileHeader;
    BITMAPINFOHEADER *bitmapInfoHeader;
    std::vector<QColor> bitmapColorTable;
    std::vector<unsigned char> bitmapPixelIndices;
    std::unordered_set<unsigned char> colorSet;
} BITMAP;

BITMAPFILEHEADER *readBitmapFileHeader(std::ifstream& is);
BITMAPINFOHEADER *readBitmapInfoHeader(std::ifstream& is);
std::vector<QColor> readBitmapColorTable(std::ifstream& is, BITMAPINFOHEADER *bitmapInfoHeader, int colorTableEntries);
std::vector<unsigned char> readBitmapPixelIndices(std::ifstream& is, BITMAPFILEHEADER *bitmapFileHeader, BITMAPINFOHEADER* bitmapInfoHeader, std::unordered_set<unsigned char> &colorSet);

bool verifyBitmapFileHeader(BITMAPFILEHEADER *bitmapFileHeader, int fileLength, QString &errorMessage);
bool verifyBitmapInfoHeader(BITMAPINFOHEADER *bitmapInfoHeader, QString &errorMessage);
int getColorTableEntries(BITMAPINFOHEADER *bitmapInfoHeader);

bool compareBitmapDimensions(BITMAP *bmp1, BITMAP *bmp2, QString &errorMessage);
bool compareColorTables(BITMAP *bmp1, BITMAP *bmp2, QString &errorMessage);
void saveBMP(BITMAP *bmp, std::string filename);
#endif // BITMAP_H
