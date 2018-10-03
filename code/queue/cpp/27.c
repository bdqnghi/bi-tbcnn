#include <iostream>
using namespace std;

template <typename T>
class queue {
public:
    queue();
    virtual ~queue();
    void push(T & item);
    void pop();
    T front() const;
    bool empty() const;
    int size() const;
    void print() const;
private:
    T * m_arr;
    int m_capacity;
    int m_size;
    int m_index;
    static const int DEFAULT_CAPACITY = 8;
};

template <typename T>
queue<T>::queue()
    : m_arr(new T[DEFAULT_CAPACITY])
    , m_capacity(DEFAULT_CAPACITY)
    , m_size(0)
    , m_index(0) {

}

template <typename T>
queue<T>::~queue() {
    delete[] m_arr;
}

template <typename T>
void queue<T>::push(T & item) {
    if (m_capacity - 1 == m_size) {
        T * new_arr = new T[m_capacity * 2];
        for (int i = 0; i < m_size; ++i) {
            new_arr[i] = m_arr[(m_capacity + i - m_index) % m_capacity];
        }
        delete[] m_arr;
        m_arr = new_arr;
        m_capacity *= 2;
        m_index = 0;
    }
    m_arr[(m_index + m_size) % m_capacity] = item;
    m_size++;
}

template <typename T>
void queue<T>::pop() {
    if (empty()) {
        throw -1;
    }
    m_index = (m_index + 1) % m_capacity;
    m_size--;
}

template <typename T>
T queue<T>::front() const {
    if (empty()) {
        throw -1;
    }
    return m_arr[m_index];    
}

template <typename T>
int queue<T>::size() const {
    return m_size;
}

template <typename T>
bool queue<T>::empty() const {
    return m_size == 0;
}

template <typename T>
void queue<T>::print() const {
    for (int i = 0; i < m_size; ++i) {
        cout << m_arr[(m_index + i) % m_capacity] << ", ";
    }
    cout << endl;
    for (int i = 0; i < m_capacity; ++i) {
        bool is_inside = false;
        if (m_index + m_size < m_capacity) {
            is_inside = (m_index <= i && i < m_index + m_size);
        }
        else {
            is_inside = (m_index <= i || i < m_index + m_size - m_capacity);
        }
        if (is_inside) {
            cout << m_arr[i] << ", ";
        }
        else {
            cout << "_, ";
        }
    }
    cout << endl;
}

int main(int argc, const char ** argv) {
    queue<int> q;
    for (int i = 0; i < 6; ++i) {
        q.push(i);
    }
    for (int i = 0; i < 4; ++i) {
        q.pop();
    }
    q.print();
    for (int i = 6; i < 9; ++i) {
        q.push(i);
    }
    q.print();
    for (int i = 9; i < 19; ++i) {
        q.push(i);
    }
    q.print();
    for (int i = 4; i < 14; ++i) {
        q.pop();
    }
    q.print();
    return 0;
}