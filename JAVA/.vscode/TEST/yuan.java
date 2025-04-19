package TEST;
/*1、编写一个圆类Circle，该类拥有：
①一个成员变量
Radius（私有，浮点型） ； // 存放圆的半径；
②两个构造方法
Circle( ) // 将半径设为0
Circle(double r ) //创建Circle 对象时将半径初始化为r
③ 三个成员方法
double getArea( ) //获取圆的面积
double getPerimeter( ) //获取圆的周长
void show( ) //将圆的半径、周长、面积输出到屏幕
*/
class Circle{
    private double Radius;
    public double getRadius() {
        return Radius;
    }
    public void setRadius(double radius) {
        Radius = radius;
    }

    public Circle(){
        this.Radius = 0;
    }
    public Circle(double Radius){
        this.Radius = Radius;
    }
    public double getArea(){
        return Math.PI*Radius*Radius;
    }
    public double getPerimeter(){
        return Math.PI*2*Radius;
    }
    public void show(){
        System.out.println("圆的半径："+Radius);
        System.out.println("圆的周长："+getPerimeter());
        System.out.println("圆的面积："+getArea());
    }
}
public class yuan {
    public static void main(String[] args) {
        Circle a = new Circle(3);
        a.show();
    }
}
