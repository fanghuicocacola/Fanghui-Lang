package TEST;

public class juxing {
	private double width;
	private double height;
	
	public juxing(double width, double height) {
		setWidth(width);
		this.height = height;
	}
	
	public void setWidth(double width) {
		if(width > 0) {
			this.width = width;
		} else {
			System.out.println("宽度不合理！");
		}
	}
	public double getWidth() {
		return width;
	}
	
	public double perimeter() {
		return (getWidth() + height)*2;
	}
	
}

/*public class Test {

	public static void main(String[] args) {
		
		Retange rt = new Retange(11, 20.6);
		double res = rt.perimeter();
		System.out.println("矩形周长：" + res);

	}

}
*/
