## proto
### proto基础知识
#### proto数据类型
![Alt text](pic/image1.png)
#### ProtoBuf 使用一般步骤
- 第一步：定义 proto 文件，文件的内容就是定义我们需要存储或者传输的数据结构，也就是定义我们自己的数据存储或者传输的协议。
- 第二步：使用 ProtoBuf 编译器 protoc 来编译自定义的 proto 文件，用于生成 .pb.h 文件（proto 文件中自定义类的头文件）和 .pb.cc（proto文件中自定义类的实现文件）。
- 第三步：使用 ProtoBuf 的 C++ API 来读写消息。
#### 定义proto文件
- test.proto
```
syntax = "proto3";
package monitor.proto;

message CpuLoad {
    float load_avg_1 = 1;
    float load_avg_3 = 2;
    float load_avg_15 = 3;
  }
  
message NetInfo {
    string name = 1;
    float send_rate = 2;
  }
  
 message MonitorInfo{
  CpuLoad cpu_load = 1; #std::string
  repeated NetInfo net_info = 2; # std::vector
}
```