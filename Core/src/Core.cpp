#include "../include/Core.h"





void Test() {
	TrieRoot<int> a;

	a.AddElement("test", 10);
	a.AddElement("test2", 11);

	a.BuildTrie();
}
