#pragma once

#include <memory>

namespace core {

	class DataObject
	{
	public:
		DataObject() : _content(nullptr) {}

		template<typename ValueType> DataObject(const ValueType& value) :
			_content(new Holder<ValueType>(value)){}

		DataObject(const DataObject& other) :
			_content(other._content ? other._content->clone() : nullptr)
		{}

		virtual ~DataObject() {
			delete _content;
		}

		template<typename ValueType> ValueType get() const {
			return static_cast< Holder<ValueType>* >(_content)->get();
		}

		DataObject& operator=(DataObject& other) {
			DataObject(other).swap(*this);
			return *this;
		}

		DataObject& operator=(const DataObject& other) {
			DataObject(other).swap(*this);
			return *this;
		}

		void swap(DataObject & other) {
			std::swap(_content, other._content);
		}

		friend void swap(DataObject& a, DataObject& b) {
			a.swap(b);
		}

	private:
		class PlaceHolder {
		public:
			virtual ~PlaceHolder(){}
			virtual PlaceHolder* clone() const = 0;
		};

		template<typename ValueType>
		class Holder : public PlaceHolder {
			friend class DataObject;
		public:
			Holder(const ValueType& value) : _value(value){}
			virtual ~Holder(){}
			ValueType get() const {
				return _value;
			}


			virtual PlaceHolder * clone() const
			{
				return new Holder(_value);
			}
		private:
			ValueType _value;
		};

		PlaceHolder* _content;
	};

}
