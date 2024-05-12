
#include <iostream>
#include <cstring> 
// Функція-шаблон для обчислення середнього значення в масиві
template <typename T>
double calculateAverage(const T arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

// Спеціалізація функції-шаблону для типу char*
template <>
double calculateAverage<char*>(char* arr[], int size) {
    double sumLength = 0.0;
    for (int i = 0; i < size; ++i) {
        // Використовуємо strlen для підрахунку довжини кожного рядка
        sumLength += std::strlen(arr[i]);
    }
    // Повертаємо середню довжину рядків
    return sumLength / size;
}

int main() {
    // Приклади використання функції-шаблону
    int intArr[] = {1, 2, 3, 4, 5};
    std::cout << "Average of int array: " << calculateAverage(intArr, 5) << std::endl;

    double doubleArr[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    std::cout << "Average of double array: " << calculateAverage(doubleArr, 5) << std::endl;

    const char* strArr[] = {"apple", "banana", "orange", "grape", "watermelon"};
    std::cout << "Average length of strings in char* array: " << calculateAverage(strArr, 5) << std::endl;

    return 0;
}



/*
#include <iostream>

// Функція-шаблон для обміну елементів місцями
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Функція-шаблон для швидкого сортування
template <typename T>
void quickSort(T arr[], int left, int right) {
    if (left < right) {
        T pivot = arr[right]; // Вибираємо останній елемент як опорний
        int i = left - 1;

        for (int j = left; j <= right - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[right]);
        int pivotIndex = i + 1;

        // Рекурсивно сортуємо елементи менше та більше опорного
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

// Специфікація функції-шаблону для типу char*
template <>
void quickSort(char* arr[], int left, int right) {
    if (left < right) {
        char* pivot = arr[right]; // Вибираємо останній рядок як опорний
        int i = left - 1;

        for (int j = left; j <= right - 1; j++) {
            if (std::strcmp(arr[j], pivot) < 0) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[right]);
        int pivotIndex = i + 1;

        // Рекурсивно сортуємо рядки менше та більше опорного
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main() {
    int intArr[] = {5, 1, 4, 2, 8};
    int intSize = sizeof(intArr) / sizeof(int);
    quickSort(intArr, 0, intSize - 1);
    std::cout << "Sorted int array: ";
    for (int i = 0; i < intSize; ++i) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    const char* strArr[] = {"banana", "apple", "orange", "grape", "watermelon"};
    int strSize = sizeof(strArr) / sizeof(const char*);
    quickSort(strArr, 0, strSize - 1);
    std::cout << "Sorted char* array: ";
    for (int i = 0; i < strSize; ++i) {
        std::cout << strArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
#include <iostream>

template<typename T, int maxSize>
class CircularQueue {
private:
    T elements[maxSize]; // Масив елементів черги
    int front;           // Індекс переднього елемента черги
    int rear;            // Індекс заднього елемента черги
    int count;           // Кількість елементів у черзі
public:
    // Конструктор
    CircularQueue() : front(0), rear(-1), count(0) {}

    // Перевірка на порожність
    bool isEmpty() const {
        return count == 0;
    }

    // Перевірка на повноту
    bool isFull() const {
        return count == maxSize;
    }

    // Отримати поточний розмір черги
    int size() const {
        return count;
    }

    // Додати елемент у чергу
    void enqueue(const T& item) {
        if (isFull()) {
            std::cerr << "Queue is full. Cannot enqueue.\n";
            return;
        }
        rear = (rear + 1) % maxSize; // Обчислюємо індекс заднього елемента з урахуванням циклічності
        elements[rear] = item;       // Додаємо елемент у чергу
        count++;                     // Збільшуємо лічильник елементів
    }

    // Видалити елемент з черги
    T dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot dequeue.\n";
            exit(1); // Якщо черга порожня, вихід з програми з кодом помилки 1
        }
        T item = elements[front];     // Зберігаємо передній елемент
        front = (front + 1) % maxSize; // Оновлюємо індекс переднього елемента з урахуванням циклічності
        count--;                      // Зменшуємо лічильник елементів
        return item;                  // Повертаємо видалений елемент
    }
};

int main() {
    CircularQueue<int, 5> queue; // Створення циклічної черги типу int з розміром 5

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Queue size: " << queue.size() << std::endl;

    std::cout << "Dequeued item: " << queue.dequeue() << std::endl;
    std::cout << "Dequeued item: " << queue.dequeue() << std::endl;

    std::cout << "Queue size after dequeue: " << queue.size() << std::endl;

    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6); // Видасть помилку, бо черга повна

    return 0;
}
/*
#include <iostream>
#include <stack>

// Клас, що представляє вузол бінарного дерева
template<typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(const T& val) : data(val), left(nullptr), right(nullptr) {}
};

// Клас, що представляє бінарне дерево
template<typename T>
class BinaryTree {
private:
    TreeNode<T>* root;

    // Приватний метод для рекурсивного додавання елемента у дерево
    TreeNode<T>* addNode(TreeNode<T>* node, const T& val) {
        if (node == nullptr) {
            node = new TreeNode<T>(val);
        } else if (val < node->data) {
            node->left = addNode(node->left, val);
        } else {
            node->right = addNode(node->right, val);
        }
        return node;
    }

    // Приватний метод для рекурсивного виведення дерева у порядку прямого обходу
    void preOrderTraversal(TreeNode<T>* node) const {
        if (node == nullptr) return;
        std::cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

public:
    BinaryTree() : root(nullptr) {}

    // Метод для додавання елемента у дерево
    void add(const T& val) {
        root = addNode(root, val);
    }

    // Метод для виведення дерева у порядку прямого обходу
    void preOrder() const {
        preOrderTraversal(root);
        std::cout << std::endl;
    }

    // Клас ітератора для обходу бінарного дерева у порядку прямого обходу
    class Iterator {
    private:
        std::stack<TreeNode<T>*> nodeStack;

    public:
        Iterator(TreeNode<T>* root) {
            if (root != nullptr) {
                nodeStack.push(root);
            }
        }

        bool hasNext() const {
            return !nodeStack.empty();
        }

        T next() {
            if (!hasNext()) {
                throw std::out_of_range("Iterator has reached the end");
            }

            TreeNode<T>* currNode = nodeStack.top();
            nodeStack.pop();
            if (currNode->right != nullptr) {
                nodeStack.push(currNode->right);
            }
            if (currNode->left != nullptr) {
                nodeStack.push(currNode->left);
            }

            return currNode->data;
        }
    };

    // Метод для отримання початкового ітератора
    Iterator begin() const {
        return Iterator(root);
    }

    // Метод для отримання кінцевого ітератора
    Iterator end() const {
        return Iterator(nullptr);
    }
};

int main() {
    BinaryTree<int> tree;
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(3);
    tree.add(7);
    tree.add(12);
    tree.add(20);

    std::cout << "Binary Tree in pre-order traversal:" << std::endl;
    tree.preOrder();

    std::cout << "Iterating through the tree using Iterator:" << std::endl;
    BinaryTree<int>::Iterator it = tree.begin();
    while (it.hasNext()) {
        std::cout << it.next() << " ";
    }
    std::cout << std::endl;

    return 0;
}

*/