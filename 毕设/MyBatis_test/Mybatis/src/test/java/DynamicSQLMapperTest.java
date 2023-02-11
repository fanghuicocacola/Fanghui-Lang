import com.example.mapper.DynamicSQLMapper;
import com.example.pojo.Emp;
import com.example.utils.SqlSessionUtils;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;

import java.util.Arrays;
import java.util.List;

public class DynamicSQLMapperTest {

    /*
    * 动态SQL:
    * 1.if:根据标签中test属性所对应的表达式决定标签中的内容是否需要拼接到SQL中
    * 2.where:
    * 当where标签中有内容时,会自动生成where关键字,并且将内容前多余的and或or去掉
    * 当where标签中没有where没有内容时,此时where标签没有任何效果
    * 注意:where标签不能将其中内容后面多余的and或or去掉
    * 3.trim:
    * prefix/suffix:将trim标签内容前或后面添加指定内容
    * suffixOverrides/prefixOverrides:将trim标签内容前或后面去掉指定内容
    * 若标签中没有内容,trim标签也没有任何效果
    * 4.choose,when,otherwise,相当于if...else if...else
    * when至少要有一个，otherwise最多只能有一个
    * 5.foreach
    * collection:设置需要循环的数组或集合
    * item:表示数组或集合中的每一个数据
    * separator:循环体之间的分隔符
    * open:foreach标签所循环的所有内容的开始符
    * close:foreach标签所训话的所有内容的结束符
    * 6.sql标签
    * 设置SQL片段:<sql id="empColumns">eid,emp_name,sex,email</sql>
    * 引用SQL片段:<include refid="empColumns"></include>
    * */
    @Test
    public void testGetEmpByConditionTest(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        DynamicSQLMapper mapper = sqlSession.getMapper(DynamicSQLMapper.class);
        List<Emp> empList = mapper.getEmpByCondition(new Emp(null,"张三",23,"","",1));
        System.out.println(empList);
    }

    @Test
    public void testGetEmpByChooseTest(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        DynamicSQLMapper mapper = sqlSession.getMapper(DynamicSQLMapper.class);
        List<Emp> empList = mapper.getEmpByChoose(new Emp(null,"",null,"","",1));
        for (Emp emp:empList) {
            System.out.println(emp);
        }
    }
    @Test
    public void testDeleteMoreByArrayTest(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        DynamicSQLMapper mapper = sqlSession.getMapper(DynamicSQLMapper.class);
        int result = mapper.deleteMoreByArray(new Integer[]{6,7,8});
        System.out.println(result);
    }
    @Test
    public void testInsertMoreByList(){
        SqlSession sqlSession = SqlSessionUtils.getSqlSession();
        DynamicSQLMapper mapper = sqlSession.getMapper(DynamicSQLMapper.class);
        Emp emp1 = new Emp(null,"a1",23,"男","123@qq.com",1);
        Emp emp2 = new Emp(null,"a2",23,"男","123@qq.com",1);
        Emp emp3 = new Emp(null,"a3",23,"男","123@qq.com",1);
        Emp emp4 = new Emp(null,"a4",23,"男","123@qq.com",1);
        List<Emp> emps = Arrays.asList(emp1,emp2,emp3,emp4);
        System.out.println(mapper.insertMoreByList(emps));
    }
}
