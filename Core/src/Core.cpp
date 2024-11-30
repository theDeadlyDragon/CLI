#include "../include/Core.h"


bool test2(char* args, int size){
	return true;
}


void Test() {
	TrieRoot a;

	std::cout << "lib" << std::endl;

	a.AddElement("test", &test2);
	a.AddElement("test2", nullptr);

	a.BuildTrie();

	a.print();
}
