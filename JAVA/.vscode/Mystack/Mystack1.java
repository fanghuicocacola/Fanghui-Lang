package Mystack;

class Husband {

}

class Wife{

}
public class Mystack1 {
    private Object[] elements;
    private int index = -1;
    public Object[] getelements(){
        return elements;
    }
    public void setelements(Object[] elements) {
        this.elements = elements;
    }
    public void push(Object obj){
        if(this.index >= this.elements.length -1){
            System.out.println("栈已满，压栈失败");
            return;
        }
        this.index ++;
    this.elements[index] = obj;
    System.out.println("压栈"+obj+"元素成功，栈帧指向"+index);
    }
    
    public void pop(){
        if(index < 0){
            System.out.println("弹栈失败，栈已空！");
            return;
        }
        System.out.println("弹栈"+elements[index]+"元素成功");
        index--;
        System.out.println("栈帧指向"+index);
        return;
    }
    public Mystack1(){
        this.elements = new Object[10];
    }
    public static void main(String[] args) {
        Object[] arr = {new Husband(),new Wife(),"abc"};
        Mystack1 stack = new Mystack1();
        stack.push("qwer");
        stack.push("asdf");
        stack.push("zxcv");
        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();
    }
}
