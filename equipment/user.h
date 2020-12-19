void printUser(UNode *user)
{
    UNode *p;
    p = user->next;
    if(p == NULL)
    {
        printf("\n>>>>>>>>>>提示:没有记录可以显示!\n");
        return;
    }
    printf("\t\t\t\t显示结果\n\n");
    printf("用户ID   用户名   密码   用户身份   \n");
    while(p)
    {
        printf("\n%-9s%-11s%-10s%-15s\n",p->data.id,p->data.username,p->data.password,p->data.identity);
        p=p->next;
    }
}

void printUserInfo(UNode *user)
{
    printf("%s",user);
    UNode *p;
    p = user->next;
    printf("%s",p);
    if(p == NULL)
    {
        printf("\n>>>>>>>>>>提示:没有用户信息!\n");
        return;
    }
    printf("\t\t\t\t显示结果\n\n");
    printf("ID号   用户昵称   用户密码   用户权限\n");
    while(p)
    {
        printf("\n%-9s%-11s%-10s%-15s%\n",p->data.id,p->data.username,p->data.password,p->data.identity);
        p=p->next;
    }
}

void addUserInfo(UNode *user)          //添加设备记录
{
    UNode *p,*r;
    char id[10];            //输入用户的ID
    r = user;
    while(r->next != NULL)
        r = r->next;
    while(1)
    {
        printf("\n请输入用户ID(输入0则返回主菜单):\n");
        scanf("%s",id);
        if(strcmp(id,"0") == 0)
            break;
        p=(UNode *)malloc(sizeof(UNode));
        strcpy(p->data.id,id);
        printf("\n请输入用户昵称:");
        scanf("%s",p->data.username);
        printf("\n请输入用户密码:");
        scanf("%s",p->data.password);
        printf("\n请输入用户身份:");
        scanf("%s",p->data.identity);
        p->next = NULL;
        r->next = p;
        r = p;
        write_user_toFile(user);
        printf("\n>>>>>>>>>>提示:成功添加一条用户记录\n\n");
    }
}

void updateUserInfo(UNode *user)       //更新设备信息
{
    UNode *p;
    char find[20];
    if(user->next == NULL)
    {
        printf("\n>>>>>>>>>>提示:没有资料可以修改!\n");
        return ;
    }
    printf("\n请输入要修改的用户ID号(输入0退出):");
    scanf("%s",find);
    if(strcmp(find,"0") == 0)
        exit(0);
    p = user->next;
    while(p != NULL)
    {
        if(strcmp(p->data.id,find) == 0)
            break;
        p = p->next;
    }
    if(p)
    {
        while(1)
        {
            char x[10];
            printf("请输入新设备号(原来是 %s ):",p->data.id);
            scanf("%s",x);
            strcpy(p->data.id,x);
            printf("请输入用户昵称(原来是 %s ):",p->data.username);
            scanf("%s",p->data.username);
            printf("请输入新用户密码(原来是 %s ):",p->data.password);
            scanf("%s",p->data.password);
            write_user_toFile(user);
            break;
        }
    }
    else
    {
        printf("\n>>>>>>>>>>提示:你要修改的信息不存在!\n");
    }
}


void updateUser_F(UNode *user)       //更新用户信息
{
    UNode *p;
    p = user->next;
    printf(currentUser.data.username);
    while(p != NULL &&(strcmp(currentUser.data.username,p->data.username)!=0))
    {
        p = p->next;
    }

    if(p)
    {
        while(1)
        {
            char x[20];
            printf("请输入新用户名称(原来是 %s ):",p->data.username);
            scanf("%s",p->data.username);
            printf("请输入新用户密码(原来是 %s ):",p->data.password);
            scanf("%s",p->data.password);
            printf("\n>>>>>>>>>>提示:该项记录资料已经成功修改!\n");
           // printUser(user);
            write_user_toFile(user);
            break;
        }
    }
    else
    {
        printf("\n>>>>>>>>>>提示:你要修改的信息不存在!\n");
    }
}
