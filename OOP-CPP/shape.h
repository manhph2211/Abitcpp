#include"Center_Point.h"


class shape
{
	protected:
		shapeType name;
		centerPoint cp;
		string color;
		float lineThickness;
		float peri;
		float are;
	public:
		shape();
		shape(float ,float );
		float getA();
		float getP();
		void setPeri(float );
		void setArea(float );
		void setName(shapeType );
		centerPoint getCP();
		bool operator ==(shape* );
		shapeType getType();
		virtual void init();
		virtual void show();
		virtual float perimeter()=0;
		virtual float area()=0;	
		virtual shape* readShape(ifstream& )=0;
};


class circle: public shape
{
	private:
		float radius;
	public:
		circle();
		circle(float ,float );
		circle(float ,float ,float ,string ,float );
		void init();
		void show();
		float perimeter();
		float area();
		shape* readShape(ifstream&);
};


class triangle:public shape
{
	private:
		float x,y,z; // length of each side
	public:
		triangle(float,float);
		
		triangle(float ,float ,float ,float ,float ,string ,float );
		triangle();
		void init();
		void show();
		float perimeter();	
		float area();
		shape* readShape(ifstream& ifs);
};


class rectangle:public shape
{
	private:
		float length,width;
	public:
		rectangle(float ,float);
		rectangle(float ,float ,float ,float ,string ,float );
		rectangle();
		void init();
		void show();
		float perimeter();
		float area();
		shape* readShape(ifstream& );
};


class ellipse:public shape
{
	private:
		float a,b;
	public:
		ellipse(float ,float );
		ellipse(float ,float ,float ,float ,string ,float);
		ellipse();
		void init();
		void show();	
		float area();
		float integrate( float , float , int);
		float perimeter();
		float f(float x);
		shape* readShape(ifstream&);

};
