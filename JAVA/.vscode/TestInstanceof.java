class Apple {
    public Apple() {

    }

    public void fun1() {
        System.out.println("fun1()");
    }

    public void fun2() {
        System.out.println("fun2()");
    }
}

class Fruit extends Apple {
    public void fun1() {
        System.out.println("new fun1()");
    }
}

public class TestInstanceof {
    public static void main(String[] args) {
        Apple a1 = new Fruit();
        Apple a2 = new Apple();
        Fruit a3 = new Fruit();
        if (a1 instanceof Fruit) {
            System.out.println("a1 is the instance of Fruit");
        }
        if (a1 instanceof Apple) {
            System.out.println("a1 is the instance of Apple");
        }

        if (a2 instanceof Fruit) {
            System.out.println("a2 is the instance of Fruit");
        }
        if (a2 instanceof Apple) {
            System.out.println("a2 is the instance of Apple");
        }
        if (a3 instanceof Fruit) {
            System.out.println("a3 is the instance of Fruit");
        }
        if (a3 instanceof Apple) {
            System.out.println("a3 is the instance of Apple");
        }

    }
}