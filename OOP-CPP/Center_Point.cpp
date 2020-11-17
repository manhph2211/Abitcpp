#include"Center_Point.h"


		centerPoint::centerPoint()
		{
			x=y=0;
		}
		centerPoint::centerPoint(float a,float b)
		{
			x=a;y=b;
		}
		void centerPoint::setX(float x1)
		{
			x=x1;
		}
		void centerPoint::setY(float y1)
		{
			y=y1;
		}
		void centerPoint::init()
		{
			cout<<"\nEnter the value of x: ";
			cin>>x;
			cout<<"\nEnter the value of y: ";
			cin>>y;
		}
		void centerPoint::show(ofstream& of)
		{
			of<<setw(15)<<"CP("<<x<<","<<y<<")";
		}
		void centerPoint::show()
		{
			cout<<setw(15)<<"CP("<<x<<","<<y<<")";
		}
		bool centerPoint::operator == (centerPoint c)
		{
			return (c.x==x && c.y==y);
		}