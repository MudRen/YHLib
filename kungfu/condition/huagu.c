// huagu.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "huagu"; }

string chinese_name() { return "��������"; }

string update_msg_others()
{
       return HIC "$N" HIC "������ͻȻ�������Σ�����������\n" NOR;
}

string update_msg_self()
{
        return HIR "��Ȼ����һ���ʹ�����еĻ������ƶ����ˣ�\n" NOR;
}

string die_reason()
{
        return "��Ϲ��飬���ĲҲ�����";
}
