class Person6{
    protected void finalize() throws Throwable{
        System.out.println(this+"即将被销毁");
    }
}

public class FinalizeTest {
    public static void main(String[] args) {
        /*for(int i = 0;i<1000000;i++){
        Person6 p = new Person6();
        p = null;
        }*/
        Person6 p = new Person6();
        p = null;
        System.gc();
    }
}
