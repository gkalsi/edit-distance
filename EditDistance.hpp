#ifndef __GK_EDIT_DISTANCE__
#define __GK_EDIT_DISTANCE__

#include <string>

namespace EditDistance {
	int editDistance(std::string&, std::string&);
	int editDistanceFast(std::string, std::string);
}

#endif /* __GK_EDIT_DISTANCE__ */