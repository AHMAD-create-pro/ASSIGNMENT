#include <iostream>
//#include <string>
using namespace std;
class expense {
public:
    string name;
    double amount;
    expense* next;
    expense(string n, double a) : name(n), amount(a), next(NULL) {}};
class month {
public:
    string name;
    expense* head;
    month* next;  
    month(string n) : name(n), head(NULL), next(NULL) {}
};
class tracker {
    month* head = NULL;
    month* gMon(string n) {
        for (month* m = head; m; m = m->next)
            if (m->name == n) return m;
        month* m = new month(n);
        m->next = head;
        head = m;
        return m;}
public:
    void add() {
        string m, n; double a;
        cout << "Month: "; cin >> m;
        cout << "Expense: "; cin >> n;
        cout << "Amount: "; cin >> a;
        expense* e = new expense(n, a);
        month* mo = gMon(m);
        e->next = mo->head;
        mo->head = e;
        cout << "Added!\n";}
    void show() {
        for (month* m = head; m; m = m->next) {
            cout << "\n" << m->name << ":\n";
            for (expense* e = m->head; e; e = e->next)
                cout << "- " << e->name << ": RS" << e->amount << "\n";
        }}
    void update() {
        string m, n; double a;
        cout << "Month: "; cin >> m;
        cout << "Expense to update: "; cin >> n;
        cout << "New amount: "; cin >> a;
        for (month* mo = head; mo; mo = mo->next)
            if (mo->name == m)
                for (expense* e = mo->head; e; e = e->next)
                    if (e->name == n) {
                        e->amount = a;
                        cout << "Updated!\n"; return;
                    }
        cout << "Expense not found.\n";
    }
void remove() {
    string m, n;
    cout << "Month: ";
    cin >> m;
    cout << "Expense to delete: ";
    cin >> n;
    month* mo = head;
    while (mo != NULL && mo->name != m)
        mo = mo->next;
    if (!mo) {
        cout << "Month not found.\n";
        return;
    }
    expense* e = mo->head;
    expense* prev = NULL;
    while (e != NULL) {
        if (e->name == n) {
            if (prev)
                prev->next = e->next;
            else
                mo->head = e->next;
            delete e;
            cout << "Deleted!\n";
            return;
        }
        prev = e;
        e = e->next;
    }
   cout << "Expense not found.\n";
}
void most() {
    string m;
    cout << "Month: ";
    cin >> m;
    month* mo = head;
    while (mo && mo->name != m) mo = mo->next;
    if (!mo) {
        cout << "Month not found.\n";
        return;
    }
    if (!mo->head) {
        cout << "No expenses.\n";
        return;
    }
    expense* max = mo->head;
    for (expense* e = mo->head; e; e = e->next)
        if (e->amount > max->amount) max = e;
    cout << "Most expensive: " << max->name << " (RS" << max->amount << ")\n";
}
};
int main() {
    tracker a;
    int c;
    while (true) {
        cout << "\nExpense Tracker Menu\n";
        cout << "1. Add Expense\n";
        cout << "2. Show All Expenses\n";
        cout << "3. Update Expense\n";
        cout << "4. Delete Expense\n";
        cout << "5. Most Expensive Item in Month\n";
        cout << "6. Exit\n";
        cout << "Choose: ";
        cin >> c;
        if (c == 1) {
            a.add();
        } else if (c == 2) {
            a.show();
        } else if (c == 3) {
            a.update();
        } else if (c == 4) {
            a.remove();
        } else if (c == 5) {
            a.most();
        } else if (c == 6) {
            cout << "Bye!\n";
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
