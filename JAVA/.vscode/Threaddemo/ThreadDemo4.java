package Threaddemo;

class p {
    String name = "张三";
    String sex = "男";
    boolean bFull = false;

    public synchronized void set(String name, String sex) {
        // 同组里的 wait 只能被同组的 notify 唤醒
        if (bFull) {
            try {
                wait(); // 后来的线程要等待
            } catch (InterruptedException e) {
            }
        }
        try {
            Thread.sleep(1000);
        } 
        catch (Exception e) {
            System.out.println(e.getMessage());

        }
        this.name = name;
        this.sex = sex;
        bFull = true;

        notify(); // 唤醒最先到达的线程
    }

    public synchronized void get() {
        if (!bFull) {
            try {
                wait();
            } catch (InterruptedException e) {
            }
        }
        System.out.println(name + " ---->" + sex);
        bFull = false;
        notify();
    }
}

class Producer implements Runnable {
    p q = null;

    public Producer(p q) {
        this.q = q;
    }

    public void run() {
        int i = 0;
        while (true) {
            if (i == 0) {
                q.set("李四", "女");
            } 
            else if(i == 1){
                q.set("张三", "男");
            }
            else {
                q.set("王五", "？");
            }
            i = (i + 1) % 3;
        }
    }
}

class Consumer implements Runnable {

    p q = null;

    public Consumer(p q) {
        this.q = q;
    }

    public void run() {
        while (true) {
            q.get();
        }
    }

}

public class ThreadDemo4 {
    public static void main(String[] args) {
        p q = new p();
        new Thread(new Producer(q)).start();//set()
        new Thread(new Consumer(q)).start();//get(1)
    }
}
