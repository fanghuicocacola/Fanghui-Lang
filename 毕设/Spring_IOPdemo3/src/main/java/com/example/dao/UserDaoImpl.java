package com.example.dao;

import org.springframework.stereotype.Repository;

@Repository(value = "userDaolmpl")
public class UserDaoImpl implements UserDao {
    @Override
    public void add() {
        System.out.println("Dao add......");
    }
}
