#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "zhurong_jian"; }

string chinese_name() { return "���׽���"; }

string update_msg_others()
{
       return HIR "$N" HIR "һ���Һ������˴������类�һ����չ�һ�㣡\n" NOR;
}

string update_msg_self()
{
        return HIR "��е�һ��׶�ĵ���ʹ�ӽ��˴�������ѪҺ����Ҫ������������\n" NOR;
}

