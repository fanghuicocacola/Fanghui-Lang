package com.example.Dao;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.example.entity.Book;

import java.util.List;

@Service
public class BookService {
    //注入dao
    @Autowired
    private BookDao bookDao;
    public void addBook(Book book){
        bookDao.add(book);
    }

    public void updateBook(Book book){
        bookDao.updateBook(book);
    }
    public void deleteBook(String bookID){
        bookDao.delete(bookID);
    }
    //查询表中记录数
    public int findCount(){
        return bookDao.selectCount();
    }

    //查询返回对象
    public Book findOne(String BookID){
        return bookDao.findBookInfo(BookID);
    }

    //查询返回集合
    public List<Book> finAll(){
        return  bookDao.findAllBook();
    }

    //批量操作-添加
    public void batchAdd(List<Object[]> batchArgs){
        bookDao.batchAddBook(batchArgs);
    }

    //批量操作-修改
    public void batchUpdate(List<Object[]> batchArgs){
        bookDao.batchUpdateBook(batchArgs);
    }

    //批量操作-删除
    public void batchDelete(List<Object[]> batchArgs){
        bookDao.batchDeleteBook(batchArgs);
    }
}
