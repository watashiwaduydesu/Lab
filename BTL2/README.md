# Assignment 2 Kỹ thuật lập trình

## Tổ chức dữ liệu: 
https://github.com/huynhsamha/Assignment_02_KTLT_Version_1/blob/master/to-chuc-du-lieu.md

## Tổ chức File lưu trữ:
https://github.com/huynhsamha/Assignment_02_KTLT_Version_1/blob/master/to-chuc-file.md

## Mấy ông làm cái này nha, tui thấy mấy ông làm được
### xem cách tui làm trong file librarian, mấy cái khác giống vậy:

+ File ``librarian`` hiện thực các hàm:
``` cpp
    int editBook_name(book &bk, string new_name);
    int editBook_author(book &bk, string new_author);
    int editBook_information(book &bk, string new_information);
```

+ Trong file ``admin.h`` và ``admin.cpp`` hiện thực các hàm

``` cpp
	account findAccount_code(string code_);
	account findAccount_name(string name_);

	int addAdmin(admin &admin_);
	int addLibrarian(librarian &lib_);
	int addUser(user &user_);

	int deleteLibrarian(librarian &lib_);
	int deleteUser(user &user_);

	int lockLibrarian(librarian &lib_);
	int lockUser(user &user_);

	int unlockLibrarian(librarian &lib_);
	int unlockUser(user &user_);	
```

## Lịch sử cập nhật

### sáng ngày 12 / 5
+ tạo người dùng chính trong phiên làm việc, (main_account), toàn cục ở các file, khai báo trong file external.
	+ dùng class account vì không xác định cụ thể người này có chức năng gì, tuy nhiên biết được role của người này, do đó có các hàm tương thích.
+ tạo hàm ``updatePasswordMainAccount(int password_new)``, khi người dùng đổi mật khẩu
+ hoàn thành đăng nhập và đổi mật khẩu cho người dùng.
+ hoàn thành chức năng xem thông tin tài khoản trong phiên làm việc
+ thêm giao diện làm việc của user, lib, <<chưa xử lí sự kiện>>

### chiều tối ngày 11 / 5
+ Hiện thực hàm ``eraseBook()`` và ``removeBook()`` cho class ``librarian``
+ Thêm trạng thái tài khoản ``state`` (ACTIVE or DISABLED) (định nghĩa trong macro)
+ Thêm giao diện phiên bản cũ vào, sửa đổi lại các hàm cho giao diện này.
+ Hiện tại đã có thể đăng nhập hệ thống, gửi yêu cầu đăng kí tài khoản.
+ Tạo giao diện thay đổi mật khẩu, chưa xử lí sự kiện

### sáng 11/5
+ hiện thực hàm khoảng cách chuỗi **``LevensteinDistance(string, string)``**:
	+ xem mô tả hàm trong file **``Levenstein Distance.md``**
	+ xem hiện thực hàm trong file ``external``
+ hiện thực các hàm tìm sách của account, trong file ``account``

### trưa + chiều 10/5
+ class **``user_book``** sửa lại biến ngày tháng bằng ``QDate`` trong QT để dễ xử lí thời gian trong hệ thống.

+ hiện thực hàm ``requireBook()`` cho ``user``

+ hiện thực hàm ``addBook()`` cho ``librarian``

+ tạo hàm cấp ID mới cho ``book`` và ``account`` (trong file **external**), trong đó: 
	+ ID sẽ được cộng dồn lên theo thứ tự bắt đầu từ giá trị 0
	+ ID của account bắt đầu bằng IDA (viết tắt account, ở đây hiểu là code của nó)
	+ ID của book bắt đầu bằng IDB (viết tắt book)
	+ số ID của mỗi loại gồm 7 chữ số, bắt đầu từ 0000000
	+ Ví dụ: ``IDA0000000 -> IDA0000001 -> ..., IDB0000000 -> ...``
	+ tạo hai biến **``ID_account``** và **``ID_book``** lưu lại ID cuối cùng mà hệ thống tạo được
	+ hai biến nói trên cần được lưu vào file để lưu trữ dữ liệu, trước mắt sẽ được lưu chung với file **bookList** và **accountList**;

+ hiện thực hàm ``loadDataBook()`` và ``storageDataBook()``, xem cấu trúc file này ở Tổ chức file

### tối 9/5
+ Danh sách **l_account, ...** từ static trong class **data**, chuyển thành biến **``extern``** trong file ``external.h``, được khởi tạo trong file ``external.cpp``.
	+ Lợi ích: truy cập được ở các file bất kì khi ``#include "external.h" ``, mấy thằng trong này là toàn cục ở các file luôn.

+ Trong file **account.h**, các hàm ``findBook()...`` , giá trị trả về thay từ ``book`` bằng ``vector<book>``.
	+ Lý do và lợi ích: nếu size = 0, tức không có sách tìm thấy, nếu có nhiều sách cùng lượng thông tin, có khả năng trả về đầy đủ.

+ Thêm class **user_book** quản lí một cặp user và book, xử lí trong các tình huống: mượn sách, nợ sách, trả sách, đòi sách, ..., nói chung liên quan giữa người dùng và sách.
	+ Bỏ **``vector<book> l_bookRequirement``**. 
	+ Bỏ file **bookRequirement.txt**. 
	+ Thêm **``vector<user_book> l_user_book``**: người dùng - sách đang được mượn
	+ Thêm file **userBook.txt**, tương ứng
	+ Thêm **``vector<user_book> l_user_require_book``**: người dùng yêu cầu sách
	+ Thêm file **userRequireBook.txt**, tương ứng

+ Thêm vào file **extern**, hai hàm 
	+ (Cái này không cần quan tâm, chỉ dùng khi xử lí giao diện lúc người ta đăng nhập, đăng kí, ...)
	+ **``int hashPassword(string password)``** : mã hóa mật khẩu thành số int (MOD 1e9) 
	+ **``bool checkPassword(string password, int value)``** : kiểm tra xem mật khẩu ``password`` có trùng khớp với ``value`` password của người dùng.


## Các phiên bản:
+ Phiên bản chính (chưa có giao diện) là LibApplcation (version 2, đang làm trên cái này)
+ Phiên bản cũ (có một số giao diện) là LibraryApplicaion (version 1, không làm trên cái này nữa, chỉ dùng để thêm giao diện sau khi version 2 làm xong!)
+ Các file khác là lưu trữ các quy định trong lúc lập trình để thống nhất.
