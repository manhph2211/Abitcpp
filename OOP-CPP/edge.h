#include"shapeFactory.h"



class edge
{
	private:
		shape* s1;
		shape* s2;
		string color;
		float lineThickness;
	public:
		edge();
		~edge();
		void free();
		edge(shape* , shape *,string ,float );
		shape* getS1();
		shape* getS2();
		void set(string ,float );
		edge(shape* , shape *);
		bool operator ==(edge* e);
		void init();
		void show();
};