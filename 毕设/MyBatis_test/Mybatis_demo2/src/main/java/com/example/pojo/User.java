package com.example.pojo;

public class User {
    private Integer id;
    private String name;
    private String password;
    private Integer age;
    private String gender;
    private String email;

    public User(Integer id,String name,String password,Integer age,String gender,String email){
        this.id = id;
        this.name = name;
        this.password = password;
        this.age = age;
        this.gender = gender;
        this.email = email;
    }

    @Override
    public String toString() {
        return "User{" +
                "id='" + id + '\'' +
                ", name='" + name + '\'' +
                ", password='" + password + '\'' +
                ", age=" + age +
                ", gender='" + gender + '\'' +
                ", email='" + email + '\'' +
                '}';
    }
}
