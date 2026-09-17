class DiningPhilosophers {
public:

    mutex fork[5];

    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        int left = philosopher;
        int right = (philosopher + 1) % 5;

        lock(fork[left], fork[right]);

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();
        fork[left].unlock();
        fork[right].unlock();
    }
};