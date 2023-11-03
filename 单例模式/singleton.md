[知乎文章](https://zhuanlan.zhihu.com/p/37469260)
[lightcity](https://github.com/Light-City/CPlusPlusThings/tree/master/design_pattern/singleton)

> 单例模式（Singleton），保证一个类仅有一个实例，并提供一个访问它的全局访问点。
单例模式的实现分为两大类，懒汉模式和饿汉模式。懒汉模式的单例秉承着实例能晚一点构造就晚一点构造的思想，直到第一次使用单例时才构造单例；饿汉模式则恰好相反，即使实例永远不会被使用，实例的构造还是会早早的发生。


## C++中static对象的初始化
　　- C++规定，non-local static 对象的初始化发生在main函数执行之前。但C++没有规定多个non-local static 对象的初始化顺序，尤其是来自多个编译单元的non-local static对象，他们的初始化顺序是随机的。

　　- 然而，对于local static 对象，其初始化发生在控制流第一次执行到该对象的初始化语句时。 **`non-local static对象的初始化发生在main函数之前的单线程启动阶段，所以无需担心线程安全问题 `**。但是local static对象则不同，多个线程的控制流可能同时到达其初始化语句。

　　- 在C++11之前，在多线程环境下local static对象的初始化并不是线程安全的。具体表现就是：如果一个线程正在执行local static对象的初始化语句但还没有完成初始化，此时若其它线程也执行到该语句，那么这个线程会认为自己是第一次执行该语句并进入该local static对象的构造函数中。这会造成这个**local static对象的重复构造，进而产生内存泄露问题。**

　　- 为了**解决local static对象在多线程环境下的重复构造问题**。C++11在语言的规范中解决了这个问题。C++11规定，在一个线程开始local static 对象的初始化后完成初始化前，其他线程执行到这个local static对象的初始化语句就会等待，直到该local static 对象初始化完成。

