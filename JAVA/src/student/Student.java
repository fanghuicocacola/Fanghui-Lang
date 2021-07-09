package student;

public class Student {	
	private String name;
	private int pwd;
	private int age;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getPwd() {
		return pwd;
	}
	public void setPwd(int pwd) {
		this.pwd = pwd;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String toString() {
		return "Student [name=" + name + ", pwd=" 
	            + pwd + ", age=" + age + "]";
	}
}
