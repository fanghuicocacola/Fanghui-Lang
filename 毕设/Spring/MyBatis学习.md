# MyBatis学习

## 1.MyBatis简介

1. MyBatis历史

    * MyBatis最初是Apache的一个开源项目iBatis, 2010年6月这个项目由Apache Software Foundation迁移到了Google Code。随着开发团队转投Google Code旗下，iBatis3.x正式更名为MyBatis。代码于2013年11月迁移到Github
    * iBatis 一词来源于 "internet" 和 "abatis" 的组合，是一个基于 java 的持久层框架。iBatis 提供的持久层框架包括 SQL Maps（数据库数据与 Java 数据的映射关系）和 Data Access Object（DAO）

2. MyBatis特性

    1. MyBatis 是支持定制化 SQL、存储过程以及高级映射的优秀**持久层框架**
    2. MyBatis 避免了几乎所有的 JDBC 代码和手动设置参数以及获取结果集
    3. MyBatis 可以使用简单的 XML 或注解用于配置和原始映射，将接口和 java 的 POJO（Plain Old Java Object，普通的 java 对象）映射成数据库中的记录
    4. MyBatis 是一个 半自动的 ORM（Object Relation Mapping，对象关系映射）框架

3. 和其他持久层技术的比较
    * JDBC
        * SQL 夹杂在 Java 语句中耦合度高，导致硬编码内伤
        * 维护不易且实际开发需求中 SQL 有变化，频繁修改的情况多见
        * 代码，冗长
    * Hibernate 和 JPA
        * 操作简洁，开发效率高
        * 程序中的长难复杂 SQL 需要绕过框架
        * 内部自动生产的 SQL，不容易做特殊优化
        * 基于全映射的全自动框架，大量字段的 POJO 进行部分映射比较困难
        * 反射操作过多，导致数据库性能下降
    * MyBatis
        * 轻量级，性能出色
        * SQL 和 Java 编码分开，功能边界清晰。Java 代码专注业务、SQL 语句专注数据
        * 开发效率稍逊 HIbernate，但是完全能接受

## 2.搭建 MyBatis

1. 引入依赖

    ```代码
        <?xml version="1.0" encoding="UTF-8"?>
        <project xmlns="http://maven.apache.org/POM/4.0.0"
                xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
                xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
            <modelVersion>4.0.0</modelVersion>

            <groupId>org.example</groupId>
            <artifactId>MyBatis_test</artifactId>
            <version>1.0-SNAPSHOT</version>
            <packaging>pom</packaging>
            <modules>
                <module>MyBatis_demo1</module>
            </modules>
            <dependencies>
                <!-- mybatis驱动 -->
                <dependency>
                    <groupId>org.mybatis</groupId>
                    <artifactId>mybatis</artifactId>
                    <version>3.5.11</version>
                </dependency>

                <!-- junit测试 -->
                <dependency>
                    <groupId>junit</groupId>
                    <artifactId>junit</artifactId>
                    <version>4.13.2</version>
                    <scope>test</scope>
                </dependency>
                <!-- MySQL驱动 -->
                <dependency>
                    <groupId>mysql</groupId>
                    <artifactId>mysql-connector-java</artifactId>
                    <version>8.0.30</version>
                </dependency>
                <dependency>
                    <groupId>org.apache.logging.log4j</groupId>
                    <artifactId>log4j-core</artifactId>
                    <version>2.19.0</version>
                </dependency>
                <dependency>
                    <groupId>org.springframework</groupId>
                    <artifactId>spring-test</artifactId>
                    <version>6.0.3</version>
                </dependency>
                <dependency>
                    <groupId>org.projectlombok</groupId>
                    <artifactId>lombok</artifactId>
                    <version>1.18.24</version>
                    <scope>provided</scope>
                </dependency>
            </dependencies>

            <properties>
                <maven.compiler.source>8</maven.compiler.source>
                <maven.compiler.target>8</maven.compiler.target>
                <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>
            </properties>


        </project>
    ```

