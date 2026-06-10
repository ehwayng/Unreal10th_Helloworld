#pragma once
#include <type_traits>


// std::enable_if_t<std::is_enum_v<T>, T>
//	- T 타입이 enum인 경우에만 생성해라

// std::underlying_type_t<T>
//	- T 타입의 본직적인 타입을 리턴(enum class의 경우 사이즈가 다른 정수형이 올 수 있기 때문)

template <typename T>
typename std::enable_if_t<std::is_enum_v<T>, T> operator | (T InLeft, T InRight)		//T타입이 enum이면 리턴하고 아니면 하지 말라
{
	return static_cast<T>(
		static_cast<std::underlying_type_t<T>>(InLeft) | static_cast<std::underlying_type_t<T>>(InRight));
}

template <typename T>
typename std::enable_if_t<std::is_enum_v<T>, T> operator & (T InLeft, T InRight)		//T타입이 enum이면 리턴하고 아니면 하지 말라
{
	return static_cast<T>(
		static_cast<std::underlying_type_t<T>>(InLeft) & static_cast<std::underlying_type_t<T>>(InRight));
}


enum class TestEnumClass : uint8_t
{
	Up = 1 << 0,
	Down = 1 << 1,
	Left = 1 << 2,
	Right = 1 << 3
};