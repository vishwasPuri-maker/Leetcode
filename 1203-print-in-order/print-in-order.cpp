class Foo {
public:

    mutex m;
    condition_variable cv;
    int num = 1;

    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        unique_lock<mutex> lock(m);
        printFirst();

        num = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        unique_lock<mutex> lock(m);

        cv.wait(lock, [this] {
            return num == 2;
        });
        printSecond();

        num = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        unique_lock<mutex> lock(m);

        cv.wait(lock, [this] {
            return num == 3;
        });
        printThird();
    }
};