2. 配置核心配置文件
    >习惯上命名为 mybatis-config.xml，这个文件名仅仅只是建议，并非强制要求。将来整合 Spring 之后，这个配置文件可以省略，所以大家操作时可以直接复制、粘贴。
    核心配置文件主要用于配置连接数据库的环境以及 MyBatis 的全局配置信息
    核心配置文件存放的位置是 src/main/resources 目录下

    ```代码
        <?xml version="1.0" encoding="UTF-8" ?>
        <!DOCTYPE configuration
                PUBLIC "-//mybatis.org//DTD Config 3.0//EN"
                "http://mybatis.org/dtd/mybatis-3-config.dtd">
        <configuration>
            <environments default="development">
                <environment id="development">
                    <transactionManager type="JDBC"/>
                    <dataSource type="POOLED">
                        <property name="driver" value="com.mysql.jdbc.Driver"/>
                        <property name="url" value="jdbc:mysql://localhost:3306/MyBatis"/>
                        <property name="username" value="root"/>
                        <property name="password" value="123456"/>
                    </dataSource>
                </environment>
            </environments>
            <mappers>
                <mapper resource="org/mybatis/example/BlogMapper.xml"/>
            </mappers>
        </configuration>
    ```

3. 创建mapper接口
   > MyBatis 中的 mapper 接口相当于以前的 dao。但是区别在于，mapper 仅仅是接口，我们不需要提供实现类

    ```代码
        public interface UserMapper {  
            /*
            * MyBatis面向接口编程的两个一致
            * 1. 映射文件的namespace要和mapper接口的全类名保持一致
            * 2. 映射文件中SQL语句的id要和mapper接口中的方法名一致
            * */
            int insertUser();  
        }
    ```

4. 创建 MyBatis 的映射文件

   * 相关概念：ORM（Object Relationship Mapping）对象关系映射。
       * 对象：Java 的实体类对象
       * 关系：关系型数据库
       * 映射：二者之间的对应关系
        > 类对应表，属性对应字段/列  
        > 属性对应字段/列  
        > 对象对应记录/行

    > 1. 映射文件的命名规则:表所对应的实体类的类名 + Mapper.xml,例如：表 t_user，映射的实体类为 User，所对应的映射文件为 UserMapper.xml,因此一个映射文件对应一个实体类，对应一张表的操作,MyBatis 映射文件用于编写 SQL，访问以及操作表中的数据,MyBatis 映射文件存放的位置是 src/main/resources/mappers 目录下
    > 2. MyBatis中可以面向接口操作数据，要保证两个一致：
    a>mapper接口的全类名和映射文件的命名空间(namespace)保持一致,b>mapper接口中方法的方法名和映射文件中编写SQL的标签的id属性保持一致

5. 通过 junit 测试功能
  
    * SqlSession：代表 Java 程序和数据库之间的会话。
    * SqlSessionFactory：是 生产 SqlSession 的 工厂
    * 工厂模式：如果创建某一个对象，使用的过程基本固定，那么我们可以把创建的这个对象的相关代码封装到一个工厂类，以后都可以使用这个工厂类来生产我们需要的对象

        ```代码
            public class MyBatisTest {
            @Test
            public void testMyBatis() throws Exception {
                //加载核心配置文件
                InputStream is = Resources.getResourceAsStream("mybatis-config.xml");
                //获取SqlSessionFactoryBuilder
                SqlSessionFactoryBuilder sqlSessionFactoryBuilder = new SqlSessionFactoryBuilder();
                //获取SqlSessionFactory
                SqlSessionFactory sqlSessionFactory = sqlSessionFactoryBuilder.build(is);
                //获取SqlSession
                SqlSession sqlSession = sqlSessionFactory.openSession();
                //获取mapper接口对象
                UserMapper mapper = sqlSession.getMapper(UserMapper.class);
                //测试功能
                int result = mapper.insertUser();
                //提交事务
                sqlSession.commit();
                System.out.println("result:" + result);
            }
        }
        ```

    * 注意：此时需要手动提交，如果自动提交事务，则在获取 sqlSession 对象时，使用 SqlSession sqlSession = sqlSessionFactory.openSession(true);，传入一个 Boolean 类型的参数，值为 true，这样就可以自动提交

