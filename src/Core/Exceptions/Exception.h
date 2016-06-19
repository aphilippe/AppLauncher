#pragma once
#include <exception>
#include <string>

namespace core {

	class Exception :
		public std::exception
	{
	public:
		Exception();
		virtual ~Exception();

		virtual char const * what() const override;

	protected:
		void setMessage(const std::string& message);
	private:
		std::string _message;
	};

}