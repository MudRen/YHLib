#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "wudu_shenzhang"; }

string chinese_name() { return "���Ķ�"; }

string update_msg_others()
{
       return HIR "ֻ��$N" HIR "�ְ��ؿڣ���ɫ���ڣ�ʹ����֡�\n" NOR;
}

string update_msg_self()
{
        return HIB "������Ŀ���ʹ��֣�������ǧ�������Ĵ��ǣ�\n" NOR;
}
