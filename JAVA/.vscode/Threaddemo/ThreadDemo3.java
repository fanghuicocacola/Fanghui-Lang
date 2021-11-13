package Threaddemo;

import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.locks.Lock;

//多线程同步 有同步方法和同步代码块两种同步
class TestThread implements Runnable {
    private int tickets_1 = 20;

    @Override
    public void run() {
        Lock lock = new ReentrantLock();
        while (true) {
            lock.lock();
            if (tickets_1 > 0) {
                try {
                    Thread.sleep(100);
                } catch (Exception e) {
                }
                System.out.println(Thread.currentThread().getName() + "拿到票号" + tickets_1--);
            }
            lock.unlock();
        }
    }

    /*
     * synchronized (this) { if (tickets_1 > 0) { try { Thread.sleep(100); } catch
     * (Exception e) { } System.out.println(Thread.currentThread().getName() +
     * "拿到票号" + tickets_1--); } }
     */
}

public class ThreadDemo3 {
    public static void main(String[] args) {
        TestThread p = new TestThread();
        Thread t1 = new Thread(p, "我");
        Thread t2 = new Thread(p, "黄牛");
        Thread t3 = new Thread(p, "小明");
        Thread t4 = new Thread(p, "老师");
        t1.start();
        t2.start();
        t3.start();
        t4.start();
    }
}
