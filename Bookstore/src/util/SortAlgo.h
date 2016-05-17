/*
 * SortAlgo.h
 *
 *  Created on: Mar 30, 2016
 *      Author: claudiu
 */

#ifndef UTIL_SORTALGO_H_
#define UTIL_SORTALGO_H_

template<typename Element>
class SortAlgo {
public:
	DynamicArray<Element> sortBy(auto begin, auto end, void (*func));
};
template<typename Element>
DynamicArray<Element> SortAlgo<Element>::sortBy(auto begin, auto end,
		void (*func)) {
	bool ok = true;
	do {
		while (begin != end) {
			auto current = *begin;
			++begin;
		}
	} while (ok == false);
}

#endif /* UTIL_SORTALGO_H_ */
