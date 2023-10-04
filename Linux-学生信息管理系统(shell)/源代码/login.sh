#!/bin/bash
echo
echo  -e "\t\t\t \e[1;34m   欢迎进入学生管理系统  \e[0m"
echo  -e "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\e[1;36m 按Enter键进入学生管理系统\e[0m"
read     
clear
i=0
while ((i!=1))
do
read -p "请输入你的用户名 " username
read -s -p "请输入你的密码 " password
echo "  "
if [ $username = 'admin' ]
then
	if [ $password = 'admin' ]
	then
		echo "欢迎登录"
		i=1
	else
		echo '密码不正确，请重新输入'
	fi
else
	echo '用户名不正确，重新输入'
fi
done
bash main.sh  
