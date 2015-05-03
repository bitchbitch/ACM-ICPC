#!/bin/bash
# Author: cijianzy
# Created Time: 2015年05月03日 星期日 17时49分55秒
#/user/bin/sh
cat /dev/null > infoma         #清空infoma
types=("*.asm" "*.s" "*.c" "*.cpp" "*.h" "*.cs" "*.java")   #所有要统计的文件类型
for i in ${types[@]}         #遍历每个文件类型
do
    find . -iname $i > tmp    #按类型（大小写不敏感）查找，缓存到tmp
    cat tmp >> infoma           #将查询结果追加到infoma
done
sed -i 's/ /\\&/g' infoma      #处理文件名出现空格的情况
cat infoma | xargs wc -l > tmp #统计行数，输出到文件
grep -rin "^[ ]*[1-9][0-9]*[ ]*总用量$" tmp > infoma    #提取行数信息
let sum=0                    #总行数
while read tag count flag    #取出每一批处理结果的行数
do
    let sum=sum+count         #累加行数
done < infoma                  #指定读取的文件
echo 总行数=$sum行            #显示最终总行数
rm infoma tmp                  #删除临时文件
