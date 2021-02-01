package Threaddemo;

//多线程同步
class TestThread implements Runnable {
    private int tickets = 20;

    public void run() {
        while (true) {
            synchronized (this) {
                if (tickets > 0) {
                    try {
                        Thread.sleep(100);
                    } catch (Exception e) {
                    }
                    System.out.println(Thread.currentThread().getName() + "出售票" + tickets--);
                }
            }
        }
    }
}

public class ThreadDemo3 {
    public static void main(String[] args) {
        TestThread p = new TestThread();
        Thread t1 = new Thread(p);
        Thread t2 = new Thread(p);
        Thread t3 = new Thread(p);
        Thread t4 = new Thread(p);
        t1.start();
        t2.start();
        t3.start();
        t4.start();
    }
}
