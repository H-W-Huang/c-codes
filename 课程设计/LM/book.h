#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
 typedef struct Book
 {
     double ISBN;              //ISBN code,13λ����
     char name[20];          //name,author,publiserʹ���ַ�ָ����ָ��ͬһ����ַ����
     char author[20];
     char publisher[20];
     int  release_date[4]; //month-date-year
     double price;
 }Book;
    void make_book(Book &b);
#endif // BOOK_H_INCLUDED
