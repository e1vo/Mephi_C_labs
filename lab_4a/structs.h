typedef struct Info {
    double num1;
    double num2;
    char *string;
} Info;

typedef struct Node {
    char *key;
    int l_threaded;
    int r_threaded;
    Info *info;
    struct Node *left;
    struct Node *right;
} Node;