#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <vector>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()){
		childCount = m;
		minMax = c;
	};

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
std::vector<T> myHeap;
int childCount;
PComparator minMax;
void heapify(int index);
void trickleUp(int loc);
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){

}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
	return myHeap.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
	return myHeap.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc){
	int parent = loc/childCount;
	while(loc != 0 && minMax(myHeap[loc], myHeap[parent])){
		std::swap(myHeap[parent], myHeap[loc]);
		loc = parent;
		parent = loc/childCount;
	}
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int index){
	int lChild = childCount*index + 1;
	int rChild = childCount*index + 2;
	if(lChild >= (int)myHeap.size()){
		return;
	}
	if(rChild < (int)myHeap.size()){
		if(minMax(myHeap[rChild], myHeap[lChild])){
			lChild = rChild;
		}
	}
	if(minMax(myHeap[index], myHeap[lChild])){
		std::swap(myHeap[index], myHeap[lChild]);
		heapify(lChild);
	}
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(myHeap.empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Heap is empty");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return myHeap[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(myHeap.empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Heap is empty");


  }
	myHeap[0] = myHeap.back();
	myHeap.pop_back();
	heapify(0);



}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
	myHeap.push_back(item);
	trickleUp((int)myHeap.size()-1);
}



#endif

