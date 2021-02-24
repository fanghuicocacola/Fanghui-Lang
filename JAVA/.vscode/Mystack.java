class Husband{

}

class Wife{

}
public class Mystack {
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
    
    public void pop(Object obj){

    }
    public Mystack(){
        this.elements = new Object[10];
    }
    public static void main(String[] args) {
        Object[] arr = {new Husband(),new Wife(),"abc"};
        Mystack stack = new Mystack();
        stack.push("qwer");
        stack.push("asdf");
    }
}
