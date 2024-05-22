    #ifndef BOOK_H
    #define BOOK_H

    #include <string>

    class book
    {
    private:
    std::string m_title;
    std::string m_author;
    int m_ID;

    public:
    std::string get_title() const ;
    std::string get_author() const;
    int get_ID() const;
    
    void set_title(std::string title);
    void set_author(std::string author);
    void set_ID(int ID);
    };

    #endif //BOOK_H