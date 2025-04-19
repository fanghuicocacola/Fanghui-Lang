
public class TestClassTwo extends TestClass {
	public TestClassTwo() {
		System.out.println("来自TestClassTwo 空参构造方法");
	}

	public static void main(String[] args) {
		// 类的继承
		new TestClassTwo();
		new TestClass("info");
		new TestClass(1, 2, 3, "info");
	}
}
