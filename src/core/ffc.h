#ifndef FFC_H
#define FFC_H
#include <iostream>
#include <cstdlib>



namespace ffc
{
/**
 *  ffc::cfp 全称 function for chack :: chack for ptr
 *  @param ptr 指针
 *  @return 如果 ptr 非空，则返回 ptr 本身，否则程序退出。
 */ 
template<typename T>
T* cfp(T* ptr);

/**
 *  ffc::cfb 全称 function for chack :: chack for bool
 *  @param flag 传入 true
 *  @note WHY inline can solve MSVC(error LNK2005)
 */ 
inline void cfb(bool flag);

}



#ifdef FCP_IMPLEMENTATION

namespace ffc {
template<typename T>
T* cfp(T* ptr)
{
    if (ptr == nullptr) {
        std::cout << "FCP Received nullptr!\n";
        exit(-1);
    }
    return ptr;
}
inline void cfb(bool flag)
{
    if (!flag) {
        std::cout << "FCP Received nullptr!\n";
        std::exit(-1);
    }
}



}

#endif // FFC_IMPLEMENTATION

#endif // FFC_H