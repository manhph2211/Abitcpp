#include"shape.h"


		shape::shape()
		{
			color="NULL";
			peri=are=0;
			lineThickness=0;
		}

		shape::shape(float p,float a)
		{
			peri=p;
			are=a;
		}

		float shape::getA()
		{
			return are;
		}

		float shape::getP()
		{
			return peri;
		}


		void shape::setPeri(float pe)
		{
			peri=pe;
		}

		void shape::setArea(float ar)
		{
			are=ar;
		}

		void shape::setName(shapeType st)
		{
			name=st;
		}

		centerPoint shape::getCP()
		{
			return cp;
		}
		bool shape::operator ==(shape* s)
		{
			return (s->cp==this->cp);
		}
		//template<typename T>
		shapeType shape::getType();
		void shape::init()
		{
			cp.init();
			cout<<"\nEnter the color: ";
			fflush(stdin);
			getline(cin,color);
			cout<<"\nEnter the thickness of the strock: ";
			cin>>lineThickness;
		}

		void shape::show()
		{
			cout<<setw(10)<<name;
			cp.show();
			cout<<setw(10)<<color<<setw(20)<<lineThickness<<setw(15)<<peri<<setw(15)<<are;
		}

		shapeType shape::getType()
		{
			if (typeid(*this) == typeid(circle))
				return t_circle;
			else if (typeid(*this) == typeid(triangle))
				return t_triangle;
			else if (typeid(*this) == typeid(rectangle))
				return t_rectangle;
			else if (typeid(*this) == typeid(ellipse))
				return t_ellipse;
			else { cout << "\nwrong"; exit(1); }
		}



		circle::circle(){
			name=t_circle;
			radius=0;
		}
		circle::circle(float p,float a)
		{
			
			name=t_circle;
			//cp=c;
			peri=p;
			are=a;
			radius=0;
		}
		circle::circle(float x1,float y1,float ra,string co,float thi)
		{
			name=t_circle;
			cp.setX(x1);
			cp.setY(y1);
			radius=ra;
			color=co;
			lineThickness=thi;
			peri=this->perimeter();
			are=this->area();
		}
		void circle::init()
		{
			shape::init();
			cout<<"\nEnter value of radius of the circle: ";
			cin>>radius;
			peri=this->perimeter();
			are=this->area();
		}

		void circle::show()
		{
		
			cout<<"\n*********************************************************************************************************\n";
			cout<<setw(10)<<"name"<<setw(20)<<"center point"<<setw(10)<<"color"<<setw(20)<<"lineThickness"<<setw(15)<<"perimeter"<<setw(15)<<"area"<<setw(10)<<"radius\n";
			shape::show();
			cout<<setw(10)<<radius;
		}

		float circle::perimeter()
		{
			peri= 2* M_PI * radius;
			return peri;
		}

		float circle::area()
		{
			are= M_PI* pow(radius,2);
			return are;
		}
		shape* circle::readShape(ifstream& ifs)
		{
			
			// solution1:
			string co;
			char *xc1=new char[10];
			char *yc1=new char[10];
			char *x2=new char[10];
			char *l=new char[10];
			ifs.getline(xc1,10,',');	
			ifs.getline(yc1,10,',');
			ifs.getline(x2,10,',');
			getline(ifs,co,',');
			ifs.getline(l,10,'}');
			shape* s=new circle(atof(xc1),atof(yc1),atof(x2),co,atof(l));
			return s;
		}



		triangle::triangle(float p,float a)
		{
			name=t_triangle;
			peri=p;
			are=a;
			x=y=z=0;
		}
		
		triangle::triangle(float xc,float yc,float x1,float y1,float z1,string co,float thi)
		{
			name=t_triangle;
			cp.setX(xc);
			cp.setY(yc);
			x=x1;y=y1;z=z1;
			color=co;
			lineThickness=thi;
			peri=this->perimeter();
			are=this->area();
		}
		triangle::triangle(){
			name=t_triangle;
			x=y=z=0;
		}
		void triangle::init()
		{
			shape::init();
			do
			{
			cout<<"\nEnter the length x,y,z respectively: ";
			cin>>x>>y>>z;
			if((x+y)<z&&(x+z)<y&&(y+z)<x)
				cout<<"\nWrong!!!";
			}while((x+y)<z&&(x+z)<y&&(y+z)<x);
			peri=this->perimeter();
			are=this->area();
		}
		void triangle::show()
		{			
			cout<<"\n*********************************************************************************************************\n";
			cout<<setw(10)<<"name"<<setw(20)<<"center point"<<setw(10)<<"color"<<setw(20)<<"lineThickness"<<setw(15)<<"perimeter"<<setw(15)<<"area"<<setw(10)<<"lengths\n";
			shape::show();
			cout<<setw(3)<<"("<<x<<","<<y<<","<<z<<")";
		}
		float triangle::perimeter()
		{
			peri=x+y+z;
			return peri;
		}	
		float triangle::area()
		{
			float p=this->perimeter()/2;
			are=sqrt(p*(p-x)*(p-y)*(p-z));
			return are;
		}
		shape* triangle::readShape(ifstream& ifs)
		{
			//solution2:
			char x;
			string co;
			float _xc1,_yc1,_x2,_y2,_z2,_l;
			ifs>>_xc1>>x>>_yc1>>x>>_x2>>x>>_y2>>x>>_z2>>x;
			getline(ifs,co,',');
			ifs>>_l;
			shape* s=new triangle(_xc1,_yc1,_x2,_y2,_z2,co,_l);
			return s;
		}


		rectangle::rectangle(float p,float a)
		{
			name=t_rectangle;
			//name=na;
			//cp=c;
			peri=p;
			are=a;
			length=width=0;
		}
		rectangle::rectangle::rectangle(float x1,float y1,float le,float wid,string co,float thi)
		{
			name=t_rectangle;
			cp.setX(x1);
			cp.setY(y1);
			length=le;width=wid;
			color=co;
			lineThickness=thi;
			peri=this->perimeter();
			are=this->area();
		}
		rectangle::rectangle()
		{
			name=t_rectangle;
			length=width=0;
		}
		void rectangle::init()
		{
			shape::init();
			cout<<"\nEnter the length: ";
			cin>>length;
			do
			{
				cout<<"\nEnter the width: ";
				cin>>width;
				if(width>length)
					cout<<"!wrong";
			}while(width>length);
			peri=this->perimeter();
			are=this->area();
		}
		void rectangle::show()
		{
	
			cout<<"\n*********************************************************************************************************\n";
			cout<<setw(10)<<"name"<<setw(20)<<"center point"<<setw(10)<<"color"<<setw(20)<<"lineThickness"<<setw(15)<<"perimeter"<<setw(15)<<"area"<<setw(15)<<"edge values\n";
			shape::show();
			cout<<setw(5)<<"("<<width<<","<<length<<")";
		}
		float rectangle::perimeter()
		{
			peri=2*(length+width);
			return peri;
		}
		float rectangle::area()
		{
			are=length*width;
			return are;
		}
		
		
		shape* rectangle::readShape(ifstream& ifs)
		{
			//solution 3: using stringstream
			string co,xc1,yc1,x2,y2,l;
			float _xc1,_yc1,_x2,_y2,_l;
			getline(ifs,xc1,',');
			getline(ifs,yc1,',');
			getline(ifs,x2,',');
			getline(ifs,y2,',');
			getline(ifs,co,',');
			getline(ifs,l,'}');
			stringstream geek(xc1+" "+yc1+" "+x2+" "+y2+" "+l);	
			geek>>_xc1>>_yc1>>_x2>>_y2>>_l;
			shape* s=new rectangle(_xc1,_yc1,_x2,_y2,co,_l);
			return s;

		}



		ellipse::ellipse(float p,float ar)
		{
			name=t_ellipse;
			peri=p;
			are=ar;
			a=b=0;
		}
		ellipse::ellipse(float x1,float y1,float a1,float b1,string co,float thi)
		{
			name=t_ellipse;
			cp.setX(x1);
			cp.setY(y1);
			a=a1;b=b1;
			color=co;
			lineThickness=thi;
			peri=this->perimeter();
			are=this->area();
		}
		ellipse::ellipse()
		{
			name=t_ellipse;
			a=b=0;
		}
		void ellipse::init()
		{
			shape::init();
			cout<<"\nEnter semi-major axis length: ";
			cin>>a;
			do
			{
				cout<<"\nEnter the semi-minor axis length: ";
				cin>>b;
				if(b>a)
					cout<<"!wrong";
			}while(b>a);
			peri=this->perimeter();
			are=this->area();
		}
		void ellipse::show()
		{
		
			cout<<"\n*********************************************************************************************************\n";
			cout<<setw(10)<<"name"<<setw(20)<<"center point"<<setw(10)<<"color"<<setw(20)<<"lineThickness"<<setw(15)<<"perimeter"<<setw(15)<<"area"<<setw(20)<<"semiAxis values\n";
			shape::show();
			cout<<setw(8)<<"("<<a<<","<<b<<")";
		}
		
		float ellipse::area()
		{
			are=M_PI*a*b;
			return are;
		}

		float ellipse::integrate( float loli, float upli, int acc)
		{
		    float avg   = ( upli - loli ) / acc;
		    float val   = 0.5 * avg * (f(loli)+f(upli));
		    for( int i = 1; i <= acc; ++i )
		        val += avg * f( loli + avg * i );
		 
		    return val;
		}
		float ellipse::perimeter()
		{
			peri= this->integrate(0,M_PI/2,100000);
			return peri;
		}
		float ellipse::f(float x)
		{
			return 4*sqrt(pow(a*cos(x),2)+pow(b*sin(x),2));
		}
		shape* ellipse::readShape(ifstream& ifs)
		{
			string co,xc1,yc1,x2,y2,l;
			float _xc1,_yc1,_x2,_y2,_l;
			getline(ifs,xc1,',');
			getline(ifs,yc1,',');
			getline(ifs,x2,',');
			getline(ifs,y2,',');
			getline(ifs,co,',');
			getline(ifs,l,'}');
			stringstream geek(xc1+" "+yc1+" "+x2+" "+y2+" "+l);	
			geek>>_xc1>>_yc1>>_x2>>_y2>>_l;
			shape* s=new ellipse(_xc1,_yc1,_x2,_y2,co,_l);
			return s;
		}
