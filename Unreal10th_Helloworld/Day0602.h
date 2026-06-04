#pragma once
#include <iostream>

// 객체 지향 
//	- 프로그래밍 패러다임 중 하나
//	- 객체(Object)를 만들고, 객체 간의 상호작용으로 프로그램이 돌아가게 만드는 방식.
//	- 4대 특성
//		*추상화 >> 불필요한 세부사항을 숨기고 핵심적인 부분만 말하는 것
//				>> 중요한 개념과 기능만을 드러내는 것 (상위 개념으로 묶기)
//				>> 코드의 복잡성을 낮출 수 있다.
//		*캡슐화 >> 접근제한자를 통한 데이터의 접근 제어
//				>> 몰라도 되는 것은 안 보이게 하는 것
//				>> 데이터를 보호하고 코드의 안정성을 높인다. 그리고 결합도도 낮춘다.
//				>> 접근제한자를 이용해 캡슐화를 한다.
//		*상속	>> 부모 클래스의 데이터와 기능을 물려받는 자식 클래스를 만드는 것
//				>> 코드의 재사용성이 높아진다. 계층 구조가 형성된다. (위아래가 생김)
//		*다형성	>> 동일한 인터페이스를 통해 다양한 처리를 하는 것
//				>> 가상함수의 오버라이드를 통한 다형성 구현	

// 클래스
//	- 객체(Object)를 만들기 위한 설계도
//	- 겍체가 가지게 될 상태(데이터, 변수)와 동작(기능, 함수)을 하나로 묶어놓은 것.
//	- 구성요소(Member)
//		*생성자 >> 구조체와 같이 객체를 생성했을 때 자동 호출되는 함수같은 것
//				   ex) 클래스이름()
//		*소멸자	>> 구조체나 클래스의 객체가 해제될 때(delete가 되거나, 지역변수일 때 함수 종료되는 시점)
//				>> 목적 : 객체가 사용하던 자원을 깨끗하게 정리하는 역할
//						  주로 객체가 동적할당한 메모리를 해제하는 데에 사용
//						  그 외 기타 자원들(파일, 네트워크 연결 닫기)도 이곳에서 정리
//						  ex) ~ 클래스이름()
//		*멤버 변수 >> 객체의 상태나 데이터를 저장하는 변수
//				   >> 속성, 필드라고도 한다.
//		*멤버 함수 >> 객체가 할 수 없는 동작이나 기능을 정의한 함수
//				   >> 메서드(Method)라고도 한다.
//	- 객체, 인스턴스(Instance)
//		*특정 클래스를 이용해 메모리에 할당된 실체

// 접근 제한자(Access Modifier)
//	- 특정 개체의 내부를 누구까지 볼 수 있을 것인가를 설정
//	- public, protected, private
//		*public >> public 멤버는 모두에게 공개되어 있다. 구조체는 따로 설정 안 하면 public.
//		*protected >> protected 멤버는 상속된 자식(파생) 클래스에서는 볼 수 있다.
//		*private >> private 멤버는 자기자신만 볼 수 있다. 클래스는 따로 설정 안 하면 private.


// 상속 : 부모 클래스의 내용을 물려받는 행동
//	- 자식은 부모 클래스를 확장/파생시킨다.
//	- 특징
//		*코드 재사용성 증가
//		*계층 구조로 객체들 간의 관계를 명확히 함
//		*부모 클래스의 포인터나 차조로 자식 클래스를 다룰 수 있다.

// 가상함수
//	- virtual 키워드 사용
//	- 함수를 선언할 때 가상함수로 만들 멤버 함수 앞에서 붙인다.
//	- 가상함수가 있는 클래스를 상속받은 자식클래스는 해당함수를 override(덮어쓰기)할 수 있다.
//	- 상속하거나 상속받았는데 소멸자를 만들었으면 무조건 virtual을 붙여라.
//	- 가상 함수처리를 위해 ??????????????????



class Animal
{
	//멤버 변수
protected:
	std::string Name = "삼색고양이";	//동물의 이름
	int Age = 0;						//동물의 나이
	float Energy = 100.0f;				//동물의 현재 에너지
	float MaxEnergy = 100.0f;			//동물의 최대 에너지


public:
	Animal() = default;
	Animal(const std::string& InName)
		: Name(InName)
	{ }
	//{
	//	//생성자
	//}
	~Animal() = default;
	//{
	//	//소멸자
	//}

	//멤버 함수
	virtual void Move();		//움직이기
	virtual void Scream();		//소리내기(가상함수)
	void Eat();			//먹기
	void Sleep();		//자기
	void ShowInfo();	//자신의 모든 정보 출력


private:
	const float MoveEnergy = 10.0f;		//움직일 때 사용하는 에너지
	const float EatEnergy = 30.0f;		//먹으면 회복되는 에너지

	// getter / setter (필요한 경우 쓰면 좋음)
	// => private로 있는 멤버를 바깥에서 보고 싶을 때
public:
	// int GetAge() const;		//여기서 const는 함수 내에서 다른 멤버 변수를 수정하지 않겠다라는 의미
	inline int GetAge() const { return Age; }
	inline void SetAge(int InAge) { Age = InAge; }
};

// 간단실습
// 동물 클래스 만들어보기
//	- 움직이면 에너지를 소비한다.
//	- 소리를 지를 수 있다.
//	- 먹을 수 있다. (먹으면 에너지가 증가한다.)
//	- 잠을 잘 수 있다. (잠을 자면 나이가 증가하고 에너지가 완전 회복된다.)
//	- 자신의 모든 정보를 출력할 수 있다.

class Eagle : public Animal		// Animal의 모드 
{
public:
	Eagle()
		: Animal()
	{ }
	Eagle(const std::string& InName)
		: Animal(InName)
	{ }
	virtual ~Eagle() = default;		// 상속받았는데 소멸자를 만들었으면 무조건 virtual을 붙여라.

	void Fly();
	virtual void Scream() override;	// 가상함수를 덮어쓰기 하겠다.

private:
	const float FlyEnergy = 20.0f;
};

// 간단실습
// - Animal의 자식 클래스 5개 이상 만들기
// - 각 자식 클래스는 자신만의 기능이 있어야 한다.

class Skunk : public Animal
{
public:
	Skunk()
		: Animal()
	{ }
	Skunk(const std::string& InName)
		: Animal(InName)
	{ }
	virtual ~Skunk() = default;

	void Fart();
	virtual void Scream() override;
	virtual void Move() override;

private:
	const float FartEnergy = 5.0f;
};

class Pigeon : public Eagle
{
public:
	Pigeon()
		: Eagle()
	{ }
	Pigeon(const std::string& InName)
		: Eagle(InName)
	{ }
	virtual ~Pigeon() = default;

	void Kicked();
	virtual void Scream() override;
	virtual void Move() override;

private:
	const float KickedEnergy = 70.0f;
};

class Baby : public Animal
{
public:
	Baby()
		: Animal()
	{ }
	Baby(const std::string& InName)
		: Animal(InName)
	{ }
	virtual ~Baby() = default;

	void Awake();
	virtual void Scream() override;
	virtual void Move() override;

private:
	const float AwakeEnergy = 30.0f;
};

// 간단실습
// Move함수를 가상함수로 만들어 처리
// - 고래는 수영, 독수리는 날기, 호랑이는 뛰기


void Day0602();
void Day0602_virtual();