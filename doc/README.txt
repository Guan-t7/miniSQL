包内有 master 和 noindex 两个分支的代码：
    noindex 分支成功通过了期末验收，能够正确运行;
    原计划在 master 分支完成 index 相关功能，并最后合并,
        但截至上交时，负责 IndexManager(IM) 的同学仍未能完成 IM, 
        master 的代码是半成品，但可以从中看出其他模块为调用 IM 接口做的准备工作。

注意：VS解决方案文件是 SimpleSQLInterpreter.sln，项目为 SimpleSQLInterpreter
您需要修改项目选项：
    C/C++ 常规 附加包含目录，以包含 \ 和 \include\antlr4-runtime
    链接器 附加库目录，以链接附带的 .lib 文件
您可能还需要修改
    常规 平台工具集
    常规 Windows SDK版本
