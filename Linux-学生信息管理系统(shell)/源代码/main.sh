#!/bin/bash


echo  -e "\t\t\t \e[1;34m   欢迎进入学生管理系统  \e[0m"
echo  -e "\n\n\n"
echo  -e  "\t\t\t\e[1;29m| 1.学工系统"
echo  -e  "\t\t\t| 2.教务系统"
echo  -e  "\t\t\t\e[1;29m| q.返回退出\e[0m"
echo  -e  "\e[1;31m----------------------\e[0m"
read  -p  "请选择：" choice

case $choice in
	1)
		bash main_information.sh	
		;;
	2)

		bash main_grade.sh
		;;
	q)
		clear
		bash quit.sh   	
		;;
	*)
		bash mian.sh
		;;
esac

