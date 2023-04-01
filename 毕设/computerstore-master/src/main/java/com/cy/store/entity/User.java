package com.cy.store.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @description: 对应数据表t_user的实体类
 * */
@Data
/*
* @NoArgsConstructor ： 生成一个无参数的构造方法
* @AllArgsConstructor： 会生成一个包含所有变量的构造方法，默认生成的方法是 public 的
* */
@NoArgsConstructor
@AllArgsConstructor
public class User extends BaseEntity {
    private Integer uid;
    private String username;
    private String password;
    private String salt; //用于加密密码
    private String phone;
    private String email;
    private Integer gender;//'性别:0-女，1-男',
    private String avatar;
    private Integer isDelete;
}

