package com.example.test;

import com.example.mapper.EmpMapper;
import com.example.pojo.Emp;
import com.example.utils.SqlSessionFactoryUtil;
import com.github.pagehelper.Page;
import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.List;

public class PageHelperTest {

    /*
    * limit, index, pageSize
    * index:当前页的起始索引
    * pageSize:每页显示的条数
    * pageNum:当前页的页码
    * index=(pageNum-1)*pageSize
    *
    * 使用Mybatis的分页插件实现分页功能
    * 1.需要在查询功能之前开启分页
    * PageHelper.startPage(int pageNum,int pageSize)
    * 2. 在查询功能之后获取分页相关信息
    * PageInfo<Emp> page = new PageInfo<>(list,5)
    * list表示分页数据
    * 5表示当前当行分页的数量
    * */
    @Test
    public void testPageHelper(){
        SqlSession sqlSession = SqlSessionFactoryUtil.getSqlSession();
        EmpMapper mapper = sqlSession.getMapper(EmpMapper.class);
        Page<Object> page = PageHelper.startPage(2,4);
        System.out.println(page);
        List<Emp> list = mapper.selectByExample(null);
        PageInfo<Emp> pageInfo = new PageInfo<>(list,4);
        System.out.println(pageInfo);
        list.forEach(emp -> System.out.println(emp));
    }
}
