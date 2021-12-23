<div align=center>
<img src="/doc/image/logo.png"/>
</div>

## LibDriver HCSR04

[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md)

HCSR04超声波测距模块可提供 2cm-400cm的非接触式距离感测功能，测距精度可达高到 3mm。模块包括超声波发射器、接收器与控制电路。

LibDriver HCSR04是LibDriver推出的HCSR04全功能驱动，该驱动提供超声波测距的功能。

### 目录

  - [说明](#说明)
  - [安装](#安装)
  - [使用](#使用)
    - [example basic](#example-basic)
  - [文档](#文档)
  - [贡献](#贡献)
  - [版权](#版权)
  - [联系我们](#联系我们)

### 说明

/src目录包含了LibDriver HCSR04的源文件。

/interface目录包含了LibDriver HCSR04与平台无关的gpio模板。

/test目录包含了LibDriver HCSR04驱动测试程序，该程序可以简单的测试芯片必要功能。

/example目录包含了LibDriver HCSR04编程范例。

/doc目录包含了LibDriver HCSR04离线文档。

/datasheet目录包含了HCSR04数据手册。

/project目录包含了常用Linux与单片机开发板的工程样例。所有工程均采用shell脚本作为调试方法，详细内容可参考每个工程里面的README.md。

### 安装

参考/interface目录下与平台无关的gpio模板，完成指定平台的gpio驱动。

将/src目录，/interface目录和/example目录加入工程。

### 使用

#### example basic

```C
uint8_t res;
uint8_t i;
float m;

res = hcsr04_basic_init();
if (res)
{
    return 1;
}

...
    
for (i = 0; i < 3; i++)
{
    res = hcsr04_basic_read((float *)&m);
    if (res)
    {
        hcsr04_basic_deinit();

        return 1;
    }
    hcsr04_interface_delay_ms(1000);
    hcsr04_interface_debug_print("hcsr04: distance is %0.4fm.\n", m);
    
    ...
    
}

...

hcsr04_basic_deinit();

return 0;
```

### 文档

在线文档: https://www.libdriver.com/docs/hcsr04/index.html

离线文档: /doc/html/index.html

### 贡献

请联系lishifenging@outlook.com

### 版权

版权 (c) 2015 - 现在 LibDriver 版权所有

MIT 许可证（MIT）

特此免费授予任何获得本软件副本和相关文档文件（下称“软件”）的人不受限制地处置该软件的权利，包括不受限制地使用、复制、修改、合并、发布、分发、转授许可和/或出售该软件副本，以及再授权被配发了本软件的人如上的权利，须在下列条件下：

上述版权声明和本许可声明应包含在该软件的所有副本或实质成分中。

本软件是“如此”提供的，没有任何形式的明示或暗示的保证，包括但不限于对适销性、特定用途的适用性和不侵权的保证。在任何情况下，作者或版权持有人都不对任何索赔、损害或其他责任负责，无论这些追责来自合同、侵权或其它行为中，还是产生于、源于或有关于本软件以及本软件的使用或其它处置。

### 联系我们

请联系lishifenging@outlook.com