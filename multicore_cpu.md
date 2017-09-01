# 멀티코어 CPU
### ISA
* **ISA**(Instruction Set Architecture)
* **CISC** vs **RISC**
	* **CISC**(Complex Instruction Set Computer) : 복잡하고 많은 명령어 제공
		* 명령어의 길이가 주로 가변적
		* 복잡한 형태의 주소 모드 지원
		* **GPR**(General Purpose Register;범용 레지스터) 의 갯수가 적다.
		* 적은 명령어로 수행 할 수 있어서 코드에 드는 메모리가 작다.
		* 연산 명령어의 피연산자로 메모리 주소가 올 수 있다.
		* ex) IA-32(x86) (of Microsoft), AMD64(x86-64) (of AMD)
	* **RISC**(Reduced Instruction Set Computer) : 간단.
		* Make Common Case Fast
		* 명령어 크기 고정
		* 모든 명령어의 opcode는 상위 6bit 으로 하드웨어 회로가 간단
		* 하나를 수행하는데 대체로 CISC보다 많은 명령어가 필요.
		* 연산 명령어의 피연산자에 레지스터만 올 수 있으므로 메모리 주소의 데이터를 레지스터에 load 한뒤 연산하고 다시 store 해야 한다.
		* ex) MIPS (of Microsoft), PowerPC (of ARM and IBM)
* **CISC**의 **RISC**화
	* RISC가 하드웨어 구성이 간단해 파이프라인 기술 적용이 쉬웠으나 이제는 거기서 거기다.
	* 여전히 처음 명령어 분석은 복잡하지만 이제 이 명령어를 micro op으로 쪼개서 RISC처럼 처리한다.
	* 명령어 분석의 복잡함은 Atom 같은 초전력 프로세서에게 여전히 부담이 된다.
	* 레지스터의 갯수가 물리적으로는 100개 이상으로 늘어났지만 개념상 여전히 8/16개를 인식하므로 Register Renaming 테크닉을 이용한다.
	* CISC는 레지스터 부족으로 인해 임시 계산 결과를 메모리에 잠시 저장했다 다시 불러와야 한다 (Register spill). 이러한 문제는 큰 캐시로 어느정도 극복 하고 있다.
* **VLIW**(View Long Instruction Word)
	* CISC, RISC와는 다른 형태의 ISA
	* 하드웨어 역할의 많은 부분을 소프트웨어에 넘긴다.
	* ex) Itanium (of Intel)에 쓰이는 IA-64
* 기타
	* MIPS 명령어는 모두 32bit로 Register, Immediate(상수), Jump로 나뉜다.
	* 인텔과 AMD 모두 **x86** CISC ISA를 사용한다.
	* .NET 프레임워크와 JAVA JVM은 가상의 ISA로 프로그램을 운영체제와 CPU에 독립적으로 실행할 수 있게 한다.
	* x86 ISA의 표기 형식
	    * Microsoft : **MASM**(Microsoft Assembler)
	    * Linux/Unix : **GAS**(GNU Assembler)
	* **ABI**(Application Binary Interface) 함수호출 규약 등 응용프로그램과 운영체체 사이의 규약
### 프로세서의 기본 부품과 개념
* **Micro Architecture** (=uarch): 마이크로 프로세서 하나를 만드는데 필요한 알고리즘과 회로 수준의 구조를 정의하는 것.
* 마이크로 프로세서의 설계
	1. 마이크로 아키텍쳐의 설계
		* 목표 성능을 위한 알고리즘과 테크닉 개발
			* 시뮬레이터를 통한 알고리즘 성능 검증
			* **RTL**(Register Transfer Language) 이라는 설계 언어로 기술
			* ex) 캐싱 알고리즘
	2. 로직 설계
		* RTL을 보고 하드웨어 구현에 적합한지 검증
		* RTL을 베릴로그 같은 HDL(Hardware Description Language)로 바꿈.
* 연산의 종류
	* 스칼라 연산
		* 간단한 정수 연산
		* 복잡한 정수 연산
			* Early exit : 나눗셈을 하는데 필요한 루프 횟수를 미리 계산하여 시간을 단축하는 인텔의 기술.
		* 부동 소숫점 연산
	* 벡터 연산
* 부품
	* **Data Path**
		* **ALU** (Arithmetic Logical Unit;산술논리장치) : 정수 사칙 연산, 비트 논리 연산, 비트 시프트 연산
		* **FPU** (Floating Point Unit;부동소숫점 처리기)
		* 메모리 : 레지스터 파일 (레지스터 읽기, 쓰기 기능), 캐시, 메인 메모리
	* **Control Unit** : 뇌 같은 역할. 파이프 라인, 비순차 실행 등.
