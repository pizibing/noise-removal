This will be added later!
# Noise Removal #

## 问题描述 ##
在生成的Morse-Smale Complex中有许多噪声点存在，需要对这些噪声点进行移除使得连线后
生成的四边形质量尽可能好。

## 算法描述 ##
you can find it on [Algorithm](WikiSyntax.md).

## 进程安排 ##

> <table align='center' border='1'>
<blockquote><tr>
<th> <font color='blue' size='3'> 任务安排 </font></th>
<th> <font color='red' size='3'>  Deadline  </font></th>
<th> <font color='green' size='3'> 困难 </font></th>
<th> <font color='black' size='3'> 完成情况 </font> </th>
</tr>
<tr>
<td align='center'> version 1，可以将现有几个mesh模型的bad-chart控制在20个以下</td>
<td align='center'> 03/04/2010 </td>
<td align='center'> 有两种情况比较难于处理 -- 1:拓扑正确，连线错误; 2: 拓扑错误</td>
<td align='center'> 已完成 </td>
</tr>
<tr>
<td align='center'>完成对拓扑正确，连线错误这种情况的修改</td>
<td align='center'> 03/07/2010 </td>
<td align='center'> 如何判断拓扑是否正确</td>
<td align='center'>已完成，bad-chart控制在10个以下</td>
</tr>
<tr>
<td align='center'>采用理论上更好的一种算法测试结果</td>
<td align='center'> 03/10/2010 </td>
<td align='center'> </td>
</tr>
<tr>
<td align='center'>完成对拓扑错误情况的修改，将bad-chart控制在5个以下</td>
<td align='center'> 03/13/2010</td>
<td align='center'> </td>
</tr>
<tr>
<td align='center'> 寻找更多的模型，测试结果</td>
<td align='center'> </td>
<td align='center'> </td>
</tr>
<tr>
<td align='center'> 将程序从MFC移植到QT</td>
<td align='center'> </td>
<td align='center'> </td>
<td align='center'> 完成部分工作 </td>
</tr>
</table>