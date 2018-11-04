// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "corpse_poison"; }

string chinese_name() { return "��ʬ��"; }

string update_msg_others()
{
        return WHT "$N" WHT "ȫ���������Ż�ˮ����ס��˻����ɢ��"
               "���������ŵĶ����\n" NOR;
}

string update_msg_self()
{
        return WHT "��ֻ��ȫ�������Ƹ�����һ�㣬ɢ����һ�ɼ���"
               "�ŵĶ����\n" NOR;
}

string die_msg_others()
{
        return WHT "$N" WHT "˻���˼���������û��㶯����ȫ��ɢ"
               "����һ�ɶ����\n" NOR;
}

string die_reason()
{
        return "��ʬ������������";
}