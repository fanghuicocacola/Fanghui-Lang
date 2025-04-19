class Students extends Person {
    // JAVA 允许单继承和多层继承，不允许多重继承
    private String school;
    public void setschool(String s){
        school = s;
    }
    public String getschool(){
        return school;
    }
}

public class Testextends {
    public static void main(String[] args) {
        Students stu1 = new Students();
        stu1.setname("张三");
        stu1.setage(18);
        stu1.setschool("北大");
        System.out.println("我叫"+stu1.getname()+"今年"+stu1.getage()+"来自"+stu1.getschool());

    }
}
