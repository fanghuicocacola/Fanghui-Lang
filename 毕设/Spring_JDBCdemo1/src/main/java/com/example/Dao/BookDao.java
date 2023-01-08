package com.example.Dao;


import com.example.entity.Book;

import java.util.List;

public interface BookDao {
    void add(Book book);
    void updateBook(Book book);
    void delete(String bookID);
    int selectCount();
    Book findBookInfo(String bookID);

    List<Book> findAllBook();

    void batchAddBook(List<Object[]> batchArgs);

    void batchUpdateBook(List<Object[]> batchArgs);

    void batchDeleteBook(List<Object[]> batchArgs);
}
