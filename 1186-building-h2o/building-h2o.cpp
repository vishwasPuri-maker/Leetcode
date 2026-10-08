class H2O {
public:
    mutex mtx;
    condition_variable cv;

    int h = 0;

    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [&]() {
            return h < 2;
        });

        releaseHydrogen();

        h++;

        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [&]() {
            return h == 2;
        });

        releaseOxygen();

        h = 0;

        cv.notify_all();
    }
};