//封装函数显示该界面
//在mian函数中调用封装好的函数
#include<iostream>
using namespace std;
# define MAX 1000 


//一.菜单界面
void showMenu() {
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;
}
//二.设计联系人结构体
struct Person {
	//姓名
	string m_Name;
	//性别
	int m_Sex; //1 -》男    2 -》女
	//年龄 
	int m_Age;
	//电话
	string m_Phone;
	//地址
	string m_Addr;
};
//三.设计通讯录结构体
struct Addressbooks {
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前保存的联系人的个数
	int m_Size=0;

};

//四、各功能函数实现
//1.添加联系人
void addPerson(Addressbooks * abs) {
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加!" << endl;
		return;
	}
	else {
		//添加联系人

		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		int sex=0;
		cout << "请输入性别：" << endl;
		cout << "1-男" << endl;
		cout << "2-女" << endl;
		
		while (true) {
			//如果输入1或2可以退出循环，否则重新输入
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;			//0<age<150
		
		while (true) {
			cin >> age;
			if (age >0 &&age<150) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//电话
		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		string address;
		cout << "请输入地址：" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功!" << endl;

		system("pause");
		system("cls");

	}
}

//2、显示所有联系人
void showPerson(Addressbooks* abs) {
	//判断通讯录人数是否为0，若为0则提示记录为空
	if (abs->m_Size == 0) {
		cout << "当前记录为空！" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";
			cout << "电话： " << abs->personArray[i].m_Phone << "\t";
			cout << "地址： " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");

}


//检测联系人是否存在，若存在，返回其在数组中的位置，若不存在返回-1
int isExist(Addressbooks* abs, string name) { 
	for (int i = 0; i < abs->m_Size;i++ ) {
		if (abs->personArray[i].m_Name == name) {
			return i;//找到了，返回这个人的数组编号
		}	
	}
	return -1;//如果遍历结束都没找到，则返回-1
}

//3、删除联系人
void delectPerson(Addressbooks * abs) {
	cout << "请输入您要删除的联系人姓名" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//4.查找联系人
void findPerson(Addressbooks* abs) {
	string name;
	cout << "请输入所要查找的联系人的姓名：" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret!= -1) {
		cout << "找到此人" << endl;
		cout << "姓名： " << abs->personArray[ret].m_Name << "\t";
		cout << "性别： " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personArray[ret].m_Age << "\t";
		cout << "电话： " << abs->personArray[ret].m_Phone << "\t";
		cout << "地址： " << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//5.修改联系人
void modifyPerson(Addressbooks* abs) {
	cout << "请输入所要修改的联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "找到此人" << endl;
		string modify_name;
		cout << "请输入修改后的姓名：" << endl;
		cin >> modify_name;
		abs->personArray[ret].m_Name = modify_name;

		//性别
		int sex = 0;
		cout << "请输入修改后的性别：" << endl;
		cout << "1-男" << endl;
		cout << "2-女" << endl;

		while (true) {
			//如果输入1或2可以退出循环，否则重新输入
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		int age = 0;
		cout << "请输入修改后的年龄：" << endl;			//0<age<150

		while (true) {
			cin >> age;
			if (age > 0 && age < 150) {
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//电话
		string phone;
		cout << "请输入修改后的电话号码：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//住址
		string address;
		cout << "请输入修改后的地址：" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
	}
	else {
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}

//6、清空联系人
void cleanPerson(Addressbooks * abs) {
	abs->m_Size = 0;
	cout << "通讯录已清空!" << endl;
	system("pause");
	system("cls"); 
	
}


int main() {

	//创建结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0; 


	int select = 0; //创建用户选择输入的变量
	while (true) {
		//菜单调用
		showMenu();

		cin >> select;

		switch (select) {
		case 1:	//1、添加联系人
			addPerson(&abs);//利用地址传递可以修饰实参
			break;
		case 2:	//2、显示联系人
			showPerson(&abs);
			break;
		case 3:	//3、删除联系人
			delectPerson(&abs);
			break;
		case 4:	//4、查找联系人
			findPerson(&abs);
			break;
		case 5:	//5、修改联系人
			modifyPerson(&abs);
			break;
		case 6:	//6、清空联系人
			cleanPerson(&abs);
			break;
		case 0:	//0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0; //返回0 退出系统
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}
