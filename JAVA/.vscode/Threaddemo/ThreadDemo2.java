package Threaddemo;

class MyThread2 implements Runnable {
    // Runable可以实现资源共享
    private String name;
    int i = 20;

    public MyThread2(String name) {
        this.name = name;
    }

    public MyThread2() {
    }

    public void run() {
        while (true) {
            if (i > 0) {
                System.out.println(name + "在运行" + i--);

            }
        }
    }

    public void printMsg() {
        Thread t = Thread.currentThread();
        String s = t.getName();
        System.out.println("name=" + s);
    }

    public void setName(String string) {
        Thread t = Thread.currentThread();
        t.setName(string);
    }
}

public class ThreadDemo2 {
    public static void main(String[] args) {
        MyThread2 t1 = new MyThread2("线程A");
        t1.setName("Test Thread");
        Thread p = new Thread(t1);
        System.out.println(Thread.activeCount());
        System.out.println("调用 start()方法之前 , isAlive() = " + p.isAlive());
        p.start();
        System.out.println("调用 start()方法之前 , isAlive() = " + p.isAlive());
        for (int i = 20; i >= 0; i--) {
            t1.printMsg();
        }
        System.out.println("结束时 , isAlive() = " + p.isAlive());
    }
}
