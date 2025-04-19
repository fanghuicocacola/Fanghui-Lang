package TEST;

public class txing {
	private double top;
	private double bottom;
	private double height;
	
	public txing(double top, double bottom, double height) {
		this.top = top;
		this.bottom = bottom;
		this.height = height;
	}
	
	public void setHeight(double height) {
		if(height > 0) {
			this.height = height;
		} else {
			System.out.println("高不合理！");
		}
	}
	public double getHeight() {
		return height;
	}
	
	public double area() {
		return (top + bottom)*getHeight() / 2;
	}
	
}

public class Test {

	public static void main(String[] args) {
		
		Trapezoid tz = new Trapezoid(12.5, 20.2, 10);
		double res = tz.area();
		System.out.println("梯形的面积：" + res);
		
	}

}