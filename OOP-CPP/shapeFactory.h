#include"shape.h"


class shapeFactory
{
public:
  shape* newShape(const int &);
  shape* newShape(int &, int,int);
  shape* newShape(string &);
};