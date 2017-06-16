# Tổ chức dữ liệu

## File văn bản:

+ Khi chương trình được chạy, hệ thống load dữ liệu từ các file lên, khởi tạo cho các biến trong chương trình.
+ Khi chương trình được thoát, hệ thống lưu lại dữ liệu sau các phiên làm việc về các file.

## Hệ thống quản lý các thông tin:
+ Các tài khoản (**``account``**):
	+ Tài khoản admin (**``admin``**) 
	+ Tài khoản thủ thư (**``librarian``**)
	+ Tài khoản người dùng (**``user``**)
+ Thông tin sách (**``book``**)
	
## Bảng phân quyền:

+ **``user``** là cấp thấp nhất trong hệ thống, chức năng tìm / mượn sách, thay đổi mật khẩu.
+ **``librarian``** là cấp thứ hai trong hệ thống, có thêm các chức năng về quản lí sách.
+ **``admin``** là cấp cao nhất trong hệ thống, có các chức năng về quản lí sách và quản lí tài khoản.
+ ``admin`` và ``librarian`` không xem xét chức năng mượn sách.
+ Tổ chức lớp:
	+ Lớp ``account`` là lớp basic
	+ Lớp ``user`` kế thừa lớp ``account``
	+ Lớp ``librarian`` kế thừa lớp ``account``
	+ Lớp ``admin`` kế thừa lớp ``librarian``
	
|Quyền sử dụng| admin| librarian| user| account |
|----|-----|-----|-----|----|
|Tìm sách| 1|	1|	1|	1	|
|Thay đổi mật khẩu |	1|	1|1	|	1|
|Mượn sách | | | 1| |
|Thêm, xóa, sửa sách|1|1|||
|Xử lí yêu cầu mượn sách|1|1|||
|Xem danh sách người mượn, nợ sách|1|1|||
|Yều cầu trả sách|1|1|||
| Thêm, xóa, khóa, mở, tìm tài khoản | 1||||
|Xử lí yêu cầu đăng kí tài khoản |1||||

	
## Tóm lược chức năng:
+ Lớp **``account``**: 
	+ Tìm sách:
		```
		+ findBook_code(string code); dựa trên mã code sách
		+ findBook_name(string title); dựa trên tên sách 
		+ findBook_author(string author); dựa trên tên tác giả
		+ findBook_information(string information); dựa trên thông tin mô tả
		```
	+ Thay đổi mật khẩu:
		```
		+ changePassword(string pass);
		```
+ Lớp **``user: public account``**:
	+ Mượn sách:
		```
		+ requireBook(string code); bắt buộc là mã sách
		```
+ Lớp **``librarian: public account``**:
	+ Thêm sách:
		```
		+ addBook(const book &bk, int number = 1);
		```
	+ Xóa sách:
		```
		+ eraseBook(const book &bk, int number = 1);
		+ eraseBookAll(const book &bk);
		```
	+ Sửa thông tin sách:
		```
		+ editBook(const book &bk);
		```
	+ Xử lí yêu cầu mượn sách:
		```
		+ ....
		```
	+ Danh sách người mượn sách:
		```
		+ ....
		```
	+ Danh sách người nợ sách:
		```
		+ ....
		```
	+ Yêu cầu trả sách:
		```
		+ ....
		```
+ Lớp **``admin: public librarian``**:
	+ Thêm tài khoản:
		```
		+ addAdmin(const admin &ad);
		+ addLibrarian(const librarian &lib);
		+ addUser(const user &us);
		```
	+ Xóa tài khoản:
		```
		+ deleteLibrarian(const librarian &lib);
		+ deleteUser(const user &us);
		```
	+ Khóa tài khoản:
		```
		+ lockLibrarian(const librarian &lib);
		+ lockUser(const user &us);
		```
	+ Mở lại tài khoản:
		```
		+ unlockLibrabrian(const librarian &lib);
		+ unlockUser(const user &us);
		```
	+ Tìm kiếm tài khoản:
		```
		+ findAccount_code(string code);
		+ findAccount_name(string name);
		```
	+ Xử lí yêu cầu đăng kí mới tài khoản:
		```
		+ ....
		```
			
## Thông tin các lớp:
``` cpp
"account.h" :
	string code;
	string name; 
	int password;
	string email, id, username, tel;
	int day, month, year;
	int role, state;
```
	
``` cpp
"book.h" :
	string code;
	string name, author, information;
	int remain_number;
```

``` cpp
"user_book":
	lớp này quản lí một cặp người dùng - sách
	user _user
	book _book
	int d1, m1, y1, d2, m2, y2; // ngày mượn trả sách
```
	
## Khởi tạo các biến dữ liệu trong hệ thống:
+ Tạo header external.h lưu các biến toàn cục của các file, và file external.cpp để khởi tạo giá trị cho các biến này.
+ Trong đó có các danh sách hệ thống sau:
``` cpp
	+ vector<account> l_account, l_account_require; 
	+ vector<admin> l_admin, l_admin_require; 
	+ vector<librarian> l_lib, l_lib_require;
	+ vector<user> l_user, l_user_require;
	+ vector<book> l_book;
	+ vector<user_book> l_user_book, l_user_require_book;
```
+ Lớp ``data`` lưu trữ các hàm load dữ liệu và storage dữ liệu, dùng hàm ``friend`` để có thể lấy các thông tin private từ các lớp book, account, ...
+ Khi chương trình được chạy, lớp data được thực thi:
	+ ``loadData();``
	+ các danh sách trên được lấy dữ liệu từ file dưới hệ thống
+ Khi chương trình được thoát, lớp data thực thi:
	+ ``storageData();``
	+ các danh sách trên được lưu xuống các file
				