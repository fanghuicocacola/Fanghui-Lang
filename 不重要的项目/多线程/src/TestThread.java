public class TestThread extends Thread {
    @Override
    public void run() {
        //run方法线程体
        for (int i=0;i<5;i++)
        {
            System.out.println("我在-线程里--看代码--我是房辉2702190102"+i);
            System.out.println("我的名字是"+Thread.currentThread().getName());
        }
    }

    public static void main(String[] args) {
        //main线程，主线程
        //创建一个子线程对象
        TestThread testThread_1 = new TestThread();
        //调用start方法开启子线程
        testThread_1.start();
        Thread t = Thread.currentThread();
        String name = t.getName();
        System.out.println("我叫name=" + name);
        for (int i = 0; i < 5; i++) {
            System.out.println("我在-进程里-学习多线程--我是房辉2702190102"+i);
        }
    }
}