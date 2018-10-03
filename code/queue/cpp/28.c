template <class T>
class queue {
  static const int SIZE = 10000;
  T que[SIZE];
  int head;
  int tail;
public:
  queue() { Init(); }
  void Init() {
    head = 0;
    tail = 0;
  }
  bool empty() { return head == tail; }
  T front() {
    assert(!empty());
    return que[tail];
  }
  void push(T x) {
    que[head++] = x;
    if (head == SIZE) { head = 0; }
    assert(head != tail);
  }
  void pop() {
    assert(!empty());
    tail++;
    if (tail == SIZE) { tail = 0; }
  }
};
template <class T>
class priority_queue {
  static const int SIZE = 10000;
  T que[SIZE];
  int s;
  void PushTop() {
    int index = 1;
    while (index * 2 <= s) {
      int child = HeapSwap(index);
      if (child == 0) { break; }
      if (child == 1) { index = index * 2; }
      if (child == 2) { index = index * 2 + 1; }
    }
  }
  void PushBottom() {
    int index = s;
    while (index > 1) {
      index /= 2;
      if (HeapSwap(index) == 0) { break; }
    }
  }
  int HeapSwap(int index) {
    int ret = -1;
    if (index * 2 == s) {
      if (que[index * 2] < que[index]) {
        ret = 0;
      } else {
        swap(que[index], que[index * 2]);
        ret = 1;
      }
    } else if (index * 2 + 1 <= s) {
      if (que[index * 2] < que[index] && que[index * 2 + 1] < que[index]) {
        ret = 0;
      } else if (que[index] < que[index * 2] && que[index * 2 + 1] < que[index * 2]) {
        swap(que[index], que[index * 2]);
        ret = 1;
      } else if (que[index] < que[index * 2 + 1] && que[index * 2] < que[index * 2 + 1]) {
        swap(que[index], que[index * 2 + 1]);
        ret = 2;
      } else if (que[index] < que[index * 2]) {
        swap(que[index], que[index * 2]);
        ret = 1;
      } else {
        ret = 0;
      }
    }
    return ret;
  }
  public:
  priority_queue() { Init(); }
  void Init() {
    s = 0;
  }
  T top() {
    assert(s != 0);
    return que[1];
  }
  bool empty() { return s == 0; }
  void push(T x) {
    assert(s < SIZE - 1);
    que[s + 1] = x;
    s++;
    PushBottom();
  }
  void pop() {
    assert(s != 0);
    swap(que[1], que[s]);
    s--;
    PushTop();
  }
};
