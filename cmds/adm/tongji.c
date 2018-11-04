#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object* users;
        int count, i, j;
        
        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        users = all_interactive();

        if (wiz_level(me) < 4)
                return 0;
  
        if (! str)
                return notify_fail("��Ҫͳ��ʲô���ܣ�\n");

        if (file_size("/kungfu/skill/" + str + ".c") == -1)
                return notify_fail("û��������ܴ��ڣ�\n");                

        count = sizeof(users);

        j = 0;
        write(HIW "\n����Ϊ��MUD������ " + HIM + CHINESE_D->chinese(str) + HIW + " ��������ҡ�\n" NOR);
        write(HIY "-------------------------------------------------------------------------\n" NOR);
        for (i = 0; i < count; i ++)
        {
             if (users[i]->query_skill(str, 1))
             {
                  write(HIC + users[i]->name() + "(" + users[i]->query("id") + ") \t\t" NOR);
                  write(HIC "���䣺" + users[i]->query("age") + "\t" NOR);
                  write(HIC "�������ɣ�" + users[i]->query("family/family_name") + "\t" NOR);
                  write(HIC "�ȼ���" + users[i]->query_skill(str, 1) + "\n" NOR);
                  j ++;
             }
         
        }
        write(HIW "\n�ܹ� " HIR + j + HIW " λ�������" + HIM + CHINESE_D->chinese(str) + "\n" NOR);
        write(HIY "-------------------------------------------------------------------------\n" NOR);

        return 1;
}

