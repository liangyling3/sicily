template <typename T> 
class Queue{
public:
    Queue() {
        count = 0;
        for (int i = 0; i < 100; ++i) {
            data[i] = 0;
        }
    } // construct an empty queue
    ~Queue() {
        count = 0;
        for (int i = 0; i < 100; ++i) {
            data[i] = 0;
        }
    }  // destructor
    Queue(const Queue &rhs) {
        count = rhs.count;
        for (int i = 0; i < 100; ++i) {
            data[i] = rhs.data[i];
        }
    }
    const Queue & operator = (const Queue &rhs) {
        count = rhs.count;
        for (int i = 0; i < 100; ++i) {
            data[i] = rhs.data[i];
        }
        return *this;
    }
    bool empty()const {
        return count == 0;
    }
    bool full()const {
        return count == 100;
    }
    int size()const {
        return count;
    }
    bool push(const T &x) {
        if (count < 100) {
            data[count] = x;
            count ++;
            return true;
        }
        return false;
    }//enqueue
    bool pop() {
         if (count == 0) 
            return false;
        count --;
        for (int i = 0; i < count; ++i) {
            data[i] = data[i+1];
        }
        return true;
    }//dequeue
    const T & front()const {
        return data[0];
    }//returns a reference to the front element
private:
    T data[100];
    int count;
};


