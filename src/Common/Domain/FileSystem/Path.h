#ifndef Path_hpp
#define Path_hpp

#include <stdio.h>
#include <string>

namespace filesystem {

class Path {
public:
	Path(const std::string & value);
	std::string getValue() const;
	
private:
	std::string _value;
};

}
#endif /* Path_hpp */