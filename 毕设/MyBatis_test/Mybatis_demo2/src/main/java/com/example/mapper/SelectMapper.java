package com.example.mapper;

import com.example.pojo.User;
import org.apache.ibatis.annotations.Param;

import java.util.List;

public interface SelectMapper {
    /*
    * 根据id来查询用户信息
    * */
    User getUserById(@Param("id") Integer id);
    /*
    * 查询所有的用户信息
    * */
    List<User> getAllUser();
}
