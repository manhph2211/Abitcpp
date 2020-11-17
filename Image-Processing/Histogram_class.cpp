#include <iostream>
#include <stdlib.h>
#define BYTE unsigned char

using namespace std;

class Pixel
{
private:
    BYTE R, G, B;

public:
    Pixel() : R(0), G(0), B(0) {}

    Pixel(BYTE r, BYTE g, BYTE b) : R(r), G(g), B(b) {}

    Pixel(int value)
    {
        R = (value >> 16) & 0xFF;
        G = (value >> 8 ) & 0xFF;
        B = value & 0xFF;
    }
    int GrayScale() const
    {
        return (2 * R + 3 * G + B) / 8;
    }

    friend Pixel operator+(const Pixel &left, const Pixel &right)
    {
        return Pixel(left.R + right.R, left.G + right.G, left.B + right.B);
    }

    friend ostream &operator<<(ostream &left, const Pixel &right)
    {
        left << "(" << (int)right.R << "," << (int)right.G << "," << (int)right.B << ")";
        return left;
    }
};

class Bitmap
{
private:
    int width, height;
    Pixel **data;

    void freeData()
    {
        if (data == 0)
            return;
        for (int i = 0; i < height; ++i)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    void createData(int w, int h)
    {
        width = w;
        height = h;
        data = new Pixel *[height];
        for (int i = 0; i < height; ++i)
        {
            data[i] = new Pixel[width];
        }
    }

public:
    Bitmap() { createData(0, 0); }

    Bitmap(int w, int h) { createData(w, h); }

    Bitmap(const Bitmap &bmp)
    {
        createData(bmp.width, bmp.height);
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
                data[i][j] = bmp.data[i][j];
        }
    }
    ~Bitmap() { freeData(); }

    int getWidth() const { return width; }

    int getHeight() const { return height; }

    Bitmap Crop(int x, int y, int w, int h)
    {
        int tW, tH;
        tW = (x + w) > width ? width - x : w;
        tH = (y + h) > height ? height - y : h;
        Bitmap result(tW, tH);
        for (int i = x; i < x + tW; ++i)
        {
            for (int j = y; j < y + tH; ++j)
                result.data[i][j] = data[i][j];
        }
        return result;
    }
    int *Histogram()
    {
        int *res = new int[256];
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
                res[data[i][j].GrayScale()]++;
        }
        return res;
    }

    Pixel &operator()(int x, int y) { return data[x][y]; }

    Bitmap &operator=(const Bitmap &bmp)
    {
        if (this != &bmp)
        {
            freeData();
            createData(bmp.width, bmp.height);
            for (int i = 0; i < height; ++i)
            {
                for (int j = 0; j < width; ++j)
                    data[i][j] = bmp.data[i][j];
            }
        }
        return *this;
    }
};

int main()
{
    Pixel p(10, 10, 20);
    cout << p + Pixel(10, 10, 10) << endl;
    Bitmap A;
    Bitmap B(100, 100);
    for (int i = 0; i < B.getHeight(); ++i)
    {
        for (int j = 0; j < B.getWidth(); ++j)
            B(i, j) = Pixel(rand());
    }
    A = B;
    int *his = A.Histogram();
    for (int i = 0; i < 256; ++i)
        cout << his[i] << endl;
    delete[] his;
    Bitmap C(B.Crop(20, 20, 40, 60));
    return 0;
}
