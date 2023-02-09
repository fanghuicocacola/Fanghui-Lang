package com.example.mapper;

import com.example.pojo.Emp;

import java.util.List;

public interface DynamicSQLMapper {
    /*
    * 多条件查询
    * */
    List<Emp> getEmpByCondition(Emp emp);
    List<Emp> getEmpByChoose(Emp emp);
}
