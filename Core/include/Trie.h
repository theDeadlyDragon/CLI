#pragma once
#include <vector>
#include <string>
#include "iostream"
#include "Utility.h"

struct PreTrieElement;
class TrieElement;
class TrieRoot;

void  AddElementToArray(TrieElement* elements, int& size, TrieElement element);

class TrieElement {
private:
	char m_key;
	TrieElement* m_childs;
	int m_childsSize;
	TrieElement* m_parent;
	bool (*m_func)(char*, int);
	
public:
	TrieElement();
	TrieElement(char key, TrieElement* parent, bool (*func)(char*, int) );

	void print();
	void addElement(PreTrieElement element);
};



class TrieRoot {
private:
	std::vector<PreTrieElement> m_prebuildElements;
	TrieElement m_rootElement;

public:
	TrieRoot() {}

	void AddElement(std::string name, bool (*func)(char*, int));
	void BuildTrie();
	void print();
};




struct PreTrieElement {
	std::string name;
	bool (*func)(char*, int);
	int textIndex = 0;
	PreTrieElement(std::string name, bool (*func)(char*, int)): name(name), func(func)
	{}
};


