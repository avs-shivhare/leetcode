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
    Iterator* head = NULL;
    int temp = -1;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        head = new Iterator(nums);
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(temp != -1) return temp;
        return temp = head->next();
        
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(temp != -1) {
            int ans = temp;
            temp = -1;
            return ans;
        }
        return head->next();

	}
	
	bool hasNext() const {
	    if(temp != -1) return true;
        return head->hasNext();
	}
};