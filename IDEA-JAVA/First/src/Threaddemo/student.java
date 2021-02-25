package Threaddemo;
class MyThread1 extends Thread{
    // Thread,一个对象，一个线程，启动一次
    private String name;
    public MyThread1(String name){
        this.name = name;
    }
    public void run(){
        for(int i = 0;i<10;i++){
            System.out.println(name+"正在运行"+i);
        }
    }
}

public class student {
    public static void main(String[] args) {
        MyThread1 t1 = new MyThread1("线程A");
        MyThread1 t2 = new MyThread1("线程B");
        t1.start();
        t2.start();
    }

}
