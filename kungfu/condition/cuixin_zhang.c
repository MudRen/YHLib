#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "cuixin_zhang"; }

string chinese_name() { return "����������"; }

string update_msg_others()
{
       return HIR "$N" HIR "һ���Һ�����Ϣ���������ۡ���һ�����һ�����Ѫ��\n" NOR;
}

string update_msg_self()
{
        return HIR "��ֻ�е������������ڲ�ֹ���綾���ģ����������˴������ƾ��ĸ��ţ�\n" NOR;
}

