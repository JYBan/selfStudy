### Forward Index & Inverted Index
* **Forward index**: 각 문서(장)에 어떤 단어가 있는지
* **Inverted index**: 책 맨 뒷장의 index처럼 각 단어가 어느 문서(장)에 있는지. 실제로 어떤게 invert 된게 아니라 단순히 이전에 forward index가 존재했기 때문에 붙여진 이름이다
* Example
  ```
  Forward index :
	doc1 : word1, word2
	doc2 : word2, word3
	doc3 : word1, word3

  Inverted index :
	word1 : doc1, doc3
	word2 : doc1, doc2
	word3 : doc2, doc3
  ```
### Framwork & Platform
* **Framework**:
  * 어떤 목적이 있고 이를 위한 처음 부터 끝까지의 과정을 라이브러리로 지원하는 것
  * Framework를 이용할 때 개발자는 persistence, routing, session 등 자잘한 것들에 대해 신경 쓰지 않아도 됨
  * Framework는 사용하기 위해 설치를 먼저 해야됨
* **Platform**:
  * 플랫폼은 어플리케이션을 돌리기 위해 제공되는 하드웨어 또는 소프트웨어이다
  * 플랫폼은 Stand-alone program이거나 다른 프레임워크의 top에 build 된다
  * 보통 PaaS(Platform-as-a-Service)로 제공됨(= host되는 solution에 일부로 클라우드 안에서 API나 GUI로 접근됨)

### Dom (Document Object Model)
* DOM을 정의 하는 3가지 말 (3가지 모두 같은 의미)
  1. 문서를 객체로 표현하기 위한 표준으로서 HTML이나 xml등의 문서를 객체로 표현할 때 사용하는 API
  2. 문서의 객체 모델(DOM)은 html내에 들어 있는 요소를 구조화 객체 모델로 표현하는 양식
  3. DOM은 HTML과 XML문서에 대하여, 이들 문서의 구조적인 표현방법을 제공하며 어떻게 하면 스크립트를 이용하여 이러한 구조에 접근할 수 있는지를 정의하는 API이다.
* Example
  * HTML은 DOM이 아니다. 하지만 브라우저에 의해 DOM으로 바뀌긴 한다.
  * View Source도 DOM이 아니다. View Source는 해당 페이지를 구성하는 HTML이기 때문에 아마 개발자가 작성한 HTML과 동일할 것이다.
  * HTML에 덜 채워진 부분을 채우고, 연결된 자바스크립트 등을 반영해서 만들어진 것이 DOM이다.
