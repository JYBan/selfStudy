# Getting Started
## Introduction to Java
* 자바에는 두 종류의 프로그램이 있다.
	* Applets
		* 웹 브라우저에서 실행됨 (따라서 전송 가능).
		* Applet viewer를 이용하면 독립적으로 실행 되는 것 처럼 보이게 할 수 있다.
		* 항상 창으로 된 인터페이스이다.
	* Applications
* 자바는 linker 대신 loader가 있다.
## Expressions and assignment statements
* 변수 이름의 첫글자에 숫자는 올 수 없다. _는 가능.
* 이름 convention
	* primitive type: lower camel
	* object type: upper camel
* 변수
	* Primitive Type
		* boolean
		* char
		* byte
		* short
		* int
		* long
		* float
		* double
* 암시적 변환
	* byte > short > int > long > float > double
	* 피연산자의 타입이 서로 다른 연산에서도 이와 같은 순서로 결과의 타입이 정해진다. ex) int + float = float
## the class String
* \+ 연산자 사용 가능
* method

|   |     |     |
| --- | --- | --- |
| int length() | boolean equals(String) | boolean equalsIgnoreCase(String) |
| String toLowerCase() | String toUpperCase() | String trim() |
| char charAt(int) | String substring(int start) | String substring(int start, end) |
| int indexOf(String) | int indexOf(String, int start) | int lastIndexOf(String) |
| int compareTo(String) | int compareToIgnoreCase(String) ||
* String은 immutable object로 변경 불가 (StringBuffer는 mutable)
## program style
