/*
6_반복자3

반복자(iterator) 디자인 패턴
다양한 종류의 컨테이너(list, vector등) 또는 복합객체의
모든 요소를 자료구조에 상관없이 동일한 방식으로 열거하기 위한 객체

-대표적 구현 방법

					STL방식				인터페이스 방식
										java, C#, 타이젠, Objective - C
find()함수			find(T p)			find(IEnumerator* p)
					(템플릿, inline)		(결국 템플릿 방식, LSP, 부모클래스, virtual, 객체지향의 방식)
					C랑 같은 성능
이동 방법			++p, *p				p->MoveNext()
요소 얻기			*p					p->GetObject()
성능					빠르다.				느리다.
					일반 배열 사용가능		일반 배열 사용불가능

반복자 꺼내기			begin()				GetEnumeratorN()
					암시적 약속			명시적 약속
				동적 생성이 아닌 반복자	동적으로 생성된 반복자
*/