# MyBatis学习

## MyBatis简介

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

## 搭建 MyBatis

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

