#!/bin/bash
echo  -e "\t\t\t \e[1;34m   欢迎进入学生信息管理系统  \e[0m"
echo  -e "\n\n\n"
echo  -e  "\t\t\t\e[1;29m| 1.添加成绩"
echo  -e  "\t\t\t\e[1;29m| 2.删除成绩"
echo  -e  "\t\t\t\e[1;29m| 3.成绩列表"
echo  -e  "\t\t\t\e[1;29m| 4.查找成绩"
echo  -e  "\t\t\t\e[1;29m| 5.成绩统计"
echo  -e  "\t\t\t\e[1;29m| 6.返回上级"
echo  -e  "\t\t\t\e[1;29m| q.退出系统"
read  -p  "请选择：" choice
case $choice in
	1)
		echo  -e  " \t\t添加成绩"
		bash add_grade.sh	
			;;
	2)
		echo  -e  " \t\t删除成绩"
		bash del_grade.sh	
			;;
	3)
		echo  -e  " \t\t成绩列表"
		bash display_grade.sh	
			;;
	4)
		echo  -e  " \t\t查找成绩"
		bash search_grade.sh
			;;
	5)
		echo  -e  " \t\t成绩统计"
		bash sum_grade.sh	
			;;
	6)
		echo  -e  " \t\t返回上级页面"
		bash main.sh
			;;
	q)
		echo  -e  " \t\t退出系统"
		bash quit_saybaby.sh   	
			;;
	*)
		bash main_grade.sh
			;;
	esac
bash main_grade.sh
