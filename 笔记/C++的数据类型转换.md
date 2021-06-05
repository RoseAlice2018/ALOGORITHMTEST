# C++的新型数据类型转换
## const_cast
- const_cast主要用于解除常指针和常量的const和volatile属性，也就是说，把const type* 转换成为type* 类型或将const type& 转换为type&类型。但是需要注意的是，如果一个变量本身被定义为只读变量，那么它永远都是常变量。const_cast 取消的是对间接引用时的改写限制（只针对指针或者引用），而不能改变变量本身的const属性。

## static_cast
## dynamic_cast
## reinterpret_cast