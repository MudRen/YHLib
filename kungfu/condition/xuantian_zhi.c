#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "xuantian_zhi"; }

string chinese_name() { return "���캮��"; }

string update_msg_others()
{
       return HIW "$N" HIW "��ʹ���������һ�������Ͼ���"
              "����һ�ɱ����ĺ�˪��\n" NOR;
}

string update_msg_self()
{
        return HIW "��Ȼһ�����Ե���Ķ�������͸����"
               "֫���࣬͸�������⡣\n" NOR;
}

int jing_damage(object me, mapping cnd)
{
        return cnd["level"] / 6;
}

int qi_damage(object me, mapping cnd)
{
        return cnd["level"] / 3;
}