6. 加入 log4j 日志功能
   1. 加入依赖

        ```代码
        <!-- log4j日志 -->
        <dependency>
        <groupId>log4j</groupId>
        <artifactId>log4j</artifactId>
        <version>1.2.17</version>
        </dependency>
        ```

   2. 加入log4j的配置文件

        ```代码
        <?xml version="1.0" encoding="UTF-8" ?>
        <!DOCTYPE log4j:configuration SYSTEM "log4j.dtd">
        <log4j:configuration xmlns:log4j="http://jakarta.apache.org/log4j/">
            <appender name="STDOUT" class="org.apache.log4j.ConsoleAppender">
                <param name="Encoding" value="UTF-8" />
                <layout class="org.apache.log4j.PatternLayout">
                    <param name="ConversionPattern" value="%-5p %d{MM-dd HH:mm:ss,SSS} %m (%F:%L) \n" />
                </layout>
            </appender>
            <logger name="java.sql">
                <level value="debug" />
            </logger>
            <logger name="org.apache.ibatis">
                <level value="info" />
            </logger>
            <root>
                <level value="debug" />
                <appender-ref ref="STDOUT" />
            </root>
        </log4j:configuration>    
        ```

    >日志的级别  
    >FATAL:致命;ERROR(错误);WARN(警告);INFO(信息);DEBUG(调试)(从左到右打印的信息越来越详细)

## 3.核心配置文件详解

> 核心配置文件中的标签必须按照固定的顺序 (有的标签可以不写，但顺序一定不能乱)：  
> properties、settings、typeAliases、typeHandlers、objectFactory、objectWrapperFactory、reflectorFactory、plugins、environments、databaseIdProvider、mappers

```代码
    <?xml version="1.0" encoding="UTF-8" ?>
    <!DOCTYPE configuration
            PUBLIC "-//MyBatis.org//DTD Config 3.0//EN"
            "http://MyBatis.org/dtd/MyBatis-3-config.dtd">
    <configuration>
        <!--引入properties文件，此时就可以${属性名}的方式访问属性值-->
        <properties resource="jdbc.properties"></properties>
        <settings>
            <!--将表中字段的下划线自动转换为驼峰-->
            <setting name="mapUnderscoreToCamelCase" value="true"/>
            <!--开启延迟加载-->
            <setting name="lazyLoadingEnabled" value="true"/>
        </settings>
        <typeAliases>
            <!--
            typeAlias：设置某个具体的类型的别名
            属性：
            type：需要设置别名的类型的全类名
            alias：设置此类型的别名，且别名不区分大小写。若不设置此属性，该类型拥有默认的别名，即类名
            -->
            <!--<typeAlias type="com.atguigu.mybatis.bean.User"></typeAlias>-->
            <!--<typeAlias type="com.atguigu.mybatis.bean.User" alias="user">
            </typeAlias>-->
            <!--以包为单位，设置改包下所有的类型都拥有默认的别名，即类名且不区分大小写-->
            <package name="com.atguigu.mybatis.bean"/>
        </typeAliases>
        <!--
        environments：设置多个连接数据库的环境
        属性：
            default：设置默认使用的环境的id
        -->
        <environments default="mysql_test">
            <!--
            environment：设置具体的连接数据库的环境信息
            属性：
                id：设置环境的唯一标识，可通过environments标签中的default设置某一个环境的id，表示默认使用的环境
            -->
            <environment id="mysql_test">
                <!--
                transactionManager：设置事务管理方式
                属性：
                    type：设置事务管理方式，type="JDBC|MANAGED"
                    type="JDBC"：设置当前环境的事务管理都必须手动处理
                    type="MANAGED"：设置事务被管理，例如spring中的AOP
                -->
                <transactionManager type="JDBC"/>
                <!--
                dataSource：设置数据源
                属性：
                    type：设置数据源的类型，type="POOLED|UNPOOLED|JNDI"
                    type="POOLED"：使用数据库连接池，即会将创建的连接进行缓存，下次使用可以从缓存中直接获取，不需要重新创建
                    type="UNPOOLED"：不使用数据库连接池，即每次使用连接都需要重新创建
                    type="JNDI"：调用上下文中的数据源
                -->
                <dataSource type="POOLED">
                    <!--设置驱动类的全类名-->
                    <property name="driver" value="${jdbc.driver}"/>
                    <!--设置连接数据库的连接地址-->
                    <property name="url" value="${jdbc.url}"/>
                    <!--设置连接数据库的用户名-->
                    <property name="username" value="${jdbc.username}"/>
                    <!--设置连接数据库的密码-->
                    <property name="password" value="${jdbc.password}"/>
                </dataSource>
            </environment>
        </environments>
        <!--引入映射文件-->
        <mappers>
            <!-- <mapper resource="UserMapper.xml"/> -->
            <!--
            以包为单位，将包下所有的映射文件引入核心配置文件
            注意：
                1. 此方式必须保证mapper接口和mapper映射文件必须在相同的包下
                2. mapper接口要和mapper映射文件的名字一致
            -->
            <package name="com.atguigu.mybatis.mapper"/>
        </mappers>
    </configuration>
```

