// iceshock.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "iceshock"; }

string chinese_name() { return "����"; }

string update_msg_others()
{
       return HIR "$N��Ȼ����һ�����¡�\n" NOR;
}

string update_msg_self()
{
        return HIB "����þ�������˱�����һ���������Ǻ��������ˣ�\n" NOR;
}
