### 基本语法
1. **标题**
  #一级标题
  ##二级标题
  ...
2. **引用**
  >这是引用的一段话 
  >>可以嵌套
3. **列表**
    1. 无序列表
    - 列表一
    + 列表二
    * 列表三
    2. 有序列表
    3. 嵌套
    4. Todolist
       - [ ] a
       - [ ] b
       - [ ] c
4. **表格**
   | 左对齐 | 居中对齐 | 右对齐 |
   | :----- | :----: | ----: |
   | a | b | c |
5. **段落**  
   - 换行 —— 俩个以上空格后回车/空一行
   - 分割线 —— 三个*       
***                
   - 字体             
     | 字体 | 代码 |
     |:--:|:--:| 
     |*斜体*|* *|
     |==高亮==|== ==|
     |**粗体**|** **|
     |***粗斜体***|*** ***|
     |~~删除~~|~~ ~~|
     |<u>下划线</u>|```<u> </u>```|     

- 脚注  
  为什么脚注打不出来啊啊啊啊啊啊[^1]
6. **代码**
   ```
   #include<iostream>
   using namespace std;
   int main()
   {
    print("hello world");
   }
   ```
   `print(hello world");`
7. **超链接**
   - [更多使用教程可以参考网站]：https://www.runoob.com/markdown/md-link.html
   - 查看更多使用功能请[点击链接][教程]
8. **图片**
   - 使用图床保存图片并实现插入
    [路过图床]：https://imgse.com/
   - 使用markdown语法插入
   ![图片的替代文字]（图片的网址）
### 其他操作
- **插入latex公式**   
    - 行内显示公式：
    $f(x)=ax+b$
    - 块内显示数学公式：
    $$
    \begin{Bmatrix}
    a & b \\
    c & d 
    \end{Bmatrix}
    $$
- **html/css语法**
  - ctrl+shift+p 搜索“Markdown Preview Enhanced：Customize Css”在style中使用css语法改标题格式等
- **个性化设置**
  File-preference-Settings
### 导出为PDF文档
- 使用Markdown PDF（会出现排版混乱）
- open in Browser-手动另存为PDF文档
[教程]：https://www.runoob.com/markdown/md-link.html
[^1]:原来是因为没有做出解释，无语啦       
    
    
    
  