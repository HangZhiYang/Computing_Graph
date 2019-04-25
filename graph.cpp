#include "graph.h"
#include<iostream>
#include <string>
/*int Graph::getid(std::string str)
{
    for (int i = 0;i < used; ++i)
    {
        if(str == nodes[i]->name)
            return i;
    }
    return -1;
}*/
Graph::Graph(int sz)
{
}
Graph::~Graph()
{
}
Node* Graph::getNamePointer(string str)
{
	if(nodes.count(str))return nodes[str];
	else return nullptr;
}
Node* Graph::operator[](const string str)
{
	return getNamePointer(str);
}
int Graph::push(Node* newnode)
{
	if(nodes.count(newnode->name))
	{
		std::cout<<"Same name!"<<std::endl;
		return 1;
	}
	nodes.insert(std::make_pair(newnode->name,newnode));
	return 0;
}
void Graph::reset()
{
	for(auto iter = nodes.begin(); iter != nodes.end(); iter++)
	{
		iter->second->reset();
	}
}
float Graph::eval(string nodename,int placeholdernum,string* placeholdernames,float* placeholdervalue)
{
	reset();
	for(int i=0; i<placeholdernum; i++)
		getNamePointer(placeholdernames[i])->setvalue(placeholdervalue[i]);

	return getNamePointer(nodename)->geteval();
}
void Graph::setvariable(string vname,float value)
{
	getNamePointer(vname)->setvalue(value);
}
