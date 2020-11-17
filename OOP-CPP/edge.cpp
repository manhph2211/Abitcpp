#include"edge.h"


		edge::edge()
		{
			color="NULL";
			lineThickness=0;
		}
			
		
		edge::~edge()
		{
			
		}
		
		
		void edge::free()
		{
			s1=NULL;
			s2=NULL;
		}
		
		
		edge::edge(shape* a, shape *b,string c,float t)
		{
			s1=a;s2=b;
			color=c;lineThickness=t;
		}
		
		
		shape* edge::getS1()
		{
			return s1;
		}
		
		
		shape* edge::getS2()
		{
			return s2;
		}
		
		
		void edge::set(string c,float l)
		{
			color=c;
			lineThickness=l;
		}
		
		edge::edge(shape* a, shape *b)
		{
			s1=a;s2=b;
		}
		
		
		bool edge::operator ==(edge* e)
		{
			return ((e->s1==this->s2) && (e->s2==this->s1)) || ((e->s1==this->s1) && (e->s2==this->s2));
		}
		
		
		void edge::init()
		{
			cout<<"\nColor of the edge: ";
			fflush(stdin);
			getline(cin,color);
			cout<<"\nAnd the line thickness: ";
			cin>>lineThickness;
		}
		
		
		void edge::show()
		{
			cout<<endl<<setw(20)<<"Shape 1"<<setw(20)<<"Shape 2"<<setw(20)<<"color"<<setw(20)<<"lineThickness\n";
			s1->getCP().show();cout<<":"<<s1->getType();
			s2->getCP().show();cout<<":"<<s2->getType();		
			cout<<setw(15)<<color<<setw(15)<<lineThickness;		
		}