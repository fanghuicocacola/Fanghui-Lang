public class TestRunnable implements Runnable {
    @Override

    // 实现Runnable接口，只创建了一个类的实例，而且被多个线程共享了。
    // 而继承Thread类，你必须为每一个线程创建不同的实例。因此每个类的实例分配了不同的内存空间,这意味着没有一个对象的引用是相同的。
    public void run() {
        //run方法线程体
        for (int i=0;i<5;i++)
        {
            System.out.println("我在-线程里--看代码--我是房辉2702190102 "+i);
            System.out.println("我是"+Thread.currentThread().getName());
        }
    }

    public static void main(String[] args) {

        //方法1：
        //创建实现类对象
        TestRunnable testThread_3 = new TestRunnable();
        //创建代理对象
        Thread thread = new Thread(testThread_3);
        thread.start();

        //方法2：对方法1进行简化
        //        new Thread(testThread_3).start();
        for (int i = 0; i < 5; i++) {
            System.out.println("我在-进程里-学习多线程--我是房辉2702190102 "+i);
        }
    }
}