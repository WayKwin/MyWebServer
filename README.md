# 自主Web服务器
## 主体框架  
![这里本来是一张图片,看到文字表明GitHub的网对国内环境太不友好了!](https://github.com/WayKwin/MyWebServer/blob/master/picture/%E6%9C%8D%E5%8A%A1%E5%99%A8%E6%A1%86%E6%9E%B6.png)  


- [我把服务器挂在阿里云上了,网页点这里](http://waykwin.xin:8080/)
## 开发环境 
  - Linux,VIM,CGDB,CLANG++
## 实现细节
  - 主线程使用epoll监听listen套接字
  - 加快并发,使用线程池来处理到来的Http请求 
## 实现功能
  - 回应浏览器请求的资源
  - 支持POST和GET方法
  - 判断是否是长连接(Keep-Alive)
  - CGI
    - 写了一个提交表单插入数据库的玩具Demo
    - 支持Shell,PHP,Python脚本
## 扩展
  - 发现只要实现简单的GET和POST方法,就可以在前端挂载一些网页了
  - 虽然不懂前端,但是还是鼓捣出了一些小工具,实现了进制转换,二维码生成和日期计算,看上去不错!
  - 把这个服务器变成守护进程就挂载阿里云上了
## 压力测试 
### 部署环境 
    阿里云的乞丐服务器,1核2G内存1M带宽
###  测试工具 webbench
- 分别测试10,100,1000个客户端分别请求服务器10秒
结果如下:
- 10个客户端  

10 clients, running 10 sec.
Speed=3024 pages/min, 61055 bytes/sec.
Requests: 504 susceed, 0 failed.
- 100个客户端  

100 clients, running 10 sec.
Speed=2364 pages/min, 47756 bytes/sec.
Requests: 394 susceed, 0 failed.

- 1000个客户端  

1000 clients, running 10 sec.
Speed=6216 pages/min, 125738 bytes/sec.
Requests: 1036 susceed, 0 failed.
## 一些小发现
## 在http发送请求等待响应时,服务器对回应的处理
1. 子线程使用epollctl 将socket添加写事件,然后主线程epoll_wait监测到写事件就绪去写回应
2. 直接在子线程中调用write函数进行写写回应 
  虽然epoll事件成立是通过回调函数进行的O(1)返回;但是在实际中第1中方案比第2中方案要慢得多(第2中方案浏览器秒开网页,第1中要等上1秒以上)
## 一点小反思 
  - 使用事件队列将读取IO和事件处理完全解耦合
  - 虽然使用线程池来处理Http请求,但是这是一个典型的生产消费者模型.在请求队列中取出事件和放入事件都需要加锁(效率偏低)
  - 必须保证Http请求是无状态的,因为同一个Http请求可能由不同的线程来处理(我认为可以通过线程ID取模的方式指定线程??)
  - 进行回应浏览器请求(写事件),是由主线程统一处理,多个事件同时就绪,还是主线程排队一个一个回应
  - 一种更好的解决方案 使用半同步-半异步方式 主线程只负责监听socket,然后向特定的子线程派发文件描述符,每个子线程自己维护一个EPOLL 
## TODO
- Fix Bug
    - 条件编译无法正常工作 ✔(问题是makefile中的依赖写错)
    - 一个bool函数一个逻辑没有返回值,导致出现非法指令的错误 ✔ (调试最久)
    - 打印日志函数无法正常工作( 似乎是double free的问题 ) ✔ 日志换成了glog
    -  HTTP中文乱码 ✔(html response头部的content-type指定 utf-8不管用,需要在html文档的头部指定)
    - CGI中数据库连接失败 ✔
- 逻辑实现
  - CGI✔
    - 添加判断执行脚本的函数✔
    - 支持更多脚本✔
    - 使用域间套接字父子进程交流,子进程stdin没有重定向✔
- 考虑实现delete方法(似乎没有必要)

