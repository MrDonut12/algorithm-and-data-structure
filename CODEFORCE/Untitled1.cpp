#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef struct {
    char id[10];
    char first_name[30];
    char last_name[30];
    double gpa;
} Student;


Student students[MAX];

void print_menu();
int make_choice(int min, int max);
void add();
void edit();
void delete();
void search_by_id();
void search_by_name();
void display();


// bonus function
void merge_array(Student array[], int left, int mid, int right); // merge array
void sort_func(Student array[], int left, int right); // merge sort
int lower_bound_by_lastname(Student array[], int left, int right, char *target); //binary search too...

int cmp_custom(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (unsigned char)(*s1) - (unsigned char)(*s2);
}

int binary_search(Student students[], int n, const char *id) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = cmp_custom(students[mid].id, id);
        if (cmp == 0) return mid;
        else if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}



int main(void)
{
	void (*func[7])(void) = {NULL, &add, &edit, &delete, &search_by_id, &search_by_name, &display};
	int choice;

	do
	{
		choice = make_choice(0, 6);
		if (choice)
		{
			func[choice]();
			printf("\nPress any key to return to the menu.");
			getchar();
		}
	} while (choice);

	return 0;
}

void print_menu()
{
	system("cls");
	printf("STUDENT MANAGEMENT SYSTEM\n");
	printf("-------------------------\n");
	printf("1. Add a new student\n");
	printf("2. Edit a student\n");
	printf("3. Delete a student\n");
	printf("4. Search for student by ID\n");
	printf("5. Search for student by last name\n");
	printf("6. Display all students sorted by last name\n");
	printf("0. Exit\n");
}

int make_choice(int min, int max)
{
	int not_valid = 1, num, scanf_ret;
	char c;

	print_menu();
	fflush(stdin);
	do
	{
		printf("\nEnter your choice: ");
		scanf_ret = scanf("%d%c", &num, &c);
		if (scanf_ret < 2 || c != '\n')
		{
			print_menu();
			printf("\nYour choice is not valid. Please try again!\n");
			fflush(stdin);
		}
		else if (num < min || num > max)
		{
			print_menu();
			printf("\nYour choice is not valid. Please try again!\n");
		}
		else
		{
			not_valid = 0;
		}
	} while (not_valid);

	system("cls");

	return num;
}

void add()
{
	printf("Write your code here to implement the add() function.\n");
}


void edit(Student students[], int n) {
    char id[11];
    printf("Enter student ID to edit: ");
    scanf("%10s", id);

    int idx = binary_search(students, n, id);
    if (idx == -1) {
        printf("Student with ID %s not found.\n", id);
        return;
    }

    printf("Editing student: %s %s, GPA: %.2f\n", 
            students[idx].first_name, students[idx].last_name, students[idx].gpa);

    printf("Enter new First name: ");
    scanf("%29s", students[idx].first_name);

    printf("Enter new Last name: ");
    scanf("%29s", students[idx].last_name);

    printf("Enter new GPA: ");
    scanf("%lf", &students[idx].gpa); 

    printf("Student updated successfully.\n");
}


void delete()
{
	printf("Write your code here to implement the delete() function.\n");
}

void search_by_id(Student students[], int n) {
    char id[11];
	
    printf("Enter student ID to search: ");
    scanf("%10s", id);

    int idx = binary_search(students, n, id);
	
    if (idx == -1) {
        printf("Student with ID %s not found.\n", id);
        return;
    }

    printf("Student found:\n");
	
    printf("ID: %s\n", students[idx].id);

    printf("First name: %s\n", students[idx].first_name);
	
    printf("Last name: %s\n", students[idx].last_name);
	
    printf("GPA: %.2f\n", students[idx].gpa);
}

void search_by_name()
{
	printf("Write your code here to implement the search_by_name() function.\n");
}

void display()
{
    printf("Write your code here to implement the display() function.\n");
}

int lower_bound_by_lastname(Student array[], int left, int right, char *target) {
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (strcmp(array[mid].last_name, target) >= 0) right = mid - 1;
		else {
			left = mid + 1;
		}
	}
	return left;
}
void merge_array(Student array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Student *L = (Student *)malloc(n1 * sizeof(Student));
    Student *R = (Student *)malloc(n2 * sizeof(Student));

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i].last_name, R[j].last_name) <= 0) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }

    while (i < n1)
        array[k++] = L[i++];
    while (j < n2)
        array[k++] = R[j++];

    free(L);
    free(R);
}

void sort_func(Student array[], int left, int right){
    if (left >= right)
        return ;
    int mid = (left + right) >> 1;
    sort_func(array, left, mid);
    sort_func(array, mid + 1, right);
    merge_array(array, left, mid, right);
}

