# @author : Tanmay Kokate

#! /bin/zsh

po()
{
	echo $n
}

mn()
{
	echo "Current Address Book is -> $addBook"
}

dispBooks()
{
	echo $n 
	echo " : Available Address Books are : "
	ls | grep ".txt"
	echo $n 
}

selectBook()
{
	dispBooks
	po
	echo -n "Enter Name of Address Book you want to Select : "
	read tempFile

	if [ -e $tempFile.txt ]
	then
		addBook="$tempFile.txt"
		echo "Selected Address Book : $addBook"
	else
		echo "Address Book Not Found!!!"
	fi
	po
}

createBook()
{
	echo $n
	echo -n "Enter The name of Address book you want to Create : "
	read fileName
	echo $n 
	if [ -e $fileName.txt ]
	then
		po
		echo "File already Exists"
	else
		po
		touch $fileName.txt
		echo $n 
		dispBooks
		echo $n 
	fi
	po
}

insertRec()
{
	echo "Current Address Book is -> $addBook"
	po 
	echo -n "How Many Records Do you wish to Insert : "
	read num

	while [ $num -gt 0 ]
	do
		echo -n "Enter Name : "
		read name
		echo -n "Enter PhNo : "
		read pno
		record=`echo "$name\t\t$pno"`
		po
		echo "Confirm Record"
		echo "$record"
		po
		echo -n "Correct? (y/n) : "
		read cflg

		if [ $cflg = "y" ]
		then 
			po
			echo "$record" >> $addBook
			echo "Record Inserted Successfully!!"
			po 
		else
			po
			echo "Record Not inserted"
		fi		
		num=`expr $num - 1`
	done 
	po
}

dispRec()
{
	mn
	po
	echo "Name\t\tPhNo"
	echo "================================================================="
	cat $addBook
	po
}

searchRec()
{
	mn
	po
	echo -n "Enter Name/Phone You want to Search : "
	read srch
	po
	var=`cat $addBook | grep -in $srch | wc -w` 
	if [ $var -gt 0 ]
	then
		po
		echo "Record Found as Follows"
		grep -ni "$srch" $addBook
		po
	else
		po 
		echo "Record Absent in File"
		po 
	fi
	po
}

modiRec()
{
	mn
	po
	echo -n "Enter Name/Phone you want to Modify : "
	read mdfy
	po
	var=`cat $addBook | grep -in $mdfy | wc -w` 
	if [ $var -gt 0 ]
	then
		po
		echo "Record Found"
		echo -n "Enter Modified Value : "
		read modified
		sed -ie "s/$mdfy/$modified/" $addBook
		po
		echo "Record Modified!!"
		dispRec
		po
	else
		po 
		echo "Record Absent in File"
		po 
	fi
	po
}

delRec()
{
	dispRec
	echo -n "Enter Name/Phone you want to Delete : "
	read dele
	po
	var=`cat $addBook | grep -in $dele | wc -w` 
	if [ $var -gt 0 ]
	then
		po
		echo "Record Found"
		sed -ie "/$dele/d" $addBook
		po
		echo "Record Deleted!!"
		dispRec
		po
	else
		po 
		echo "Record Absent in File"
		po 
	fi
	po
}

while [ true ]
do
	echo "******* Main Menu ********"
	echo "1) Display Address Books"
	echo "2) Select Address Book"
	echo "3) Create Address Book"
	echo "4) Insert Record"
	echo "5) Display Records"
	echo "6) Search Record"
	echo "7) Modify Record"
	echo "8) Delete Record"
	echo "9) Exit"

	echo -n "Enter Your Choice : "
	read choice

	case $choice in 
	1)
		dispBooks
		echo -n "Press [Enter] to Continue..."
		read EnterKey
		clear
		;;
	2)
		selectBook
		echo -n "Press [Enter] to Continue..."
		read EnterKey
		clear
		;;
	3)
		createBook
		echo -n "Press [Enter] to Continue..."
		read EnterKey
		clear
		;;
	4)
		insertRec
		echo -n "Press [Enter] to Continue..."
		read EnterKey
		clear
		;;
	5)
		dispRec
		echo -n "Press [Enter] to Continue..."
		read EnterKey
		clear
		;;
	6)
		searchRec
		echo -n "Press [Enter] to Continue..."
		read EnterKey
		clear
		;;
	7)
		modiRec
		echo -n "Press [Enter] to Continue..."
		read EnterKey
		clear
		;;
	8)
		delRec
		echo -n "Press [Enter] to Continue..."
		read EnterKey
		clear
		;;
	9)
		echo "Bye!!~~"
		clear
		exit 0
		;;
	esac
done
	mn
