/*
 * Filename singleton.cc
 * CreateTime 2019-03-03 11:50:50
 * author zhzcsp@gmail.com
 */


#include <iostream>

class Singleton {
private:
    Singleton() {};
    ~Singleton() {};
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton&);

public:
    static Singleton& getInstance()
    {
    	static Singleton instance();
	return instance;
    }

};


//NOTES:
//静态成员/静态成员函数不属于任何一个特定的实例化对象，所以不存在隐含的this指针
//
//静态成员函数常用来操作静态成员
//

