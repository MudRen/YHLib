
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "yufengdu"; }

string chinese_name() { return "��䶾"; }

string update_msg_others()
{
        return HIW "$N" HIW "��ɫʹ�࣬��֫��ס��΢΢�鶯��\n" NOR;
}

string update_msg_self()
{
        return HIG "��ֻ��ȫ�������ޱȣ��������������������ڡ�\n" NOR;
}
