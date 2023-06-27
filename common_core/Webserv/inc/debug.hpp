#pragma once

#include "utilities.hpp"

template <class T>
void xlog(const T& s) {
#ifdef DEBUG
	std::cerr << s;
#else
	(void)s;
#endif
}

template <class T>
void xlogn(const T& s) {
	xlog(s);
	xlog('\n');
}



