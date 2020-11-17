#include "edge.h"


class graph
{
	private:
		shapeFactory sf;
		vector<shape*> sList;
		vector<edge*> eList;
	public:
		graph();
		~graph();
		int findS();
		int findE(shape*,shape*);
		int checkEdge(edge* );
		vector<shape*> getLIST();
		void clearS();
		void clearE();
		void add();		
		void show();
		void find();
		void sort_(int ,bool (*comparisonFunc)(shape*&, shape*&));
		void sort_(int ,int );
		void read();
		void readEdge(ifstream &);
		void write();
		void showAllPossibleEdges();
		void matchEdge();
		void showAllEdges();
		void readSE();
		void menu();

};
