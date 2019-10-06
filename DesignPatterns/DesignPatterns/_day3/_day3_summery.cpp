/*
1. 객체 복사 기술 4가지
- 깊은복사 / 참조계수 / 소유권이전 / 복사금지

2. 스마트포인터 만들기
- 참조계수 기반 2가지 모델(shared_ptr<>, sp<>)  (= 템플릿기반, 객체기반)
- 복사금지 모델(unique_ptr)

3. 컨테이너 만드는 3가지 방식
- Object * class 기반
- template
- thin template

4. 컨테이너 혹은 복합객체에 적용되는 디자인 패턴 2개
내부구조에 상관없이 동일하게 복합객체 열거 : "Iterator"
- 인터페이스 기반 반복자
- STL 방식 반복자

내부구조에 상관없이 동일하게 복합객체 요소에 연산 수행 : "Visitor"

5. Proxy

지금까지 나온 모든 패턴
Template Method					// 가상함수로 뽑자
Strategy						// 클래스로 뽑자
Observer						// 다수의 이벤트 
Chain of Responsibility			// 책임을 부모에게
Composite						// 재귀적 '포함'을 가지는 패턴
Adapter							// 기존 것을 사용자 입맛에 맞게 모은 클래스
Prototype						// Clone, 자신을 찍어내서 반환 ?

Proxy
Iterator
Visitor
*/