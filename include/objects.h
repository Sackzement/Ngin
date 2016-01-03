#pragma once
#include "Object.h"
#include <vector>
using std::vector;



struct CObjects;
extern CObjects objects;



struct CObject
{
private:
	vector<Object> m_list;
private:
	const vector<Object>& list = m_list;
};

