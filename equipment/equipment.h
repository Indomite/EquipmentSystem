

void addEquipment(ENode *equip)          //添加设备记录
{
    ENode *p,*r;
    char id[10];            //输入设备的ID
    r = equip;
    while(r->next != NULL)
        r = r->next;
    while(1)
    {
        printf("\n请你输入设备ID号(输入0则返回主菜单):\n");
        scanf("%s",id);
        if(strcmp(id,"0") == 0)
            break;
        if(checkID(equip,id))
        {
            printf("\n>>>>>>>>>>提示:输入的编号已经存在,输入失败\n\n");
            return;
        }
        p=(ENode *)malloc(sizeof(ENode));
        strcpy(p->data.ID,id);
        printf("\n请输入设备种类:");
        scanf("%s",p->data.kind);
        printf("\n请输入设备名称:");
        scanf("%s",p->data.name);
        printf("\n请输入设备价格:");
        scanf("%s",p->data.price);
        printf("\n请输入设备购入日期:");
        scanf("%s",&p->data.date);
        printf("\n设备是否报废(1=>是;0=>否):");
        scanf("%s",&p->data.scrap);
        printf("\n设备报废日期:");
        scanf("%s",&p->data.over);
        p->next = NULL;
        r->next = p;
        r = p;
        fscanfEquipment(equip);
        printf("\n>>>>>>>>>>提示:成功添加一条记录\n\n");
    }
}

void deleteEquipment(ENode *equip)       //删除设备信息
{
    ENode *r,*s;
    char id[10];
    r = equip;
    s = r->next;
    if(equip->next == NULL)
    {
        printf("\n>>>>>>>>>>提示:没有资料可以删除\n\n");
        return ;
    }
    printf("\n请你输入要删除的设备ID号(输入0退出):");
    scanf("%s",id);
    if(strcmp(id,"0") == 0)
    {
        return;
    }
    if(!checkID(equip,id))
    {
        printf("\n>>>>>>>>>>提示:ID为%s的设备不存在\n\n",id);
        return;
    }
    while(s->next != NULL)
    {
        if(strcmp(s->data.ID,id) == 0)
        {
//                printf("%s",s->data.ID);
            r->next = s->next;
            free(s);
//                printf("%s",r->data.ID);
//                printf("%s",s->data.ID);
            fscanfEquipment(equip);
            printf("\n>>>>>>>>>>提示:成功删除一条记录\n");
            return ;
        }
        r = s;
        s = s->next;
    }
}

void updateEquipment(ENode *equip)       //更新设备信息
{
    ENode *p;
    char find[20];
    if(equip->next == NULL)
    {
        printf("\n>>>>>>>>>>提示:没有资料可以修改!\n");
        return ;
    }
    printf("\n请输入要修改的设备ID号(输入0退出):");
    scanf("%s",find);
    if(strcmp(find,"0") == 0)
        exit(0);
    p = equip->next;
    while(p != NULL)
    {
        if(strcmp(p->data.ID,find) == 0)
            break;
        p = p->next;
    }
    if(p)
    {
        while(1)
        {
            char x[10];
            printf("请输入新设备号(原来是 %s ):",p->data.ID);
            scanf("%s",x);
            if(checkID(equip,x) && (strcmp(p->data.ID,x)))              //在设备的信息修改时，满足ID不变的情况
            {
                printf("输入的编号已经存在，输入失败\n");
                return;
            }
            strcpy(p->data.ID,x);
            printf("请输入新设备名称(原来是 %s ):",p->data.name);
            scanf("%s",p->data.name);
            printf("请输入新设备设备种类名称(原来是 %s ):",p->data.kind);
            scanf("%s",p->data.kind);
            printf("请输入新设备报废日期名称(原来是 %s ):",p->data.over);
            scanf("%s",p->data.over);
            printf("请输入新设备是否报废(原来是 %s ):",p->data.scrap);
            scanf("%s",p->data.scrap);
            printf("请输入新设备购买时间(原来是 %s ):",p->data.date);
            scanf("%s",p->data.date);
            printf("请输入新设备价格(原来是 %s ):",p->data.price);
            scanf("%s",p->data.price);
            printf("\n>>>>>>>>>>提示:该项记录资料已经成功修改!\n");
            fscanfEquipment(equip);
            break;
        }
    }
    else
    {
        printf("\n>>>>>>>>>>提示:你要修改的信息不存在!\n");
    }
}

