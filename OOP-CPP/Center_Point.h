#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

enum shapeType{t_circle, t_triangle, t_rectangle, t_ellipse};

int opt=0;


class centerPoint
{
	private:			
		float x;
		float y;
	public:
		centerPoint();
		centerPoint(float,float);
		void setX(float );
		void setY(float );
		void init();
		void show(ofstream&);
		void show();
		bool operator == (centerPoint);
};
