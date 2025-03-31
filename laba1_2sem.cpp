#include "infa.h"
using namespace std;
using namespace TVR;
int main() {
	tvr *arr = nullptr;
	int count = 0;
	arr = load(count);
	int n;
	do {
		cout << ("---------------------------------------\n") << endl;
		cout << ("Menu smetana:\n") << endl;
		cout << ("1. Skachat smetu bez sms i registracii \n") << endl;
		cout << ("2. Pokazat smetu\n") << endl;
		cout << ("3. Dobavit tovar\n") << endl;
		cout << ("4. Ydalit tovar\n") << endl;
		cout << ("5. Redaktirovat tovar\n") << endl;
		cout << ("6. Naiti tovar\n") << endl;
		cout << ("0. Exit\n") << endl;
		cout << ("---------------------------------------\n") << endl;
		cin >> n;
		switch (n) {
		case 1:
			arr = create(count);
			break;
		case 2:
			show(arr, count);
			break;
		case 3:
			add(&arr, &count);
			break;
		case 4:
			del(arr, &count);
			break;
		case 5:
			edit(arr, count);
			break;
		case 6:
			search(arr, count);
			break;
		case 0:
			cout << "Bye-Bye" << endl;
			save(arr, count);
			delete[] arr;
			break;
		default:
			printf("Ne ponimau \n");
		}
	} while (n != 0);
	return 0;
}