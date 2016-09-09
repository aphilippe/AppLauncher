#ifndef FILETOBACKUP_H
#define FILETOBACKUP_H

#include <string>

namespace settings { namespace domain {

class FileToBackup
{
public:
    FileToBackup(const std::string& path, const std::string& label);
    virtual ~FileToBackup();

    std::string getPath() const;
	std::string getLabel() const;

private:
    std::string _path;
	std::string _label;
};

} }
#endif // FILETOBACKUP_H
