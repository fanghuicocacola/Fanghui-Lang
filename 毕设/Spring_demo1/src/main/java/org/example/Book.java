package org.example;

public class Book {

    private String name;
    private int price;
    private String publisher;
    //set方法
    public void setName(String name) {
        this.name = name;
    }
    public void setPublisher(String publisher){
        this.publisher = publisher;
    }
    //有参构造注入
    public Book(int price){
        this.price = price;
    }
    //测试方法
    public void test(){
        System.out.println(name);
    }
    //有参构造
    public void test_2(){
        System.out.println(price+"元");
    }
    public void test_3(){
        System.out.println(publisher);
    }
}