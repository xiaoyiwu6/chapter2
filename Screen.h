#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen move(pos r, pos c);
    void some_menber() const { ++access_ctr; }
    Screen set(char);
    Screen set(pos, pos, char);
    //根据对象是否是const重载了display函数
    Screen display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    // mutable var
    mutable size_t access_ctr = 0;
    //显示Screen的内容
    void do_display(std::ostream &os) const { os << contents; }
};

inline Screen Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

Screen Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
Screen Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}

#endif