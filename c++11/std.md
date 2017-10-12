## std::pair
* #include<utility>
  * c++11에서 std::map의 element가 std::pair로 구현되어 있으므로 #include<map>을 해도 되긴 된다.
  * make_pair()
    ```c++
    std::pair<int, std::string> p = make_pair(3, "example"); // 암시적 형변환 가능
    ```
## std::tuple
## std::array (c++11)
## std::list
## std::forward_list (c++11)
## std::unordered_set (c++11)
## std::set
## std::unordered_map (c++1)
## std::map
## std::future (c++11)
## std::vector
* 특징
  * 일반 array와 같이 원소들이 연속된 주소 공간에 할당된다
    * random access가 빠르다
    * capacity를 늘릴 때 전체 공간을 새로 할당한 뒤 원소들을 복사하게 되므로 cost가 크다
    * data() method로 iterator가 아니라 pointer로 접근 가능하다 (c++11)
  * 원소를 끝에서 삽입/삭제할 때 빠르다
* 사용
  * include \<vector>
  * template
    * T
    * Allocator = std::allocator<T>
* method
  * 접근
    * `operator[]`
    * `at(int index)` : operator[]와 달리 주어진 index가 범위 안인지를 체크한다
    * `front()`
    * `back()`
    * `data()`
  * 삽입/삭제
    * assign
      * `assign(InputIterator begin, InputIterator end)` : begin부터 end 전까지 요소를 카피해 할당
      * `assign(int num, value_type val)` : num개 원소에 val을 할당
      * `assign(initializer_list<value_type> il)`
    * `push_back(value_type val)`
    * `pop_back()`
    * insert
      * `insert(iterator position, value_type val)` : position 앞에 val 삽입
      * `insert(iterator position, size_type n, value_type val)` : val을 n개 삽입
      * `insert(iterator position, InputIterator first, InputIterator last)`
      * `insert(iterator position, initializer_list<value_type> il)`
    * erase
      * `erase(iterator position)`
      * `erase(iterator first, iterator last)` : first 부터 last 전 원소까지 삭제
    * `emplace(iterator position, Args&&... args)` : 임시 객체를 만들지 않고 바로 새 자리에서 생성해서 원소를 삽입 (c++11)
    * `swap(vector x)` : x와 원소들을 swap (c++11)

# Container Adapter
(현재까지 아래 3가지 종류)
## std::queue
* 특징
  * Container adapter로 내부 container의 인터페이스를 FIFO로 제한해주는 wrapper
  * 내부 container는 back(), front(), push_back(), pop_front()를 지원해야 함 ex) deque, list
  * 내부 container를 따로 지정하지 않으면 deque가 쓰임
* 사용
  * include \<queue>
  * template
    * T
    * Container = std::deque<T>
* method
  * 접근
    * `front()`
    * `back()`
  * 삽입/삭제
    * `push(value_type val)` : 끝에서 삽입
    * `pop()` : 앞에서 삭제
    * `emplace(Args&&... args)` : 임시 객체를 만들지 않고 바로 새 자리에서 생성해서 원소를 삽입 (c++11)
    * `swap(queue x)` : x와 원소들을 swap (c++11)

## std::stack
* 특징
  * Container adapter로 내부 container의 인터페이스를 LIFO로 제한해주는 wrapper
  * 내부 container는 back(), push_back(), pop_back()을 지원해야 함 ex) vector, deque, list
  * 내부 container를 따로 지정하지 않으면 deque가 쓰임
* 사용
  * include \<stack>
  * template
    * T
    * Container = std::deque<T>
* method
  * 접근
    * `top()`
  * 삽입/삭제
    * `push(value_type val)` : 끝에서 삽입
    * `pop()` : 앞에서 삭제
    * `emplace(Args&&... args)` : 임시 객체를 만들지 않고 바로 새 자리에서 생성해서 원소를 삽입 (c++11)
    * `swap(stack x)` : x와 원소들을 swap (c++11)

## std::priority_queue
* 특징
  * 내부 container는 front(), push_back(), pop_back()을 지원해야 함 ex) vector, deque
  * compare에는 less, greator, functor가 올 수 있다
* 사용
  * include \<queue>
  * template
    * T
    * Container = std::vector<T>
    * Compare = std::less\<typename Container::value_type>
* method
  * 접근
    * `top()`
  * 삽입/삭제
    * `push(value_type val)` : 삽입후 정렬
    * `pop()` : 앞에서 삭제
    * `emplace(Args&&... args)` : 임시 객체를 만들지 않고 바로 새 자리에서 생성해서 원소를 삽입 후 정렬 (c++11)
    * `swap(priority_queue x)` : x와 원소들을 swap (c++11)