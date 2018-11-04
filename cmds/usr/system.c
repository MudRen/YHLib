// system.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

string fs(int supplied);
string fc(int cost);

int main(object me, string arg)
{
        string msg;
        mapping cm;

        cm = CPU_D->query_entire_dbase();
        msg  = "���һ��ʱ��ϵͳʹ��CPU�����ͳ�ƣ�\n";
        msg += "ϵͳ�ṩCPU��Դ������ȣ�" + fs(cm["last_0"]["supplied"]) +
              "  ��Ϸ��CPU��ռ���ʣ�" + fc(cm["last_0"]["cost"]) + "��\n";

        msg += sprintf("ǰһЩʱ��CPU������Ⱥ�ռ���ʣ�%s/%s  %s/%s  %s/%s  %s/%s��\n",
                       fs(cm["last_1"]["supplied"]), fc(cm["last_1"]["cost"]),
                       fs(cm["last_2"]["supplied"]), fc(cm["last_2"]["cost"]),
                       fs(cm["last_3"]["supplied"]), fc(cm["last_3"]["cost"]),
                       fs(cm["last_4"]["supplied"]), fc(cm["last_4"]["cost"]));
        write(msg);
        return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : system
 
���ָ�������ʾ��Ŀǰ��Ϸʹ��ϵͳ��Դ��״��.
 
HELP );
    return 1;
}
 
string fs(int supplied)
{
        if (supplied <= 70)
                return sprintf(RED "%d%%" NOR, supplied);
        else
        if (supplied <= 90)
                return sprintf(HIR "%d%%" NOR, supplied);

        return sprintf(WHT "%d%%" NOR, supplied);
}

string fc(int cost)
{
        if (cost >= 90)
                return sprintf(RED "%d%%" NOR, cost);
        else
        if (cost >= 70)
                return sprintf(HIR "%d%%" NOR, cost);

        return sprintf(WHT "%d%%" NOR, cost);
}
