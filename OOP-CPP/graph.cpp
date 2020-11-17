#include"graph.h"


		graph::graph()
		{

		}

		graph::~graph()
		{
			sList.clear();
			eList.clear();
		}
		
		void graph::clearS()
		{
			sList.clear();
		}	

		void graph::clearE()
		{
			eList.clear();
		}

		bool ascending(shape*&s1, shape*&s2)
		{
			return opt ? s1->getP() > s2->getP():s1->getA() > s2->getA() ;
		}

		bool descending(shape*&s1, shape*&s2)
		{
			return opt ? s1->getP() < s2->getP():s1->getA()< s2->getA() ;
		}
		vector<shape*> graph::getLIST()
		{
		return sList;	
		} 
		void graph::add()
		{
			do
			{
				shape *G;
				system("cls");
				cout << "\nPress 'c' to add a Circle";
				cout << "\nPress 't' to add a Triangle";
				cout << "\nPress 'r' to add a  rectangle";
				cout << "\nPress 'e' to add a Ellipse";
				cout << "\nPress 'xxx' to exit";
				cout << "\n\nPress ...";
				switch (_getch())
				{
					case 'c':G = sf.newShape(t_circle);G->init();sList.push_back(G); break;
					case 't':G = sf.newShape(t_triangle);G->init();sList.push_back(G); break;
					case 'r':G = sf.newShape(t_rectangle);G->init();sList.push_back(G); break;
					case 'e':G = sf.newShape(t_ellipse);G->init();sList.push_back(G); break;
					case 'x': break;
					default: cout << "\nWrong!"; system("pause"); break;
				}
				
			}while(_getch()!='x');
		}
		
		
		void graph::show()
			{
				for(int i=0;i<sList.size();i++)
				{
					sList.at(i)->show();
					cout<<"\n*********************************************************************************************************\n";
				}
			}
			
			
		void graph::find()
		{
				centerPoint c;
				c.init();
				int k=0;
				for(int i=0;i<sList.size();i++)
				{
					if(sList.at(i)->getCP()==c)
						{
							cout<<"\nThis one?";
							sList.at(i)->show();
							k++;
						}
					if(k==0&&(i+1)==sList.size())
						cout<<"\nCannot find that shape!!!";
					cout<<endl;
				}
		}
		
		
		int graph::findS()
		{
				centerPoint c;
				c.init();
				int j=-1;
				for(int i=0;i<sList.size();i++)
				{
					if(sList.at(i)->getCP()==c) {j=i;break;}
					if(i+1==sList.size()){cout<<"\nCannot find that shape!!!";exit(1);}
				}
				return j;
		}
		
		
		int graph::findE(shape*s1,shape*s2)
		{
			int j=-1;
			for(int i=0;i<eList.size();i++)
			{
				if (eList[i]->getS1()==s1&&eList[i]->getS2()==s2 || eList[i]->getS1()==s2&&eList[i]->getS2()==s1)
				{
					j=i;
					break;
				}
			}
			return j;
		}
		
		
		void graph::sort_(int x,bool (*comparisonFunc)(shape*&, shape*&))
		{
			opt=x;
			for(int i=0;i<sList.size()-1;i++)
			{
				for(int j=i+1;j<sList.size();j++)
				{
				//	if((x==1&&comparisonFunc(sList[i], sList[j]))||(x==0&&comparisonFunc(sList[i], sList[j])))
					if(comparisonFunc(sList[i], sList[j]))
						swap(sList[i],sList[j]);
				}
			}
		}
		
		
		void graph::sort_(int x,int y)
		{
			opt=x;
			sort(sList.begin(),sList.end(),y?ascending:descending) ;
		}
		
		
		void graph::read()
		{
			ifstream ifs;
			ifs.open("shape.txt",ios::in);
			int size;
			ifs>>size;
			for (int i=0;i<size;i++)
			{
				shape* s;
				int st;
				float x,y;
				ifs>>st;
				ifs>>x;
				ifs>>y;
				s=sf.newShape(st,x,y);
				sList.push_back(s);
			}
			ifs.close();
		}
		
		
		void graph::readEdge(ifstream &ifs)
		{
			string co;
			char* lt=new char[10];
			char* i=new char[10];char* j=new char[10];
			ifs.getline(i,10,',');
			ifs.getline(j,10,',');
			getline(ifs,co,',');
			ifs.getline(lt,10,'}');
			edge* e=new edge(sList[atoi(i)-1],sList[atoi(j)-1]);
			e->set(co,atof(lt));
			eList.push_back(e);
		}
		
		
		void graph::write()
		{
			cout<<"\nWriting "<<sList.size()<<" shapes...";
			ofstream of("shape.txt",ios::out);
			of<<sList.size()<<"\n";
			for (int i=0;i<sList.size();i++)
			{
				of<<sList.at(i)->getType()<<" ";
				of<<sList.at(i)->perimeter()<<" "<<sList.at(i)->area();
				//sList.at(i)->getCP().show(of);
				if(i<sList.size()-1)
					of<<"\n";
			}
			cout<<"\nDone!";
			of.close();
		}
		
		
		void graph::showAllPossibleEdges()
		{
			cout<<"\nwhat shape in the above list(just type its cp) you want to see its matching_cp edges to others: ";
			int j=this->findS();
			for(int i=0;i<this->sList.size();i++)
				{
				if(j>0&&i==j)continue;
				edge ed(this->getLIST().at(i),this->getLIST().at(j));
				ed.init(); 
				ed.show();
				cout<<endl;
				}
		}
		
		
		int graph::checkEdge(edge* e)
		{
			int t=1;
			//vector<edge*>::iterator pt;
			for(int i=0;i<eList.size();i++)
			{
				if (eList[i]->getS1()==e->getS1()&&eList[i]->getS2()==e->getS2() || eList[i]->getS1()==e->getS2()&&eList[i]->getS2()==e->getS1())
				{
					t=0;
					break;
				}
			}
			return t;
		}
		
		
		void graph::matchEdge()
		{
			this->show();
			cout<<"\nEnter 2 shape you want to match: ";
			int i=findS();
			int j=findS();
			//cout<<i<<"   "<<j;
			edge *e=new edge(sList[i],sList[j]);
			int op=0;
			if(!checkEdge(e))
			{
				cout<<"\nAlready matched edge!, do u want to update color and line thickness?";
				cin>>op;
				if(op)
				{
					e->init();
					int k=this->findE(sList[i],sList[j]);
					eList.erase(eList.begin()+k);
					eList.push_back(e);
					e->show();
				}
				cout<<"\nOK!";
			}
			else
			{
				e->init();
				eList.push_back(e);
				e->show();
			}
			system("pause");
		}
		
		
		void graph::showAllEdges()
		{
			cout<<"\n\nAll matched edges:\n";
			vector<edge*>::iterator pt;
			for(pt=eList.begin();pt<eList.end();pt++)
				{(*pt)->show(); cout<<endl;}
		}
		
		
		void graph::readSE()
		{
			ifstream ifs;
			ifs.open("shape_edge.txt",ios_base::in);
			int num=0;
			string line;		
			while(getline(ifs,line))
				++num;
			int num1=num;
			cout<<"\n\nReading shape_edge.txt...";
			ifs.clear();
			ifs.seekg(0);
			while(num>0 && ifs.eof()==false)
			{
				string z="NULL";
				getline(ifs, z,'{');
				if(z=="shape")
				{
					shape* sh; 
					string t;				
					getline(ifs,t,',');
					sh=sf.newShape(t);
					sList.push_back(sh->readShape(ifs));  											
				}
				else if(z=="edge")
					this->readEdge(ifs);
				string temp;
				getline(ifs,temp,'\n');
				--num;
			}
			cout<<"\nDone! "<<num1<<" objects have been read:))";
			ifs.close();
		}
		
		
		void graph::menu()
		{
				system("cls");
				cout<<"\n Press 'a' to add a new shape";
				cout<<"\n Press 's' to show the list";
				cout<<"\n Press 'f' to find a shape through its centerPoint";
				cout<<"\n Press 'p' to sort the list by its elements's perimeters as ascending order";
				cout<<"\n Press 'o' to sort the list by its elements's areas as ascending order";
				cout<<"\n Press 'n' to sort the list by its elements's perimeters as descending order";
				cout<<"\n Press 'm' to sort the list by its elements's areas as descending order";
				cout<<"\n Press 'i' to read shape_edge.txt file";
				cout<<"\n Press 't' to match 2 shape you want!";
				cout<<"\n Press 'b' to show all the matched edges";
				cout<<"\n Press 'w' to write file";
				cout<<"\n Press 'c' to clear shape list";
				cout<<"\n Press 'k' to clear edge list";
				cout<<"\n Press 'r' to read file";
				cout<<"\n Press 'q' to exit!";
				cout << "\n\nPress ...";
				switch (_getch())
				{
					case 'a':add(); break;
					case 's':show();cout<<endl;system("pause"); break;
					case 'f':find();system("pause"); break;
					case 'p':sort_(1,ascending);show();cout<<endl;system("pause"); break;
					case 'o':sort_(0,ascending);show();cout<<endl;system("pause"); break;
					case 'n':sort_(1,descending);show();cout<<endl;system("pause"); break;
					case 'm':sort_(0,descending);show();cout<<endl;system("pause"); break;
					case 'w':write();break;
					case 'c':clearS();break;
					case 'i':readSE();break;	 
					case 'r':read();show();cout<<endl;system("pause");break;
					case 'v':sort_(1,0);show();cout<<endl;system("pause"); break;  // this's also true
					case 'e':showAllPossibleEdges();system("pause"); break;
					case 't':matchEdge();break;
					case 'b':showAllEdges();system("pause");break;
					case 'k':clearE();break;
					case 'q': break;
					default: cout << "\nWrong!"; system("pause"); break;
				}

		}
