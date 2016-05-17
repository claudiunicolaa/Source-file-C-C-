/*
 * DynamicArray.h
 *
 *  Created on: Mar 28, 2016
 *      Author: claudiu
 */

#ifndef UTIL_DYNAMICARRAY_H_
#define UTIL_DYNAMICARRAY_H_

template<typename Element>
class IteratorVector;

template<typename Element>
class DynamicArray {
public:
	/**
	 * Default constructor
	 */
	DynamicArray();
	/**
	 * Copy constructor
	 */
	DynamicArray(const DynamicArray &ot);

	/**
	 * destructor
	 */
	~DynamicArray();
	/**
	 * Add an element to the dynamic array to the end of the array
	 * e - is a generic element
	 */
	void addE(Element r);

	/**
	 * Update an element from the given position.
	 * poz - the position
	 * r - the element that be updated
	 */
	void updateElem(int poz, Element r);

	/**
	 * Delete the element from the given position
	 * returns the deleted element
	 */
	Element deleteElem(Element poz);

	/**
	 * Access the element from a given position
	 * poz - the position (poz>=0;poz<size)
	 */
	Element& get(int poz) const;
	/**
	 * Give the size of the array
	 * return the number of elements in the array
	 */
	int getSize() const;
	/**
	 * Clear the array
	 * Post: the array will contain 0 elements
	 */
	void clear();
	/*
	 * Getter for capacity
	 */
	int getCapacity() const;

	/*
	 * This function return us the position of an Element
	 * in the DynamicArray searching for an unique code
	 */
	int position(Element& elem) {
		for (int i = 0; i < size; i++)
			if (elems[i] == elem)
				return i;
		return -1;
	}

	/*
	 * Function for modify an object
	 */
	void setElement(const Element& ot, int poz) {
		elems[poz] = ot;
	}

	friend IteratorVector<Element> ;
	IteratorVector<Element> being();
	IteratorVector<Element> end();

	DynamicArray<Element>& operator=(const DynamicArray<Element>& ot) {
		if (this == &ot)
			return ot; //protect against self-assignemet
		delete[] this->elems;
		this->elems = new Element[ot.capacity];
		for (int i = 0; i < ot.size; i++) {
			this->elems[i] = ot.elems[i];
		}
		this->capacity = ot.capacity;
		this->size = ot.size;
		return *this;
	}

	DynamicArray<Element>& operator+(const Element& ot) {
		this->addE(ot);
		return *this;
	}

	DynamicArray<Element>& operator-(const Element& elem) {
		this->deleteElem(elem);
		return *this;
	}

private:
	int capacity;
	Element* elems;
	int size;
	/**
	 * Create enough space to hold nrElem elements
	 * nrElems - the number of elements that we need to store
	 */
	void ensureCapacity(int nrElems);
};

template<typename Element>
DynamicArray<Element>::DynamicArray() {
	capacity = 10;
	elems = new Element[capacity];
	size = 0;
}

template<typename Element>
DynamicArray<Element>::DynamicArray(const DynamicArray<Element>& ot) {
	this->capacity = ot.capacity;
//	delete[] elems;
	this->size = ot.size;
	elems = new Element[this->capacity];
	for (int i = 0; i < size; i++)
		this->elems[i] = ot.elems[i];
}

template<typename Element>
DynamicArray<Element>::~DynamicArray() {
	delete[] elems;
}

template<typename Element>
void DynamicArray<Element>::ensureCapacity(int nrElems) {
	if (capacity >= nrElems)
		return; //we have space to store the values
	//we need to allocate more space for the values
	Element* aux = elems;
	//create space to hold more numbers
	capacity *= 2;
	elems = new Element[capacity];
	//copy the values
	for (int i = 0; i < size; i++)
		elems[i] = aux[i];
	//release the memory
	delete[] aux;
}

template<typename Element>
void DynamicArray<Element>::addE(Element r) {
	ensureCapacity(size + 1);
	elems[size] = r;
	size++;
}
template<typename Element>
void DynamicArray<Element>::updateElem(int poz, Element r) {
//	deleteElem(elems[poz]);
	elems[poz] = r;
}
/**
 * Access the element from a given position
 * poz - the position (poz>=0;poz<size)
 */
template<typename Element>
Element& DynamicArray<Element>::get(int poz) const {
	return elems[poz];
}

/**
 * Give the size of the array
 * return the number of elements in the array
 */
template<typename Element>
int DynamicArray<Element>::getSize() const {
	return size;
}

/**
 * Clear the element of the arrays
 * Post: the array will contain 0 elements
 */
template<typename Element>
void DynamicArray<Element>::clear() {
	size = 0;
}

/**
 * Delete the element from the given position
 * poz - the position of the elem to be deleted, poz>=0;poz<size
 * return the deleted element
 */
template<typename Element>
Element DynamicArray<Element>::deleteElem(Element rez) {
	int poz = position(rez);
	for (int i = poz; i < size - 1; i++) {
		elems[i] = elems[i + 1];
	}
	size--;
	return rez;
}

template<typename Element>
int DynamicArray<Element>::getCapacity() const {
	return capacity;
}

/*
 *
 *
 *
 */

template<typename Element>
class IteratorVector {
private:
	const DynamicArray<Element>& v;
	int poz = 0;

public:
	IteratorVector<Element>(const DynamicArray<Element>& v) :
			v(v) {
	}
	IteratorVector<Element>(const DynamicArray<Element>& v, int poz) :
			v(v), poz(poz) {
	}
	bool valid() const {
		return poz < v.getSize();
	}

	Element& element() const {
		return v.elems[poz];
	}

	void next() {
		poz++;
	}

	Element& operator*() {
		return element();
	}
	IteratorVector& operator++() {
		next();
		return *this;
	}
	bool operator==(const IteratorVector& ot) {
		return poz == ot.poz;
	}
	bool operator!=(const IteratorVector& ot) {
		return !(*this == ot);
	}

	int getPos() {
		return this->poz;
	}
};

template<typename Element>
IteratorVector<Element> DynamicArray<Element>::being() {
	return IteratorVector<Element>(*this);
}

template<typename Element>
IteratorVector<Element> DynamicArray<Element>::end() {
	return IteratorVector<Element>(*this, getSize());
}

#endif /* UTIL_DYNAMICARRAY_H_ */
