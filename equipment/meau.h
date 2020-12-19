void printBlank(int n)          //打印指定数量的空格
{
    int i;
    for(i=0; i<=n; i++)
        putchar(' ');
}

void printLine(char c, int n)       //打印一行指定的字符
{
    int i;
    for(i=0; i<=n; i++)
        putchar(c);
    printf("\n");
}

void title()        //系统标题页面
{
    printBlank(20);
    printLine('=', 60);
    printBlank(20);
    printf("☆");
    printBlank(17);
    printBlank(38);
    printf("☆\n");
    printBlank(20);
    printf("☆");
    printBlank(20);
      printf("**实验设备管理系统**");
    printBlank(15);
    printf("☆\n");
    printBlank(20);
    printf("☆");
    printBlank(56);
    printf("☆\n");
    printBlank(20);
    printLine('=', 60);
}

void work_meau()
{
    if(strcmp(currentUser.data.identity,"user")==0)
    {
        user_work_station();
    }
    else if(strcmp(currentUser.data.identity,"admin")==0)
    {
        admin_work_station();
    }
}

void  user_work_meau()        //用户主菜单
{
    printBlank(20);
    printf("1->设备分类统计");
    printBlank(20);
    printf("2->设备查询显示");
    printf("\n");
    printBlank(20);
    printf("3->个人信息管理");
    printBlank(20);
    printf("0->退出");
    printf("\n");
    printf("\n");
}

void  admin_work_meau()        //管理员主菜单
{
    printBlank(20);
    printf("1->添加实验设备信息");
    printBlank(20);
    printf("2->删除实验设备信息");
    printf("\n");
    printBlank(20);
    printf("3->修改实验设备信息");
    printBlank(20);
    printf("4->显示实验设备信息");
    printf("\n");
    printBlank(20);
    printf("5->设备信息统计分类");
   // printf("\n");
    printBlank(20);
    printf("6->显示用户信息");
    printBlank(24);
     printf("\n");
     printBlank(20);
    printf("7->增加用户信息");
   // printf("\n");
    printBlank(24);
    printf("8->修改用户信息");
    printf("\n");
    printBlank(20);
    printf("0->退出");
    printf("\n");
    printf("\n");
}
