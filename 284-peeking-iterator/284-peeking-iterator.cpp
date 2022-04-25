/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
     vector<int>::iterator it1;
     vector<int>::iterator it2;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        vector<int> *temp = new vector<int>;
        
        for(int i=0; i<nums.size(); i++){
            temp->push_back(nums[i]);
        }
        
        it1 = temp->begin();
        it2 = temp->end();
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return *(it1);
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return *(it1++);
	}
	
	bool hasNext() const {
	    return (it1!=it2);
	}
};