int data::loadDataAccountRequest() {
	ifstream f(FILE_ACCOUNT_REQUEST);
	if (!f.is_open()) return NOT_ACCESS_FILE;
	int n = 0;
	f >> n;
	for (int i = 0; i < n; ++i) {
		account a;
		f >> a.code >> a.name >> a.password >> a.email >> a.id;
		f.get();
		getline(f, a.username);
		f >> a.tel >> a.day >> a.month >> a.year >> a.role;
		l_account.push_back(a);
		if (a.role == ADMIN) l_admin.push_back(admin(a));
		else if (a.role == LIBRARIAN) l_lib.push_back(librarian(a));
		else if (a.role == USER) l_user.push_back(user(a));
		else { f.close(); return ERROR; }
		return TRUE;
	}
}
