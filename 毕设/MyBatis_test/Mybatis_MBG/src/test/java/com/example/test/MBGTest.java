package com.example.test;

import com.example.mapper.EmpMapper;
import com.example.pojo.Emp;
import com.example.pojo.EmpExample;
import com.example.utils.SqlSessionFactoryUtil;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.List;

public class MBGTest {
    @Test
    public void testMBG_1(){
        SqlSession sqlSession = SqlSessionFactoryUtil.getSqlSession();
        EmpMapper mapper = sqlSession.getMapper(EmpMapper.class);
        /*
        * 查询所有数据
        * */
        List<Emp> list1 = mapper.selectByExample(null);
        list1.forEach(emp -> System.out.println(emp));
        /*
        * 根据条件查询
        * */
        EmpExample example = new EmpExample();
        example.createCriteria().andEmpNameEqualTo("张三").andAgeGreaterThan(20);
        example.or().andDidIsNull();
        List<Emp> list2 = mapper.selectByExample(example);
        list2.forEach(emp -> System.out.println(emp));
    }

    @Test
    public void testMBG_2(){
        SqlSession sqlSession = SqlSessionFactoryUtil.getSqlSession();
        EmpMapper mapper = sqlSession.getMapper(EmpMapper.class);
        mapper.updateByPrimaryKey(new Emp(1,"admin",22,"女","123@163.com",3));
    }

}
