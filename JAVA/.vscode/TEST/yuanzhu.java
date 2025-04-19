package TEST;

/*编写一个圆柱体类Cylinder ，它继承于上面的Circle 类。还拥有：
①一个成员变量
double hight（私有，浮点型） ； // 圆柱体的高；
②构造方法
Cylinder (double r, double h ) //创建Circle 对象时将半径初始化为
r
③ 成员方法
double getVolume( ) //获取圆柱体的体积
void showVolume( ) //将圆柱体的体积输出到屏幕

*/
class Cylinder extends Circle {
    private double hight;

    public Cylinder(double r, double h) {
        super(r);
        this.hight = h;
    }

    public double getVolume() {
        return Math.PI * this.getRadius() * this.getRadius() * hight;
    }

    public void showVolume() {
        System.out.println("圆柱体的体积：" + this.getVolume());
    }
}
public class yuanzhu {
    public static void main(String[] args) {
        Cylinder b =new Cylinder(5, 3);
        b.showVolume();
    }    
}

