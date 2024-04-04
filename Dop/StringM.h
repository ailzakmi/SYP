#ifndef CPP_LABS_STRINGM_H
#define CPP_LABS_STRINGM_H


class StringM {
    char *str = new char[80];

public:
    StringM(char *other);

    StringM();

    StringM(const StringM &other);

    StringM(int size);

    ~StringM();

    StringM &operator=(const StringM &other);

    StringM &operator+(const StringM &other);

    int operator==(const StringM &other);

    int length();

    void input();

    void output();

    //ЛР 8
    friend std::istream &operator>>(std::istream &is, StringM &str);

    friend std::ostream &operator<<(std::ostream &os, StringM &str);
};


#endif //CPP_LABS_STRINGM_H
