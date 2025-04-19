package com.example.Dao;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import com.example.entity.Book;

import java.util.Arrays;
import java.util.List;

@Repository
public class BookDaoImpl implements BookDao {
    //注入jdbcTemplate
    @Autowired
    private JdbcTemplate jdbcTemplate;
    //添加
    @Override
    public void add(Book book) {
        System.out.println("添加书本");
        //1 创建sql语句
        String sql = "insert into t_book values(?,?,?)";
        //2 调用方法实现
        Object[] args = {book.getUserID(),book.getUserName(),book.getUStatus()};
        int update = jdbcTemplate.update(sql,args);
        System.out.println(update);
    }
    //修改
    @Override
    public void updateBook(Book book) {
        String sql = "update t_book set userName=?,uStatus=? where userID=?";
        Object[] args = {book.getUserName(),book.getUStatus(),book.getUserID()};
        int update = jdbcTemplate.update(sql,args);
        System.out.println(update);
    }
    //删除
    @Override
    public void delete(String bookID) {
        String sql = "delete from t_book where userID=?";
        int update = jdbcTemplate.update(sql,bookID);
        System.out.println(update);
    }

    @Override
    public int selectCount() {
        String sql = "select count(*) from t_book";
        int count = jdbcTemplate.queryForObject(sql,Integer.class);
        return count;
    }

    @Override
    public Book findBookInfo(String bookID) {
        String sql = "select * from t_book where userID=?";
        Book book = jdbcTemplate.queryForObject(sql,new BeanPropertyRowMapper<Book>(Book.class),bookID);
        return book;
    }

    @Override
    public List<Book> findAllBook() {
        String sql = "select * from t_book";
        //调用方法
        List<Book> bookList = jdbcTemplate.query(sql,new BeanPropertyRowMapper<Book>(Book.class));
        return bookList;
    }

    @Override
    public void batchAddBook(List<Object[]> batchArgs) {
        String sql = "insert into t_book values(?,?,?)";
        int[] ints = jdbcTemplate.batchUpdate(sql,batchArgs);
        System.out.println(Arrays.toString(ints));
    }

    @Override
    public void batchUpdateBook(List<Object[]> batchArgs) {
        String sql = "update t_book set userName=?,uStatus=? where userID=?";
        int[] ints = jdbcTemplate.batchUpdate(sql,batchArgs);
        System.out.println(Arrays.toString(ints));
    }

    @Override
    public void batchDeleteBook(List<Object[]> batchArgs) {
        String sql = "delete from t_book where userID=?";
        int[] ints = jdbcTemplate.batchUpdate(sql,batchArgs);
        System.out.println(Arrays.toString(ints));
    }
}
