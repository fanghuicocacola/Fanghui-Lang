import javax.print.event.PrintJobListener;

interface Animals{
    public void Eat();
    public void Travel();
}

interface Earth{
    public void f1();
    public void f2();
}
class Horses implements Animals,Earth{

    public void Eat() {
        System.out.println("Horses are eating");
    }
    public void Travel() {
        System.out.println("Horses are travelling");
    }
    public void f1(){
        System.out.println("地球生物");
    }
    public void f2(){

    }
    
}
public class TextInterface {
    /*
     * 1、 接口里的数据成员必须初始化，且数据成员均为常量。 
     * 2、 接口里的方法必须全部声明为 abstract，也就是说，接口不能像抽象类一样保有一
     * 般的方法，而必须全部是“抽象方法”。
     */
    public static void main(String[] args) {
        Horses a = new Horses();
        a.Eat();
        a.Travel();
        a.f1();
    }
}
