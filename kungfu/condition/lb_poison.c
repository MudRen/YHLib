#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "lb_poison"; }

string chinese_name() { return "�̲��綾"; }

string update_msg_others()
{
       return HIB "ֻ��$N" HIB "��ɫɷ�ף����ӻ������Σ�����ɢ�ң����ƺ����һ�㡣\n" NOR;
}

string update_msg_self()
{
        return HIR "��ֻ��һ��Ī���Ķ���ӿ����ͷ��ȫ��������Ѫ����������������\n" NOR;
}
