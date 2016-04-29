#pragma once

#include <memory>

namespace core {

	class DataObject
	{
	public:
		DataObject() : _placeHolder(nullptr) {}

		template<typename ValueType> DataObject(const ValueType& value) :
			_placeHolder(new Holder<ValueType>(value)){}

		virtual ~DataObject() {
			delete _placeHolder;
		}

		template<typename ValueType> ValueType get() const {
			return static_cast< Holder<ValueType>* >(_placeHolder)->_value;
		}

		DataObject& operator=(DataObject& other) {
			std::swap(_placeHolder, other._placeHolder);
			return *this;
		}

	private:
		class PlaceHolder {
		public:
			virtual ~PlaceHolder(){}
		};

		PlaceHolder* _placeHolder;




		template<typename ValueType>
		class Holder : public PlaceHolder {
			friend class DataObject;
		public:
			Holder(const ValueType& value) : _value(value){}
			virtual ~Holder(){}
			ValueType get() {
				return _value;
			}
		private:
			ValueType _value;
		};
	};

}
