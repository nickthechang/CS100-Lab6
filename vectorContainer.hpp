#ifndef __VECTORCONTAINER_HPP__
#define __VECTORCONTAINER_HPP__

#include "container.hpp"
#include "sort.hpp"
#include <vector>
using namespace std;

class Container;
class Sort;

class VectorContainer : public Container{
	protected:
		vector<Base*> baseVector;
		Sort* sort_function;
	public:
		VectorContainer(): sort_function(NULL) {}	
		VectorContainer(Sort* temp): sort_function(NULL){
			sort_function = temp;
		}
		void set_sort_function(Sort* sort_function) {
			this -> sort_function = sort_function;
		}
		void sort(){
			if (sort_function != NULL) {
				sort_function->sort(this);
			}
			else {
				throw "sort function is null";
			}
		}
		void add_element(Base* element){
			baseVector.push_back(element);
		}
		void print(){
			for(unsigned int i = 0; i < baseVector.size(); ++i)
			{
				cout << baseVector.at(i)-> stringify() << endl;
			}
		}
		void swap(int i,int j){
			Base* temp2 = baseVector.at(i);
			baseVector.at(i) = baseVector.at(j);
			baseVector.at(j) = temp2;
		}
		Base* at(int i){
			return baseVector.at(i);
		}
		int size(){
			return baseVector.size();
		}
};

#endif
