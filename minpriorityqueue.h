
#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

// NOTE: You may not include any other libraries!
#include <unordered_map>
#include <vector>
#include <utility> // Has pair and swap

using namespace std;

template <typename T>
class MinPriorityQueue
{
	// For the mandatory running times below:
	//
	// n is the number of elements in the MinPriorityQueue.
	//
	// Assume that the operations of unordered_map are O(1) time 
	// (they are average case, but not worst-case).

	public:
		// Creates an empty MinPriorityQueue
		MinPriorityQueue()
		{
			H.clear();
			I.clear();
		}

		// Returns the number of elements in the MinPriorityQueue.
		//
		// Must run in O(1) time.
		int size()
		{
			return H.size();	
		}

		// Pushes a new value x with priority p
		// into the MinPriorityQueue.
		//
		// Must run in O(log(n)) time.		 
		void push(T x, int p)
		{
			pair<T, int> couple;
			couple.first = x;
			couple.second = p;
			H.push_back(couple);
			int updIndex = bubbleUp(H.size() - 1);
			I[x] = updIndex;
		}

		// Returns the value at the front of the MinPriorityQueue.
		// Undefined behavior if the MinPriorityQueue is empty.
		// 
		// Must run in O(1) time.
		T front()
		{
			return (H[0].first);		// The min is always the "root", index 0
		}

		// Removes the value at the front of the MinPriorityQueue.
		// Undefined behavior if the MinPriorityQueue is empty.
		//
		// Must run in O(log(n)) time. 
		void pop()
		{
			if (H.size()== 0){
				cout << "There are no elements to pop."
				return;
			}
			bubbleDown(0);
		}

		// If x is in the MinPriorityQueue 
		// with current priority at least new_p,  
		// then changes the priority of x to new_p.
		// Undefined behavior otherwise.
		//
		// Must run in O(log(n)) time. 
		void decrease_key(T x, int new_p)
		{
			// TODO
		}

	private:
		// You don't need any other instance variables,
		// but you can add some if you want to.
		vector< pair<T, int> > H; // The heap.
		unordered_map<T, int> I;  // Maps values to their indices in H.

		int parent(int i)
		{
			return (i-1)/2;
		}

		int childLeft(int i)
		{
			return 2*i + 1;
		}

		int childRight(int i)
		{
			return 2*i + 2;
		}

		int bubbleUp(int index)
		{
			int i = index;

			while (i > 0 && H[i].second < H[parent(i)].second) 	// while the second member is less than its parent
			{											// which is a parent violation
				// Before swapping, update the map 'I' for both items being moved.
        		I[H[i].first] = parent(i);		// The child item is moving to the parent's index
        		I[H[parent(i)].first] = i;  	// The parent item is moving to the child's index

				swap(H[i], H[parent(i)]);	// swap the two couples			
				i = parent(i);
			}
			return i;
		}
		int bubbleDown(int index)
		{
			int i = index;
			int sizeH = H.size();
			
			while (childLeft(i)<sizeH)		// Check that at least there's a left child
			{
				int smallerChildInd = childLeft(i);
				if (childRight(i)<sizeH && H[childRight(i)].second < H[childLeft(i)].second )
			}

			return i;
		}
};

#endif 