* 메모리 계층
	* 폰 노이만 구조 : 프로그램과 데이터가 구분 없이 메모리에 저장됨
	1. 레지스터 : 가장 빠름. 컴파일러는 가능하면 메모리보다 레지스터에 변수를 할당해 성능을 높인다.
		* **Logical Register** :  프로그래머가 볼 수 있는 레지스터들
			* **GPR**(General Purpose Register;범용 레지스터)
				* 메모리에서 읽은 연산의 피연산자 저장
				* 연산 결과를 메모리에 저장하기 전에 임시 저장
			* 프로세서 상태를 관리 레지스터
				* PC (Program Counter)
			* 프로세서 내부 상태 관리 레지스터
				* CR (Control Register) : 현재 수행중인 프로세스 페이지 테이블 등
		* **Physical Register** : 외부로 노출 되지 않아 좀 더 자유롭게쓸 수 있는 레지스터
	2. 캐시 메모리 : 프로세서와 메인 메모리의 속도차이를 극복하기 위해 자주 쓰는 데이터를 여기에 둠.
	3.  메인 메모리 : **DRAM**(Dynamic Random Access Memory)
* 프로세스와 쓰레드
	* 프로세스 : 현재 실행 중인 프로그램
	* 쓰레드 : 멀티 태스킹을 위한 시분할을 할 때 context switching을 가볍게 하기 위해 탄생. 프로세서를 사용하는 최소 단위
	* 현대 운영체제는 Preemptive 스케줄링으로 정해진 시간이 지나면 쓰레드가 시간을 더 요구해도 다음 쓰레드에 넘긴다.  ex) Round Robin
	* **Virtual Memory** : 
		* 개념
			* 메모리를 페이지로 나누어 각 프로세서에 페이지 단위로 가상 메모리 할당.
		* 장점
			* 실제 물리 메모리보다 더 큰 메모리 사용 가능
			* 프로세스들이 서로의 주소 공간을 침범하지 않아 운영체제 안정성을 높임.
		* 구현
			* 가상 메모리의 페이지는 페이지 테이블을 통해 물리 메모리로 변환됨
			* **Page fault** : 필요한 페이지가 물리 메모리에 없는 경우. (올리면 됨)
			* **Swap** : 페이지를 올릴 물리 메모리가 부족하면 기존 페이지를 버린다 이때 이 페이지가 쓰기를 수행한 dirty page인 경우 swap file이라는 특수 파일에 저장한다.
			* **Thrashing** : Swap 알고리즘이 나빠서 프로세서가 일은 안하고 swap만 하느라 성능을 저하시키는 것
			* 가상 메모리를 실제 메모리로 바꾸는 것은 속도를 위해 하드웨어로 구현
		* 32bit 운영체제에서 각 프로세스 마다 4GB 가짐
			* 커널 영역
			* 텍스트 : 코드
			* 데이터 : 전역 변수
			* 힙 : 동적 메모리
			* 스택 : 지역 변수, 함수 호출
### 프로세서의 성능
* **Amdal's Law**(암달의 법칙) : 부분의 성능을 1 개선 하더라도 이에 영향 받지 않는 부분으로 인해 전체 성능은 1만큼 좋아지지 않는다.
* ::멀티 코어라면 프로그램을 병렬화하는 것이 좋지만 지나치면 쓰레드 생성 비용과 쓰레드간 동기화(뮤텍스 등)문제로 인해 성능이 저하 될 수 있다.::
* 성능 지표
	* Latency : 어떤 프로그램을 완료하는데 드는 시간
		* 프로세서 성능이 나쁘고, 분기문, 나눗셈과 같이 처리에 오래 걸리는 명령어가 많다면 느려질 것이다.
		* 캐시로 Latency를 향상 시킬 수 있다.
		* GPU 같은 경우 Floating Point 처리 명령어만 고려해서 계산하기도 한다.
		* **IPC** : Instructions Per Second
		* => 클럭이 빠르고, IPC가 높고, 처리 명령어 수가 적어야 한다.
	* Throughput : 단위 시간당 얼마나 많이 처리 할 수 있는가 ex) 파이프라인
### 의존성
* 데이터 의존성
	* **RAW** (Read After Write) : Flow dependency;흐름 의존성.
 	* **WAW** (Write After Write) : Output dependency;출력 의존성.
	* **WAR** (Write After Read) : Anti-dependency;반의존성.
	* RAW는 순차적으로 실행되어야 하고, WAW, WAR은 변수 이름 변경으로 의존성을 없앨 수 있다.
* 컨트롤 의존성 : 조건문, 함수 호출 등으로 생기는 의존성
* 메모리 의존성 : 포인터간의 연산. 포인터가 가리키는 대상에 따라 의존성이 결정돼 의존성 판단이 어렵다.
* 루프 의존성 : 이터레이션 사이의 의존성.
* **IPO** (Interprocedural Optimization) : 프로시저간 최적화
* 명령어 간에 의존성이 없다면 컴파일러는 명령어 재배치 또는 명령어 스케줄링을 통해 실행 순서를 조정하거나 병렬로 수행한다.