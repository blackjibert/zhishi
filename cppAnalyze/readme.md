### C++中类成员的访问权限
#### Public
- 使用public标签指定的成员可以被任何访问该类对象的代码访问。
- 公开成员定义了类的外部接口。
#### Protected
- 使用protected标签指定的成员只能被以下几种代码访问：
- 类本身内部的成员函数。
- 继承自该类的派生类中的成员函数。
- 保护成员通常用于在基类和派生类之间共享数据或行为，同时对类的其他使用者隐藏这些细节。
#### Private:
- 使用private标签指定的成员只能被类本身内部的成员函数（以及其友元）访问。
- 私有成员是实现类内部封装的关键，防止了对类实现细节的外部访问。


### 工厂模式
- 鞋厂可以指定生产耐克、阿迪达斯和李宁牌子的鞋子。哪个鞋炒的火爆，老板就生产哪个，看形势生产。
- 1. 工厂类：工厂模式的核心类，会定义一个用于创建指定的具体实例对象的接口。
- 2. 抽象产品类：是具体产品类的继承的父类或实现的接口。
- 3. 具体产品类：工厂类所创建的对象就是此具体产品实例。

### 智能指针
#### std::shared_ptr
#### shared_ptr 的初始化
- 共享智能指针是指多个智能指针可以同时管理同一块有效的内存，共享智能指针 shared_ptr 是一个模板类，如果要进行初始化有三种方式：通过构造函数、std::make_shared 辅助函数以及 reset 方法。共享智能指针对象初始化完毕之后就指向了要管理的那块堆内存，如果想要查看当前有多少个智能指针同时管理着这块内存可以使用共享智能指针提供的一个成员函数 use_count，函数原型如下：
```
// shared_ptr<T> 类模板中，提供了多种实用的构造函数, 语法格式如下:
std::shared_ptr<T> 智能指针名字(创建堆内存);

 // 使用智能指针管理一块 int 型的堆内存
 shared_ptr<int> ptr1(new int(520));
 ```
- 通过拷贝和移动构造函数初始化
 ```
// 使用智能指针管理一块 int 型的堆内存, 内部引用计数为 1
shared_ptr<int> ptr1(new int(520));
cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;
//调用拷贝构造函数
shared_ptr<int> ptr2(ptr1);


//调用移动构造函数
shared_ptr<int> ptr4(std::move(ptr1));
 ```

- 通过 std::make_shared 初始化
```
shared_ptr<int> ptr1 = make_shared<int>(520);
```

#### std::unique_ptr
- std::unique_ptr 是一个独占型的智能指针，它不允许其他的智能指针共享其内部的指针，可以通过它的构造函数初始化一个独占智能指针对象，但是不允许通过赋值将一个 unique_ptr 赋值给另一个 unique_ptr。
```
// 通过构造函数初始化对象
unique_ptr<int> ptr1(new int(10));
// error, 不允许将一个unique_ptr赋值给另一个unique_ptr
unique_ptr<int> ptr2 = ptr1;

std::unique_ptr 不允许复制，但是可以通过函数返回给其他的 std::unique_ptr，还可以通过 std::move 来转译给其他的 std::unique_ptr，这样原始指针的所有权就被转移了，这个原始指针还是被独占的。

// 通过转移所有权的方式初始化
unique_ptr<int> ptr2 = move(ptr1);
```