>注意：jdbc:mysql://localhost:3306/mybatis?
serverTimezone=UTC&amp;useSSL=false&amp;useUnicode=true&amp;characterEncoding=utf8在properties文件中写为:url=jdbc:mysql://localhost:3306/mybatis
?serverTimezone=UTC&useSSL=false&useUnicode=true&characterEncoding=utf8

## 4.用MyBatis进行CRUD测试

```UserTest.java
    import com.mapper.UserMapper;
    import com.pojo.User;
    import com.utils.SqlSessionFactoryUtil;
    import org.apache.ibatis.session.SqlSession;
    import org.junit.Test;

    import java.util.List;

    public class UserTest {
        @Test
        public void testInsert() {
            //从工具方法中获取 SqlSession
            SqlSession sqlSession = SqlSessionFactoryUtil.getSqlSession();
            //获取接口对象
            UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
            //测试功能
            int result = userMapper.insertUser();
            sqlSession.commit();
            System.out.println("result:"+result);
            sqlSession.close();
        }
        @Test
        public void testUpdate(){
            //从工具方法中获取 SqlSession
            SqlSession sqlSession = SqlSessionFactoryUtil.getSqlSession();
            //获取接口对象
            UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
            //测试功能
            userMapper.updateUser();
            sqlSession.commit();
            sqlSession.close();
        }
        @Test
        public void testDelete(){
            //从工具方法中获取 SqlSession
            SqlSession sqlSession = SqlSessionFactoryUtil.getSqlSession();
            //获取接口对象
            UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
            //测试功能
            userMapper.deleteUser();
            sqlSession.commit();
            sqlSession.close();
        }
        @Test
        public void testSelect(){
            //从工具方法中获取 SqlSession
            SqlSession sqlSession = SqlSessionFactoryUtil.getSqlSession();
            //获取接口对象
            UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
            //测试功能
            User user = userMapper.selectUserById();
            System.out.println(user);
            sqlSession.commit();
            sqlSession.close();
        }
        @Test
        public void testSelectAll(){
            //从工具方法中获取 SqlSession
            SqlSession sqlSession = SqlSessionFactoryUtil.getSqlSession();
            //获取接口对象
            UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
            //测试功能
            List<User> users = userMapper.selectUserAll();
            for (User user:users){
                System.out.println(user);
            }
            sqlSession.commit();
            sqlSession.close();
        }
    }

```

```UserMapper.xml
    <!DOCTYPE mapper PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
    <mapper namespace="com.mapper.UserMapper">
        <insert id="insertUser">
            insert into t_user values (3,'admin3','123456',23,'男','12345@qq.com')
        </insert>
        <update id="updateUser">
            update t_user set name = '张三' where id = '2'
        </update>
        <delete id="deleteUser">
            delete from t_user where id = '3'
        </delete>
        <select id="selectUserById" resultType="User">
            select * from t_user where id = '2'
        </select>
        <select id="selectUserAll" resultType="User">
            select * from t_user
        </select>
    </mapper>

```

## 5.MyBatis获取参数值的两种方式(重点)

> https://blog.csdn.net/baiqi123456/article/details/123750259

* MyBatis获取参数值的两种方式：${}和#{}
  ${}本质是字符串拼接
  #{}本质是占位符赋值
* MyBatis获取参数值的各种情况:
    1. mapper接口方法的参数为单个的字面量案例
        可以通过${}和#{}以任意的字符串获取参数值，但是需要注意${}的单引号问题
    2. mapper接口方法的参数为多个时
        此时MyBatis会将这些参数放在一个map集合中，以两种方式进行存储
        a>以agr0，arg1...为键，以参数为值
        b>以param1，param2...为键，以参数为值
        c>两者混用
        因此只需要通过#{}和${}以键的方式访问值即可，但是需要注意${}的单引号问题
    3. 若mapper接口的方法的参数有多个时,可以手动将这些参数放在一个map中存储
    4. 若mapper接口的方法的参数是实体类类型的参数时
    5.使用@Param注解命名参数
        此时MyBatis会将这些参数放在一个map集合中，以两种方式进行存储
        a>以@Param为键,以参数为值
        b>以param1，param2...为键，以参数为值
