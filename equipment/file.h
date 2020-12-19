struct user
{
    char id[10];
    char username[20];
    char password[20];
    char identity[20];
};

struct equipment
{
    char ID[10];            //设备ID
    char name[20];          //设备名称
    char kind[20];          //设备种类
    char over[50];          //设备报废日期
    char scrap[10];         //设备是否报废
    char date[50];          //设备生产时间
    char price[10];         //设备价格
};

typedef struct Enode
{
    struct equipment data;
    struct node *next;
} ENode;

typedef struct Unode
{
    struct user data;
    struct node *next;
} UNode;

UNode currentUser;          //保存当前用户信息
UNode *currentUserP;          //保存当前用户信息

void *write_user_toFile(UNode *user)      //将用户信息输入文件
{
    FILE *fp = fopen("user.txt","w");
    UNode *current = user->next;
    while(current)
    {
        fprintf(fp,"%s\t",current->data.id);
        fprintf(fp,"%s\t",current->data.username);
        fprintf(fp,"%s\t",current->data.password);
        if(!current->next)          //判断是否为最后一行，是->不换行
            fprintf(fp,"%s",current->data.identity);
        else
            fprintf(fp,"%s\t\n",current->data.identity);
        current = current->next;
    }
    fclose(fp);
}

void fscanfEquipment(ENode *equip)      //将设备信息输入文件
{
    FILE *fp = fopen("equipment.txt","w");
    ENode *current = equip->next;
    while(current)
    {
        fprintf(fp,"%s\t",current->data.ID);
        fprintf(fp,"%s\t",current->data.name);
        fprintf(fp,"%s\t",current->data.kind);
        fprintf(fp,"%s\t",current->data.over);
        fprintf(fp,"%s\t",current->data.scrap);
        fprintf(fp,"%s\t",current->data.date);
        if(!current->next)          //判断是否为最后一行，是->不换行
            fprintf(fp,"%s",current->data.price);
        else
            fprintf(fp,"%s\t\n",current->data.price);
        current = current->next;
    }
    fclose(fp);
}

UNode *read_user_fromFile()            //将用户信息从文件中输出
{
    FILE* fp;
    fp = fopen("user.txt","r");
    UNode *head = (UNode *)malloc(sizeof(UNode));
    UNode* pre = head;
    while(!feof(fp))
    {
        UNode *newnode = (UNode*)malloc(sizeof(UNode));
        fscanf(fp,"%s",newnode->data.id);
        fscanf(fp,"%s",newnode->data.username);
        fscanf(fp,"%s",newnode->data.password);
        fscanf(fp,"%s",newnode->data.identity);
        pre->next = newnode;
        pre = newnode;
    }
    pre->next = NULL;
    fclose(fp);
    return head;
}

ENode *fprintfEquipment()            //将设备信息从文件中输出
{
    FILE* fp;
    fp = fopen("equipment.txt","r");
    ENode *head = (ENode *)malloc(sizeof(ENode));
    ENode* pre = head;
    while(!feof(fp))
    {
        ENode *newnode = (ENode*)malloc(sizeof(ENode));
        fscanf(fp,"%s",newnode->data.ID);
        fscanf(fp,"%s",newnode->data.name);
        fscanf(fp,"%s",newnode->data.kind);
        fscanf(fp,"%s",newnode->data.over);
        fscanf(fp,"%s",newnode->data.scrap);
        fscanf(fp,"%s",newnode->data.date);
        fscanf(fp,"%s",newnode->data.price);
        pre->next = newnode;
        pre = newnode;
    }
    pre->next = NULL;
    fclose(fp);
    return head;
}
