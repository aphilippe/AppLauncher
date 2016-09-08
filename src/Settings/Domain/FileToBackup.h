#ifndef FILETOBACKUP_H
#define FILETOBACKUP_H

#include <string>

namespace settings { namespace domain {

class FileToBackup
{
public:
    FileToBackup(const std::string& path);
    virtual ~FileToBackup();

    std::string getPath() const;

private:
    std::string _path;
};

} }
#endif // FILETOBACKUP_H
