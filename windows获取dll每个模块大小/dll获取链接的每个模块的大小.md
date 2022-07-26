对比测试

将使用到的库代码注释掉，进行编译，再进行前后对比。

问题：

- 效率比较低，而且在增加调用方法后，其实链接进入的库的代码会变大。

通过pdb解析获取

问题：

- 没有pdb就会导致获取不准确。

通过vs编译时的map文件计算获取

MAP 文件是程序的全局符号、[源文件](https://baike.baidu.com/item/源文件)和代码行号信息的唯一的文本表示方法，它可以在任何地方、任何时候使用，不需要有额外的程序进行支持。

map文件结构：

 Start                         Length     Name                   Class
 0001:00000000 00000d18H .text$mn               CODE
 0002:00000000 00000068H .idata$5                 DATA
 0002:00000068 00000004H .00cfg                     DATA
 0002:0000006c 00000004H .CRT$XCA               DATA
 0002:00000070 00000004H .CRT$XCZ               DATA
 0002:00000074 00000004H .CRT$XIA                DATA
 0002:00000078 00000004H .CRT$XIZ                DATA
 0002:0000007c 00000004H .CRT$XPA               DATA
 0002:00000080 00000004H .CRT$XPZ               DATA
 0002:00000084 00000004H .CRT$XTA               DATA
 0002:00000088 00000008H .CRT$XTZ               DATA
 0002:0000008c 00000000H .gfids$y                   DATA
 0002:00000090 00000570H .rdata                      DATA

**Start**  段号 : 段内偏移

**Length** 自然就是这个section的长度。

**Name** 段的名字 

**Class** 段的类型（数据段 代码段）



 Address                   Publics by Value              Rva+Base       Lib:Object

 0001:00000000       ?InitMediaSDK@@YGPADPAH@Z  10001000 f   map_test.obj
 0001:00000015       @__security_check_cookie@4 10001015 f   MSVCRT:secchk.obj
 0001:00000363       __DllMainCRTStartup@12     10001363 f   MSVCRT:dll_dllmain.obj
 0001:00000386       ___raise_securityfailure   10001386 f   MSVCRT:gs_report.obj
 0001:000003ae       ___report_gsfailure        100013ae f   MSVCRT:gs_report.obj
 0001:000004f5       ___security_init_cookie    100014f5 f   MSVCRT:gs_support.obj
 0001:00000540       _DllMain@12                10001540 f   MSVCRT:dll_dllmain_stub.obj
 0001:00000562       ?__scrt_initialize_type_info@@YAXXZ 10001562 f   MSVCRT:tncleanup.obj
 0001:0000056e       ?__scrt_uninitialize_type_info@@YAXXZ 1000156e f   MSVCRT:tncleanup.obj

**Address**  *segment:offset*  段号 : 段内偏移

**Publics by Value** 修饰过的符号名称，也就是函数，变量名

**Rva+Base** *RVA is the Relative Virtual Address*（相对虚拟地址）. *Base is the Preferred Load Address*（最佳加载地址）

**Lib:Object** 模块名称:文件名



计算方法

相同的段segment，后面的offset减去前面的offset，就能得到该符号名称占用的存储空间大小；然后根据lib:object就能算出每一个文件和每一个模块具体占用了多的存储空间。



开启生成map文件：

![vs_map_option](.\resource\vs_map_option.png)



自制计算工具vsmap_analysis_tool

![vsmap_analysis_tool](.\resource\vsmap_analysis_tool.png)

- map_analyze_1 map_analyze_2可以选择vs生成的map文件。

- LibLength获取对应模块的占用大小。
- FileLength获取每个文件占用的大小。
- Undname将修饰过的符号名称转成没有修饰的。
- SaveFuncToXlsx将每个符号名称占用的大小保存到excel文件。
- SaveToXlsx将每个模块大小保存到excel文件。

生成的excel文件

![xlsx_lib_length](.\resource\xlsx_lib_length.png)

Gcc也可以生成类似的map文件，分析方式也是类似。