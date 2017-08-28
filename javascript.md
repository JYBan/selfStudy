# Javascript
## 1. 코어 자바스크립트
### 어휘 구조
* HTML과 달리 JS는 case sensative
* 문자열 중간에 유니코드를 사용 할 수 있다. 유니코드는 \u 뒤에 16진수 4자리로 표현된다.
  `"caf\u0065" === "cafe"`
* **literal** : 숫자, 문자(열), 불리언, regex, null 등 모든 데이터 값
* 식별자는 알파벳, 밑줄(_), 달러($)로 시작하고 두 번째 부터 숫자가 올 수 있다.
* 식별자에는 유니코드의 문자/숫자도 가능하므로 𝜋도 된다.
* '}'로 끝나면 세미콜론을 생략할 수 있다.
* 세미콜론 없이는 해석이 불가할 때 줄바꿈은 세미콜론으로 해석된다.
* 세미콜론 미스가 걱정되면 방어적으로 문장 앞에 세미콜론을 붙일 수 있다.

### 타입, 값, 변수
* Type
  * Primitive
    * 숫자
    * 문자열
    * 불리언
    * null
    * undefined
  * Object
    * 이름과 값을 갖는 property의 집합
    * 함수 (Function)
    * 배열 (Array)
    * Date
    * RegExp
    * Error
* JS는 가비지 컬렉션 기능이 있다.
* null, undefined는 유일하게 method를 가질 수 없는 타입이다.
* 변수가 함수 밖에서 선언되면 전역변수가 된다.
* 숫자
  * Number() 생성자로 만들어진다.
  * 모든 숫자는 실수로 표현한다. 단 배열 인덱싱과 비트 연산은 정수다.
  * 숫자 앞에 0붙이면 8진수로 오해 받을 수 있다.
  * 8진수 리터럴은 JS5 Strict Mode에서는 사용이 금지된다.
  * 6.02e23 도 가능
  * 복잡한 산술이 필요하면 `Math` 객체를 쓰면 된다.
  * JS는 오버/언더 플로, 0으로 나누기 에러가 없다.
    * Overflow: Infinity, -Infinity
    * Underflow: 0, 음의 0
    * N/0: Infinity, -Infinity
    * 0/0, (-)Infinity/(-)Infinity, sqrt(음수): NaN
  * Infinity와 NaN는 전역 변수다.
  * Number에도 읽기 전용으로 이들이 따로 저장되어 있다.
    * POSITIVE_INFINITY
    * NEGATIVE_INFINITY
    * NaN
  * 비교문
    ```javascript
      x == NaN;       // (x)
      x != x;         // (o) true if x is NaN
      isNaN(x);       // (o)
      isFinit(x);     // (o)
      0 === -0;       // true
      1/0 === 1/(-0); // false
    ```
  * 부동소수점 비교는 부정확하니 정수로 만들어서 비교하는게 좋다.
