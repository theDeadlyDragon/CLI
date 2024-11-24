#pragma once
#include <vector>
#include <string>
#include "../build/Utility.h"


template <typename T>
struct PreTrieElement {
	std::string m_name;
	T m_data;

	PreTrieElement(std::string name, T data){
		this->m_name = name;
		this->m_data = data;
	}
};

template <typename T>
class TrieElement {
private:
	char m_key;
	TrieElement* m_childs = nullptr;
	int m_childsSize = 0;
	TrieElement* m_parent;
	T m_data;
	
public:
	TrieElement();
	TrieElement(char key, TrieElement<T>* parent, T data): m_key(key), m_parent(parent), m_data(data){}

	void addElement(PreTrieElement<T>* element) {
		//AddElementToArray(m_childs, m_childsSize, new TrieElement<T>('1', this, 10));
		AddElementToArray('a',m_childsSize,'a');

	}
};


template <typename T>
class TrieRoot {
private:
	std::vector<PreTrieElement<T>> m_elementBBuild;
	TrieElement<T> m_rootElement;

public:
	TrieRoot() {}

	void BuildTrie() {
		m_rootElement.addElement(nullptr);
	}

	void AddElement(std::string name, T data) {
		this->m_elementBBuild.push_back(PreTrieElement<T>(name, data));
	}

};






