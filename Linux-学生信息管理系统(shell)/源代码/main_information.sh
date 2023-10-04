#!/bin/bash

echo  -e "\t\t\t \e[1;34m   欢迎进入学生信息管理系统  \e[0m"
	echo  -e "\n\n\n"
	echo  -e  "\t\t\t\e[1;29m| 1.添加学生"
	echo  -e  "\t\t\t\e[1;29m| 2.删除学生"
	echo  -e  "\t\t\t\e[1;29m| 3.学生列表"
	echo  -e  "\t\t\t\e[1;29m| 4.查找学生"
	echo  -e  "\t\t\t\e[1;29m| 5.修改学生信息"
	echo  -e  "\t\t\t\e[1;29m| 6.返回上级"
	echo  -e  "\t\t\t\e[1;29m| q.退出系统"
	read  -p  "请选择：" choice

	case $choice in
		1)
			echo  -e  " \t\t添加学生"
			bash add_information.sh	
			;;
		2)
			echo  -e  " \t\t删除学生"
			bash del_information.sh	
			;;
		3)
			echo  -e  " \t\t学生列表"
			bash display_information.sh	
			;;
		4)
			echo  -e  " \t\t查找学生"
			bash search_information.sh
			;;
		5)
			echo  -e  " \t\t修改学生信息"
			bash update_information.sh	
			;;
		6)
			echo  -e  " \t\t返回上级页面"
			bash main.sh
			;;
		q)
			echo  -e  " \t\t退出系统"
			bash quit.sh   	
			;;
		*)
			bash main_information.sh
			;;
	esac
bash main_information.sh
