# 自主Web服务器
## 主体框架  
![主体框架](https://github.com/WayKwin/MyWebServer/blob/master/picture/%E6%9C%8D%E5%8A%A1%E5%99%A8%E6%A1%86%E6%9E%B6.png)
## 一些小发现
## 在http发送请求等待响应时,服务器对回应的处理
    1. 子线程使用epollctl 将socket添加写事件,然后主线程epoll_wait监测到写事件就绪去写回应
    2. 直接在子线程中调用write函数进行写写回应 
  虽然epoll事件成立是通过回调函数进行的O(1)返回;但是在实际中第1中方案比第2中方案要慢得多(第2中方案浏览器秒开网页,第1中要等上1秒以上)
## TODO
- fix Bug
    - 条件编译无法正常工作 ✔(问题是makefile中的依赖写错)
    - 一个bool函数一个逻辑没有返回值,导致出现非法指令的错误✔(调试最久)
    - 打印日志函数无法正常工作( 似乎是double free的问题 ) 
    -  HTTP中文乱码
    - 数据库连接失败
- 逻辑实现
  - cgi✔
    - 添加判断执行脚本的函数✔
    - 支持更多脚本✔
    - 使用域间套接字父子进程交流,子进程stdin没有重定向✔