* 문자열
  * char 같은 건 없다. 다 문자열이다.
  * 16비트를 한 문자로 본다. (두 유니코드의 조합으로 만들어지는 글자의 경우 보이는 것과 length 결과가 다를 수 있다.)
  * 한글은 1글자에 16bit라서 이런 걱정 필요 없다.
  * 파이썬 처럼 \로 한 줄을 다음 줄에 이어 쓸 수 있다.
    ```javascript
    "one\
    line"         // "oneline"
    ```
  * HTML과 JS를 섞어 쓰는 경우 각각 다른 " 또는 '를 쓰는 것을 추천
  * Escape sequence(\)가 정의되지 않은 문자앞에 올 경우 무시된다. ( \# -> # )
  * 문자열과 관련된 method는 기존 문자열을 수정하지 않고 새 문자열을 반환한다. s.replace(), s.toUpperCase()해도 s는 그대로.
* 불리언
  * false : undefined ,null, 0, -0, NaN, ""
  * true : 객체, 배열(빈 배열도) 등
* null, undefined
  *
    ```javascript
    typeof(null)        // "object" 값이 없다는 객체
    typeof(undefined)   // "undefined" 값이 없다는 값
    null == undefined   // true
    null === undefined  // false
    ```
* 전역 '객체'
  * 함수 밖에서 선언 되는 변수는 전역 객체의 property다.
  * 함수 밖에서 this를 써서 전역 객체에 접근 할 수 있다.
  * 클라이언트 측 JS에는 전역 Window 객체가 있다.
* Wrapper 객체
  * String, Number, Boolean 객체를 말한다.
  * 문자열, 숫자, 불리언의 property나 method가 불릴 때 각각의 Wrapper 객체가 임시 객체를 만들어 값을 반환한다.
  * 따라서 그 줄 뒤엔 없어지는 임시객체이기 때문에 이들 property에 값을 바꾸는 것이나 새 property에 값을 할당하는 것은 의미 없다.
    ```javascript
    var s = "abc";
    s.len = 1;      // String(s).len = 1
    var t = s.len;  // t는 undefined
    ```
  * 명시적으로 Wrapper 객체로 생성한 경우와 그렇지 않은 경우의 동작은 같다. 다만 ===으로 구별은 할 수 있다.
    ```javascript
    new String("a") == "a"   // true
    new String("a") === "a"  // false
    ```
* mutable 과 immutable
  * 객체와 배열은 mutable이고, primitive type은 모두 immutable이다.
  * 문자열도 수정 불가.
  * 문자열을 제외한 primitive type은 값이 같아야 같다.
  * 문자열은 길이가 같고, 각 인덱스의 문자가 같아야 같다.
  * 객체, 배열은 참조로 비교된다. 따라서 같은 property의 객체와, 같은 원소의 배열들은 서로 같지 않다.
    ```javascript
    [1, 2] === [1, 2]       // false
    a = b = { x: 1, y: 2 };
    c = { x: 1, y: 2 };
    a === b                 // true
    a === c                 // false
    ```
  * 객체를 변수에 할당하는 것은 변수의 복사본이 아니라 참조를 할당하는 것이다.
  * 두 객체의 참조가 같을 때 한 객체의 property/원소를 변하면 다른 값도 변한다.
    ```javascript
    a = b = { x: 1, y: 2 };
    a.z = 3;
    b                     // { x: 1, y: 2, z:3 }
    ```
  * 객체나 배열을 값으로 비교하려면 그 함수를 직접 만들어야 한다.
* 타입 변환
  * null과 undefine
    * null, undefine는 객체로 암시적 변환을 할 수 없고, TypeError가 발생한다.
    * Object()로 null, undefine를 객체로 명시적으로 변환하면 빈 객체가 만들어 진다.
  * 암시적 변환
    * JS는 대체로 타입 변환에 관대하다.
      ```javascript
      null == undefined     // true (이 둘은 그냥 같은 걸로 봄)
      "0" == 0              // true ("0"이 숫자로 변환됨)
      "0" == false          // true (둘 다 숫자로 변환됨)
      ```
    * '=='비교문에서 타입이 자동으로 변환된다.
    * 어떤 연산자들은 암시적 형변환을 일으킨다.
      * \+ 이항 연산자는 한 피연산자가 문자열이면 다른 피연산자를 문자열로 만든다.
        3 + "4" === "34"
      * \+ 단항 연산자는 피 연산자를 숫자로 만든다.
      * ! 단항 연산자는 피 연산자를 Boolean으로 만든다.
      * 암시적 형변환을 할 때 다음과 같은 구문을 자주 쓴다.
        ```javascript
        x + ""    // String(x)
        +x        // Number(x)
        !!x       // Boolean(x)
        ```
  * 명시적 변환
    * Wrapper 객체나 Object를 new 없이 쓰면 명시적 타입변환으로 작동한다.
      ```javascript
      Number("3")     // 3
      Object(3)       // new Number(3) = Number {3}
      Object(null)    // Object { }
      ```
  * 어떤 연산자들은 암시적 형변환을 일으킨다.
    * \+ 이항 연산자는 한 피연산자가 문자열이면 다른 피연산자를 문자열로 만든다.
      3 + "4" === "34"
    * \+ 단항 연산자는 피 연산자를 숫자로 만든다.
    * ! 단항 연산자는 피 연산자를 Boolean으로 만든다.
    * 암시적 형변환을 할 때 다음과 같은 구문을 자주 쓴다.
      ```javascript
      x + ""    // String(x)
      +x        // Number(x)
      !!x       // Boolean(x)
      ```
  * 문자열과 숫자 사이의 형변환
    * 문자열->숫자의 경우 parseInt(), parseFloat() 전역 함수가 있다.
    * 숫자->문자열의 경우 toFixed(), toExponential(), toPrecision() 멤버 메서드가 있다.
    * Number() 과 parseInt()
      * Number()는 문자열에 알파벳이 들어가면 NaN지만 parseInt()는 적당히 무시한다.
      * parseInt()는 두 번째 인자로 진법을 정할 수 있다.
  * 모든 객체는 Boolean으로 변환되면 true다.
  * null과 undefined를 제외한 모든 값에 toString(), valueOf() 메서드가 있다. 대부분 이 두 함수는 재정의 해서 쓴다.
  * 객체->문자열 형변환
    * toString()이 있다면 toString() > (다른 primitive type) > String
    * valueOf()만 있다면 valueOf() > (다른 primitive type) > String
    * 둘 다 없다면 TypeError
  * 객체->숫자 형변환
    * valueOf()이 있다면 valueOf() > (다른 primitive type) > Number
    * toString()만 있다면 toString() > (다른 primitive type) > Number
    * 둘 다 없다면 TypeError
  * 단 Date객체->숫자/문자열 변환은 위와 다르다.
* 변수 선언
  * 변수를 선언만 하고 할당 안하면 그 변수는 undefined이다.
  * 변수를 선언하지 않고 읽으면 에러다.
  * 변수를 선언하지 않고 쓰면 전역변수와 비슷하게 취급된다. (strict 모드에서는 에러)
* 변수의 scope
  * 함수 정의 안에 함수를 정의 할 수 있고, 그 scope는 그 바깥 함수 정의 안으로 한정 된다.
  * Hoisting (호이스팅)
    * JS에서 변수의 scope는 함수로만 제한된다. {} 블록, 루프로 인한 블록 등은 scope에 영향이 없다.
    * 한 함수 안에 선언 된 모든 변수는 scope이 모두 그 중첩된 함수도 포함한 함수 전체이다.
    * 함수 중간에 변수를 선언, 할당하면, 선언만 함수 시작부분으로 옮겨져 undefined가 되고, 중간에는 할당만 남게 된다.
    ```javascript
    function f(){
      console.log(temp);    // "undefined"
      var temp = "abc";
      console.log(temp);    // "abc"
    }
    ```
  * 전역 변수
    * 전역 변수는 사실 전역 객체의 property이다.
    * var로 선언한 전연 객체의 property는 delete 할 수 없다.
      ```javascript
      var x = 1;    // delete x 불가능
      y = 2;        // delete y 가능
      this.z = 3;   // delete this.z 가능
      ```
  * Scope chain
    * 어떤 변수를 찾을 때 함수 밖이면 전역 객체의 property, 함수 안이면 차례로 바깥 함수들, 마지막으로 전역 객체 순으로 찾는다.
    * Nested 함수의 경우 바깥 함수가 불릴 때마다 함수가 다시 선언되기 때문에 scope chain이 조금씩 달라진다.