void printEquipment(ENode *equip)
{
    ENode *p;
    p = equip->next;
    if(p == NULL)
    {
        printf("\n>>>>>>>>>>提示:没有记录可以显示!\n");
        return;
    }
    printf("\t\t\t\t显示结果\n\n");
    printf("设备号   设备名称   设备种类   报废日期   是否报废   购买时间   价格\n");
    while(p)
    {
        printf("\n%-9s%-11s%-10s%-15s%-7s%-12s%-8s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.scrap,p->data.date,p->data.price);
        p=p->next;
    }
}

void classifyEquipment(ENode *equip)
{
    ENode *p;
    int sel;
    int flag2 = 0,ha = 0;
    p = equip->next;
    char find[20];
    if(equip->next == NULL)
    {
        printf("\n>>>>>>>>>>提示:没有资料可以统计分类!\n");
        return ;
    }
    printf(">>>>>>>>>>提示:\n0=>退出\n1=>按设备名称统计\n2=>按设备种类统计\n");
    scanf("%d",&sel);
    if(sel == 1)
    {
        printf("\n输入你要统计分类的设备名称:");
        scanf("%s",find);
        while(p)
        {
            if(strcmp(p->data.name,find)==0)
            {
                flag2++;
            }
            //找到符合条件的信息
            if(flag2 == 1 && ha!=flag2)
            {
                printf("设备号   设备名称   设备种类   报废日期   是否报废   购买时间   价格\n");
                printf("\n%-9s%-11s%-10s%-15s%-7s%-12s%-8s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.scrap,p->data.date,p->data.price);
                ha = flag2;
            }
            else if(flag2 > ha)
            {
                printf("\n%-9s%-11s%-10s%-15s%-7s%-12s%-8s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.scrap,p->data.date,p->data.price);
                ha = flag2;
            }
            p = p->next;
        }
        if(flag2)
        {
            printf("\n*************************按设备名称%s统计分类的有%d条记录:*************************\n\n",find,flag2);
        }
        else
        {
            printf("\n按设备名称%s统计的结果为0个\n\n",find);
        }
    }
    else if(sel == 2)
    {
        printf("\n输入你要统计分类的设备种类:");
        scanf("%s",find);
        while(p)
        {
            if(strcmp(p->data.kind,find)==0)
            {
                flag2++;
            }
            if(flag2 == 1 && ha!=flag2)
            {
                printf("设备号   设备名称   设备种类   报废日期   是否报废   购买时间   价格\n");
                printf("\n%-9s%-11s%-10s%-15s%-7s%-12s%-8s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.scrap,p->data.date,p->data.price);
                ha = flag2;
            }
            else if(flag2 > ha)
            {
                printf("\n%-9s%-11s%-10s%-15s%-7s%-12s%-8s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.scrap,p->data.date,p->data.price);
                ha = flag2;
            }
            p = p->next;
        }
        if(flag2)
        {
            printf("\n*************************按设备种类%s统计分类的有%d条记录:*************************\n\n",find,flag2);
        }
        else
        {
            printf("\n按设备种类%s统计的结果为0个\n\n",find);
        }
    }
    else
        return;
}

int checkID(ENode *equip,char* num)         //查询ID是否已经存在
{
    ENode *current = equip->next;
    while(current)
    {
        if(strcmp(current->data.ID,num)==0)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
