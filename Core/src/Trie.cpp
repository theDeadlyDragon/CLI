#include "../include/Trie.h"

void AddElementToArray(TrieElement *elements, int &size, TrieElement element)
{
    TrieElement *resizedList = new TrieElement[size];

    // std::memcpy(
  
    if (size  == 0)
    {
        memcpy(&elements[size++],&element,sizeof(TrieElement));
        elements = resizedList;
        return;
    }

  size = size + 1;
    //
    memcpy(resizedList, elements, (size)*sizeof(TrieElement));
    memcpy(&resizedList[size-1],&element,sizeof(TrieElement));

    TrieElement * a = &resizedList[size-1];

    delete elements;
    elements = resizedList;
}

TrieElement::TrieElement()
{
    m_childsSize = 0;
}

TrieElement::TrieElement(char key, TrieElement *parent, bool (*func)(char *, int)) : m_key(key), m_parent(parent), m_func(func)
{
    m_childsSize = 0;
}

void TrieElement::addElement(PreTrieElement element)
{
    std::cout << element.name[element.textIndex] << std::endl;
    if (element.name[element.textIndex] == '\0')
        return;


    for (int i = 0; i < m_childsSize; i++)
    {
        if (m_childs[i].m_key == element.name[element.textIndex])
        {
            m_childs[i].addElement(element);
            return;
        }
    }
    char a = element.name[element.textIndex];

    // AddElementToArray(m_childs, m_childsSize, new TrieElement<T>('1', this, 10));
    AddElementToArray(m_childs, m_childsSize, TrieElement(element.name[element.textIndex], this, element.func));
    element.textIndex++;

    m_childs[m_childsSize-1].addElement(element);
}

void TrieElement::print(){
    for(int i =0; i< m_childsSize; i++){
        std::cout << m_key << std::endl;
        m_childs[i].print();
    }
}

void TrieRoot::AddElement(std::string name, bool (*func)(char *, int))
{
    this->m_prebuildElements.push_back(PreTrieElement(name, func));
}

void TrieRoot::BuildTrie()
{
    for (auto item : m_prebuildElements)
        m_rootElement.addElement(item);
}
void TrieRoot::print()
{
   m_rootElement.print();
}
