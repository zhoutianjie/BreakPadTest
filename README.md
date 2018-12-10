# BreakPadTest
Android BreakPad debug

### BreakPad Android平台的应用
谷歌开源的BreakPad是获取native crash 比较不错的框架。这里面是一个BreakPad的native封装。
你可以直接用项目里面生成的libbreakpad.so,注意初始化的时候BreakPad这个类的包名不能搞错。

或者你也可以直接修改我的CmakeList.txt文件以及对应的breakpad.cpp,来修改包名，定义自己的工具类
