﻿// map_test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

static int g_global_int = 1;
//static const char g_global_char[1024] = "hello world!\n";
static const char g_global_char[1024] =
    "hello world!=============================================================="
    "==========================================================================================================="
"=============================================================================="
"============================="
"=============================================================================="
"=============\n";

int dllmain() { 
	std::cout << g_global_char; 
	//std::cout << g_local_char; 
	return 0;
}

__declspec(dllexport) char* __stdcall InitMediaSDK(int* log_config){
  g_global_int = 2;
  char ret[1024] = "";
  memcpy(ret, g_global_char, sizeof(g_global_char));
  return ret;
};

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
