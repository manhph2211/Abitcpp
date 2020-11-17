#include"shapFactory.h"



	shape* shapeFactory::newShape(const int &description)
   {
        if(description == t_circle)
            return new circle;
        if(description == t_triangle)
            return new triangle;
    	if(description == t_rectangle)
            return new rectangle;
        if(description == t_ellipse)
            return new ellipse;           
        return NULL;
   }
   shape* shapeFactory::newShape(int &description, int x,int y)
   {
   	    if(description == t_circle)
            return new circle(x,y);
        if(description == t_triangle)
            return new triangle(x,y);
    	if(description == t_rectangle)
            return new rectangle(x,y);
        if(description == t_ellipse)
            return new ellipse(x,y);           
        return NULL;
   }
  shape* shapeFactory::newShape(string &description)
   {
   	    if(description == "t_circle")
            return new circle;
        if(description == "t_triangle")
            return new triangle;
    	if(description == "t_rectangle")
            return new rectangle;
        if(description == "t_ellipse")
            return new ellipse;           
        return NULL;
   }
