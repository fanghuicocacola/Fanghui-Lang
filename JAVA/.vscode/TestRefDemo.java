class Change {
    int x = 0;
}

public class TestRefDemo {
    public static void main(String[] args) {
        Change c = new Change();
        c.x = 20;
        fun(c);
        fun2(c);
        System.out.println("x = " + c.x);
    }

    public static void fun(Change c1) {
        c1.x = 25;
    }
    public static void fun2(Change c2){
        c2.x = 30;
    }
}