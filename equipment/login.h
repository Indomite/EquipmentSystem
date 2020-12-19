/* 查找一个元素 */
UNode *Logincheck(UNode *user,char* userName, char* passWord)
{
    UNode *ptr;
    ptr = user->next;
    if (ptr == NULL)
    {
        printf("用户链表为空！\n");
        return NULL;
    }

    while (ptr != NULL && (strcmp(userName,ptr->data.username)!=0))
    {
        ptr = ptr->next;
    }

    if (ptr != NULL)
    {
        if(strcmp(passWord,ptr->data.password)==0)
        {
            printf("                     登录成功，欢迎您！\n\n");
            strcpy(currentUser.data.id,ptr->data.id);
            strcpy(currentUser.data.username,ptr->data.username);
            strcpy(currentUser.data.password,ptr->data.password);
            strcpy(currentUser.data.identity,ptr->data.identity);
            currentUserP = ptr;
            return ptr;
        }
        else
        {
            printf("                     密码错误\n");
            return NULL;
        }
    }
    else
    {
        printf("用户名不存在！\n");
    }
    return ptr;
}

int Login()
{
    UNode *userlist;
    userlist = read_user_fromFile();
    char userName[20];/*用户名*/
    char userPassword[20];/*密码*/
    int i,sum;
    system("color 0B");//用于调整控制台颜色
    for(i=0; i<5; i++)
    {
        printf("\n                     请输入您的用户名:");
        gets(userName);
        printf("\n                     请输入您的密码:");
        gets(userPassword);
        UNode *current_User = Logincheck(userlist,userName, userPassword);
        if(current_User)
        {
            strcpy(currentUser.data.identity, current_User->data.identity);
            return 0;
        }
        else
        {
            if (i < 2)
            {
                printf("                     请重新输入!");//提示用户重新输入
            }
            else
            {
                printf("您已连续3次以上将用户名或密码输错，系统将退出!");//连续3次以上输错用户名或密码，退出系统。
                exit(1);
            }
        }
    }
}

void user_work_station()
{
    UNode *user;
    user = read_user_fromFile();
    ENode *equip;
    equip = fprintfEquipment();
    int flag;
    while(1)
    {
        user_work_meau();
        printf("请输入你要操作的序号:");
        scanf("%d",&flag);
        switch(flag)
        {
        case 0:
            printf("\n>>>>>>>>>>提示:已经退出系统,ByeBye!\n");
            exit(0);
        case 1:
            classifyEquipment(equip);
            break; //增加记录
        case 2:
            printEquipment(equip);
            break;//删除记录
        case 3:
            updateUser_F(user);
            break;//修改记录
        default:
            printf("\n>>>>>>>>>>提示:输入错误!\n");
            break;
        }
    }
}

void admin_work_station()
{
    UNode *user;
    user = read_user_fromFile();
    ENode *equip;
    equip = fprintfEquipment();
    int flag;
    while(1)
    {
        admin_work_meau();
        printf("请输入你要操作的序号:");
        scanf("%d",&flag);
        switch(flag)
        {
        case 0:
            printf("\n>>>>>>>>>>提示:已经退出系统,ByeBye!\n");
            exit(0);
        case 1:
            addEquipment(equip);
            break; //增加记录
        case 2:
            deleteEquipment(equip);
            break;//删除记录
        case 3:
            updateEquipment(equip);
            break;//修改记录
        case 4:
            printEquipment(equip);
            break;//显示记录信息
        case 5:
            classifyEquipment(equip);
            break;//统计记录
        case 6:
            printUserInfo(user);
            break;//统计记录
        case 7:
            addUserInfo(user);
            break;//统计记录
        case 8:
            updateUserInfo(user);
            break;//统计记录
        case 9:
            classifyEquipment(equip);
            break;//统计记录
        default:
            printf("\n>>>>>>>>>>提示:输入错误!\n");
            break;
        }
    }
}
