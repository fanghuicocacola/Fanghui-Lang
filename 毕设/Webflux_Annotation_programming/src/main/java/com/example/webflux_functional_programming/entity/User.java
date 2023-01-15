package com.example.webflux_functional_programming.entity;

public class User {
    private String name;
    private String gender;
    private Integer age;

    public User(String name,String gender,Integer age){
        this.name = name;
        this.gender = gender;
        this.age = age;
    }

    public void setName(String name){
        this.name = name;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }
}
