#include "Day0602.h"

void Animal::Move()			// Animal 클래스의 멤버함수인 Move
{
	printf("\n이동합니다.\n");
	Energy -= MoveEnergy;	// 움직이면 에너지 감소
	printf("에너지가 %.0f만큼 감소합니다.\n", MoveEnergy);
}

void Animal::Scream()
{
	printf("\n크아앙... 이상한 소리를 냅니다.\n");
}

void Animal::Eat()
{
	printf("\n무언가를 먹습니다.\n");
	Energy += EatEnergy;
	printf("에너지가 %.0f만큼 증가합니다.\n", EatEnergy);
}

void Animal::Sleep()
{
	printf("\n쿨쿨 잡니다.\n에너지가 완전히 회복됩니다.\n");
	Energy = MaxEnergy;
	Age++;
}

void Animal::ShowInfo()
{
	printf("\n=======================\n");
	printf("Name : %s\nAge : %d\nEnergy : %.0f / %.0f\n", Name.c_str(), Age, Energy, MaxEnergy);
	printf("=======================\n");
}

void Eagle::Scream()
{
	printf("\n빼액- 독소리가 목소리를 울립니다.\n");
}

void Skunk::Scream()
{
	printf("\n부우웅... 스컹크가 이상한 소리를 냅니다.\n");
}


void Pigeon::Scream()
{
	printf("\n구구...구구구! 비둘기가 소리를 지릅니다.\n");
}


void Baby::Scream()
{
	printf("\n응애!!!응애애애애!!!!! 갓난아기가 집안이 떠나가라 울부짖습니다.\n");
}




void Day0602()
{
	Animal* MyAnimal = new Animal();
	MyAnimal->ShowInfo();
	MyAnimal->Move();
	MyAnimal->Scream();
	MyAnimal->ShowInfo();
	MyAnimal->Move();
	MyAnimal->Move();
	MyAnimal->Move();
	MyAnimal->Move();
	MyAnimal->ShowInfo();
	MyAnimal->Eat();
	MyAnimal->ShowInfo();
	MyAnimal->Sleep();
	MyAnimal->ShowInfo();

	// MyAnimal->GetAge();
	// MyAnimal->Age;

	delete MyAnimal;
	MyAnimal = nullptr;

	Eagle* MyEagle = new Eagle("독수리");
	MyEagle->Fly();
	MyEagle->ShowInfo();

	Animal* pEagle = MyEagle;	// Animal이 Eagle의 부모이기 때문에 저장 가능
	// pEagle은 Animal* 타입이기 때문에 멤버에 접근은 불가. 캐스팅(Eagle*)해주면 가능.
	// (Eagle*)pEagle;		// C스타일의 캐스팅. 위험.
							// int* a;
							// Eagle* Test = (Eagle*)a; => 문법적으로 가능
	// dynamic_cast			=> C++ 스타일의 캐스팅. 안전. 느리다.

	delete MyEagle;
	MyEagle = nullptr;

	// pEagle->ShowInfo();		// pEagle은 댕글링 포인터다. (MyEagle을 지웠기에 이미 유효하지 않은 주소)
	

	//====================간단실습====================

	Skunk* MySkunk = new Skunk("스컹크");
	MySkunk->Move();
	MySkunk->Fart();
	MySkunk->ShowInfo();

	Pigeon* MyPigeon = new Pigeon("비둘기");
	MyPigeon->ShowInfo();
	MyPigeon->Kicked();
	MyPigeon->Move();
	MyPigeon->ShowInfo();

	Baby* MyBaby = new Baby("갓난아기");
	MyBaby->Move();
	MyBaby->Eat();
	MyBaby->Sleep();
	MyBaby->Awake();
	MyBaby->ShowInfo();
}




void Day0602_virtual()
{
	Animal* Zoo[3] = { nullptr, };
	Zoo[0] = new Skunk("스컹크");
	Zoo[1] = new Pigeon("비둘기");
	Zoo[2] = new Baby("갓난아기");

	for (Animal* anim : Zoo)
	{
		anim->ShowInfo();
		anim->Scream();
	}
	for (int i = 0; i < 3; i++)
	{
		delete Zoo[1];
		Zoo[i] = nullptr;
	}
}


void Eagle::Fly()
{
	printf("\n독수리가 하늘을 납니다.\n에너지가 %.0f만큼 감소합니다.\n", FlyEnergy);
	Energy -= FlyEnergy;
}


void Skunk::Fart()
{
	printf("\n스컹크가 방귀를 낍니다.\n에너지가 %.0f만큼 회복됩니다.\n", FartEnergy);
	Energy += FartEnergy;
}


void Pigeon::Kicked()
{
	printf("\n비둘기가 지나가는 행인의 발에 치였습니다.\n에너지가 %.0f만큼 감소합니다.\n", KickedEnergy);
	Energy -= KickedEnergy;
}


void Baby::Awake()
{
	printf("\n아기가 새벽에 잠에서 깨 울기 시작했습니다.\n에너지가 %.0f만큼 감소합니다.\n", AwakeEnergy);
}

// 간단실습
// Move함수를 가상함수로 만들어 처리

void Skunk::Move()
{
	printf("\n스컹크가 뛰어갑니다.\n");
}

void Pigeon::Move()
{
	printf("\n비둘기가 느릿느릿 사람들에게 다가갑니다.\n");
}

void Baby::Move()
{
	printf("\n아가가 온집안을 기어다닙니다.\n");
}