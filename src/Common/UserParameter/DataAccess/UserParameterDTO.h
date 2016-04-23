#pragma once

#include <string>
#include <vector>

namespace userparameter { namespace dataaccess {

	class UserParameterDTO
	{
	public:
		UserParameterDTO();
		virtual ~UserParameterDTO();

		void setBackupFolder(const std::string& value);
		void addFile(const std::string& value);

		std::string getBackupFolder() const;
		const std::vector<std::string> getFiles() const;

	private:
		std::string _backupFolder;
		std::vector<std::string> _files;
	};

} }