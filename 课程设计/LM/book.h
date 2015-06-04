#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
 typedef struct Book
 {
     double ISBN;              //ISBN code,13位数字
     char name[20];          //name,author,publiser使用字符指针是指向同一个地址？？
     char author[20];
     char publisher[20];
     int  release_date[4]; //month-date-year
     double price;
 }Book;
    void make_book(Book &b);
#endif // BOOK_H_INCLUDED
