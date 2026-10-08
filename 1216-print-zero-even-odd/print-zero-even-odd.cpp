class ZeroEvenOdd {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool zeroTurn = true;
    bool oddTurn = false;
    bool evenTurn = false;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    void zero(function<void(int)> printNumber) {
        for(int i = 1; i <= n; i++) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [&]() {
                return zeroTurn;
            });

            printNumber(0);

            zeroTurn = false;

            if(i % 2 == 1) {
                oddTurn = true;
            } else {
                evenTurn = true;
            }

            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [&]() {
                return evenTurn;
            });

            printNumber(i);

            evenTurn = false;
            zeroTurn = true;

            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [&]() {
                return oddTurn;
            });

            printNumber(i);

            oddTurn = false;
            zeroTurn = true;

            cv.notify_all();
        }
    }
};